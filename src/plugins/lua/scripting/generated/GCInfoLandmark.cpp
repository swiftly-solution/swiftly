#include "../../../core/scripting/generated/classes/GCInfoLandmark.h"
#include "../core.h"

void SetupLuaClassGCInfoLandmark(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoLandmark>("CInfoLandmark")

        .endClass();
}