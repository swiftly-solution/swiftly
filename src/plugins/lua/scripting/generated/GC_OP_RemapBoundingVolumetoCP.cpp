#include "../../../core/scripting/generated/classes/GC_OP_RemapBoundingVolumetoCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapBoundingVolumetoCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapBoundingVolumetoCP>("C_OP_RemapBoundingVolumetoCP")
        .addProperty("OutControlPointNumber", &GC_OP_RemapBoundingVolumetoCP::GetOutControlPointNumber, &GC_OP_RemapBoundingVolumetoCP::SetOutControlPointNumber)
        .addProperty("InputMin", &GC_OP_RemapBoundingVolumetoCP::GetInputMin, &GC_OP_RemapBoundingVolumetoCP::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapBoundingVolumetoCP::GetInputMax, &GC_OP_RemapBoundingVolumetoCP::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapBoundingVolumetoCP::GetOutputMin, &GC_OP_RemapBoundingVolumetoCP::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapBoundingVolumetoCP::GetOutputMax, &GC_OP_RemapBoundingVolumetoCP::SetOutputMax)
        .endClass();
}