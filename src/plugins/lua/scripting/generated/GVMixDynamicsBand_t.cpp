#include "../../../core/scripting/generated/classes/GVMixDynamicsBand_t.h"
#include "../core.h"

void SetupLuaClassGVMixDynamicsBand_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixDynamicsBand_t>("VMixDynamicsBand_t")
        .addProperty("FldbGainInput", &GVMixDynamicsBand_t::GetFldbGainInput, &GVMixDynamicsBand_t::SetFldbGainInput)
        .addProperty("FldbGainOutput", &GVMixDynamicsBand_t::GetFldbGainOutput, &GVMixDynamicsBand_t::SetFldbGainOutput)
        .addProperty("FldbThresholdBelow", &GVMixDynamicsBand_t::GetFldbThresholdBelow, &GVMixDynamicsBand_t::SetFldbThresholdBelow)
        .addProperty("FldbThresholdAbove", &GVMixDynamicsBand_t::GetFldbThresholdAbove, &GVMixDynamicsBand_t::SetFldbThresholdAbove)
        .addProperty("RatioBelow", &GVMixDynamicsBand_t::GetRatioBelow, &GVMixDynamicsBand_t::SetRatioBelow)
        .addProperty("RatioAbove", &GVMixDynamicsBand_t::GetRatioAbove, &GVMixDynamicsBand_t::SetRatioAbove)
        .addProperty("AttackTimeMS", &GVMixDynamicsBand_t::GetAttackTimeMS, &GVMixDynamicsBand_t::SetAttackTimeMS)
        .addProperty("ReleaseTimeMS", &GVMixDynamicsBand_t::GetReleaseTimeMS, &GVMixDynamicsBand_t::SetReleaseTimeMS)
        .addProperty("Enable", &GVMixDynamicsBand_t::GetEnable, &GVMixDynamicsBand_t::SetEnable)
        .addProperty("Solo", &GVMixDynamicsBand_t::GetSolo, &GVMixDynamicsBand_t::SetSolo)
        .endClass();
}