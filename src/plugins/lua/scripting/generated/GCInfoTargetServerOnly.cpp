#include "../../../core/scripting/generated/classes/GCInfoTargetServerOnly.h"
#include "../core.h"

void SetupLuaClassGCInfoTargetServerOnly(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoTargetServerOnly>("CInfoTargetServerOnly")

        .endClass();
}