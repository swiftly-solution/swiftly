#include "../../scripting.h"
#include "../../../../sdk/entity/CGameRules.h"

PluginServer::PluginServer(std::string m_plugin_name)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginServer::PluginServer(m_plugin_name=\"%s\")", m_plugin_name.c_str()));

    this->plugin_name = m_plugin_name;
}

std::string PluginServer::GetMap()
{
    REGISTER_CALLSTACK(this->plugin_name, "PluginServer::GetMap()");
    if (!engine->GetServerGlobals())
        return "unknown_map";

    return engine->GetServerGlobals()->mapname.ToCStr();
}

bool is_number(const std::string &s) {
  return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

bool PluginServer::IsMapValid(std::string map)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginServer::IsMapValid(map=\"%s\")", map.c_str()));
    
    return (is_number(map) || (engine->IsMapValid(map.c_str()) == 1));
}

void PluginServer::ChangeMap(std::string map, bool workshop)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginServer::ChangeMap(map=\"%s\", workshop=%d)", map.c_str(), workshop));
    if (!IsMapValid(map))
        return;

    Execute(string_format("%s %s", workshop ? "host_workshop_map" : "changelevel", map.c_str()));
}

uint16_t PluginServer::GetMaxPlayers()
{
    REGISTER_CALLSTACK(this->plugin_name, "PluginServer::GetMaxPlayers()");
    return engine->GetServerGlobals()->maxClients;
}

void PluginServer::Execute(std::string cmd)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginServer::Execute(cmd=\"%s\")", cmd.c_str()));
    engine->ServerCommand(cmd.c_str());
}

float PluginServer::GetCurrentTime()
{
    REGISTER_CALLSTACK(this->plugin_name, "PluginServer::GetCurrentTime()");
    if (!engine->GetServerGlobals())
        return 0.0f;

    return engine->GetServerGlobals()->curtime;
}

int PluginServer::GetTickCount()
{
    REGISTER_CALLSTACK(this->plugin_name, "PluginServer::GetTickCount()");
    if (!engine->GetServerGlobals())
        return 0;

    return engine->GetServerGlobals()->tickcount;
}

typedef void (*CGameRules_TerminateRound)(void*, float, uint32_t, int64_t, uint32_t);

void PluginServer::TerminateRound(float delay, uint32_t reason)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginServer::TerminateRound(%f,%d)", delay, reason));
    if(!gameRules) return;

    g_Signatures->FetchSignature<CGameRules_TerminateRound>("CGameRules_TerminateRound")(gameRules, delay, reason, 0, 0);
}