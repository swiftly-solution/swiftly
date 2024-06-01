#include "../scripting.h"
#include "../../PluginManager.h"

#include <vector>
#include <msgpack.hpp>

void OnClientKeyStateChange(int playerid, std::string key, bool pressed)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(playerid));
    eventData.push_back(msgpack::object(key.c_str()));
    eventData.push_back(msgpack::object(pressed));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", nullptr, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnClientKeyStateChange", ss.str(), event);
    delete event;
}

bool OnClientCommand(int playerid, std::string command)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(playerid));
    eventData.push_back(msgpack::object(command.c_str()));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", nullptr, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnClientCommand", ss.str(), event);

    bool response = true;
    try
    {
        response = std::any_cast<bool>(event->GetReturnValue());
    }
    catch (std::bad_any_cast &e)
    {
        response = true;
    }

    delete event;
    return response;
}

bool OnClientChat(int playerid, std::string text, bool teamonly)
{
    std::stringstream ss;
    std::vector<msgpack::object> eventData;

    eventData.push_back(msgpack::object(playerid));
    eventData.push_back(msgpack::object(text.c_str()));
    eventData.push_back(msgpack::object(teamonly));

    msgpack::pack(ss, eventData);

    PluginEvent *event = new PluginEvent("core", nullptr, nullptr);
    g_pluginManager->ExecuteEvent("core", "OnClientChat", ss.str(), event);

    bool response = true;
    try
    {
        response = std::any_cast<bool>(event->GetReturnValue());
    }
    catch (std::bad_any_cast &e)
    {
        response = true;
    }

    delete event;
    return response;
}