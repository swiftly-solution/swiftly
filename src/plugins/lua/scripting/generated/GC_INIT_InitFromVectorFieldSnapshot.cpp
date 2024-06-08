#include "../../../core/scripting/generated/classes/GC_INIT_InitFromVectorFieldSnapshot.h"
#include "../core.h"

void SetupLuaClassGC_INIT_InitFromVectorFieldSnapshot(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_InitFromVectorFieldSnapshot>("C_INIT_InitFromVectorFieldSnapshot")
        .addProperty("ControlPointNumber", &GC_INIT_InitFromVectorFieldSnapshot::GetControlPointNumber, &GC_INIT_InitFromVectorFieldSnapshot::SetControlPointNumber)
        .addProperty("LocalSpaceCP", &GC_INIT_InitFromVectorFieldSnapshot::GetLocalSpaceCP, &GC_INIT_InitFromVectorFieldSnapshot::SetLocalSpaceCP)
        .addProperty("WeightUpdateCP", &GC_INIT_InitFromVectorFieldSnapshot::GetWeightUpdateCP, &GC_INIT_InitFromVectorFieldSnapshot::SetWeightUpdateCP)
        .addProperty("UseVerticalVelocity", &GC_INIT_InitFromVectorFieldSnapshot::GetUseVerticalVelocity, &GC_INIT_InitFromVectorFieldSnapshot::SetUseVerticalVelocity)
        .addProperty("Scale", &GC_INIT_InitFromVectorFieldSnapshot::GetScale, &GC_INIT_InitFromVectorFieldSnapshot::SetScale)
        .endClass();
}