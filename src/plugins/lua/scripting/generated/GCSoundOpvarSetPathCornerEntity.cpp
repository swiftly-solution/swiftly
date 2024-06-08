#include "../../../core/scripting/generated/classes/GCSoundOpvarSetPathCornerEntity.h"
#include "../core.h"

void SetupLuaClassGCSoundOpvarSetPathCornerEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundOpvarSetPathCornerEntity>("CSoundOpvarSetPathCornerEntity")
        .addProperty("DistMinSqr", &GCSoundOpvarSetPathCornerEntity::GetDistMinSqr, &GCSoundOpvarSetPathCornerEntity::SetDistMinSqr)
        .addProperty("DistMaxSqr", &GCSoundOpvarSetPathCornerEntity::GetDistMaxSqr, &GCSoundOpvarSetPathCornerEntity::SetDistMaxSqr)
        .addProperty("PathCornerEntityName", &GCSoundOpvarSetPathCornerEntity::GetPathCornerEntityName, &GCSoundOpvarSetPathCornerEntity::SetPathCornerEntityName)
        .endClass();
}