#include "../../../core/scripting/generated/classes/GC_OP_DistanceBetweenVecs.h"
#include "../core.h"

void SetupLuaClassGC_OP_DistanceBetweenVecs(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_DistanceBetweenVecs>("C_OP_DistanceBetweenVecs")
        .addProperty("FieldOutput", &GC_OP_DistanceBetweenVecs::GetFieldOutput, &GC_OP_DistanceBetweenVecs::SetFieldOutput)
        .addProperty("Point1", &GC_OP_DistanceBetweenVecs::GetPoint1, &GC_OP_DistanceBetweenVecs::SetPoint1)
        .addProperty("Point2", &GC_OP_DistanceBetweenVecs::GetPoint2, &GC_OP_DistanceBetweenVecs::SetPoint2)
        .addProperty("InputMin", &GC_OP_DistanceBetweenVecs::GetInputMin, &GC_OP_DistanceBetweenVecs::SetInputMin)
        .addProperty("InputMax", &GC_OP_DistanceBetweenVecs::GetInputMax, &GC_OP_DistanceBetweenVecs::SetInputMax)
        .addProperty("OutputMin", &GC_OP_DistanceBetweenVecs::GetOutputMin, &GC_OP_DistanceBetweenVecs::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_DistanceBetweenVecs::GetOutputMax, &GC_OP_DistanceBetweenVecs::SetOutputMax)
        .addProperty("SetMethod", &GC_OP_DistanceBetweenVecs::GetSetMethod, &GC_OP_DistanceBetweenVecs::SetSetMethod)
        .addProperty("DeltaTime", &GC_OP_DistanceBetweenVecs::GetDeltaTime, &GC_OP_DistanceBetweenVecs::SetDeltaTime)
        .endClass();
}