#include "../../../core/scripting/generated/classes/GCTouchExpansionComponent.h"
#include "../core.h"

void SetupLuaClassGCTouchExpansionComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTouchExpansionComponent>("CTouchExpansionComponent")

        .endClass();
}