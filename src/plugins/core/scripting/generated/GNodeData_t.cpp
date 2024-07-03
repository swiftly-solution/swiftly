#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GNodeData_t::GNodeData_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GNodeData_t::GNodeData_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GNodeData_t::GetParent() const {
    return GetSchemaValue<int32_t>(m_ptr, "NodeData_t", "m_nParent");
}
void GNodeData_t::SetParent(int32_t value) {
    SetSchemaValue(m_ptr, "NodeData_t", "m_nParent", true, value);
}
Vector GNodeData_t::GetOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "NodeData_t", "m_vOrigin");
}
void GNodeData_t::SetOrigin(Vector value) {
    SetSchemaValue(m_ptr, "NodeData_t", "m_vOrigin", true, value);
}
Vector GNodeData_t::GetMinBounds() const {
    return GetSchemaValue<Vector>(m_ptr, "NodeData_t", "m_vMinBounds");
}
void GNodeData_t::SetMinBounds(Vector value) {
    SetSchemaValue(m_ptr, "NodeData_t", "m_vMinBounds", true, value);
}
Vector GNodeData_t::GetMaxBounds() const {
    return GetSchemaValue<Vector>(m_ptr, "NodeData_t", "m_vMaxBounds");
}
void GNodeData_t::SetMaxBounds(Vector value) {
    SetSchemaValue(m_ptr, "NodeData_t", "m_vMaxBounds", true, value);
}
float GNodeData_t::GetMinimumDistance() const {
    return GetSchemaValue<float>(m_ptr, "NodeData_t", "m_flMinimumDistance");
}
void GNodeData_t::SetMinimumDistance(float value) {
    SetSchemaValue(m_ptr, "NodeData_t", "m_flMinimumDistance", true, value);
}
std::vector<int32> GNodeData_t::GetChildNodeIndices() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "NodeData_t", "m_ChildNodeIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GNodeData_t::SetChildNodeIndices(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "NodeData_t", "m_ChildNodeIndices", true, value);
}
std::string GNodeData_t::GetWorldNodePrefix() const {
    return GetSchemaValue<CUtlString>(m_ptr, "NodeData_t", "m_worldNodePrefix").Get();
}
void GNodeData_t::SetWorldNodePrefix(std::string value) {
    SetSchemaValue(m_ptr, "NodeData_t", "m_worldNodePrefix", true, CUtlString(value.c_str()));
}
std::string GNodeData_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GNodeData_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassNodeData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GNodeData_t>("NodeData_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GNodeData_t::GetParent, &GNodeData_t::SetParent)
        .addProperty("Origin", &GNodeData_t::GetOrigin, &GNodeData_t::SetOrigin)
        .addProperty("MinBounds", &GNodeData_t::GetMinBounds, &GNodeData_t::SetMinBounds)
        .addProperty("MaxBounds", &GNodeData_t::GetMaxBounds, &GNodeData_t::SetMaxBounds)
        .addProperty("MinimumDistance", &GNodeData_t::GetMinimumDistance, &GNodeData_t::SetMinimumDistance)
        .addProperty("ChildNodeIndices", &GNodeData_t::GetChildNodeIndices, &GNodeData_t::SetChildNodeIndices)
        .addProperty("WorldNodePrefix", &GNodeData_t::GetWorldNodePrefix, &GNodeData_t::SetWorldNodePrefix)
        .addFunction("ToPtr", &GNodeData_t::ToPtr)
        .addFunction("IsValid", &GNodeData_t::IsValid)
        .endClass();
}