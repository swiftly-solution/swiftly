#include "../../../core/scripting/generated/classes/GCSosGroupActionSetSoundeventParameterSchema.h"
#include "../core.h"

void SetupLuaClassGCSosGroupActionSetSoundeventParameterSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupActionSetSoundeventParameterSchema>("CSosGroupActionSetSoundeventParameterSchema")
        .addProperty("MaxCount", &GCSosGroupActionSetSoundeventParameterSchema::GetMaxCount, &GCSosGroupActionSetSoundeventParameterSchema::SetMaxCount)
        .addProperty("MinValue", &GCSosGroupActionSetSoundeventParameterSchema::GetMinValue, &GCSosGroupActionSetSoundeventParameterSchema::SetMinValue)
        .addProperty("MaxValue", &GCSosGroupActionSetSoundeventParameterSchema::GetMaxValue, &GCSosGroupActionSetSoundeventParameterSchema::SetMaxValue)
        .addProperty("OpvarName", &GCSosGroupActionSetSoundeventParameterSchema::GetOpvarName, &GCSosGroupActionSetSoundeventParameterSchema::SetOpvarName)
        .addProperty("SortType", &GCSosGroupActionSetSoundeventParameterSchema::GetSortType, &GCSosGroupActionSetSoundeventParameterSchema::SetSortType)
        .endClass();
}