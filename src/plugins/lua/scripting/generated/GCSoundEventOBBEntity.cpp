#include "../../../core/scripting/generated/classes/GCSoundEventOBBEntity.h"
#include "../core.h"

void SetupLuaClassGCSoundEventOBBEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEventOBBEntity>("CSoundEventOBBEntity")
        .addProperty("Mins", &GCSoundEventOBBEntity::GetMins, &GCSoundEventOBBEntity::SetMins)
        .addProperty("Maxs", &GCSoundEventOBBEntity::GetMaxs, &GCSoundEventOBBEntity::SetMaxs)
        .endClass();
}