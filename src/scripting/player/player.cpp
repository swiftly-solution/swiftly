#include <scripting/core.h>

#include <sdk/game.h>
#include <server/player/manager.h>
#include <server/commands/manager.h>
#include <utils/utils.h>
#include <utils/common.h>
#include <memory/gamedata/gamedata.h>
#include <memory/virtual/virtual.h>
#include <engine/convars/query.h>
#include <server/configuration/configuration.h>
#include <sdk/schema.h>

#include "network_connection.pb.h"

typedef void (*CBasePlayerController_SetPawn)(void*, void*, bool, bool);

LoadScriptingComponent(player, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_FUNCTION("GetPlayer", [](FunctionContext* context) -> void {
        int playerid = context->GetArgumentOr<int>(0, -1);
        if (playerid < 0 || playerid >= GetMaxGameClients()) return;

        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        context->SetReturn(player->GetPlayerObject());
    });

    ADD_CLASS("Player");

    ADD_CLASS_FUNCTION("Player", "CBaseEntity", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn(MakeSDKClassInstance("CBaseEntity", nullptr, context->GetPluginContext()));

        context->SetReturn(MakeSDKClassInstance("CBaseEntity", player->GetPlayerPawn(), context->GetPluginContext()));
    });

    ADD_CLASS_FUNCTION("Player", "CBasePlayerController", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn(MakeSDKClassInstance("CBasePlayerController", nullptr, context->GetPluginContext()));

        context->SetReturn(MakeSDKClassInstance("CBasePlayerController", player->GetController(), context->GetPluginContext()));
    });

    ADD_CLASS_FUNCTION("Player", "CBasePlayerPawn", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn(MakeSDKClassInstance("CBasePlayerPawn", nullptr, context->GetPluginContext()));

        context->SetReturn(MakeSDKClassInstance("CBasePlayerPawn", player->GetPawn(), context->GetPluginContext()));
    });

    ADD_CLASS_FUNCTION("Player", "CCSPlayerController", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn(MakeSDKClassInstance("CCSPlayerController", nullptr, context->GetPluginContext()));

        context->SetReturn(MakeSDKClassInstance("CCSPlayerController", player->GetController(), context->GetPluginContext()));
    });

    ADD_CLASS_FUNCTION("Player", "CCSPlayerPawn", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn(MakeSDKClassInstance("CCSPlayerPawn", nullptr, context->GetPluginContext()));

        context->SetReturn(MakeSDKClassInstance("CCSPlayerPawn", player->GetPlayerPawn(), context->GetPluginContext()));
    });

    ADD_CLASS_FUNCTION("Player", "CCSPlayerPawnBase", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn(MakeSDKClassInstance("CCSPlayerPawnBase", nullptr, context->GetPluginContext()));

        context->SetReturn(MakeSDKClassInstance("CCSPlayerPawnBase", player->GetPlayerPawn(), context->GetPluginContext()));
    });

    ADD_CLASS_FUNCTION("Player", "Drop", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        int reason = context->GetArgumentOr<int>(0, -1);
        if (reason == -1) return;

        std::string str_reason = context->GetArgumentOr<std::string>(1, "");

        if (!engine) return;

        engine->DisconnectClient(CPlayerSlot(playerid), (ENetworkDisconnectionReason)reason, str_reason == "" ? nullptr : str_reason.c_str());
    });

    ADD_CLASS_FUNCTION("Player", "GetChatTag", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn("");

        context->SetReturn(player->GetInternalVar("tag"));
    });

    ADD_CLASS_FUNCTION("Player", "GetChatTagColor", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn("");

        context->SetReturn(player->GetInternalVar("tagcolor"));
    });

    ADD_CLASS_FUNCTION("Player", "GetNameColor", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn("");

        context->SetReturn(player->GetInternalVar("namecolor"));
    });

    ADD_CLASS_FUNCTION("Player", "GetChatColor", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn("");

        context->SetReturn(player->GetInternalVar("chatcolor"));
    });

    ADD_CLASS_FUNCTION("Player", "SetChatTag", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        std::string value = context->GetArgumentOr<std::string>(0, "");

        player->SetInternalVar("tag", value);
    });

    ADD_CLASS_FUNCTION("Player", "SetChatTagColor", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        std::string value = context->GetArgumentOr<std::string>(0, "");

        player->SetInternalVar("tagcolor", value);
    });

    ADD_CLASS_FUNCTION("Player", "SetNameColor", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        std::string value = context->GetArgumentOr<std::string>(0, "");

        player->SetInternalVar("namecolor", value);
    });

    ADD_CLASS_FUNCTION("Player", "SetChatColor", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        std::string value = context->GetArgumentOr<std::string>(0, "");

        player->SetInternalVar("chatcolor", value);
    });

    ADD_CLASS_FUNCTION("Player", "ExecuteCommand", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");
        std::string cmd = context->GetArgumentOr<std::string>(0, "");
        if (cmd == "") return;

        if (starts_with(cmd, "sw_"))
        {
            CCommand tokenizedArgs;
            tokenizedArgs.Tokenize(cmd.c_str());

            std::vector<std::string> cmdString = TokenizeCommand(cmd);
            cmdString.erase(cmdString.begin());

            std::string commandName = replace(tokenizedArgs[0], "sw_", "");

            Command* command = g_commandsManager.FetchCommand(commandName);
            if (command)
                command->Execute(playerid, cmdString, true, "sw_");
        }
        else
            engine->ClientCommand(playerid, cmd.c_str());
    });

    ADD_CLASS_FUNCTION("Player", "GetConvar", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");
        std::string cvarname = context->GetArgumentOr<std::string>(0, "");

        if (!engine) return context->SetReturn("");

        context->SetReturn(engine->GetClientConVarValue(CPlayerSlot(playerid), cvarname.c_str()));
    });

    ADD_CLASS_FUNCTION("Player", "SetConvar", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        std::string cvar_name = context->GetArgumentOr<std::string>(0, "");
        std::string cvar_value = context->GetArgumentOr<std::string>(1, "");

        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        player->SetClientConvar(cvar_name, cvar_value);
    });

    ADD_CLASS_FUNCTION("Player", "GetIPAddress", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn("0.0.0.0");

        context->SetReturn(player->GetIPAddress());
    });

    ADD_CLASS_FUNCTION("Player", "GetSlot", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");
        context->SetReturn(playerid);
    });

    ADD_CLASS_FUNCTION("Player", "GetSteamID", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn(0);

        context->SetReturn(player->GetSteamID());
    });

    ADD_CLASS_FUNCTION("Player", "GetUnauthorizedSteamID", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn(0);

        context->SetReturn(player->GetUnauthorizedSteamID());
    });

    ADD_CLASS_FUNCTION("Player", "GetSteamID2", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn("STEAM_0:0:000000000");

        uint64_t steamid = player->GetSteamID();

        if (steamid == 0)
            return context->SetReturn("STEAM_0:0:000000000");

        static const uint64_t base = 76561197960265728;
        context->SetReturn(string_format("STEAM_0:%d:%llu", (steamid - base) & 1, (steamid - base) / 2));
    });

    ADD_CLASS_FUNCTION("Player", "GetUnauthorizedSteamID2", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn("STEAM_0:0:000000000");

        uint64_t steamid = player->GetUnauthorizedSteamID();

        if (steamid == 0)
            return context->SetReturn("STEAM_0:0:000000000");

        static const uint64_t base = 76561197960265728;
        context->SetReturn(string_format("STEAM_0:%d:%llu", (steamid - base) & 1, (steamid - base) / 2));
    });

    ADD_CLASS_FUNCTION("Player", "IsAuthorized", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn(false);

        context->SetReturn(player->IsAuthorized());
    });

    ADD_CLASS_FUNCTION("Player", "HideMenu", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);

        if (!player) return;
        if (!player->menu_renderer->HasMenuShown()) return;

        player->menu_renderer->HideMenu();
    });

    ADD_CLASS_FUNCTION("Player", "IsFakeClient", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn(true);

        context->SetReturn(player->IsFakeClient());
    });

    ADD_CLASS_FUNCTION("Player", "IsFirstSpawn", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn(false);

        context->SetReturn(player->IsFirstSpawn());
    });

    ADD_CLASS_FUNCTION("Player", "Kill", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        void* pawn = player->GetPawn();
        CALL_VIRTUAL(void, g_GameData.GetOffset("CBasePlayerPawn_CommitSuicide"), pawn, false, true);
    });

    ADD_CLASS_FUNCTION("Player", "Respawn", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        Player* player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn(false);

        void* controller = player->GetController();
        void* pawn = player->GetPlayerPawn();
        if (!pawn) return;

        g_GameData.FetchSignature<CBasePlayerController_SetPawn>("CBasePlayerController_SetPawn")(controller, pawn, true, false);
        CALL_VIRTUAL(void, g_GameData.GetOffset("CCSPlayerController_Respawn"), controller);
    });

    ADD_CLASS_FUNCTION("Player", "SendMsg", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        int messageType = context->GetArgumentOr<int>(0, 0);
        std::string message = context->GetArgumentOr<std::string>(1, "");

        player->SendMsg(messageType, message.c_str());
    });

    ADD_CLASS_FUNCTION("Player", "SwitchTeam", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");
        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        int team = context->GetArgumentOr<int>(0, -1);
        if (team == -1) return;

        player->SwitchTeam(team);
    });

    ADD_CLASS_FUNCTION("Player", "ChangeTeam", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");
        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        int team = context->GetArgumentOr<int>(0, -1);
        if (team == -1) return;

        player->ChangeTeam(team);
    });

    ADD_CLASS_FUNCTION("Player", "ShowMenu", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");
        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        std::string menuid = context->GetArgumentOr<std::string>(0, "");
        if (player->menu_renderer->HasMenuShown()) return;

        player->menu_renderer->ShowMenu(menuid);
    });

    ADD_CLASS_FUNCTION("Player", "GetVar", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");
        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn(nullptr);

        std::string key = context->GetArgumentOr<std::string>(0, "");
        if (key == "") return context->SetReturn(nullptr);

        context->SetReturn(player->GetInternalVar(key));
    });

    ADD_CLASS_FUNCTION("Player", "SetVar", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");
        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        std::string key = context->GetArgumentOr<std::string>(0, "");
        if (key == "") return;

        std::any value = context->GetArgumentOr<std::any>(1, nullptr);
        player->SetInternalVar(key, value);
    });

    ADD_CLASS_FUNCTION("Player", "SetListening", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");
        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        int otherid = context->GetArgumentOr<int>(0, -1);
        if (!g_playerManager.GetPlayer(otherid)) return;

        int listenOverride = context->GetArgumentOr<int>(0, 0);

        player->SetListen(CPlayerSlot(otherid), listenOverride);
    });

    ADD_CLASS_FUNCTION("Player", "GetVoiceFlags", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");
        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn(0);

        context->SetReturn(player->GetVoiceFlags());
    });

    ADD_CLASS_FUNCTION("Player", "SetVoiceFlags", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");
        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        int flags = context->GetArgumentOr<int>(0, 0);
        player->SetVoiceFlags(flags);
    });

    ADD_CLASS_FUNCTION("Player", "GetConnectedTime", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");
        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn(0);

        context->SetReturn(player->GetConnectedTime());
    });

    ADD_CLASS_FUNCTION("Player", "GetWeaponManager", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");

        context->SetReturn(MAKE_CLASS_INSTANCE("WeaponManager", { { "playerid", playerid } }));
    });

    ADD_CLASS_FUNCTION("Player", "QueryConvar", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");
        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        std::string cvar_name = context->GetArgumentOr<std::string>(0, "");
        g_convarQuery.QueryCvarClient(CPlayerSlot(playerid), cvar_name);
    });

    ADD_CLASS_FUNCTION("Player", "PerformMenuAction", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");
        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return;

        std::string action = context->GetArgumentOr<std::string>(0, "");
        int value = context->GetArgumentOr<int>(0, 0);

        if (action == "useOption") {
            if (!player->menu_renderer->HasMenuShown()) return;
            if (player->menu_renderer->GetMenu()->GetItemsOnPage(player->menu_renderer->GetPage()) < value) return;
            while (player->menu_renderer->GetSelection() != value - 1)
                player->menu_renderer->MoveSelection();

            player->menu_renderer->PerformMenuAction(g_Config.FetchValue<std::string>("core.menu.buttons.use"));
        }
        else if (action == "scrollToOption") {
            if (!player->menu_renderer->HasMenuShown()) return;
            if (player->menu_renderer->GetMenu()->GetItemsOnPage(player->menu_renderer->GetPage()) < value) return;

            while (player->menu_renderer->GetSelection() != value - 1)
                player->menu_renderer->MoveSelection();
        }
    });

    ADD_CLASS_FUNCTION("Player", "IsValid", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = data->GetData<int>("playerid");
        auto player = g_playerManager.GetPlayer(playerid);
        if (!player) return context->SetReturn(false);

        void* controller = player->GetController();
        if (!controller) return context->SetReturn(false);
        if (schema::GetProp<bool>(controller, "CBasePlayerController", "m_bIsHLTV")) return context->SetReturn(false);
        if (schema::GetProp<bool>(controller, "CBasePlayerController", "m_iConnected") != 0x0) return context->SetReturn(false);

        void* pawn = player->GetPawn();
        context->SetReturn(pawn != nullptr);
    });

})