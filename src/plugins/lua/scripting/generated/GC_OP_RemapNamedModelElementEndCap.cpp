#include "../../../core/scripting/generated/classes/GC_OP_RemapNamedModelElementEndCap.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapNamedModelElementEndCap(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapNamedModelElementEndCap>("C_OP_RemapNamedModelElementEndCap")
        .addProperty("InNames", &GC_OP_RemapNamedModelElementEndCap::GetInNames, &GC_OP_RemapNamedModelElementEndCap::SetInNames)
        .addProperty("OutNames", &GC_OP_RemapNamedModelElementEndCap::GetOutNames, &GC_OP_RemapNamedModelElementEndCap::SetOutNames)
        .addProperty("FallbackNames", &GC_OP_RemapNamedModelElementEndCap::GetFallbackNames, &GC_OP_RemapNamedModelElementEndCap::SetFallbackNames)
        .addProperty("ModelFromRenderer", &GC_OP_RemapNamedModelElementEndCap::GetModelFromRenderer, &GC_OP_RemapNamedModelElementEndCap::SetModelFromRenderer)
        .addProperty("FieldInput", &GC_OP_RemapNamedModelElementEndCap::GetFieldInput, &GC_OP_RemapNamedModelElementEndCap::SetFieldInput)
        .addProperty("FieldOutput", &GC_OP_RemapNamedModelElementEndCap::GetFieldOutput, &GC_OP_RemapNamedModelElementEndCap::SetFieldOutput)
        .endClass();
}