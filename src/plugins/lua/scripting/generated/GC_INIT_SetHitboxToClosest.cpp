#include "../../../core/scripting/generated/classes/GC_INIT_SetHitboxToClosest.h"
#include "../core.h"

void SetupLuaClassGC_INIT_SetHitboxToClosest(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_SetHitboxToClosest>("C_INIT_SetHitboxToClosest")
        .addProperty("ControlPointNumber", &GC_INIT_SetHitboxToClosest::GetControlPointNumber, &GC_INIT_SetHitboxToClosest::SetControlPointNumber)
        .addProperty("DesiredHitbox", &GC_INIT_SetHitboxToClosest::GetDesiredHitbox, &GC_INIT_SetHitboxToClosest::SetDesiredHitbox)
        .addProperty("HitboxSetName", &GC_INIT_SetHitboxToClosest::GetHitboxSetName, &GC_INIT_SetHitboxToClosest::SetHitboxSetName)
        .addProperty("UseBones", &GC_INIT_SetHitboxToClosest::GetUseBones, &GC_INIT_SetHitboxToClosest::SetUseBones)
        .addProperty("UseClosestPointOnHitbox", &GC_INIT_SetHitboxToClosest::GetUseClosestPointOnHitbox, &GC_INIT_SetHitboxToClosest::SetUseClosestPointOnHitbox)
        .addProperty("TestType", &GC_INIT_SetHitboxToClosest::GetTestType, &GC_INIT_SetHitboxToClosest::SetTestType)
        .addProperty("HybridRatio", &GC_INIT_SetHitboxToClosest::GetHybridRatio, &GC_INIT_SetHitboxToClosest::SetHybridRatio)
        .addProperty("UpdatePosition", &GC_INIT_SetHitboxToClosest::GetUpdatePosition, &GC_INIT_SetHitboxToClosest::SetUpdatePosition)
        .endClass();
}