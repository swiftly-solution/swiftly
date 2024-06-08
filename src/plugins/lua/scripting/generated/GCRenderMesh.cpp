#include "../../../core/scripting/generated/classes/GCRenderMesh.h"
#include "../core.h"

void SetupLuaClassGCRenderMesh(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRenderMesh>("CRenderMesh")
        .addProperty("Constraints", &GCRenderMesh::GetConstraints, &GCRenderMesh::SetConstraints)
        .addProperty("Skeleton", &GCRenderMesh::GetSkeleton, &GCRenderMesh::SetSkeleton)
        .addProperty("MeshDeformParams", &GCRenderMesh::GetMeshDeformParams, &GCRenderMesh::SetMeshDeformParams)
        .addProperty("GroomData", &GCRenderMesh::GetGroomData, &GCRenderMesh::SetGroomData)
        .endClass();
}