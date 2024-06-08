#include "../../../core/scripting/generated/classes/GC_OP_SetCPOrientationToDirection.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetCPOrientationToDirection(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetCPOrientationToDirection>("C_OP_SetCPOrientationToDirection")
        .addProperty("InputControlPoint", &GC_OP_SetCPOrientationToDirection::GetInputControlPoint, &GC_OP_SetCPOrientationToDirection::SetInputControlPoint)
        .addProperty("OutputControlPoint", &GC_OP_SetCPOrientationToDirection::GetOutputControlPoint, &GC_OP_SetCPOrientationToDirection::SetOutputControlPoint)
        .endClass();
}