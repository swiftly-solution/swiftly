#include "../../../core/scripting/generated/classes/GC_INIT_ModelCull.h"
#include "../core.h"

void SetupLuaClassGC_INIT_ModelCull(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_ModelCull>("C_INIT_ModelCull")
        .addProperty("ControlPointNumber", &GC_INIT_ModelCull::GetControlPointNumber, &GC_INIT_ModelCull::SetControlPointNumber)
        .addProperty("BoundBox", &GC_INIT_ModelCull::GetBoundBox, &GC_INIT_ModelCull::SetBoundBox)
        .addProperty("CullOutside", &GC_INIT_ModelCull::GetCullOutside, &GC_INIT_ModelCull::SetCullOutside)
        .addProperty("UseBones", &GC_INIT_ModelCull::GetUseBones, &GC_INIT_ModelCull::SetUseBones)
        .addProperty("HitboxSetName", &GC_INIT_ModelCull::GetHitboxSetName, &GC_INIT_ModelCull::SetHitboxSetName)
        .endClass();
}