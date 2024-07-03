#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnHull_t::GRnHull_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnHull_t::GRnHull_t(void *ptr) {
    m_ptr = ptr;
}
Vector GRnHull_t::GetCentroid() const {
    return GetSchemaValue<Vector>(m_ptr, "RnHull_t", "m_vCentroid");
}
void GRnHull_t::SetCentroid(Vector value) {
    SetSchemaValue(m_ptr, "RnHull_t", "m_vCentroid", true, value);
}
float GRnHull_t::GetMaxAngularRadius() const {
    return GetSchemaValue<float>(m_ptr, "RnHull_t", "m_flMaxAngularRadius");
}
void GRnHull_t::SetMaxAngularRadius(float value) {
    SetSchemaValue(m_ptr, "RnHull_t", "m_flMaxAngularRadius", true, value);
}
GAABB_t GRnHull_t::GetBounds() const {
    GAABB_t value(GetSchemaPtr(m_ptr, "RnHull_t", "m_Bounds"));
    return value;
}
void GRnHull_t::SetBounds(GAABB_t value) {
    SetSchemaValue(m_ptr, "RnHull_t", "m_Bounds", true, value);
}
Vector GRnHull_t::GetOrthographicAreas() const {
    return GetSchemaValue<Vector>(m_ptr, "RnHull_t", "m_vOrthographicAreas");
}
void GRnHull_t::SetOrthographicAreas(Vector value) {
    SetSchemaValue(m_ptr, "RnHull_t", "m_vOrthographicAreas", true, value);
}
matrix3x4_t GRnHull_t::GetMassProperties() const {
    return GetSchemaValue<matrix3x4_t>(m_ptr, "RnHull_t", "m_MassProperties");
}
void GRnHull_t::SetMassProperties(matrix3x4_t value) {
    SetSchemaValue(m_ptr, "RnHull_t", "m_MassProperties", true, value);
}
float GRnHull_t::GetVolume() const {
    return GetSchemaValue<float>(m_ptr, "RnHull_t", "m_flVolume");
}
void GRnHull_t::SetVolume(float value) {
    SetSchemaValue(m_ptr, "RnHull_t", "m_flVolume", true, value);
}
float GRnHull_t::GetSurfaceArea() const {
    return GetSchemaValue<float>(m_ptr, "RnHull_t", "m_flSurfaceArea");
}
void GRnHull_t::SetSurfaceArea(float value) {
    SetSchemaValue(m_ptr, "RnHull_t", "m_flSurfaceArea", true, value);
}
std::vector<GRnVertex_t> GRnHull_t::GetVertices() const {
    CUtlVector<GRnVertex_t>* vec = GetSchemaValue<CUtlVector<GRnVertex_t>*>(m_ptr, "RnHull_t", "m_Vertices"); std::vector<GRnVertex_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GRnHull_t::SetVertices(std::vector<GRnVertex_t> value) {
    SetSchemaValueCUtlVector<GRnVertex_t>(m_ptr, "RnHull_t", "m_Vertices", true, value);
}
std::vector<Vector> GRnHull_t::GetVertexPositions() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "RnHull_t", "m_VertexPositions"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GRnHull_t::SetVertexPositions(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "RnHull_t", "m_VertexPositions", true, value);
}
std::vector<GRnHalfEdge_t> GRnHull_t::GetEdges() const {
    CUtlVector<GRnHalfEdge_t>* vec = GetSchemaValue<CUtlVector<GRnHalfEdge_t>*>(m_ptr, "RnHull_t", "m_Edges"); std::vector<GRnHalfEdge_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GRnHull_t::SetEdges(std::vector<GRnHalfEdge_t> value) {
    SetSchemaValueCUtlVector<GRnHalfEdge_t>(m_ptr, "RnHull_t", "m_Edges", true, value);
}
std::vector<GRnFace_t> GRnHull_t::GetFaces() const {
    CUtlVector<GRnFace_t>* vec = GetSchemaValue<CUtlVector<GRnFace_t>*>(m_ptr, "RnHull_t", "m_Faces"); std::vector<GRnFace_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GRnHull_t::SetFaces(std::vector<GRnFace_t> value) {
    SetSchemaValueCUtlVector<GRnFace_t>(m_ptr, "RnHull_t", "m_Faces", true, value);
}
std::vector<GRnPlane_t> GRnHull_t::GetFacePlanes() const {
    CUtlVector<GRnPlane_t>* vec = GetSchemaValue<CUtlVector<GRnPlane_t>*>(m_ptr, "RnHull_t", "m_FacePlanes"); std::vector<GRnPlane_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GRnHull_t::SetFacePlanes(std::vector<GRnPlane_t> value) {
    SetSchemaValueCUtlVector<GRnPlane_t>(m_ptr, "RnHull_t", "m_FacePlanes", true, value);
}
uint32_t GRnHull_t::GetFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "RnHull_t", "m_nFlags");
}
void GRnHull_t::SetFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "RnHull_t", "m_nFlags", true, value);
}
GCRegionSVM GRnHull_t::GetRegionSVM() const {
    GCRegionSVM value(*GetSchemaValuePtr<void*>(m_ptr, "RnHull_t", "m_pRegionSVM"));
    return value;
}
void GRnHull_t::SetRegionSVM(GCRegionSVM* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'RegionSVM' is not possible.\n");
}
std::string GRnHull_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnHull_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRnHull_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnHull_t>("RnHull_t")
        .addConstructor<void (*)(std::string)>()
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
        .addFunction("ToPtr", &GRnHull_t::ToPtr)
        .addFunction("IsValid", &GRnHull_t::IsValid)
        .endClass();
}