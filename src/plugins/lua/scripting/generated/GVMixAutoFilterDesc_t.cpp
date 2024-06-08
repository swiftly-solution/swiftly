#include "../../../core/scripting/generated/classes/GVMixAutoFilterDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixAutoFilterDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixAutoFilterDesc_t>("VMixAutoFilterDesc_t")
        .addProperty("EnvelopeAmount", &GVMixAutoFilterDesc_t::GetEnvelopeAmount, &GVMixAutoFilterDesc_t::SetEnvelopeAmount)
        .addProperty("AttackTimeMS", &GVMixAutoFilterDesc_t::GetAttackTimeMS, &GVMixAutoFilterDesc_t::SetAttackTimeMS)
        .addProperty("ReleaseTimeMS", &GVMixAutoFilterDesc_t::GetReleaseTimeMS, &GVMixAutoFilterDesc_t::SetReleaseTimeMS)
        .addProperty("Filter", &GVMixAutoFilterDesc_t::GetFilter, &GVMixAutoFilterDesc_t::SetFilter)
        .addProperty("LFOAmount", &GVMixAutoFilterDesc_t::GetLFOAmount, &GVMixAutoFilterDesc_t::SetLFOAmount)
        .addProperty("LFORate", &GVMixAutoFilterDesc_t::GetLFORate, &GVMixAutoFilterDesc_t::SetLFORate)
        .addProperty("Phase", &GVMixAutoFilterDesc_t::GetPhase, &GVMixAutoFilterDesc_t::SetPhase)
        .addProperty("LFOShape", &GVMixAutoFilterDesc_t::GetLFOShape, &GVMixAutoFilterDesc_t::SetLFOShape)
        .endClass();
}