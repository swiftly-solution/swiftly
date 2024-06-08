#include "../../../core/scripting/generated/classes/GC_OP_LerpToOtherAttribute.h"
#include "../core.h"

void SetupLuaClassGC_OP_LerpToOtherAttribute(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_LerpToOtherAttribute>("C_OP_LerpToOtherAttribute")
        .addProperty("Interpolation", &GC_OP_LerpToOtherAttribute::GetInterpolation, &GC_OP_LerpToOtherAttribute::SetInterpolation)
        .addProperty("FieldInputFrom", &GC_OP_LerpToOtherAttribute::GetFieldInputFrom, &GC_OP_LerpToOtherAttribute::SetFieldInputFrom)
        .addProperty("FieldInput", &GC_OP_LerpToOtherAttribute::GetFieldInput, &GC_OP_LerpToOtherAttribute::SetFieldInput)
        .addProperty("FieldOutput", &GC_OP_LerpToOtherAttribute::GetFieldOutput, &GC_OP_LerpToOtherAttribute::SetFieldOutput)
        .endClass();
}