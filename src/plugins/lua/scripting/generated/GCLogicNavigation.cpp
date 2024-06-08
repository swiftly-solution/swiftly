#include "../../../core/scripting/generated/classes/GCLogicNavigation.h"
#include "../core.h"

void SetupLuaClassGCLogicNavigation(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicNavigation>("CLogicNavigation")
        .addProperty("IsOn", &GCLogicNavigation::GetIsOn, &GCLogicNavigation::SetIsOn)
        .addProperty("NavProperty", &GCLogicNavigation::GetNavProperty, &GCLogicNavigation::SetNavProperty)
        .endClass();
}