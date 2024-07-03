#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRenderMesh::GCRenderMesh(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRenderMesh::GCRenderMesh(void *ptr) {
    m_ptr = ptr;
}
std::vector<GCBaseConstraint*> GCRenderMesh::GetConstraints() const {
    CUtlVector<GCBaseConstraint*>* vec = GetSchemaValue<CUtlVector<GCBaseConstraint*>*>(m_ptr, "CRenderMesh", "m_constraints"); std::vector<GCBaseConstraint*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCRenderMesh::SetConstraints(std::vector<GCBaseConstraint*> value) {
    SetSchemaValueCUtlVector<GCBaseConstraint*>(m_ptr, "CRenderMesh", "m_constraints", false, value);
}
GCRenderSkeleton GCRenderMesh::GetSkeleton() const {
    GCRenderSkeleton value(GetSchemaPtr(m_ptr, "CRenderMesh", "m_skeleton"));
    return value;
}
void GCRenderMesh::SetSkeleton(GCRenderSkeleton value) {
    SetSchemaValue(m_ptr, "CRenderMesh", "m_skeleton", false, value);
}
GDynamicMeshDeformParams_t GCRenderMesh::GetMeshDeformParams() const {
    GDynamicMeshDeformParams_t value(GetSchemaPtr(m_ptr, "CRenderMesh", "m_meshDeformParams"));
    return value;
}
void GCRenderMesh::SetMeshDeformParams(GDynamicMeshDeformParams_t value) {
    SetSchemaValue(m_ptr, "CRenderMesh", "m_meshDeformParams", false, value);
}
GCRenderGroom GCRenderMesh::GetGroomData() const {
    GCRenderGroom value(*GetSchemaValuePtr<void*>(m_ptr, "CRenderMesh", "m_pGroomData"));
    return value;
}
void GCRenderMesh::SetGroomData(GCRenderGroom* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'GroomData' is not possible.\n");
}
std::string GCRenderMesh::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRenderMesh::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCRenderMesh(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRenderMesh>("CRenderMesh")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Constraints", &GCRenderMesh::GetConstraints, &GCRenderMesh::SetConstraints)
        .addProperty("Skeleton", &GCRenderMesh::GetSkeleton, &GCRenderMesh::SetSkeleton)
        .addProperty("MeshDeformParams", &GCRenderMesh::GetMeshDeformParams, &GCRenderMesh::SetMeshDeformParams)
        .addProperty("GroomData", &GCRenderMesh::GetGroomData, &GCRenderMesh::SetGroomData)
        .addFunction("ToPtr", &GCRenderMesh::ToPtr)
        .addFunction("IsValid", &GCRenderMesh::IsValid)
        .endClass();
}