#include "../../../core/scripting/generated/classes/GC_OP_RemapDistanceToLineSegmentToVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapDistanceToLineSegmentToVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapDistanceToLineSegmentToVector>("C_OP_RemapDistanceToLineSegmentToVector")
        .addProperty("FieldOutput", &GC_OP_RemapDistanceToLineSegmentToVector::GetFieldOutput, &GC_OP_RemapDistanceToLineSegmentToVector::SetFieldOutput)
        .addProperty("MinOutputValue", &GC_OP_RemapDistanceToLineSegmentToVector::GetMinOutputValue, &GC_OP_RemapDistanceToLineSegmentToVector::SetMinOutputValue)
        .addProperty("MaxOutputValue", &GC_OP_RemapDistanceToLineSegmentToVector::GetMaxOutputValue, &GC_OP_RemapDistanceToLineSegmentToVector::SetMaxOutputValue)
        .endClass();
}