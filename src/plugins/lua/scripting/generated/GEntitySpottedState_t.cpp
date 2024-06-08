#include "../../../core/scripting/generated/classes/GEntitySpottedState_t.h"
#include "../core.h"

void SetupLuaClassGEntitySpottedState_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEntitySpottedState_t>("EntitySpottedState_t")
        .addProperty("Spotted", &GEntitySpottedState_t::GetSpotted, &GEntitySpottedState_t::SetSpotted)
        .addProperty("SpottedByMask", &GEntitySpottedState_t::GetSpottedByMask, &GEntitySpottedState_t::SetSpottedByMask)
        .endClass();
}