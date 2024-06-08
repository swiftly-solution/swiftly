#include "../../../core/scripting/generated/classes/GCVectorQuantizer.h"
#include "../core.h"

void SetupLuaClassGCVectorQuantizer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVectorQuantizer>("CVectorQuantizer")
        .addProperty("CentroidVectors", &GCVectorQuantizer::GetCentroidVectors, &GCVectorQuantizer::SetCentroidVectors)
        .addProperty("Centroids", &GCVectorQuantizer::GetCentroids, &GCVectorQuantizer::SetCentroids)
        .addProperty("Dimensions", &GCVectorQuantizer::GetDimensions, &GCVectorQuantizer::SetDimensions)
        .endClass();
}