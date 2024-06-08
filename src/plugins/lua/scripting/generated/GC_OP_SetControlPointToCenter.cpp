#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointToCenter.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointToCenter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointToCenter>("C_OP_SetControlPointToCenter")
        .addProperty("CP1", &GC_OP_SetControlPointToCenter::GetCP1, &GC_OP_SetControlPointToCenter::SetCP1)
        .addProperty("CP1Pos", &GC_OP_SetControlPointToCenter::GetCP1Pos, &GC_OP_SetControlPointToCenter::SetCP1Pos)
        .addProperty("SetParent", &GC_OP_SetControlPointToCenter::GetSetParent, &GC_OP_SetControlPointToCenter::SetSetParent)
        .endClass();
}