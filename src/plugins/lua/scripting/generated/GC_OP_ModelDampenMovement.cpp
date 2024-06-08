#include "../../../core/scripting/generated/classes/GC_OP_ModelDampenMovement.h"
#include "../core.h"

void SetupLuaClassGC_OP_ModelDampenMovement(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ModelDampenMovement>("C_OP_ModelDampenMovement")
        .addProperty("ControlPointNumber", &GC_OP_ModelDampenMovement::GetControlPointNumber, &GC_OP_ModelDampenMovement::SetControlPointNumber)
        .addProperty("BoundBox", &GC_OP_ModelDampenMovement::GetBoundBox, &GC_OP_ModelDampenMovement::SetBoundBox)
        .addProperty("Outside", &GC_OP_ModelDampenMovement::GetOutside, &GC_OP_ModelDampenMovement::SetOutside)
        .addProperty("UseBones", &GC_OP_ModelDampenMovement::GetUseBones, &GC_OP_ModelDampenMovement::SetUseBones)
        .addProperty("HitboxSetName", &GC_OP_ModelDampenMovement::GetHitboxSetName, &GC_OP_ModelDampenMovement::SetHitboxSetName)
        .addProperty("PosOffset", &GC_OP_ModelDampenMovement::GetPosOffset, &GC_OP_ModelDampenMovement::SetPosOffset)
        .addProperty("Drag", &GC_OP_ModelDampenMovement::GetDrag, &GC_OP_ModelDampenMovement::SetDrag)
        .endClass();
}