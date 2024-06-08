#include "../../../core/scripting/generated/classes/GPARTICLE_EHANDLE__.h"
#include "../core.h"

void SetupLuaClassGPARTICLE_EHANDLE__(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPARTICLE_EHANDLE__>("PARTICLE_EHANDLE__")
        .addProperty("Unused", &GPARTICLE_EHANDLE__::GetUnused, &GPARTICLE_EHANDLE__::SetUnused)
        .endClass();
}