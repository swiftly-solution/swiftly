#include "../../../core/scripting/generated/classes/GIHasAttributes.h"
#include "../core.h"

void SetupLuaClassGIHasAttributes(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIHasAttributes>("IHasAttributes")

        .endClass();
}