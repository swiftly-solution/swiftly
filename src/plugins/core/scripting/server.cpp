#include "../scripting.h"
#include "../../../sdk/entity/CGameRules.h"

PluginServer::PluginServer(std::string m_plugin_name)
{
    this->plugin_name = m_plugin_name;
}

std::string PluginServer::GetMap()
{
    if (!engine->GetServerGlobals())
        return "unknown_map";

    return engine->GetServerGlobals()->mapname.ToCStr();
}

bool PluginServer::IsMapValid(std::string map)
{
    return (engine->IsMapValid(map.c_str()) == 1);
}

void PluginServer::ChangeMap(std::string map, bool workshop)
{
    if (!IsMapValid(map))
        return;

    Execute(string_format("%s %s", workshop ? "host_workshop_map" : "map", map.c_str()));
}

uint16_t PluginServer::GetMaxPlayers()
{
    return engine->GetServerGlobals()->maxClients;
}

void PluginServer::Execute(std::string cmd)
{
    engine->ServerCommand(cmd.c_str());
}

float PluginServer::GetCurrentTime()
{
    if (!engine->GetServerGlobals())
        return 0.0f;

    return engine->GetServerGlobals()->curtime;
}

int PluginServer::GetTickCount()
{
    if (!engine->GetServerGlobals())
        return 0;

    return engine->GetServerGlobals()->tickcount;
}
