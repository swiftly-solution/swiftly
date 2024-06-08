#include "../../../core/scripting/generated/classes/GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable.h"
#include "../core.h"

void SetupLuaClassGCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable>("CEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable")

        .endClass();
}