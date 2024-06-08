#include "../../../core/scripting/generated/classes/GRnHull_t.h"
#include "../core.h"

void SetupLuaClassGRnHull_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnHull_t>("RnHull_t")
        .addProperty("Centroid", &GRnHull_t::GetCentroid, &GRnHull_t::SetCentroid)
        .addProperty("MaxAngularRadius", &GRnHull_t::GetMaxAngularRadius, &GRnHull_t::SetMaxAngularRadius)
        .addProperty("Bounds", &GRnHull_t::GetBounds, &GRnHull_t::SetBounds)
        .addProperty("OrthographicAreas", &GRnHull_t::GetOrthographicAreas, &GRnHull_t::SetOrthographicAreas)
        .addProperty("MassProperties", &GRnHull_t::GetMassProperties, &GRnHull_t::SetMassProperties)
        .addProperty("Volume", &GRnHull_t::GetVolume, &GRnHull_t::SetVolume)
        .addProperty("SurfaceArea", &GRnHull_t::GetSurfaceArea, &GRnHull_t::SetSurfaceArea)
        .addProperty("Vertices", &GRnHull_t::GetVertices, &GRnHull_t::SetVertices)
        .addProperty("VertexPositions", &GRnHull_t::GetVertexPositions, &GRnHull_t::SetVertexPositions)
        .addProperty("Edges", &GRnHull_t::GetEdges, &GRnHull_t::SetEdges)
        .addProperty("Faces", &GRnHull_t::GetFaces, &GRnHull_t::SetFaces)
        .addProperty("FacePlanes", &GRnHull_t::GetFacePlanes, &GRnHull_t::SetFacePlanes)
        .addProperty("Flags", &GRnHull_t::GetFlags, &GRnHull_t::SetFlags)
        .addProperty("RegionSVM", &GRnHull_t::GetRegionSVM, &GRnHull_t::SetRegionSVM)
        .endClass();
}