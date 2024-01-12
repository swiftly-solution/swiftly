#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

class LuaConvarsClass
{
public:
    LuaConvarsClass() {}
};

void SetupLuaConvars(luacpp::LuaState *state, Plugin *plugin)
{

    auto convarsClass = state->CreateClass<LuaConvarsClass>("Convars").DefConstructor();

    convarsClass.DefMember("Get", [state](LuaConvarsClass *base, const char *key) -> luacpp::LuaObject
                           {
                            if(key == nullptr) return state->CreateNil();

                            EConVarType cvType = scripting_Server_GetConvarType(key);
                            if(cvType == EConVarType_Invalid) return state->CreateNil();

                            if(cvType == EConVarType_Bool) return state->CreateInteger(scripting_Server_GetConvarBool(key) == true ? 1 : 0);
                            else if(cvType == EConVarType_Float32) return state->CreateNumber(scripting_Server_GetConvarFloat(key));
                            else if(cvType == EConVarType_Int32) return state->CreateInteger(scripting_Server_GetConvarInt(key));
                            else if(cvType == EConVarType_UInt32) return state->CreateInteger(scripting_Server_GetConvarUint(key));
                            else if(cvType == EConVarType_String) return state->CreateString(scripting_Server_GetConvarString(key));
                            else return state->CreateNil(); })
        .DefMember("GetType", [state](LuaConvarsClass *base, const char *key) -> int
                   { return scripting_Server_GetConvarType(key); })
        .DefMember("Set", [state, plugin](LuaConvarsClass *base, const char *key, luacpp::LuaObject value) -> void
                   {
                    EConVarType cvType = scripting_Server_GetConvarType(key);
                    if(cvType == EConVarType_Invalid) return;
                    if(value.GetType() == LUA_TNIL) return;

                    if(value.GetType() == LUA_TSTRING) scripting_Server_SetConvar(key, value.ToString());
                    else if(value.GetType() == LUA_TBOOLEAN) scripting_Server_SetConvar(key, value.ToBool());
                    else if(value.GetType() == LUA_TNUMBER) {
                        lua_rawgeti(plugin->GetLuaRawState(), LUA_REGISTRYINDEX, value.GetRefIndex());
                        if(lua_isinteger(plugin->GetLuaRawState(), -1) == 1) scripting_Server_SetConvar(key, value.ToInteger());
                        else scripting_Server_SetConvar(key, value.ToNumber());
                        lua_pop(plugin->GetLuaRawState(), 1);
                    } });

    state->DoString("convar = Convars()");

    PRINT("Scripting - Lua", "Convars loaded.\n");
}