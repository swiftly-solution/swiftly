#include "../../../core/scripting/generated/classes/GVMixEffectChainDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixEffectChainDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixEffectChainDesc_t>("VMixEffectChainDesc_t")
        .addProperty("CrossfadeTime", &GVMixEffectChainDesc_t::GetCrossfadeTime, &GVMixEffectChainDesc_t::SetCrossfadeTime)
        .endClass();
}