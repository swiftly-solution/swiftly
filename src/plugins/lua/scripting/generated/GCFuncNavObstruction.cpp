#include "../../../core/scripting/generated/classes/GCFuncNavObstruction.h"
#include "../core.h"

void SetupLuaClassGCFuncNavObstruction(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncNavObstruction>("CFuncNavObstruction")
        .addProperty("Disabled", &GCFuncNavObstruction::GetDisabled, &GCFuncNavObstruction::SetDisabled)
        .endClass();
}