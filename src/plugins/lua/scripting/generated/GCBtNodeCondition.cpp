#include "../../../core/scripting/generated/classes/GCBtNodeCondition.h"
#include "../core.h"

void SetupLuaClassGCBtNodeCondition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtNodeCondition>("CBtNodeCondition")
        .addProperty("Negated", &GCBtNodeCondition::GetNegated, &GCBtNodeCondition::SetNegated)
        .endClass();
}