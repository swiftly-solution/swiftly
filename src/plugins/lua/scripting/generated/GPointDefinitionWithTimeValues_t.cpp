#include "../../../core/scripting/generated/classes/GPointDefinitionWithTimeValues_t.h"
#include "../core.h"

void SetupLuaClassGPointDefinitionWithTimeValues_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPointDefinitionWithTimeValues_t>("PointDefinitionWithTimeValues_t")
        .addProperty("TimeDuration", &GPointDefinitionWithTimeValues_t::GetTimeDuration, &GPointDefinitionWithTimeValues_t::SetTimeDuration)
        .endClass();
}