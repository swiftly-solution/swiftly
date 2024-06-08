#include "../../../core/scripting/generated/classes/GC_OP_Orient2DRelToCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_Orient2DRelToCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_Orient2DRelToCP>("C_OP_Orient2DRelToCP")
        .addProperty("RotOffset", &GC_OP_Orient2DRelToCP::GetRotOffset, &GC_OP_Orient2DRelToCP::SetRotOffset)
        .addProperty("SpinStrength", &GC_OP_Orient2DRelToCP::GetSpinStrength, &GC_OP_Orient2DRelToCP::SetSpinStrength)
        .addProperty("CP", &GC_OP_Orient2DRelToCP::GetCP, &GC_OP_Orient2DRelToCP::SetCP)
        .addProperty("FieldOutput", &GC_OP_Orient2DRelToCP::GetFieldOutput, &GC_OP_Orient2DRelToCP::SetFieldOutput)
        .endClass();
}