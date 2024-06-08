#include "../../../core/scripting/generated/classes/GCEnvWindShared__WindVariationEvent_t.h"
#include "../core.h"

void SetupLuaClassGCEnvWindShared__WindVariationEvent_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvWindShared__WindVariationEvent_t>("CEnvWindShared__WindVariationEvent_t")
        .addProperty("WindAngleVariation", &GCEnvWindShared__WindVariationEvent_t::GetWindAngleVariation, &GCEnvWindShared__WindVariationEvent_t::SetWindAngleVariation)
        .addProperty("WindSpeedVariation", &GCEnvWindShared__WindVariationEvent_t::GetWindSpeedVariation, &GCEnvWindShared__WindVariationEvent_t::SetWindSpeedVariation)
        .endClass();
}