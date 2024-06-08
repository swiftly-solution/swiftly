#include "../../../core/scripting/generated/classes/GCSoundOpvarSetOBBWindEntity.h"
#include "../core.h"

void SetupLuaClassGCSoundOpvarSetOBBWindEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundOpvarSetOBBWindEntity>("CSoundOpvarSetOBBWindEntity")
        .addProperty("Mins", &GCSoundOpvarSetOBBWindEntity::GetMins, &GCSoundOpvarSetOBBWindEntity::SetMins)
        .addProperty("Maxs", &GCSoundOpvarSetOBBWindEntity::GetMaxs, &GCSoundOpvarSetOBBWindEntity::SetMaxs)
        .addProperty("DistanceMins", &GCSoundOpvarSetOBBWindEntity::GetDistanceMins, &GCSoundOpvarSetOBBWindEntity::SetDistanceMins)
        .addProperty("DistanceMaxs", &GCSoundOpvarSetOBBWindEntity::GetDistanceMaxs, &GCSoundOpvarSetOBBWindEntity::SetDistanceMaxs)
        .addProperty("WindMin", &GCSoundOpvarSetOBBWindEntity::GetWindMin, &GCSoundOpvarSetOBBWindEntity::SetWindMin)
        .addProperty("WindMax", &GCSoundOpvarSetOBBWindEntity::GetWindMax, &GCSoundOpvarSetOBBWindEntity::SetWindMax)
        .addProperty("WindMapMin", &GCSoundOpvarSetOBBWindEntity::GetWindMapMin, &GCSoundOpvarSetOBBWindEntity::SetWindMapMin)
        .addProperty("WindMapMax", &GCSoundOpvarSetOBBWindEntity::GetWindMapMax, &GCSoundOpvarSetOBBWindEntity::SetWindMapMax)
        .endClass();
}