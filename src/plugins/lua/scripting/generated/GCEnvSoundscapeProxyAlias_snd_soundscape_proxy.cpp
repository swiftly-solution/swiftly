#include "../../../core/scripting/generated/classes/GCEnvSoundscapeProxyAlias_snd_soundscape_proxy.h"
#include "../core.h"

void SetupLuaClassGCEnvSoundscapeProxyAlias_snd_soundscape_proxy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSoundscapeProxyAlias_snd_soundscape_proxy>("CEnvSoundscapeProxyAlias_snd_soundscape_proxy")

        .endClass();
}