#include "../../../core/scripting/generated/classes/GC_INIT_SetHitboxToModel.h"
#include "../core.h"

void SetupLuaClassGC_INIT_SetHitboxToModel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_SetHitboxToModel>("C_INIT_SetHitboxToModel")
        .addProperty("ControlPointNumber", &GC_INIT_SetHitboxToModel::GetControlPointNumber, &GC_INIT_SetHitboxToModel::SetControlPointNumber)
        .addProperty("ForceInModel", &GC_INIT_SetHitboxToModel::GetForceInModel, &GC_INIT_SetHitboxToModel::SetForceInModel)
        .addProperty("EvenDistribution", &GC_INIT_SetHitboxToModel::GetEvenDistribution, &GC_INIT_SetHitboxToModel::SetEvenDistribution)
        .addProperty("DesiredHitbox", &GC_INIT_SetHitboxToModel::GetDesiredHitbox, &GC_INIT_SetHitboxToModel::SetDesiredHitbox)
        .addProperty("DirectionBias", &GC_INIT_SetHitboxToModel::GetDirectionBias, &GC_INIT_SetHitboxToModel::SetDirectionBias)
        .addProperty("MaintainHitbox", &GC_INIT_SetHitboxToModel::GetMaintainHitbox, &GC_INIT_SetHitboxToModel::SetMaintainHitbox)
        .addProperty("UseBones", &GC_INIT_SetHitboxToModel::GetUseBones, &GC_INIT_SetHitboxToModel::SetUseBones)
        .addProperty("HitboxSetName", &GC_INIT_SetHitboxToModel::GetHitboxSetName, &GC_INIT_SetHitboxToModel::SetHitboxSetName)
        .addProperty("ShellSize", &GC_INIT_SetHitboxToModel::GetShellSize, &GC_INIT_SetHitboxToModel::SetShellSize)
        .endClass();
}