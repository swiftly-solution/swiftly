#include "../../../core/scripting/generated/classes/GFuseVariableIndex_t.h"
#include "../core.h"

void SetupLuaClassGFuseVariableIndex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFuseVariableIndex_t>("FuseVariableIndex_t")
        .addProperty("Value", &GFuseVariableIndex_t::GetValue, &GFuseVariableIndex_t::SetValue)
        .endClass();
}