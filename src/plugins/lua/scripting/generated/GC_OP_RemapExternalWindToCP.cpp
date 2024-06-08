#include "../../../core/scripting/generated/classes/GC_OP_RemapExternalWindToCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapExternalWindToCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapExternalWindToCP>("C_OP_RemapExternalWindToCP")
        .addProperty("CP", &GC_OP_RemapExternalWindToCP::GetCP, &GC_OP_RemapExternalWindToCP::SetCP)
        .addProperty("CPOutput", &GC_OP_RemapExternalWindToCP::GetCPOutput, &GC_OP_RemapExternalWindToCP::SetCPOutput)
        .addProperty("SetMagnitude", &GC_OP_RemapExternalWindToCP::GetSetMagnitude, &GC_OP_RemapExternalWindToCP::SetSetMagnitude)
        .addProperty("OutVectorField", &GC_OP_RemapExternalWindToCP::GetOutVectorField, &GC_OP_RemapExternalWindToCP::SetOutVectorField)
        .endClass();
}