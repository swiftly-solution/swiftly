#include "../../../core/scripting/generated/classes/GC_OP_RemapNamedModelElementOnceTimed.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapNamedModelElementOnceTimed(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapNamedModelElementOnceTimed>("C_OP_RemapNamedModelElementOnceTimed")
        .addProperty("InNames", &GC_OP_RemapNamedModelElementOnceTimed::GetInNames, &GC_OP_RemapNamedModelElementOnceTimed::SetInNames)
        .addProperty("OutNames", &GC_OP_RemapNamedModelElementOnceTimed::GetOutNames, &GC_OP_RemapNamedModelElementOnceTimed::SetOutNames)
        .addProperty("FallbackNames", &GC_OP_RemapNamedModelElementOnceTimed::GetFallbackNames, &GC_OP_RemapNamedModelElementOnceTimed::SetFallbackNames)
        .addProperty("ModelFromRenderer", &GC_OP_RemapNamedModelElementOnceTimed::GetModelFromRenderer, &GC_OP_RemapNamedModelElementOnceTimed::SetModelFromRenderer)
        .addProperty("Proportional", &GC_OP_RemapNamedModelElementOnceTimed::GetProportional, &GC_OP_RemapNamedModelElementOnceTimed::SetProportional)
        .addProperty("FieldInput", &GC_OP_RemapNamedModelElementOnceTimed::GetFieldInput, &GC_OP_RemapNamedModelElementOnceTimed::SetFieldInput)
        .addProperty("FieldOutput", &GC_OP_RemapNamedModelElementOnceTimed::GetFieldOutput, &GC_OP_RemapNamedModelElementOnceTimed::SetFieldOutput)
        .addProperty("RemapTime", &GC_OP_RemapNamedModelElementOnceTimed::GetRemapTime, &GC_OP_RemapNamedModelElementOnceTimed::SetRemapTime)
        .endClass();
}