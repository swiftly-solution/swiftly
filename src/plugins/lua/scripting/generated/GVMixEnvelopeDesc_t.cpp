#include "../../../core/scripting/generated/classes/GVMixEnvelopeDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixEnvelopeDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixEnvelopeDesc_t>("VMixEnvelopeDesc_t")
        .addProperty("AttackTimeMS", &GVMixEnvelopeDesc_t::GetAttackTimeMS, &GVMixEnvelopeDesc_t::SetAttackTimeMS)
        .addProperty("HoldTimeMS", &GVMixEnvelopeDesc_t::GetHoldTimeMS, &GVMixEnvelopeDesc_t::SetHoldTimeMS)
        .addProperty("ReleaseTimeMS", &GVMixEnvelopeDesc_t::GetReleaseTimeMS, &GVMixEnvelopeDesc_t::SetReleaseTimeMS)
        .endClass();
}