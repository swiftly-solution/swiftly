#include "../../../core/scripting/generated/classes/GChangeAccessorFieldPathIndex_t.h"
#include "../core.h"

void SetupLuaClassGChangeAccessorFieldPathIndex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GChangeAccessorFieldPathIndex_t>("ChangeAccessorFieldPathIndex_t")
        .addProperty("Value", &GChangeAccessorFieldPathIndex_t::GetValue, &GChangeAccessorFieldPathIndex_t::SetValue)
        .endClass();
}