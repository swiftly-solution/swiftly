#include "../../../core/scripting/generated/classes/GCSosGroupActionLimitSchema.h"
#include "../core.h"

void SetupLuaClassGCSosGroupActionLimitSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupActionLimitSchema>("CSosGroupActionLimitSchema")
        .addProperty("MaxCount", &GCSosGroupActionLimitSchema::GetMaxCount, &GCSosGroupActionLimitSchema::SetMaxCount)
        .addProperty("StopType", &GCSosGroupActionLimitSchema::GetStopType, &GCSosGroupActionLimitSchema::SetStopType)
        .addProperty("SortType", &GCSosGroupActionLimitSchema::GetSortType, &GCSosGroupActionLimitSchema::SetSortType)
        .endClass();
}