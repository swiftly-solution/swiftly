#include "../../../core/scripting/generated/classes/GCBtNodeDecorator.h"
#include "../core.h"

void SetupLuaClassGCBtNodeDecorator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBtNodeDecorator>("CBtNodeDecorator")

        .endClass();
}