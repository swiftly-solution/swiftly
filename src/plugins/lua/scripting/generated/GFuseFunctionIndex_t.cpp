#include "../../../core/scripting/generated/classes/GFuseFunctionIndex_t.h"
#include "../core.h"

void SetupLuaClassGFuseFunctionIndex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFuseFunctionIndex_t>("FuseFunctionIndex_t")
        .addProperty("Value", &GFuseFunctionIndex_t::GetValue, &GFuseFunctionIndex_t::SetValue)
        .endClass();
}