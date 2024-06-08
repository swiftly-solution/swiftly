#include "../../../core/scripting/generated/classes/GFeBuildTaperedCapsuleRigid_t.h"
#include "../core.h"

void SetupLuaClassGFeBuildTaperedCapsuleRigid_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeBuildTaperedCapsuleRigid_t>("FeBuildTaperedCapsuleRigid_t")
        .addProperty("Priority", &GFeBuildTaperedCapsuleRigid_t::GetPriority, &GFeBuildTaperedCapsuleRigid_t::SetPriority)
        .addProperty("VertexMapHash", &GFeBuildTaperedCapsuleRigid_t::GetVertexMapHash, &GFeBuildTaperedCapsuleRigid_t::SetVertexMapHash)
        .endClass();
}