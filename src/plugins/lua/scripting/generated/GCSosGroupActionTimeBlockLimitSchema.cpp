#include "../../../core/scripting/generated/classes/GCSosGroupActionTimeBlockLimitSchema.h"
#include "../core.h"

void SetupLuaClassGCSosGroupActionTimeBlockLimitSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupActionTimeBlockLimitSchema>("CSosGroupActionTimeBlockLimitSchema")
        .addProperty("MaxCount", &GCSosGroupActionTimeBlockLimitSchema::GetMaxCount, &GCSosGroupActionTimeBlockLimitSchema::SetMaxCount)
        .addProperty("MaxDuration", &GCSosGroupActionTimeBlockLimitSchema::GetMaxDuration, &GCSosGroupActionTimeBlockLimitSchema::SetMaxDuration)
        .endClass();
}