#include "../../../core/scripting/generated/classes/GCPhysicalButton.h"
#include "../core.h"

void SetupLuaClassGCPhysicalButton(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysicalButton>("CPhysicalButton")

        .endClass();
}