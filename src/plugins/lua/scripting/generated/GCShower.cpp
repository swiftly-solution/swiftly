#include "../../../core/scripting/generated/classes/GCShower.h"
#include "../core.h"

void SetupLuaClassGCShower(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCShower>("CShower")

        .endClass();
}