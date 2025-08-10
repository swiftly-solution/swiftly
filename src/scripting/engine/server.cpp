#include <scripting/core.h>

#include <sdk/game.h>
#include <utils/utils.h>
#include <entities/system.h>
#include <igamesystemfactory.h>

#include <public/steam/isteamgameserver.h>

bool is_number(const std::string &s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

typedef void (*CGameRules_TerminateRound)(void*, float, uint32_t, int64_t, uint32_t);

LoadScriptingComponent(server, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("Server");

    ADD_CLASS_FUNCTION("Server", "Server", [](FunctionContext* context, ClassData* data) -> void {});

    ADD_CLASS_FUNCTION("Server", "GetMap", [](FunctionContext* context, ClassData* data) -> void {
        if(!engine->GetServerGlobals()) return context->SetReturn("unknown_map");

        context->SetReturn(engine->GetServerGlobals()->mapname.ToCStr());
    });

    ADD_CLASS_FUNCTION("Server", "IsMapValid", [](FunctionContext* context, ClassData* data) -> void {
        std::string map_name = context->GetArgumentOr<std::string>(0, "");
        context->SetReturn((is_number(map_name) || (engine->IsMapValid(map_name.c_str()) == 1)));
    });

    ADD_CLASS_FUNCTION("Server", "ChangeMap", [](FunctionContext* context, ClassData* data) -> void {
        std::string map_name = context->GetArgumentOr<std::string>(0, "");
        bool workshop = context->GetArgumentOr<bool>(1, false);
        
        engine->ServerCommand(string_format("%s %s", workshop ? "host_workshop_map" : "changelevel", map_name.c_str()).c_str());
    });

    ADD_CLASS_FUNCTION("Server", "GetMaxPlayers", [](FunctionContext* context, ClassData* data) -> void {
        if(!engine->GetServerGlobals()) return context->SetReturn(GetMaxGameClients());
        context->SetReturn(engine->GetServerGlobals()->maxClients);
    });

    ADD_CLASS_FUNCTION("Server", "Execute", [](FunctionContext* context, ClassData* data) -> void {
        std::string command = context->GetArgumentOr<std::string>(0, "");
        if(command == "") return;

        engine->ServerCommand(command.c_str());
    });

    ADD_CLASS_FUNCTION("Server", "GetCurrentTime", [](FunctionContext* context, ClassData* data) -> void {
        if(!engine->GetServerGlobals()) return context->SetReturn(0.0f);
        context->SetReturn(engine->GetServerGlobals()->curtime);
    });

    ADD_CLASS_FUNCTION("Server", "GetTickCount", [](FunctionContext* context, ClassData* data) -> void {
        if(!engine->GetServerGlobals()) return context->SetReturn(0);
        context->SetReturn(engine->GetServerGlobals()->tickcount);
    });

    ADD_CLASS_FUNCTION("Server", "TerminateRound", [](FunctionContext* context, ClassData* data) -> void {
        if(!gameRules) return;
        
        float delay = context->GetArgumentOr<float>(0, 0.0f);
        int reason = context->GetArgumentOr<int>(1, 0);

        g_GameData.FetchSignature<CGameRules_TerminateRound>("CGameRules_TerminateRound")(gameRules, delay, reason, 0, 0);
    });

    ADD_CLASS_FUNCTION("Server", "GetIP", [](FunctionContext* context, ClassData* data) -> void {
        if(!g_SteamAPI.SteamGameServer()) return context->SetReturn("0.0.0.0");

        auto ip_addr = g_SteamAPI.SteamGameServer()->GetPublicIP();
        context->SetReturn(string_format("%d.%d.%d.%d", (ip_addr.m_unIPv4 >> 24) & 0xFF, (ip_addr.m_unIPv4 >> 16) & 0xFF, (ip_addr.m_unIPv4 >> 8) & 0xFF, ip_addr.m_unIPv4 & 0xff));
    });

    ADD_CLASS_FUNCTION("Server", "FindGameSystem", [](FunctionContext* context, ClassData* data) -> void {
        std::string name = context->GetArgumentOr<std::string>(0, "");

        context->SetReturn(MAKE_CLASS_INSTANCE("Memory", { {"ptr", (void*)CBaseGameSystemFactory::GetGlobalPtrByName(name.c_str()) } }));
    });
});