#include "../../../core/scripting/generated/classes/GCSoundOpvarSetAABBEntity.h"
#include "../core.h"

void SetupLuaClassGCSoundOpvarSetAABBEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundOpvarSetAABBEntity>("CSoundOpvarSetAABBEntity")
        .addProperty("DistanceInnerMins", &GCSoundOpvarSetAABBEntity::GetDistanceInnerMins, &GCSoundOpvarSetAABBEntity::SetDistanceInnerMins)
        .addProperty("DistanceInnerMaxs", &GCSoundOpvarSetAABBEntity::GetDistanceInnerMaxs, &GCSoundOpvarSetAABBEntity::SetDistanceInnerMaxs)
        .addProperty("DistanceOuterMins", &GCSoundOpvarSetAABBEntity::GetDistanceOuterMins, &GCSoundOpvarSetAABBEntity::SetDistanceOuterMins)
        .addProperty("DistanceOuterMaxs", &GCSoundOpvarSetAABBEntity::GetDistanceOuterMaxs, &GCSoundOpvarSetAABBEntity::SetDistanceOuterMaxs)
        .addProperty("AABBDirection", &GCSoundOpvarSetAABBEntity::GetAABBDirection, &GCSoundOpvarSetAABBEntity::SetAABBDirection)
        .addProperty("InnerMins", &GCSoundOpvarSetAABBEntity::GetInnerMins, &GCSoundOpvarSetAABBEntity::SetInnerMins)
        .addProperty("InnerMaxs", &GCSoundOpvarSetAABBEntity::GetInnerMaxs, &GCSoundOpvarSetAABBEntity::SetInnerMaxs)
        .addProperty("OuterMins", &GCSoundOpvarSetAABBEntity::GetOuterMins, &GCSoundOpvarSetAABBEntity::SetOuterMins)
        .addProperty("OuterMaxs", &GCSoundOpvarSetAABBEntity::GetOuterMaxs, &GCSoundOpvarSetAABBEntity::SetOuterMaxs)
        .endClass();
}