#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmGraphDefinition::GCNmGraphDefinition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmGraphDefinition::GCNmGraphDefinition(void *ptr) {
    m_ptr = ptr;
}
std::vector<int16> GCNmGraphDefinition::GetPersistentNodeIndices() const {
    CUtlVector<int16>* vec = GetSchemaValue<CUtlVector<int16>*>(m_ptr, "CNmGraphDefinition", "m_persistentNodeIndices"); std::vector<int16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCNmGraphDefinition::SetPersistentNodeIndices(std::vector<int16> value) {
    SetSchemaValueCUtlVector<int16>(m_ptr, "CNmGraphDefinition", "m_persistentNodeIndices", false, value);
}
int16_t GCNmGraphDefinition::GetRootNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmGraphDefinition", "m_nRootNodeIdx");
}
void GCNmGraphDefinition::SetRootNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmGraphDefinition", "m_nRootNodeIdx", false, value);
}
std::vector<int16> GCNmGraphDefinition::GetVirtualParameterNodeIndices() const {
    CUtlVector<int16>* vec = GetSchemaValue<CUtlVector<int16>*>(m_ptr, "CNmGraphDefinition", "m_virtualParameterNodeIndices"); std::vector<int16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCNmGraphDefinition::SetVirtualParameterNodeIndices(std::vector<int16> value) {
    SetSchemaValueCUtlVector<int16>(m_ptr, "CNmGraphDefinition", "m_virtualParameterNodeIndices", false, value);
}
std::vector<GCNmGraphDefinition> GCNmGraphDefinition::GetChildGraphSlots() const {
    CUtlVector<GCNmGraphDefinition>* vec = GetSchemaValue<CUtlVector<GCNmGraphDefinition>*>(m_ptr, "CNmGraphDefinition", "m_childGraphSlots"); std::vector<GCNmGraphDefinition> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCNmGraphDefinition::SetChildGraphSlots(std::vector<GCNmGraphDefinition> value) {
    SetSchemaValueCUtlVector<GCNmGraphDefinition>(m_ptr, "CNmGraphDefinition", "m_childGraphSlots", false, value);
}
std::vector<GCNmGraphDefinition> GCNmGraphDefinition::GetExternalGraphSlots() const {
    CUtlVector<GCNmGraphDefinition>* vec = GetSchemaValue<CUtlVector<GCNmGraphDefinition>*>(m_ptr, "CNmGraphDefinition", "m_externalGraphSlots"); std::vector<GCNmGraphDefinition> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCNmGraphDefinition::SetExternalGraphSlots(std::vector<GCNmGraphDefinition> value) {
    SetSchemaValueCUtlVector<GCNmGraphDefinition>(m_ptr, "CNmGraphDefinition", "m_externalGraphSlots", false, value);
}
std::string GCNmGraphDefinition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmGraphDefinition::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmGraphDefinition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmGraphDefinition>("CNmGraphDefinition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PersistentNodeIndices", &GCNmGraphDefinition::GetPersistentNodeIndices, &GCNmGraphDefinition::SetPersistentNodeIndices)
        .addProperty("RootNodeIdx", &GCNmGraphDefinition::GetRootNodeIdx, &GCNmGraphDefinition::SetRootNodeIdx)
        .addProperty("VirtualParameterNodeIndices", &GCNmGraphDefinition::GetVirtualParameterNodeIndices, &GCNmGraphDefinition::SetVirtualParameterNodeIndices)
        .addProperty("ChildGraphSlots", &GCNmGraphDefinition::GetChildGraphSlots, &GCNmGraphDefinition::SetChildGraphSlots)
        .addProperty("ExternalGraphSlots", &GCNmGraphDefinition::GetExternalGraphSlots, &GCNmGraphDefinition::SetExternalGraphSlots)
        .addFunction("ToPtr", &GCNmGraphDefinition::ToPtr)
        .addFunction("IsValid", &GCNmGraphDefinition::IsValid)
        .endClass();
}