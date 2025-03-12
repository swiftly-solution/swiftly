#include "../../core.h"
#include "../../../../sdk/access/sdkaccess.h"

bool IsTypeClass(std::string key) {
    auto types = g_sdk->GetSDKTypes();
    return (types.find(key) != types.end());
}

SDKBaseType GenerateTypeFactory(std::string className) {
    return SDKBaseType(className);
}

JSValue GetType(JSContext* ctx, JSValue this_arg, int argc, JSValue* argv)
{
    EContext* ct = GetContextByState(ctx);
    std::string key = EValue::fromJSStack(ct, argv[1]).cast<std::string>();
    SDKBaseType* type = EValue::fromJSStack(ct, argv[2]).cast<SDKBaseType*>();

    return EValue(ct, type->GetTypeValue(key)).pushJS();
}

JSValue SetType(JSContext* ctx, JSValue this_arg, int argc, JSValue* argv)
{
    return JS_ThrowSyntaxError(ctx, "You cannot set values to types.");
}

int Lua_GetType(lua_State* state)
{
    EContext* ctx = GetContextByState(state);
    SDKBaseType *th = EValue::fromLuaStack(ctx, 1).cast<SDKBaseType*>();
    std::string field_name = EValue::fromLuaStack(ctx, 2).cast<std::string>();

    EValue(ctx, th->GetTypeValue(field_name)).pushLua();
    return 1;
}

int Lua_SetType(lua_State* state)
{
    return 0;
}

std::map<std::string, SDKBaseType*> jsBaseTypes;

LoadScriptingComponent(
    types,
    [](Plugin* plugin, EContext* state)
    {
        auto gns = GetGlobalNamespace(state);

        gns
            .addFunction("IsTypeClass", IsTypeClass)
            .addFunction("GenerateTypeFactory", GenerateTypeFactory);

        BeginClass<SDKBaseType>("SDKBaseType", state)
            .addJSCustomIndex(GetType, SetType)
            .addLuaCustomIndex(Lua_GetType, Lua_SetType)
        .endClass();
    }
)