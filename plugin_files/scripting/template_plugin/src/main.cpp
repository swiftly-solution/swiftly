#include <swiftly/swiftly.h>
#include <swiftly/server.h>
#include <swiftly/database.h>
#include <swiftly/commands.h>
#include <swiftly/configuration.h>
#include <swiftly/logger.h>
#include <swiftly/timers.h>

#include <main.h>

Server *server = nullptr;
PlayerManager *g_playerManager = nullptr;
Database *db = nullptr;
Commands *commands = nullptr;
Configuration *config = nullptr;
Logger *logger = nullptr;
Timers *timers = nullptr;

void OnProgramLoad(const char *pluginName, const char *mainFilePath)
{
    Swiftly_Setup(pluginName, mainFilePath);

    server = new Server();
    g_playerManager = new PlayerManager();
    commands = new Commands(pluginName);
    config = new Configuration();
    logger = new Logger(mainFilePath, pluginName);
    timers = new Timers();
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

void OnRoundStart(long timelimit, long fraglimit, const char *objective)
{
}

void OnRoundEnd(unsigned char winner, unsigned char reason, const char *message, unsigned char legacy, short player_count, unsigned char nomusic)
{
}

void OnRoundPrestart()
{
}

void OnBombBeginPlant(Player *player, unsigned short site)
{
}

void OnBombAbortPlant(Player *player, unsigned short site)
{
}

void OnBombPlanted(Player *player, unsigned short site)
{
}

void OnBombBeginDefuse(Player *player, unsigned short site)
{
}

void OnBombAbortDefuse(Player *player, unsigned short site)
{
}

void OnBombDefused(Player *player, unsigned short site)
{
}

void OnBombExploded(Player *player, unsigned short site)
{
}

void OnBombDropped(Player *player)
{
}

void OnBombPickup(Player *player)
{
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