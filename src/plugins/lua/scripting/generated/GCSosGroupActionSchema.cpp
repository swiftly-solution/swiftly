#include "../../../core/scripting/generated/classes/GCSosGroupActionSchema.h"
#include "../core.h"

void SetupLuaClassGCSosGroupActionSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupActionSchema>("CSosGroupActionSchema")
        .addProperty("Name", &GCSosGroupActionSchema::GetName, &GCSosGroupActionSchema::SetName)
        .addProperty("ActionType", &GCSosGroupActionSchema::GetActionType, &GCSosGroupActionSchema::SetActionType)
        .addProperty("ActionInstanceType", &GCSosGroupActionSchema::GetActionInstanceType, &GCSosGroupActionSchema::SetActionInstanceType)
        .endClass();
}