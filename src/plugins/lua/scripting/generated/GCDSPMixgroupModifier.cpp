#include "../../../core/scripting/generated/classes/GCDSPMixgroupModifier.h"
#include "../core.h"

void SetupLuaClassGCDSPMixgroupModifier(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDSPMixgroupModifier>("CDSPMixgroupModifier")
        .addProperty("Mixgroup", &GCDSPMixgroupModifier::GetMixgroup, &GCDSPMixgroupModifier::SetMixgroup)
        .addProperty("Modifier", &GCDSPMixgroupModifier::GetModifier, &GCDSPMixgroupModifier::SetModifier)
        .addProperty("ModifierMin", &GCDSPMixgroupModifier::GetModifierMin, &GCDSPMixgroupModifier::SetModifierMin)
        .addProperty("SourceModifier", &GCDSPMixgroupModifier::GetSourceModifier, &GCDSPMixgroupModifier::SetSourceModifier)
        .addProperty("SourceModifierMin", &GCDSPMixgroupModifier::GetSourceModifierMin, &GCDSPMixgroupModifier::SetSourceModifierMin)
        .addProperty("ListenerReverbModifierWhenSourceReverbIsActive", &GCDSPMixgroupModifier::GetListenerReverbModifierWhenSourceReverbIsActive, &GCDSPMixgroupModifier::SetListenerReverbModifierWhenSourceReverbIsActive)
        .endClass();
}