#include "../../../core/scripting/generated/classes/GC_OP_ControlPointToRadialScreenSpace.h"
#include "../core.h"

void SetupLuaClassGC_OP_ControlPointToRadialScreenSpace(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ControlPointToRadialScreenSpace>("C_OP_ControlPointToRadialScreenSpace")
        .addProperty("CPIn", &GC_OP_ControlPointToRadialScreenSpace::GetCPIn, &GC_OP_ControlPointToRadialScreenSpace::SetCPIn)
        .addProperty("CP1Pos", &GC_OP_ControlPointToRadialScreenSpace::GetCP1Pos, &GC_OP_ControlPointToRadialScreenSpace::SetCP1Pos)
        .addProperty("CPOut", &GC_OP_ControlPointToRadialScreenSpace::GetCPOut, &GC_OP_ControlPointToRadialScreenSpace::SetCPOut)
        .addProperty("CPOutField", &GC_OP_ControlPointToRadialScreenSpace::GetCPOutField, &GC_OP_ControlPointToRadialScreenSpace::SetCPOutField)
        .addProperty("CPSSPosOut", &GC_OP_ControlPointToRadialScreenSpace::GetCPSSPosOut, &GC_OP_ControlPointToRadialScreenSpace::SetCPSSPosOut)
        .endClass();
}