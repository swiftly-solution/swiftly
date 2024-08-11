#include "core.h"

#include "../../../utils/utils.h"

int customPrint(lua_State* state)
{
    std::string prefix = string_format("[Swiftly] %s[%16s]\e[39m ", GetTerminalStringColor(luabridge::getGlobal(state, "plugin_name").tostring()).c_str(), ("plugin:" + luabridge::getGlobal(state, "plugin_name").tostring()).c_str());

    int n = lua_gettop(state);

    lua_getglobal(state, "tostring");

    std::vector<std::string> outputArr;

    for (int i = 1; i <= n; i++)
    {
        lua_pushvalue(state, -1);
        lua_pushvalue(state, i);
        lua_call(state, 1, 1);

        size_t l = 0;
        const char* s = lua_tolstring(state, -1, &l);
        if (s == nullptr)
        {
            outputArr.push_back("An error has occured while trying to call 'print'.\nError: 'tostring' must return a string to 'print'\n");
            break;
        }

        if (i > 1)
            outputArr.push_back("\t");

        outputArr.push_back(TerminalProcessColor(s));
        lua_pop(state, 1);
    }
    std::vector<std::string> processingNewLines = explode(implode(outputArr, ""), "\n");
    for (const std::string str : processingNewLines)
    {
        if (str.size() == 0)
            continue;
        g_SMAPI->ConPrintf("%s%s\e[39m\e[49m\n", prefix.c_str(), str.c_str());
    }

    return 0;
}

std::map<std::string, lua_State*> pluginNamesMap = {};
std::map<lua_State*, std::string> pluginNamesMap2 = {};

std::string FetchPluginName(lua_State* state)
{
    return pluginNamesMap2.at(state);
}

void SetupLuaEnvironment(LuaPlugin* plugin, lua_State* state)
{
    if (pluginNamesMap.find(plugin->GetName()) == pluginNamesMap.end()) {
        pluginNamesMap.insert({ plugin->GetName(), state });
        pluginNamesMap2.insert({ state, plugin->GetName() });
    }
    else {
        lua_State* st = pluginNamesMap[plugin->GetName()];
        pluginNamesMap2.erase(st);

        pluginNamesMap2.insert({ state, plugin->GetName() });
        pluginNamesMap[plugin->GetName()] = state;
    }

    luabridge::getGlobalNamespace(state)
        .addCFunction("print", &customPrint)
        .addFunction("GetCurrentPluginName", +[](lua_State* L) -> std::string
            { return FetchPluginName(L); })
        .addFunction("CreateTextTable", +[](std::vector<std::vector<std::string>> data)
            {
                TextTable tbl('-', '|', '+');

                for (auto vec : data) {
                    for (std::string str : vec)
                        tbl.add(" " + str + " ");

                    tbl.endOfRow();
                }

                std::stringstream outputTable;
                outputTable << tbl;
                return outputTable.str();
            });

    luabridge::setGlobal(state, plugin->GetName(), "plugin_name");

    SetupLuaLogs(plugin, state);
    SetupLuaTypes(plugin, state);
    SetupLuaGeneratedTypes(plugin, state);
    SetupLuaTranslations(plugin, state);
    SetupLuaConfiguration(plugin, state);
    SetupLuaFiles(plugin, state);
    SetupLuaPrecacher(plugin, state);
    SetupLuaCommands(plugin, state);
    SetupLuaPlayerManager(plugin, state);
    SetupLuaEvents(plugin, state);
    SetupLuaHTTP(plugin, state);
    SetupLuaDatabase(plugin, state);
    SetupLuaMenus(plugin, state);
    SetupLuaConvars(plugin, state);
    SetupLuaUtils(plugin, state);
    SetupLuaCoreClasses(plugin, state);
    SetupLuaClasses(plugin, state);
    SetupLuaServer(plugin, state);
    SetupLuaPlayer(plugin, state);
    SetupLuaEntities(plugin, state);
    SetupLuaMemory(plugin, state);
    SetupLuaHooks(plugin, state);
    SetupLuaUserMessages(plugin, state);
    SetupLuaWeapons(plugin, state);
    SetupLuaCHandle(plugin, state);
}