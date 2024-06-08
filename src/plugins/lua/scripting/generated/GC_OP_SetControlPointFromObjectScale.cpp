#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointFromObjectScale.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointFromObjectScale(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointFromObjectScale>("C_OP_SetControlPointFromObjectScale")
        .addProperty("CPInput", &GC_OP_SetControlPointFromObjectScale::GetCPInput, &GC_OP_SetControlPointFromObjectScale::SetCPInput)
        .addProperty("CPOutput", &GC_OP_SetControlPointFromObjectScale::GetCPOutput, &GC_OP_SetControlPointFromObjectScale::SetCPOutput)
        .endClass();
}