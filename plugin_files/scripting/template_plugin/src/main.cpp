#include <swiftly/swiftly.h>
#include <swiftly/server.h>
#include <swiftly/database.h>
#include <swiftly/commands.h>
#include <swiftly/configuration.h>
#include <swiftly/logger.h>

#include <main.h>

Server *server = nullptr;
PlayerManager *g_playerManager = nullptr;
Database *db = nullptr;
Commands *commands = nullptr;
Configuration *config = nullptr;
Logger *logger = nullptr;

void OnProgramLoad(const char *pluginName, const char *mainFilePath)
{
    Swiftly_Setup(pluginName, mainFilePath);

    server = new Server();
    g_playerManager = new PlayerManager();
    commands = new Commands(pluginName);
    config = new Configuration();
    logger = new Logger(mainFilePath, pluginName);
}

void OnPluginStart()
{
}

void OnPluginStop()
{
}

bool OnClientConnected(Player *player)
{
    return true;
}

bool OnClientConnect(Player *player)
{
    return true;
}

void OnPlayerSpawn(Player *player)
{
}

void OnGameTick(bool simulating, bool bFirstTick, bool bLastTick)
{
}

bool OnPlayerChat(Player *player, const char *text, bool teamonly)
{
    return true;
}

const char *GetPluginAuthor()
{
    return "";
}

const char *GetPluginVersion()
{
    return "1.0.0";
}

const char *GetPluginName()
{
    return "PLUGIN_NAME";
}

const char *GetPluginWebsite()
{
    return "";
}