#include "../scripting.h"
#include "../../PluginManager.h"
#include "../../../player/PlayerManager.h"

void OnClientKeyStateChange(int playerid, std::string key, bool pressed)
{
    if (pressed)
    {
        Player* player = g_playerManager->GetPlayer(playerid);
        if (!player)
            return;

        player->PerformMenuAction(key);
    }

    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnClientKeyStateChange", encoders::msgpack::SerializeToString({ playerid, key, pressed }), event);
    delete event;
}

bool OnClientCommand(int playerid, std::string command)
{
    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnClientCommand", encoders::msgpack::SerializeToString({ playerid, command }), event);

    bool response = true;
    try
    {
        response = std::any_cast<bool>(event->GetReturnValue());
    }
    catch (std::bad_any_cast& e)
    {
        response = true;
    }

    delete event;
    return response;
}

bool OnClientChat(int playerid, std::string text, bool teamonly)
{
    PluginEvent* event = new PluginEvent("core", nullptr, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnClientChat", encoders::msgpack::SerializeToString({ playerid, text, teamonly }), event);

    bool response = true;
    try
    {
        response = std::any_cast<bool>(event->GetReturnValue());
    }
    catch (std::bad_any_cast& e)
    {
        response = true;
    }

    delete event;
    return response;
}