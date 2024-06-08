#include "../../../core/scripting/generated/classes/GC_OP_VectorFieldSnapshot.h"
#include "../core.h"

void SetupLuaClassGC_OP_VectorFieldSnapshot(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_VectorFieldSnapshot>("C_OP_VectorFieldSnapshot")
        .addProperty("ControlPointNumber", &GC_OP_VectorFieldSnapshot::GetControlPointNumber, &GC_OP_VectorFieldSnapshot::SetControlPointNumber)
        .addProperty("AttributeToWrite", &GC_OP_VectorFieldSnapshot::GetAttributeToWrite, &GC_OP_VectorFieldSnapshot::SetAttributeToWrite)
        .addProperty("LocalSpaceCP", &GC_OP_VectorFieldSnapshot::GetLocalSpaceCP, &GC_OP_VectorFieldSnapshot::SetLocalSpaceCP)
        .addProperty("Interpolation", &GC_OP_VectorFieldSnapshot::GetInterpolation, &GC_OP_VectorFieldSnapshot::SetInterpolation)
        .addProperty("Scale", &GC_OP_VectorFieldSnapshot::GetScale, &GC_OP_VectorFieldSnapshot::SetScale)
        .addProperty("BoundaryDampening", &GC_OP_VectorFieldSnapshot::GetBoundaryDampening, &GC_OP_VectorFieldSnapshot::SetBoundaryDampening)
        .addProperty("SetVelocity", &GC_OP_VectorFieldSnapshot::GetSetVelocity, &GC_OP_VectorFieldSnapshot::SetSetVelocity)
        .addProperty("LockToSurface", &GC_OP_VectorFieldSnapshot::GetLockToSurface, &GC_OP_VectorFieldSnapshot::SetLockToSurface)
        .addProperty("GridSpacing", &GC_OP_VectorFieldSnapshot::GetGridSpacing, &GC_OP_VectorFieldSnapshot::SetGridSpacing)
        .endClass();
}