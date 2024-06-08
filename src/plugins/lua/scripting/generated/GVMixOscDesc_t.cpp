#include "../../../core/scripting/generated/classes/GVMixOscDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixOscDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixOscDesc_t>("VMixOscDesc_t")
        .addProperty("OscType", &GVMixOscDesc_t::GetOscType, &GVMixOscDesc_t::SetOscType)
        .addProperty("Freq", &GVMixOscDesc_t::GetFreq, &GVMixOscDesc_t::SetFreq)
        .addProperty("Phase", &GVMixOscDesc_t::GetPhase, &GVMixOscDesc_t::SetPhase)
        .endClass();
}