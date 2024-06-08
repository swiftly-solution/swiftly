#include "../../../core/scripting/generated/classes/GCMaterialAttributeAnimTag.h"
#include "../core.h"

void SetupLuaClassGCMaterialAttributeAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMaterialAttributeAnimTag>("CMaterialAttributeAnimTag")
        .addProperty("AttributeName", &GCMaterialAttributeAnimTag::GetAttributeName, &GCMaterialAttributeAnimTag::SetAttributeName)
        .addProperty("AttributeType", &GCMaterialAttributeAnimTag::GetAttributeType, &GCMaterialAttributeAnimTag::SetAttributeType)
        .addProperty("Value", &GCMaterialAttributeAnimTag::GetValue, &GCMaterialAttributeAnimTag::SetValue)
        .addProperty("Color", &GCMaterialAttributeAnimTag::GetColor, &GCMaterialAttributeAnimTag::SetColor)
        .endClass();
}