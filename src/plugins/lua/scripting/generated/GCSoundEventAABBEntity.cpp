#include "../../../core/scripting/generated/classes/GCSoundEventAABBEntity.h"
#include "../core.h"

void SetupLuaClassGCSoundEventAABBEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEventAABBEntity>("CSoundEventAABBEntity")
        .addProperty("Mins", &GCSoundEventAABBEntity::GetMins, &GCSoundEventAABBEntity::SetMins)
        .addProperty("Maxs", &GCSoundEventAABBEntity::GetMaxs, &GCSoundEventAABBEntity::SetMaxs)
        .endClass();
}