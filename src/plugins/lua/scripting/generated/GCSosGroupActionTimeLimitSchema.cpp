#include "../../../core/scripting/generated/classes/GCSosGroupActionTimeLimitSchema.h"
#include "../core.h"

void SetupLuaClassGCSosGroupActionTimeLimitSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupActionTimeLimitSchema>("CSosGroupActionTimeLimitSchema")
        .addProperty("MaxDuration", &GCSosGroupActionTimeLimitSchema::GetMaxDuration, &GCSosGroupActionTimeLimitSchema::SetMaxDuration)
        .endClass();
}