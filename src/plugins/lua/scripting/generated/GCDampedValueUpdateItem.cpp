#include "../../../core/scripting/generated/classes/GCDampedValueUpdateItem.h"
#include "../core.h"

void SetupLuaClassGCDampedValueUpdateItem(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDampedValueUpdateItem>("CDampedValueUpdateItem")
        .addProperty("Damping", &GCDampedValueUpdateItem::GetDamping, &GCDampedValueUpdateItem::SetDamping)
        .addProperty("ParamIn", &GCDampedValueUpdateItem::GetParamIn, &GCDampedValueUpdateItem::SetParamIn)
        .addProperty("ParamOut", &GCDampedValueUpdateItem::GetParamOut, &GCDampedValueUpdateItem::SetParamOut)
        .endClass();
}