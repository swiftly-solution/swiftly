#include "../../../core/scripting/generated/classes/GC_OP_SetSingleControlPointPosition.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetSingleControlPointPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetSingleControlPointPosition>("C_OP_SetSingleControlPointPosition")
        .addProperty("SetOnce", &GC_OP_SetSingleControlPointPosition::GetSetOnce, &GC_OP_SetSingleControlPointPosition::SetSetOnce)
        .addProperty("CP1", &GC_OP_SetSingleControlPointPosition::GetCP1, &GC_OP_SetSingleControlPointPosition::SetCP1)
        .addProperty("TransformInput", &GC_OP_SetSingleControlPointPosition::GetTransformInput, &GC_OP_SetSingleControlPointPosition::SetTransformInput)
        .endClass();
}