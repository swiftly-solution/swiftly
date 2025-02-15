#include "core.h"

#include "../../utils/utils.h"

std::string FetchPluginName(EContext* state);
std::map<std::string, EContext*> pluginNamesMap = {};
std::map<EContext*, std::string> pluginNamesMap2 = {};
std::vector<ClassLoader*> loaderClasses;

int customPrint(lua_State* state)
{
    std::string prefix = string_format("[Swiftly] %s[%s]\e[39m ", GetTerminalStringColor(FetchPluginName(GetContextByState(state))).c_str(), ("plugin:" + FetchPluginName(GetContextByState(state))).c_str());

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

        std::string final_string = string_format("%s%s\e[39m\e[49m\n", prefix.c_str(), str.c_str());
        META_CONPRINT(final_string.c_str());
    }

    return 0;
}

JSValue customConsoleLog(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
    std::string prefix = string_format("[Swiftly] %s[%s]\e[39m ", GetTerminalStringColor(FetchPluginName(GetContextByState(ctx))).c_str(), ("plugin:" + FetchPluginName(GetContextByState(ctx))).c_str());
    EContext* sctx = GetContextByState(ctx);

    std::vector<std::string> outputArr;

    for (int i = 0; i < argc; i++)
    {
        std::string str = EValue::fromJSStack(sctx, argv[i]).tostring();

        if (i > 1)
            outputArr.push_back("\t");

        outputArr.push_back(TerminalProcessColor(str));
    }

    std::vector<std::string> processingNewLines = explode(implode(outputArr, ""), "\n");
    for (const std::string str : processingNewLines)
    {
        if (str.size() == 0)
            continue;

        std::string final_string = string_format("%s%s\e[39m\e[49m\n", prefix.c_str(), str.c_str());
        META_CONPRINT(final_string.c_str());
    }

    return JS_UNDEFINED;
}

std::string FetchPluginName(EContext* state)
{
    return pluginNamesMap2[state];
}

void SetupScriptingEnvironment(Plugin* plugin, EContext* state)
{
    if (pluginNamesMap.find(plugin->GetName()) == pluginNamesMap.end()) {
        pluginNamesMap.insert({ plugin->GetName(), state });
        pluginNamesMap2.insert({ state, plugin->GetName() });
    }
    else {
        EContext* st = pluginNamesMap[plugin->GetName()];
        pluginNamesMap2.erase(st);

        pluginNamesMap2.insert({ state, plugin->GetName() });
        pluginNamesMap[plugin->GetName()] = state;
    }

    GetGlobalNamespace(state)
        .addLuaFunction("print", &customPrint)
        .beginNamespace("console")
            .addJSFunction("log", &customConsoleLog)
        .endNamespace()
        .addFunction("GetCurrentPluginName", FetchPluginName)
        .beginNamespace("msgpack")
            .addFunction("pack", encoders::msgpack::SerializeToString)
            .addFunction("unpack", encoders::msgpack::DeserializeFromString)
        .endNamespace();

    for(auto classLoader : loaderClasses)
        classLoader->ExecuteLoad(plugin, state);
}