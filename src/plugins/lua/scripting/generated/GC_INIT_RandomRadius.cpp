#include "../../../core/scripting/generated/classes/GC_INIT_RandomRadius.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomRadius(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomRadius>("C_INIT_RandomRadius")
        .addProperty("RadiusMin", &GC_INIT_RandomRadius::GetRadiusMin, &GC_INIT_RandomRadius::SetRadiusMin)
        .addProperty("RadiusMax", &GC_INIT_RandomRadius::GetRadiusMax, &GC_INIT_RandomRadius::SetRadiusMax)
        .addProperty("RadiusRandExponent", &GC_INIT_RandomRadius::GetRadiusRandExponent, &GC_INIT_RandomRadius::SetRadiusRandExponent)
        .endClass();
}