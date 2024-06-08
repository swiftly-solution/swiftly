#include "../../../core/scripting/generated/classes/GC_OP_ReinitializeScalarEndCap.h"
#include "../core.h"

void SetupLuaClassGC_OP_ReinitializeScalarEndCap(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ReinitializeScalarEndCap>("C_OP_ReinitializeScalarEndCap")
        .addProperty("FieldOutput", &GC_OP_ReinitializeScalarEndCap::GetFieldOutput, &GC_OP_ReinitializeScalarEndCap::SetFieldOutput)
        .addProperty("OutputMin", &GC_OP_ReinitializeScalarEndCap::GetOutputMin, &GC_OP_ReinitializeScalarEndCap::SetOutputMin)
        .addProperty("OutputMax", &GC_OP_ReinitializeScalarEndCap::GetOutputMax, &GC_OP_ReinitializeScalarEndCap::SetOutputMax)
        .endClass();
}