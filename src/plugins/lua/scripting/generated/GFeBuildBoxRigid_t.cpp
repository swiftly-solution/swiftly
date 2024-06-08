#include "../../../core/scripting/generated/classes/GFeBuildBoxRigid_t.h"
#include "../core.h"

void SetupLuaClassGFeBuildBoxRigid_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeBuildBoxRigid_t>("FeBuildBoxRigid_t")
        .addProperty("Priority", &GFeBuildBoxRigid_t::GetPriority, &GFeBuildBoxRigid_t::SetPriority)
        .addProperty("VertexMapHash", &GFeBuildBoxRigid_t::GetVertexMapHash, &GFeBuildBoxRigid_t::SetVertexMapHash)
        .endClass();
}