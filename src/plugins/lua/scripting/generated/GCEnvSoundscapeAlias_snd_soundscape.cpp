#include "../../../core/scripting/generated/classes/GCEnvSoundscapeAlias_snd_soundscape.h"
#include "../core.h"

void SetupLuaClassGCEnvSoundscapeAlias_snd_soundscape(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSoundscapeAlias_snd_soundscape>("CEnvSoundscapeAlias_snd_soundscape")

        .endClass();
}