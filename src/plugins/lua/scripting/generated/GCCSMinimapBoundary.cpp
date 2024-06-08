#include "../../../core/scripting/generated/classes/GCCSMinimapBoundary.h"
#include "../core.h"

void SetupLuaClassGCCSMinimapBoundary(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSMinimapBoundary>("CCSMinimapBoundary")

        .endClass();
}