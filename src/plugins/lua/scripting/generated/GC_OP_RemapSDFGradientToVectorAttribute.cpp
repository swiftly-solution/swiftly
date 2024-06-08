#include "../../../core/scripting/generated/classes/GC_OP_RemapSDFGradientToVectorAttribute.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapSDFGradientToVectorAttribute(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapSDFGradientToVectorAttribute>("C_OP_RemapSDFGradientToVectorAttribute")
        .addProperty("FieldOutput", &GC_OP_RemapSDFGradientToVectorAttribute::GetFieldOutput, &GC_OP_RemapSDFGradientToVectorAttribute::SetFieldOutput)
        .endClass();
}