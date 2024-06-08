#include "../../../core/scripting/generated/classes/GIClientAlphaProperty.h"
#include "../core.h"

void SetupLuaClassGIClientAlphaProperty(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIClientAlphaProperty>("IClientAlphaProperty")

        .endClass();
}