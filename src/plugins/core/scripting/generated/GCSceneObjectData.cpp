#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSceneObjectData::GCSceneObjectData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSceneObjectData::GCSceneObjectData(void *ptr) {
    m_ptr = ptr;
}
Vector GCSceneObjectData::GetMinBounds() const {
    return GetSchemaValue<Vector>(m_ptr, "CSceneObjectData", "m_vMinBounds");
}
void GCSceneObjectData::SetMinBounds(Vector value) {
    SetSchemaValue(m_ptr, "CSceneObjectData", "m_vMinBounds", false, value);
}
Vector GCSceneObjectData::GetMaxBounds() const {
    return GetSchemaValue<Vector>(m_ptr, "CSceneObjectData", "m_vMaxBounds");
}
void GCSceneObjectData::SetMaxBounds(Vector value) {
    SetSchemaValue(m_ptr, "CSceneObjectData", "m_vMaxBounds", false, value);
}
std::vector<GCMaterialDrawDescriptor> GCSceneObjectData::GetDrawCalls() const {
    CUtlVector<GCMaterialDrawDescriptor>* vec = GetSchemaValue<CUtlVector<GCMaterialDrawDescriptor>*>(m_ptr, "CSceneObjectData", "m_drawCalls"); std::vector<GCMaterialDrawDescriptor> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSceneObjectData::SetDrawCalls(std::vector<GCMaterialDrawDescriptor> value) {
    SetSchemaValueCUtlVector<GCMaterialDrawDescriptor>(m_ptr, "CSceneObjectData", "m_drawCalls", false, value);
}
std::vector<GAABB_t> GCSceneObjectData::GetDrawBounds() const {
    CUtlVector<GAABB_t>* vec = GetSchemaValue<CUtlVector<GAABB_t>*>(m_ptr, "CSceneObjectData", "m_drawBounds"); std::vector<GAABB_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSceneObjectData::SetDrawBounds(std::vector<GAABB_t> value) {
    SetSchemaValueCUtlVector<GAABB_t>(m_ptr, "CSceneObjectData", "m_drawBounds", false, value);
}
std::vector<GCMeshletDescriptor> GCSceneObjectData::GetMeshlets() const {
    CUtlVector<GCMeshletDescriptor>* vec = GetSchemaValue<CUtlVector<GCMeshletDescriptor>*>(m_ptr, "CSceneObjectData", "m_meshlets"); std::vector<GCMeshletDescriptor> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSceneObjectData::SetMeshlets(std::vector<GCMeshletDescriptor> value) {
    SetSchemaValueCUtlVector<GCMeshletDescriptor>(m_ptr, "CSceneObjectData", "m_meshlets", false, value);
}
Vector4D GCSceneObjectData::GetTintColor() const {
    return GetSchemaValue<Vector4D>(m_ptr, "CSceneObjectData", "m_vTintColor");
}
void GCSceneObjectData::SetTintColor(Vector4D value) {
    SetSchemaValue(m_ptr, "CSceneObjectData", "m_vTintColor", false, value);
}
std::string GCSceneObjectData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSceneObjectData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSceneObjectData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSceneObjectData>("CSceneObjectData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MinBounds", &GCSceneObjectData::GetMinBounds, &GCSceneObjectData::SetMinBounds)
        .addProperty("MaxBounds", &GCSceneObjectData::GetMaxBounds, &GCSceneObjectData::SetMaxBounds)
        .addProperty("DrawCalls", &GCSceneObjectData::GetDrawCalls, &GCSceneObjectData::SetDrawCalls)
        .addProperty("DrawBounds", &GCSceneObjectData::GetDrawBounds, &GCSceneObjectData::SetDrawBounds)
        .addProperty("Meshlets", &GCSceneObjectData::GetMeshlets, &GCSceneObjectData::SetMeshlets)
        .addProperty("TintColor", &GCSceneObjectData::GetTintColor, &GCSceneObjectData::SetTintColor)
        .addFunction("ToPtr", &GCSceneObjectData::ToPtr)
        .addFunction("IsValid", &GCSceneObjectData::IsValid)
        .endClass();
}