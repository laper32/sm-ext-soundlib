#include "extension.h"

#include "soundfile.h"
#include "systemfilestream.h"
#include "valvefilestream.h"

extern HandleType_t g_SoundFileType;

template<typename T> concept String_c = std::same_as<T, std::string> || std::same_as<T, std::wstring>;
// trim from start (in place)
template<String_c T>
static inline void ltrim(T& s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
		return !std::isspace(ch);
		}));
}
// trim from end (in place)
template<String_c T>
static inline void rtrim(T& s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
		return !std::isspace(ch);
		}).base(), s.end());
}

// trim from both ends (in place)
template<String_c T>
static inline void trim(T& s) {
	ltrim(s);
	rtrim(s);
}

int preNUm(unsigned char byte) {
    unsigned char mask = 0x80;
    int num = 0;
    for (int i = 0; i < 8; i++) {
        if ((byte & mask) == mask) {
            mask = mask >> 1;
            num++;
        } else {
            break;
        }
    }
    return num;
}


bool isUtf8(unsigned char* data, int len) {
    int num = 0;
    int i = 0;
    while (i < len) {
        if ((data[i] & 0x80) == 0x00) {
            // 0XXX_XXXX
            i++;
            continue;
        }
        else if ((num = preNUm(data[i])) > 2) {
        // 110X_XXXX 10XX_XXXX
        // 1110_XXXX 10XX_XXXX 10XX_XXXX
        // 1111_0XXX 10XX_XXXX 10XX_XXXX 10XX_XXXX
        // 1111_10XX 10XX_XXXX 10XX_XXXX 10XX_XXXX 10XX_XXXX
        // 1111_110X 10XX_XXXX 10XX_XXXX 10XX_XXXX 10XX_XXXX 10XX_XXXX
        // preNUm() 返回首个字节8个bits中首�?0bit前面1bit的个数，该数量也是该字符所使用的字节数        
        i++;
        for(int j = 0; j < num - 1; j++) {
            //判断后面num - 1 个字节是不是都是10开
            if ((data[i] & 0xc0) != 0x80) {
                    return false;
                }
                i++;
        }
    } else {
        //其他情况说明不是utf-8
        return false;
    }
    } 
    return true;
}

bool isGBK(unsigned char* data, int len)  {
    int i  = 0;
    while (i < len)  {
        if (data[i] <= 0x7f) {
            //编码小于等于127,只有一个字节的编码，兼容ASCII
            i++;
            continue;
        } else {
            //大于127的使用双字节编码
            if  (data[i] >= 0x81 &&
                data[i] <= 0xfe &&
                data[i + 1] >= 0x40 &&
                data[i + 1] <= 0xfe &&
                data[i + 1] != 0xf7) {
                i += 2;
                continue;
            } else {
                return false;
            }
        }
    }
    return true;
}

typedef enum {
    GBK,
    UTF8,
    UNKOWN
} CODING;
//需要说明的是，isGBK()是通过双字节是否落在gbk的编码范围内实现的，
//而utf-8编码格式的每个字节都是落在gbk的编码范围内�?
//所以只有先调用isUtf8()先判断不是utf-8编码，再调用isGBK()才有意义
CODING GetCoding(unsigned char* data, int len) {
    CODING coding;
    if (isUtf8(data, len) == true) {
        coding = UTF8;
    } else if (isGBK(data, len) == true) {
        coding = GBK;
    } else {
        coding = UNKOWN;
    }
    return coding;
}

#ifdef _WIN32
inline std::string ConvertGBKToUTF8(const std::string& strGbk)//�����strGbk��GBK����  
{
	//gbkתunicode  
	auto len = MultiByteToWideChar(CP_ACP, 0, strGbk.c_str(), -1, NULL, 0);
	std::unique_ptr<wchar_t[]> strUnicode(new wchar_t[len + 1]{});
	MultiByteToWideChar(CP_ACP, 0, strGbk.c_str(), -1, strUnicode.get(), len);

	//unicodeתUTF-8  
	len = WideCharToMultiByte(CP_UTF8, 0, strUnicode.get(), -1, NULL, 0, NULL, NULL);
	std::unique_ptr<char[]> strUtf8(new char[len + 1]{});
	WideCharToMultiByte(CP_UTF8, 0, strUnicode.get(), -1, strUtf8.get(), len, NULL, NULL);

	//��ʱ��strUtf8��UTF-8����  
	return std::string(strUtf8.get());
}

// UTF8תGBK
inline std::string ConvertUTF8ToGBK(const std::string& strUtf8)
{
	//UTF-8תunicode  
	int len = MultiByteToWideChar(CP_UTF8, 0, strUtf8.c_str(), -1, NULL, 0);
	std::unique_ptr<wchar_t[]> strUnicode(new wchar_t[len + 1]{});//len = 2  
	MultiByteToWideChar(CP_UTF8, 0, strUtf8.c_str(), -1, strUnicode.get(), len);

	//unicodeתgbk  
	len = WideCharToMultiByte(CP_ACP, 0, strUnicode.get(), -1, NULL, 0, NULL, NULL);
	std::unique_ptr<char[]>strGbk(new char[len + 1]{});//len=3 ����Ϊ2������char*�����Զ�������\0  
	WideCharToMultiByte(CP_ACP, 0, strUnicode.get(), -1, strGbk.get(), len, NULL, NULL);

	//��ʱ��strTemp��GBK����  
	return std::string(strGbk.get());
}
#else
#include <iconv.h>
// TODO
inline std::string ConvertGBKToUTF8(const std::string& strGbk)
{
	char* inbuf = const_cast<char*>(strGbk.c_str());
	size_t inlen = strlen(inbuf);
	size_t outlen = inlen * 4;
	char* outbuf = (char *)malloc(inlen * 4);
	bzero(outbuf, inlen * 4);
	char* in = inbuf;
	char* out = outbuf;
	iconv_t cd = iconv_open("utf-8", "gb2312");
	iconv(cd, &in, &inlen, &out, &outlen);
	iconv_close(cd);
	std::string ret = "";
	ret = outbuf;
	return ret;
}

// TODO
inline std::string ConvertUTF8ToGBK(const std::string& strUtf8)
{
	char* inbuf = const_cast<char*>(strUtf8.c_str());
	size_t inlen = strlen(inbuf);
	size_t outlen = inlen * 4;
	char* outbuf = (char *)malloc(inlen * 4);
	bzero(outbuf, inlen * 4);
	char* in = inbuf;
	char* out = outbuf;
	iconv_t cd = iconv_open("gb2312", "utf-8");
	iconv(cd, &in, &inlen, &out, &outlen);
	iconv_close(cd);
	std::string ret = "";
	ret = outbuf;
	return ret;
}
#endif

static cell_t OpenSoundFile(IPluginContext* pContext, const cell_t* params) {
	char* filename;
	pContext->LocalToString(params[1], &filename);

	TagLib::IOStream* stream;
	if (params[2]) {
		stream = ValveFileStream::Open(filename, "rb");
	}
	else {
		std::string filename_hndl = "";
		char path[256];
		g_pSM->BuildPath(Path_Game, path, sizeof(path), "%s", filename);
		if (GetCoding((unsigned char*)path, sizeof(path) != UTF8)) {
			filename_hndl = ConvertGBKToUTF8(path);
		} else {
			filename_hndl = path;
		}
		trim(filename_hndl);
		
		stream = SystemFileStream::Open(filename_hndl.c_str(), "rb");
	}
	if (!stream) {
		return 0;
	}
	auto sf = SoundFile::Open(stream);
	if (!sf) {
		delete stream;
		return 0;
	}

	return handlesys->CreateHandle(g_SoundFileType, sf, pContext->GetIdentity(), myself->GetIdentity(), NULL);
}

static cell_t GetSoundLength(IPluginContext *pContext, const cell_t *params)
{
	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;

	/* Build our security descriptor */
	sec.pOwner = NULL;	/* Not needed, owner access is not checked */
	sec.pIdentity = myself->GetIdentity();	/* But only this extension can read */

	SoundFile *sf;
	if ((err = handlesys->ReadHandle(hndl, g_SoundFileType, &sec, (void **)&sf))
		!= HandleError_None)
	{
		pContext->ReportError("Invalid sound-file handle %x (error %d)", hndl, err);
		return 0;
	}

	return sf->length();
}

static cell_t GetSoundLengthInMilliseconds(IPluginContext *pContext, const cell_t *params)
{
	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;

	/* Build our security descriptor */
	sec.pOwner = NULL;	/* Not needed, owner access is not checked */
	sec.pIdentity = myself->GetIdentity();	/* But only this extension can read */

	SoundFile *sf;
	if ((err = handlesys->ReadHandle(hndl, g_SoundFileType, &sec, (void **)&sf))
		!= HandleError_None)
	{
		pContext->ReportError("Invalid sound-file handle %x (error %d)", hndl, err);
		return 0;
	}

	return sf->lengthInMilliseconds();
}

static cell_t GetSoundBitrate(IPluginContext *pContext, const cell_t *params)
{
	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;

	/* Build our security descriptor */
	sec.pOwner = NULL;	/* Not needed, owner access is not checked */
	sec.pIdentity = myself->GetIdentity();	/* But only this extension can read */

	SoundFile *sf;
	if ((err = handlesys->ReadHandle(hndl, g_SoundFileType, &sec, (void **)&sf))
		!= HandleError_None)
	{
		pContext->ReportError("Invalid sound-file handle %x (error %d)", hndl, err);
		return 0;
	}

	return sf->bitrate();
}

static cell_t GetSoundSamplingRate(IPluginContext *pContext, const cell_t *params)
{
	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;

	/* Build our security descriptor */
	sec.pOwner = NULL;	/* Not needed, owner access is not checked */
	sec.pIdentity = myself->GetIdentity();	/* But only this extension can read */

	SoundFile *sf;
	if ((err = handlesys->ReadHandle(hndl, g_SoundFileType, &sec, (void **)&sf))
		!= HandleError_None)
	{
		pContext->ReportError("Invalid sound-file handle %x (error %d)", hndl, err);
		return 0;
	}

	return sf->sampleRate();
}

sp_nativeinfo_t g_Natives[] =
{
	{ "SoundFile.SoundFile", OpenSoundFile},
	{ "OpenSoundFile", OpenSoundFile },

	{ "SoundFile.Length.get", GetSoundLength },
	{ "GetSoundLength", GetSoundLength },

	{ "SoundFile.LengthInMilliseconds.get", GetSoundLengthInMilliseconds },
	{ "GetSoundLengthInMilliseconds", GetSoundLengthInMilliseconds },

	{ "SoundFile.Bitrate.get", GetSoundBitrate },
	{ "GetSoundBitrate", GetSoundBitrate },

	{ "SoundFile.SamplingRate.get", GetSoundSamplingRate },
	{ "GetSoundSamplingRate", GetSoundSamplingRate },
	{ NULL,	NULL },
};