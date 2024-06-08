#include "../../../core/scripting/generated/classes/GC_OP_RemapDirectionToCPToVector.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapDirectionToCPToVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapDirectionToCPToVector>("C_OP_RemapDirectionToCPToVector")
        .addProperty("CP", &GC_OP_RemapDirectionToCPToVector::GetCP, &GC_OP_RemapDirectionToCPToVector::SetCP)
        .addProperty("FieldOutput", &GC_OP_RemapDirectionToCPToVector::GetFieldOutput, &GC_OP_RemapDirectionToCPToVector::SetFieldOutput)
        .addProperty("Scale", &GC_OP_RemapDirectionToCPToVector::GetScale, &GC_OP_RemapDirectionToCPToVector::SetScale)
        .addProperty("OffsetRot", &GC_OP_RemapDirectionToCPToVector::GetOffsetRot, &GC_OP_RemapDirectionToCPToVector::SetOffsetRot)
        .addProperty("OffsetAxis", &GC_OP_RemapDirectionToCPToVector::GetOffsetAxis, &GC_OP_RemapDirectionToCPToVector::SetOffsetAxis)
        .addProperty("Normalize", &GC_OP_RemapDirectionToCPToVector::GetNormalize, &GC_OP_RemapDirectionToCPToVector::SetNormalize)
        .addProperty("FieldStrength", &GC_OP_RemapDirectionToCPToVector::GetFieldStrength, &GC_OP_RemapDirectionToCPToVector::SetFieldStrength)
        .endClass();
}