#include "../../../core/scripting/generated/classes/GC_INIT_RandomLifeTime.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomLifeTime(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomLifeTime>("C_INIT_RandomLifeTime")
        .addProperty("LifetimeMin", &GC_INIT_RandomLifeTime::GetLifetimeMin, &GC_INIT_RandomLifeTime::SetLifetimeMin)
        .addProperty("LifetimeMax", &GC_INIT_RandomLifeTime::GetLifetimeMax, &GC_INIT_RandomLifeTime::SetLifetimeMax)
        .addProperty("LifetimeRandExponent", &GC_INIT_RandomLifeTime::GetLifetimeRandExponent, &GC_INIT_RandomLifeTime::SetLifetimeRandExponent)
        .endClass();
}