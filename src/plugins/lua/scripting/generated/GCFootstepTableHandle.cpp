#include "../../../core/scripting/generated/classes/GCFootstepTableHandle.h"
#include "../core.h"

void SetupLuaClassGCFootstepTableHandle(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootstepTableHandle>("CFootstepTableHandle")

        .endClass();
}