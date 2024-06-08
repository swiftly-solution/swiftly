#include "../../../core/scripting/generated/classes/Glocksound_t.h"
#include "../core.h"

void SetupLuaClassGlocksound_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Glocksound_t>("locksound_t")
        .addProperty("LockedSound", &Glocksound_t::GetLockedSound, &Glocksound_t::SetLockedSound)
        .addProperty("UnlockedSound", &Glocksound_t::GetUnlockedSound, &Glocksound_t::SetUnlockedSound)
        .endClass();
}