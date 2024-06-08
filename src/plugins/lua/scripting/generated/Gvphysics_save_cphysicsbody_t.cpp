#include "../../../core/scripting/generated/classes/Gvphysics_save_cphysicsbody_t.h"
#include "../core.h"

void SetupLuaClassGvphysics_save_cphysicsbody_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gvphysics_save_cphysicsbody_t>("vphysics_save_cphysicsbody_t")
        .addProperty("OldPointer", &Gvphysics_save_cphysicsbody_t::GetOldPointer, &Gvphysics_save_cphysicsbody_t::SetOldPointer)
        .endClass();
}