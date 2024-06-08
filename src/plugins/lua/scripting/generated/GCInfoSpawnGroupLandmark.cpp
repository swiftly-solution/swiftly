#include "../../../core/scripting/generated/classes/GCInfoSpawnGroupLandmark.h"
#include "../core.h"

void SetupLuaClassGCInfoSpawnGroupLandmark(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoSpawnGroupLandmark>("CInfoSpawnGroupLandmark")

        .endClass();
}