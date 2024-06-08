#include "../../../core/scripting/generated/classes/GC_OP_RotateVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_RotateVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RotateVector>("C_OP_RotateVector")
        .addProperty("FieldOutput", &GC_OP_RotateVector::GetFieldOutput, &GC_OP_RotateVector::SetFieldOutput)
        .addProperty("RotAxisMin", &GC_OP_RotateVector::GetRotAxisMin, &GC_OP_RotateVector::SetRotAxisMin)
        .addProperty("RotAxisMax", &GC_OP_RotateVector::GetRotAxisMax, &GC_OP_RotateVector::SetRotAxisMax)
        .addProperty("RotRateMin", &GC_OP_RotateVector::GetRotRateMin, &GC_OP_RotateVector::SetRotRateMin)
        .addProperty("RotRateMax", &GC_OP_RotateVector::GetRotRateMax, &GC_OP_RotateVector::SetRotRateMax)
        .addProperty("Normalize", &GC_OP_RotateVector::GetNormalize, &GC_OP_RotateVector::SetNormalize)
        .addProperty("Scale", &GC_OP_RotateVector::GetScale, &GC_OP_RotateVector::SetScale)
        .endClass();
}