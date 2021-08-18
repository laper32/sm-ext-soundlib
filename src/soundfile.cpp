#include "soundfile.h"
#include "extension.h"
SoundFile::~SoundFile() {
	delete _file;
	delete _stream;
	_file = NULL;
	_stream = NULL;
}

SoundFile *SoundFile::Open(TagLib::IOStream *stream) {
	TagLib::File* file;
	
	SoundType type;
	
	#if _WIN32
		const char* file_ext = strrchr(stream->name().toString().toCString(true), '.');
	#else
		const char* file_ext = strrchr(stream->name(), '.');
	#endif
	if (file_ext == NULL) {
		return NULL;
	}
	if (iequals(file_ext, ".wav")) {
		file = new TagLib::RIFF::WAV::File(stream);
		type = WAV;
	}
	else if (iequals(file_ext, ".mp3")) {
		file = new TagLib::MPEG::File(stream, TagLib::ID3v2::FrameFactory::instance());
		type = MP3;
	}
	else {
		return NULL;
	}

	TagLib::Tag* tag = nullptr;
	if (!tag) tag = file->tag();
	
	return new SoundFile(file, stream, type, tag);
}

int SoundFile::length() {
	return _file->audioProperties()->length();
}

int SoundFile::lengthInMilliseconds() {
	return _file->audioProperties()->lengthInMilliseconds();
}

int SoundFile::bitrate() {
	return _file->audioProperties()->bitrate();
}

int SoundFile::sampleRate() {
	return _file->audioProperties()->sampleRate();
}

std::string SoundFile::title() {
	TagLib::String title = _tag->title();
	std::string result = title.toCString(true);
	return result;
}

SoundFile::SoundFile(TagLib::File* file, TagLib::IOStream* stream, SoundType type, TagLib::Tag* tag) {
	_file = file;
	_stream = stream;
	_type = type;
	_tag = tag;
}
