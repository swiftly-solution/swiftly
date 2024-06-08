#include "../../../core/scripting/generated/classes/Gaudioparams_t.h"
#include "../core.h"

void SetupLuaClassGaudioparams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gaudioparams_t>("audioparams_t")
        .addProperty("LocalSound", &Gaudioparams_t::GetLocalSound, &Gaudioparams_t::SetLocalSound)
        .addProperty("SoundscapeIndex", &Gaudioparams_t::GetSoundscapeIndex, &Gaudioparams_t::SetSoundscapeIndex)
        .addProperty("LocalBits", &Gaudioparams_t::GetLocalBits, &Gaudioparams_t::SetLocalBits)
        .addProperty("SoundscapeEntityListIndex", &Gaudioparams_t::GetSoundscapeEntityListIndex, &Gaudioparams_t::SetSoundscapeEntityListIndex)
        .addProperty("SoundEventHash", &Gaudioparams_t::GetSoundEventHash, &Gaudioparams_t::SetSoundEventHash)
        .endClass();
}