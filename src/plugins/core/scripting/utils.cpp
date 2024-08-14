#include "../scripting.h"
#include "../../../sdk/entity/CGameRules.h"
#include "../../../hooks/FuncHook.h"
#include "../../PluginManager.h"
#include "../../../usermessages/usermessages.h"

void Hook_CGameRules_Constructor(CGameRules* pThis);
CCSGameRules* gameRules = nullptr;

FuncHook<decltype(Hook_CGameRules_Constructor)> CGameRules_ConstructorT(Hook_CGameRules_Constructor, "CGameRules_Constructor");

void Hook_CGameRules_Constructor(CGameRules* pThis)
{
    gameRules = (CCSGameRules*)pThis;
    CGameRules_ConstructorT(pThis);
}

bool scripting_IsWindows()
{
    return WIN_LINUX(true, false);
}

bool scripting_IsLinux()
{
    return WIN_LINUX(false, true);
}

std::string scripting_GetOS()
{
    return WIN_LINUX("Windows", "Linux");
}

GCCSGameRules scripting_GetCCSGameRules()
{
    GCCSGameRules val(gameRules);
    return val;
}

std::string scripting_GetPluginPath(std::string plugin_name)
{
    Plugin* plugin = g_pluginManager->FetchPlugin(plugin_name);
    if (!plugin) return "";

    return string_format("addons/swiftly/plugins/%s", plugin->GetName().c_str());
}

PluginUserMessage scripting_GetUserMessage(std::string uuid)
{
    if (scriptingUserMessages.find(uuid) == scriptingUserMessages.end()) {
        PluginUserMessage val(nullptr, nullptr, nullptr);
        return val;
    }

    return scriptingUserMessages.at(uuid);
}