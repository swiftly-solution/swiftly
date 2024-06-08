#include "../../../core/scripting/generated/classes/GVMixPannerDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixPannerDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixPannerDesc_t>("VMixPannerDesc_t")
        .addProperty("Type", &GVMixPannerDesc_t::GetType, &GVMixPannerDesc_t::SetType)
        .addProperty("Strength", &GVMixPannerDesc_t::GetStrength, &GVMixPannerDesc_t::SetStrength)
        .endClass();
}