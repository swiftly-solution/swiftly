#include "../../../core/scripting/generated/classes/GCEconItemAttribute.h"
#include "../core.h"

void SetupLuaClassGCEconItemAttribute(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEconItemAttribute>("CEconItemAttribute")
        .addProperty("AttributeDefinitionIndex", &GCEconItemAttribute::GetAttributeDefinitionIndex, &GCEconItemAttribute::SetAttributeDefinitionIndex)
        .addProperty("Value", &GCEconItemAttribute::GetValue, &GCEconItemAttribute::SetValue)
        .addProperty("InitialValue", &GCEconItemAttribute::GetInitialValue, &GCEconItemAttribute::SetInitialValue)
        .addProperty("RefundableCurrency", &GCEconItemAttribute::GetRefundableCurrency, &GCEconItemAttribute::SetRefundableCurrency)
        .addProperty("SetBonus", &GCEconItemAttribute::GetSetBonus, &GCEconItemAttribute::SetSetBonus)
        .endClass();
}