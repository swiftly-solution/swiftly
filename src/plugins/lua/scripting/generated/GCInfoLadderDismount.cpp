#include "../../../core/scripting/generated/classes/GCInfoLadderDismount.h"
#include "../core.h"

void SetupLuaClassGCInfoLadderDismount(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoLadderDismount>("CInfoLadderDismount")

        .endClass();
}