#include "../../../core/scripting/generated/classes/GCSoundEnt.h"
#include "../core.h"

void SetupLuaClassGCSoundEnt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEnt>("CSoundEnt")
        .addProperty("FreeSound", &GCSoundEnt::GetFreeSound, &GCSoundEnt::SetFreeSound)
        .addProperty("ActiveSound", &GCSoundEnt::GetActiveSound, &GCSoundEnt::SetActiveSound)
        .addProperty("CLastActiveSounds", &GCSoundEnt::GetCLastActiveSounds, &GCSoundEnt::SetCLastActiveSounds)
        .addProperty("SoundPool", &GCSoundEnt::GetSoundPool, &GCSoundEnt::SetSoundPool)
        .endClass();
}