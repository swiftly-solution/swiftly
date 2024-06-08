#include "../../../core/scripting/generated/classes/GRnMeshDesc_t.h"
#include "../core.h"

void SetupLuaClassGRnMeshDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnMeshDesc_t>("RnMeshDesc_t")
        .addProperty("Mesh", &GRnMeshDesc_t::GetMesh, &GRnMeshDesc_t::SetMesh)
        .endClass();
}