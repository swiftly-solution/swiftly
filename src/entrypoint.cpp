#include <stdio.h>
#include <stdint.h>
#include "common.h"

SwiftlyPlugin g_Plugin;
IServerGameDLL *server = NULL;
IServerGameClients *gameclients = NULL;
IVEngineServer2 *engine = NULL;
IFileSystem *filesystem = NULL;
ICvar *icvar = NULL;

PLUGIN_EXPOSE(SwiftlyPlugin, g_Plugin);
bool SwiftlyPlugin::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
    PLUGIN_SAVEVARS();
    GET_V_IFACE_CURRENT(GetEngineFactory, engine, IVEngineServer2, INTERFACEVERSION_VENGINESERVER);
    GET_V_IFACE_CURRENT(GetEngineFactory, icvar, ICvar, CVAR_INTERFACE_VERSION);
    GET_V_IFACE_CURRENT(GetFileSystemFactory, filesystem, IFileSystem, FILESYSTEM_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetServerFactory, server, IServerGameDLL, INTERFACEVERSION_SERVERGAMEDLL);
    GET_V_IFACE_ANY(GetServerFactory, gameclients, IServerGameClients, INTERFACEVERSION_SERVERGAMECLIENTS);

    g_pCVar = icvar;
    ConVar_Register(FCVAR_RELEASE | FCVAR_CLIENT_CAN_EXECUTE | FCVAR_SERVER_CAN_EXECUTE | FCVAR_GAMEDLL);

    return true;
}

void SwiftlyPlugin::AllPluginsLoaded()
{
}

bool SwiftlyPlugin::Unload(char *error, size_t maxlen)
{
    ConVar_Unregister();

    return true;
}

bool SwiftlyPlugin::Pause(char *error, size_t maxlen)
{
    return true;
}

bool SwiftlyPlugin::Unpause(char *error, size_t maxlen)
{
    return true;
}

const char *SwiftlyPlugin::GetAuthor()
{
    return "";
}

const char *SwiftlyPlugin::GetName()
{
    return "Swiftly";
}

const char *SwiftlyPlugin::GetDescription()
{
    return "";
}

const char *SwiftlyPlugin::GetURL()
{
    return "";
}

const char *SwiftlyPlugin::GetLicense()
{
    return "GPL";
}

const char *SwiftlyPlugin::GetVersion()
{
    return "1.0";
}

const char *SwiftlyPlugin::GetDate()
{
    return __DATE__;
}

const char *SwiftlyPlugin::GetLogTag()
{
    return "Swiftly";
}