#include "../../../core/scripting/generated/classes/GC_OP_RemapDistanceToLineSegmentToScalar.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapDistanceToLineSegmentToScalar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapDistanceToLineSegmentToScalar>("C_OP_RemapDistanceToLineSegmentToScalar")
        .addProperty("FieldOutput", &GC_OP_RemapDistanceToLineSegmentToScalar::GetFieldOutput, &GC_OP_RemapDistanceToLineSegmentToScalar::SetFieldOutput)
        .addProperty("MinOutputValue", &GC_OP_RemapDistanceToLineSegmentToScalar::GetMinOutputValue, &GC_OP_RemapDistanceToLineSegmentToScalar::SetMinOutputValue)
        .addProperty("MaxOutputValue", &GC_OP_RemapDistanceToLineSegmentToScalar::GetMaxOutputValue, &GC_OP_RemapDistanceToLineSegmentToScalar::SetMaxOutputValue)
        .endClass();
}