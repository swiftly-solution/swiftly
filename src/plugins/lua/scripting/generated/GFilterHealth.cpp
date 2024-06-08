#include "../../../core/scripting/generated/classes/GFilterHealth.h"
#include "../core.h"

void SetupLuaClassGFilterHealth(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFilterHealth>("FilterHealth")
        .addProperty("AdrenalineActive", &GFilterHealth::GetAdrenalineActive, &GFilterHealth::SetAdrenalineActive)
        .addProperty("HealthMin", &GFilterHealth::GetHealthMin, &GFilterHealth::SetHealthMin)
        .addProperty("HealthMax", &GFilterHealth::GetHealthMax, &GFilterHealth::SetHealthMax)
        .endClass();
}