#include "../../../core/scripting/generated/classes/GCFuncTrackAuto.h"
#include "../core.h"

void SetupLuaClassGCFuncTrackAuto(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncTrackAuto>("CFuncTrackAuto")

        .endClass();
}