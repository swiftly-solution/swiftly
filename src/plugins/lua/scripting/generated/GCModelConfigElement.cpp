#include "../../../core/scripting/generated/classes/GCModelConfigElement.h"
#include "../core.h"

void SetupLuaClassGCModelConfigElement(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement>("CModelConfigElement")
        .addProperty("ElementName", &GCModelConfigElement::GetElementName, &GCModelConfigElement::SetElementName)
        .addProperty("NestedElements", &GCModelConfigElement::GetNestedElements, &GCModelConfigElement::SetNestedElements)
        .endClass();
}