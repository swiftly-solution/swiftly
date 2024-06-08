#include "../../../core/scripting/generated/classes/GC_OP_ModelCull.h"
#include "../core.h"

void SetupLuaClassGC_OP_ModelCull(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ModelCull>("C_OP_ModelCull")
        .addProperty("ControlPointNumber", &GC_OP_ModelCull::GetControlPointNumber, &GC_OP_ModelCull::SetControlPointNumber)
        .addProperty("BoundBox", &GC_OP_ModelCull::GetBoundBox, &GC_OP_ModelCull::SetBoundBox)
        .addProperty("CullOutside", &GC_OP_ModelCull::GetCullOutside, &GC_OP_ModelCull::SetCullOutside)
        .addProperty("UseBones", &GC_OP_ModelCull::GetUseBones, &GC_OP_ModelCull::SetUseBones)
        .addProperty("HitboxSetName", &GC_OP_ModelCull::GetHitboxSetName, &GC_OP_ModelCull::SetHitboxSetName)
        .endClass();
}