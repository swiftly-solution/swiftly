#include "../../../core/scripting/generated/classes/GCNavWalkable.h"
#include "../core.h"

void SetupLuaClassGCNavWalkable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavWalkable>("CNavWalkable")

        .endClass();
}