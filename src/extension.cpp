#include "extension.h"

/**
 * @file extension.cpp
 * @brief Implement extension code here.
 */

SoundLib g_SoundLib;		/**< Global singleton for extension's main interface */

SMEXT_LINK(&g_SoundLib);

IBaseFileSystem* basefilesystem = nullptr;
HandleType_t g_SoundFileType = 0;
FileTypeHandler g_FileTypeHandler;

extern sp_nativeinfo_t g_Natives[];

bool SoundLib::SDK_OnLoad(char * error, size_t maxlength, bool late)
{
	g_SoundFileType = handlesys->CreateType("SoundFile", &g_FileTypeHandler, 0, NULL, NULL, myself->GetIdentity(), NULL);
	sharesys->AddNatives(myself, g_Natives);
	return true;
}

void SoundLib::SDK_OnUnload()
{
	handlesys->RemoveType(g_SoundFileType, myself->GetIdentity());
}

bool SoundLib::SDK_OnMetamodLoad(ISmmAPI * ismm, char * error, size_t maxlen, bool late)
{
	GET_V_IFACE_CURRENT(GetFileSystemFactory, basefilesystem, IBaseFileSystem, BASEFILESYSTEM_INTERFACE_VERSION);
	return true;
}
