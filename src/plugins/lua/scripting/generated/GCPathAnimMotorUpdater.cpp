#include "../../../core/scripting/generated/classes/GCPathAnimMotorUpdater.h"
#include "../core.h"

void SetupLuaClassGCPathAnimMotorUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathAnimMotorUpdater>("CPathAnimMotorUpdater")

        .endClass();
}