#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointToHMD.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointToHMD(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointToHMD>("C_OP_SetControlPointToHMD")
        .addProperty("CP1", &GC_OP_SetControlPointToHMD::GetCP1, &GC_OP_SetControlPointToHMD::SetCP1)
        .addProperty("CP1Pos", &GC_OP_SetControlPointToHMD::GetCP1Pos, &GC_OP_SetControlPointToHMD::SetCP1Pos)
        .addProperty("OrientToHMD", &GC_OP_SetControlPointToHMD::GetOrientToHMD, &GC_OP_SetControlPointToHMD::SetOrientToHMD)
        .endClass();
}