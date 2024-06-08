#include "../../../core/scripting/generated/classes/GC_INIT_RandomNamedModelElement.h"
#include "../core.h"

void SetupLuaClassGC_INIT_RandomNamedModelElement(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_RandomNamedModelElement>("C_INIT_RandomNamedModelElement")
        .addProperty("Names", &GC_INIT_RandomNamedModelElement::GetNames, &GC_INIT_RandomNamedModelElement::SetNames)
        .addProperty("Shuffle", &GC_INIT_RandomNamedModelElement::GetShuffle, &GC_INIT_RandomNamedModelElement::SetShuffle)
        .addProperty("Linear", &GC_INIT_RandomNamedModelElement::GetLinear, &GC_INIT_RandomNamedModelElement::SetLinear)
        .addProperty("ModelFromRenderer", &GC_INIT_RandomNamedModelElement::GetModelFromRenderer, &GC_INIT_RandomNamedModelElement::SetModelFromRenderer)
        .addProperty("FieldOutput", &GC_INIT_RandomNamedModelElement::GetFieldOutput, &GC_INIT_RandomNamedModelElement::SetFieldOutput)
        .endClass();
}