#include "../../../core/scripting/generated/classes/GRnMesh_t.h"
#include "../core.h"

void SetupLuaClassGRnMesh_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnMesh_t>("RnMesh_t")
        .addProperty("Min", &GRnMesh_t::GetMin, &GRnMesh_t::SetMin)
        .addProperty("Max", &GRnMesh_t::GetMax, &GRnMesh_t::SetMax)
        .addProperty("Nodes", &GRnMesh_t::GetNodes, &GRnMesh_t::SetNodes)
        .addProperty("Triangles", &GRnMesh_t::GetTriangles, &GRnMesh_t::SetTriangles)
        .addProperty("Wings", &GRnMesh_t::GetWings, &GRnMesh_t::SetWings)
        .addProperty("Materials", &GRnMesh_t::GetMaterials, &GRnMesh_t::SetMaterials)
        .addProperty("OrthographicAreas", &GRnMesh_t::GetOrthographicAreas, &GRnMesh_t::SetOrthographicAreas)
        .addProperty("Flags", &GRnMesh_t::GetFlags, &GRnMesh_t::SetFlags)
        .addProperty("DebugFlags", &GRnMesh_t::GetDebugFlags, &GRnMesh_t::SetDebugFlags)
        .endClass();
}