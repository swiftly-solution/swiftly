#include "../../../core/scripting/generated/classes/GPARTICLE_WORLD_HANDLE__.h"
#include "../core.h"

void SetupLuaClassGPARTICLE_WORLD_HANDLE__(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPARTICLE_WORLD_HANDLE__>("PARTICLE_WORLD_HANDLE__")
        .addProperty("Unused", &GPARTICLE_WORLD_HANDLE__::GetUnused, &GPARTICLE_WORLD_HANDLE__::SetUnused)
        .endClass();
}