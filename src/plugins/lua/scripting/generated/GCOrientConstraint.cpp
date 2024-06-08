#include "../../../core/scripting/generated/classes/GCOrientConstraint.h"
#include "../core.h"

void SetupLuaClassGCOrientConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCOrientConstraint>("COrientConstraint")

        .endClass();
}