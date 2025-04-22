#include <scripting/core.h>

#include <server/player/manager.h>

LoadScriptingComponent(playermanager, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("PlayerManager");

    ADD_CLASS_FUNCTION("PlayerManager", "PlayerManager", [](FunctionContext* context, ClassData* data) -> void {});

    ADD_CLASS_FUNCTION("PlayerManager", "GetPlayerCount", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(g_playerManager.GetPlayers());
    });

    ADD_CLASS_FUNCTION("PlayerManager", "GetPlayerCap", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(g_playerManager.GetPlayerCap());
    });

    ADD_CLASS_FUNCTION("PlayerManager", "SendMsg", [](FunctionContext* context, ClassData* data) -> void {
        int destination = context->GetArgumentOr<int>(0, -1);
        if(destination == -1) return;

        std::string text = context->GetArgumentOr<std::string>(1, "");

        for (int i = 0; i < g_playerManager.GetPlayerCap(); i++)
        {
            Player* player = g_playerManager.GetPlayer(i);
            if (!player) continue;
            if (player->IsFakeClient()) continue;
            if (!player->GetController()) continue;

            player->SendMsg(destination, text.c_str());
        }
    });
})