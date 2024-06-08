#include "../../../core/scripting/generated/classes/GCSoundEventMetaData.h"
#include "../core.h"

void SetupLuaClassGCSoundEventMetaData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEventMetaData>("CSoundEventMetaData")

        .endClass();
}