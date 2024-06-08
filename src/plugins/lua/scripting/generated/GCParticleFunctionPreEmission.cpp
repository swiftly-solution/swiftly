#include "../../../core/scripting/generated/classes/GCParticleFunctionPreEmission.h"
#include "../core.h"

void SetupLuaClassGCParticleFunctionPreEmission(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleFunctionPreEmission>("CParticleFunctionPreEmission")
        .addProperty("RunOnce", &GCParticleFunctionPreEmission::GetRunOnce, &GCParticleFunctionPreEmission::SetRunOnce)
        .endClass();
}