#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVPhysics2ShapeDef_t::GVPhysics2ShapeDef_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVPhysics2ShapeDef_t::GVPhysics2ShapeDef_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<GRnSphereDesc_t> GVPhysics2ShapeDef_t::GetSpheres() const {
    CUtlVector<GRnSphereDesc_t>* vec = GetSchemaValue<CUtlVector<GRnSphereDesc_t>*>(m_ptr, "VPhysics2ShapeDef_t", "m_spheres"); std::vector<GRnSphereDesc_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysics2ShapeDef_t::SetSpheres(std::vector<GRnSphereDesc_t> value) {
    SetSchemaValueCUtlVector<GRnSphereDesc_t>(m_ptr, "VPhysics2ShapeDef_t", "m_spheres", true, value);
}
std::vector<GRnCapsuleDesc_t> GVPhysics2ShapeDef_t::GetCapsules() const {
    CUtlVector<GRnCapsuleDesc_t>* vec = GetSchemaValue<CUtlVector<GRnCapsuleDesc_t>*>(m_ptr, "VPhysics2ShapeDef_t", "m_capsules"); std::vector<GRnCapsuleDesc_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysics2ShapeDef_t::SetCapsules(std::vector<GRnCapsuleDesc_t> value) {
    SetSchemaValueCUtlVector<GRnCapsuleDesc_t>(m_ptr, "VPhysics2ShapeDef_t", "m_capsules", true, value);
}
std::vector<GRnHullDesc_t> GVPhysics2ShapeDef_t::GetHulls() const {
    CUtlVector<GRnHullDesc_t>* vec = GetSchemaValue<CUtlVector<GRnHullDesc_t>*>(m_ptr, "VPhysics2ShapeDef_t", "m_hulls"); std::vector<GRnHullDesc_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysics2ShapeDef_t::SetHulls(std::vector<GRnHullDesc_t> value) {
    SetSchemaValueCUtlVector<GRnHullDesc_t>(m_ptr, "VPhysics2ShapeDef_t", "m_hulls", true, value);
}
std::vector<GRnMeshDesc_t> GVPhysics2ShapeDef_t::GetMeshes() const {
    CUtlVector<GRnMeshDesc_t>* vec = GetSchemaValue<CUtlVector<GRnMeshDesc_t>*>(m_ptr, "VPhysics2ShapeDef_t", "m_meshes"); std::vector<GRnMeshDesc_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysics2ShapeDef_t::SetMeshes(std::vector<GRnMeshDesc_t> value) {
    SetSchemaValueCUtlVector<GRnMeshDesc_t>(m_ptr, "VPhysics2ShapeDef_t", "m_meshes", true, value);
}
std::vector<uint16> GVPhysics2ShapeDef_t::GetCollisionAttributeIndices() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "VPhysics2ShapeDef_t", "m_CollisionAttributeIndices"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysics2ShapeDef_t::SetCollisionAttributeIndices(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "VPhysics2ShapeDef_t", "m_CollisionAttributeIndices", true, value);
}
std::string GVPhysics2ShapeDef_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVPhysics2ShapeDef_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVPhysics2ShapeDef_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVPhysics2ShapeDef_t>("VPhysics2ShapeDef_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Spheres", &GVPhysics2ShapeDef_t::GetSpheres, &GVPhysics2ShapeDef_t::SetSpheres)
        .addProperty("Capsules", &GVPhysics2ShapeDef_t::GetCapsules, &GVPhysics2ShapeDef_t::SetCapsules)
        .addProperty("Hulls", &GVPhysics2ShapeDef_t::GetHulls, &GVPhysics2ShapeDef_t::SetHulls)
        .addProperty("Meshes", &GVPhysics2ShapeDef_t::GetMeshes, &GVPhysics2ShapeDef_t::SetMeshes)
        .addProperty("CollisionAttributeIndices", &GVPhysics2ShapeDef_t::GetCollisionAttributeIndices, &GVPhysics2ShapeDef_t::SetCollisionAttributeIndices)
        .addFunction("ToPtr", &GVPhysics2ShapeDef_t::ToPtr)
        .addFunction("IsValid", &GVPhysics2ShapeDef_t::IsValid)
        .endClass();
}