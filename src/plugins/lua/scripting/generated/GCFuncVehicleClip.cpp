#include "../../../core/scripting/generated/classes/GCFuncVehicleClip.h"
#include "../core.h"

void SetupLuaClassGCFuncVehicleClip(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncVehicleClip>("CFuncVehicleClip")

        .endClass();
}