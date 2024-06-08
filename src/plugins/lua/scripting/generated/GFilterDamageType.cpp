#include "../../../core/scripting/generated/classes/GFilterDamageType.h"
#include "../core.h"

void SetupLuaClassGFilterDamageType(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFilterDamageType>("FilterDamageType")
        .addProperty("DamageType", &GFilterDamageType::GetDamageType, &GFilterDamageType::SetDamageType)
        .endClass();
}