#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointToHand.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointToHand(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointToHand>("C_OP_SetControlPointToHand")
        .addProperty("CP1", &GC_OP_SetControlPointToHand::GetCP1, &GC_OP_SetControlPointToHand::SetCP1)
        .addProperty("Hand", &GC_OP_SetControlPointToHand::GetHand, &GC_OP_SetControlPointToHand::SetHand)
        .addProperty("CP1Pos", &GC_OP_SetControlPointToHand::GetCP1Pos, &GC_OP_SetControlPointToHand::SetCP1Pos)
        .addProperty("OrientToHand", &GC_OP_SetControlPointToHand::GetOrientToHand, &GC_OP_SetControlPointToHand::SetOrientToHand)
        .endClass();
}