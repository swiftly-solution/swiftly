#include "../../../core/scripting/generated/classes/GCEntityComponent.h"
#include "../core.h"

void SetupLuaClassGCEntityComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntityComponent>("CEntityComponent")

        .endClass();
}