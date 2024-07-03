#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnMesh_t::GRnMesh_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnMesh_t::GRnMesh_t(void *ptr) {
    m_ptr = ptr;
}
Vector GRnMesh_t::GetMin() const {
    return GetSchemaValue<Vector>(m_ptr, "RnMesh_t", "m_vMin");
}
void GRnMesh_t::SetMin(Vector value) {
    SetSchemaValue(m_ptr, "RnMesh_t", "m_vMin", true, value);
}
Vector GRnMesh_t::GetMax() const {
    return GetSchemaValue<Vector>(m_ptr, "RnMesh_t", "m_vMax");
}
void GRnMesh_t::SetMax(Vector value) {
    SetSchemaValue(m_ptr, "RnMesh_t", "m_vMax", true, value);
}
std::vector<GRnNode_t> GRnMesh_t::GetNodes() const {
    CUtlVector<GRnNode_t>* vec = GetSchemaValue<CUtlVector<GRnNode_t>*>(m_ptr, "RnMesh_t", "m_Nodes"); std::vector<GRnNode_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GRnMesh_t::SetNodes(std::vector<GRnNode_t> value) {
    SetSchemaValueCUtlVector<GRnNode_t>(m_ptr, "RnMesh_t", "m_Nodes", true, value);
}
std::vector<GRnTriangle_t> GRnMesh_t::GetTriangles() const {
    CUtlVector<GRnTriangle_t>* vec = GetSchemaValue<CUtlVector<GRnTriangle_t>*>(m_ptr, "RnMesh_t", "m_Triangles"); std::vector<GRnTriangle_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GRnMesh_t::SetTriangles(std::vector<GRnTriangle_t> value) {
    SetSchemaValueCUtlVector<GRnTriangle_t>(m_ptr, "RnMesh_t", "m_Triangles", true, value);
}
std::vector<GRnWing_t> GRnMesh_t::GetWings() const {
    CUtlVector<GRnWing_t>* vec = GetSchemaValue<CUtlVector<GRnWing_t>*>(m_ptr, "RnMesh_t", "m_Wings"); std::vector<GRnWing_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GRnMesh_t::SetWings(std::vector<GRnWing_t> value) {
    SetSchemaValueCUtlVector<GRnWing_t>(m_ptr, "RnMesh_t", "m_Wings", true, value);
}
std::vector<uint8> GRnMesh_t::GetMaterials() const {
    CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "RnMesh_t", "m_Materials"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GRnMesh_t::SetMaterials(std::vector<uint8> value) {
    SetSchemaValueCUtlVector<uint8>(m_ptr, "RnMesh_t", "m_Materials", true, value);
}
Vector GRnMesh_t::GetOrthographicAreas() const {
    return GetSchemaValue<Vector>(m_ptr, "RnMesh_t", "m_vOrthographicAreas");
}
void GRnMesh_t::SetOrthographicAreas(Vector value) {
    SetSchemaValue(m_ptr, "RnMesh_t", "m_vOrthographicAreas", true, value);
}
uint32_t GRnMesh_t::GetFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "RnMesh_t", "m_nFlags");
}
void GRnMesh_t::SetFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "RnMesh_t", "m_nFlags", true, value);
}
uint32_t GRnMesh_t::GetDebugFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "RnMesh_t", "m_nDebugFlags");
}
void GRnMesh_t::SetDebugFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "RnMesh_t", "m_nDebugFlags", true, value);
}
std::string GRnMesh_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnMesh_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRnMesh_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnMesh_t>("RnMesh_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Min", &GRnMesh_t::GetMin, &GRnMesh_t::SetMin)
        .addProperty("Max", &GRnMesh_t::GetMax, &GRnMesh_t::SetMax)
        .addProperty("Nodes", &GRnMesh_t::GetNodes, &GRnMesh_t::SetNodes)
        .addProperty("Triangles", &GRnMesh_t::GetTriangles, &GRnMesh_t::SetTriangles)
        .addProperty("Wings", &GRnMesh_t::GetWings, &GRnMesh_t::SetWings)
        .addProperty("Materials", &GRnMesh_t::GetMaterials, &GRnMesh_t::SetMaterials)
        .addProperty("OrthographicAreas", &GRnMesh_t::GetOrthographicAreas, &GRnMesh_t::SetOrthographicAreas)
        .addProperty("Flags", &GRnMesh_t::GetFlags, &GRnMesh_t::SetFlags)
        .addProperty("DebugFlags", &GRnMesh_t::GetDebugFlags, &GRnMesh_t::SetDebugFlags)
        .addFunction("ToPtr", &GRnMesh_t::ToPtr)
        .addFunction("IsValid", &GRnMesh_t::IsValid)
        .endClass();
}