#include "../../../core/scripting/generated/classes/GC_OP_OrientTo2dDirection.h"
#include "../core.h"

void SetupLuaClassGC_OP_OrientTo2dDirection(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_OrientTo2dDirection>("C_OP_OrientTo2dDirection")
        .addProperty("RotOffset", &GC_OP_OrientTo2dDirection::GetRotOffset, &GC_OP_OrientTo2dDirection::SetRotOffset)
        .addProperty("SpinStrength", &GC_OP_OrientTo2dDirection::GetSpinStrength, &GC_OP_OrientTo2dDirection::SetSpinStrength)
        .addProperty("FieldOutput", &GC_OP_OrientTo2dDirection::GetFieldOutput, &GC_OP_OrientTo2dDirection::SetFieldOutput)
        .endClass();
}