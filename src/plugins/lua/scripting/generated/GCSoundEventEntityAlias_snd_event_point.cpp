#include "../../../core/scripting/generated/classes/GCSoundEventEntityAlias_snd_event_point.h"
#include "../core.h"

void SetupLuaClassGCSoundEventEntityAlias_snd_event_point(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEventEntityAlias_snd_event_point>("CSoundEventEntityAlias_snd_event_point")

        .endClass();
}