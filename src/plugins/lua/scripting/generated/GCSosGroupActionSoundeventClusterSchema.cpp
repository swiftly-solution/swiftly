#include "../../../core/scripting/generated/classes/GCSosGroupActionSoundeventClusterSchema.h"
#include "../core.h"

void SetupLuaClassGCSosGroupActionSoundeventClusterSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupActionSoundeventClusterSchema>("CSosGroupActionSoundeventClusterSchema")
        .addProperty("MinNearby", &GCSosGroupActionSoundeventClusterSchema::GetMinNearby, &GCSosGroupActionSoundeventClusterSchema::SetMinNearby)
        .addProperty("ClusterEpsilon", &GCSosGroupActionSoundeventClusterSchema::GetClusterEpsilon, &GCSosGroupActionSoundeventClusterSchema::SetClusterEpsilon)
        .addProperty("ShouldPlayOpvar", &GCSosGroupActionSoundeventClusterSchema::GetShouldPlayOpvar, &GCSosGroupActionSoundeventClusterSchema::SetShouldPlayOpvar)
        .addProperty("ShouldPlayClusterChild", &GCSosGroupActionSoundeventClusterSchema::GetShouldPlayClusterChild, &GCSosGroupActionSoundeventClusterSchema::SetShouldPlayClusterChild)
        .addProperty("ClusterSizeOpvar", &GCSosGroupActionSoundeventClusterSchema::GetClusterSizeOpvar, &GCSosGroupActionSoundeventClusterSchema::SetClusterSizeOpvar)
        .addProperty("GroupBoundingBoxMinsOpvar", &GCSosGroupActionSoundeventClusterSchema::GetGroupBoundingBoxMinsOpvar, &GCSosGroupActionSoundeventClusterSchema::SetGroupBoundingBoxMinsOpvar)
        .addProperty("GroupBoundingBoxMaxsOpvar", &GCSosGroupActionSoundeventClusterSchema::GetGroupBoundingBoxMaxsOpvar, &GCSosGroupActionSoundeventClusterSchema::SetGroupBoundingBoxMaxsOpvar)
        .endClass();
}