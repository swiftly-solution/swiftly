#include "../../../core/scripting/generated/classes/GFeBuildSphereRigid_t.h"
#include "../core.h"

void SetupLuaClassGFeBuildSphereRigid_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeBuildSphereRigid_t>("FeBuildSphereRigid_t")
        .addProperty("Priority", &GFeBuildSphereRigid_t::GetPriority, &GFeBuildSphereRigid_t::SetPriority)
        .addProperty("VertexMapHash", &GFeBuildSphereRigid_t::GetVertexMapHash, &GFeBuildSphereRigid_t::SetVertexMapHash)
        .endClass();
}