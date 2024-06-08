#include "../../../core/scripting/generated/classes/GC_OP_RemapModelVolumetoCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapModelVolumetoCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapModelVolumetoCP>("C_OP_RemapModelVolumetoCP")
        .addProperty("BBoxType", &GC_OP_RemapModelVolumetoCP::GetBBoxType, &GC_OP_RemapModelVolumetoCP::SetBBoxType)
        .addProperty("InControlPointNumber", &GC_OP_RemapModelVolumetoCP::GetInControlPointNumber, &GC_OP_RemapModelVolumetoCP::SetInControlPointNumber)
        .addProperty("OutControlPointNumber", &GC_OP_RemapModelVolumetoCP::GetOutControlPointNumber, &GC_OP_RemapModelVolumetoCP::SetOutControlPointNumber)
        .addProperty("OutControlPointMaxNumber", &GC_OP_RemapModelVolumetoCP::GetOutControlPointMaxNumber, &GC_OP_RemapModelVolumetoCP::SetOutControlPointMaxNumber)
        .addProperty("Field", &GC_OP_RemapModelVolumetoCP::GetField, &GC_OP_RemapModelVolumetoCP::SetField)
        .addProperty("InputMin", &GC_OP_RemapModelVolumetoCP::GetInputMin, &GC_OP_RemapModelVolumetoCP::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapModelVolumetoCP::GetInputMax, &GC_OP_RemapModelVolumetoCP::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapModelVolumetoCP::GetOutputMin, &GC_OP_RemapModelVolumetoCP::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapModelVolumetoCP::GetOutputMax, &GC_OP_RemapModelVolumetoCP::SetOutputMax)
        .endClass();
}