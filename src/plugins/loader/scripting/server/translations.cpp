#include "../../core.h"

int FetchTranslationLua(lua_State* L)
{
    std::string res = scripting_FetchTranslation(EValue::fromLuaStack(GetContextByState(L), 1).cast<std::string>(), EValue::fromLuaStack(GetContextByState(L), 2).cast<std::optional<int>>().value_or(-1));
    EValue(GetContextByState(L), res).pushLua();
    return 1;
}

JSValue FetchTranslationJS(JSContext* ctx, JSValue this_obj, int argc, JSValue* argv)
{
    std::string res;
    if(argc == 1) {
        res = scripting_FetchTranslation(EValue::fromJSStack(GetContextByState(ctx), argv[0]).cast<std::string>(), -1);
    } else if(argc == 2) {
        res = scripting_FetchTranslation(EValue::fromJSStack(GetContextByState(ctx), argv[0]).cast<std::string>(), EValue::fromJSStack(GetContextByState(ctx), argv[1]).cast<int>());
    }
    return EValue(GetContextByState(ctx), res).pushJS();
}

LoadScriptingComponent(
    translation,
    [](Plugin* plugin, EContext* state)
    {
        GetGlobalNamespace(state)
            .addLuaFunction("FetchTranslation", FetchTranslationLua)
            .addJSFunction("FetchTranslation", FetchTranslationJS);
    }
)