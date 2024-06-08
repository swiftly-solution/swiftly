#include "../../../core/scripting/generated/classes/GCSoundEventPathCornerEntity.h"
#include "../core.h"

void SetupLuaClassGCSoundEventPathCornerEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEventPathCornerEntity>("CSoundEventPathCornerEntity")
        .addProperty("PathCorner", &GCSoundEventPathCornerEntity::GetPathCorner, &GCSoundEventPathCornerEntity::SetPathCorner)
        .addProperty("CountMax", &GCSoundEventPathCornerEntity::GetCountMax, &GCSoundEventPathCornerEntity::SetCountMax)
        .addProperty("DistanceMax", &GCSoundEventPathCornerEntity::GetDistanceMax, &GCSoundEventPathCornerEntity::SetDistanceMax)
        .addProperty("DistMaxSqr", &GCSoundEventPathCornerEntity::GetDistMaxSqr, &GCSoundEventPathCornerEntity::SetDistMaxSqr)
        .addProperty("DotProductMax", &GCSoundEventPathCornerEntity::GetDotProductMax, &GCSoundEventPathCornerEntity::SetDotProductMax)
        .addProperty("Playing", &GCSoundEventPathCornerEntity::GetPlaying, &GCSoundEventPathCornerEntity::SetPlaying)
        .endClass();
}