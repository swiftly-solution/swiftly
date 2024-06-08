#include "../../../core/scripting/generated/classes/GCFuncPlat.h"
#include "../core.h"

void SetupLuaClassGCFuncPlat(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncPlat>("CFuncPlat")
        .addProperty("Noise", &GCFuncPlat::GetNoise, &GCFuncPlat::SetNoise)
        .endClass();
}