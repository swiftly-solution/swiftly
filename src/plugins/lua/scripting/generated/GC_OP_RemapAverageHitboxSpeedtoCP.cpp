#include "../../../core/scripting/generated/classes/GC_OP_RemapAverageHitboxSpeedtoCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapAverageHitboxSpeedtoCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapAverageHitboxSpeedtoCP>("C_OP_RemapAverageHitboxSpeedtoCP")
        .addProperty("InControlPointNumber", &GC_OP_RemapAverageHitboxSpeedtoCP::GetInControlPointNumber, &GC_OP_RemapAverageHitboxSpeedtoCP::SetInControlPointNumber)
        .addProperty("OutControlPointNumber", &GC_OP_RemapAverageHitboxSpeedtoCP::GetOutControlPointNumber, &GC_OP_RemapAverageHitboxSpeedtoCP::SetOutControlPointNumber)
        .addProperty("Field", &GC_OP_RemapAverageHitboxSpeedtoCP::GetField, &GC_OP_RemapAverageHitboxSpeedtoCP::SetField)
        .addProperty("HitboxDataType", &GC_OP_RemapAverageHitboxSpeedtoCP::GetHitboxDataType, &GC_OP_RemapAverageHitboxSpeedtoCP::SetHitboxDataType)
        .addProperty("InputMin", &GC_OP_RemapAverageHitboxSpeedtoCP::GetInputMin, &GC_OP_RemapAverageHitboxSpeedtoCP::SetInputMin)
        .addProperty("InputMax", &GC_OP_RemapAverageHitboxSpeedtoCP::GetInputMax, &GC_OP_RemapAverageHitboxSpeedtoCP::SetInputMax)
        .addProperty("OutputMin", &GC_OP_RemapAverageHitboxSpeedtoCP::GetOutputMin, &GC_OP_RemapAverageHitboxSpeedtoCP::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_RemapAverageHitboxSpeedtoCP::GetOutputMax, &GC_OP_RemapAverageHitboxSpeedtoCP::SetOutputMax)
        .addProperty("HeightControlPointNumber", &GC_OP_RemapAverageHitboxSpeedtoCP::GetHeightControlPointNumber, &GC_OP_RemapAverageHitboxSpeedtoCP::SetHeightControlPointNumber)
        .addProperty("HitboxSetName", &GC_OP_RemapAverageHitboxSpeedtoCP::GetHitboxSetName, &GC_OP_RemapAverageHitboxSpeedtoCP::SetHitboxSetName)
        .endClass();
}