#include "../../../core/scripting/generated/classes/GCInfoPlayerCounterterrorist.h"
#include "../core.h"

void SetupLuaClassGCInfoPlayerCounterterrorist(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoPlayerCounterterrorist>("CInfoPlayerCounterterrorist")

        .endClass();
}