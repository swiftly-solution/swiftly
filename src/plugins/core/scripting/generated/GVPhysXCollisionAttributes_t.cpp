#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVPhysXCollisionAttributes_t::GVPhysXCollisionAttributes_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVPhysXCollisionAttributes_t::GVPhysXCollisionAttributes_t(void *ptr) {
    m_ptr = ptr;
}
uint32_t GVPhysXCollisionAttributes_t::GetCollisionGroup() const {
    return GetSchemaValue<uint32_t>(m_ptr, "VPhysXCollisionAttributes_t", "m_CollisionGroup");
}
void GVPhysXCollisionAttributes_t::SetCollisionGroup(uint32_t value) {
    SetSchemaValue(m_ptr, "VPhysXCollisionAttributes_t", "m_CollisionGroup", true, value);
}
std::vector<uint32> GVPhysXCollisionAttributes_t::GetInteractAs() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractAs"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXCollisionAttributes_t::SetInteractAs(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractAs", true, value);
}
std::vector<uint32> GVPhysXCollisionAttributes_t::GetInteractWith() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractWith"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXCollisionAttributes_t::SetInteractWith(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractWith", true, value);
}
std::vector<uint32> GVPhysXCollisionAttributes_t::GetInteractExclude() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractExclude"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXCollisionAttributes_t::SetInteractExclude(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractExclude", true, value);
}
std::string GVPhysXCollisionAttributes_t::GetCollisionGroupString() const {
    return GetSchemaValue<CUtlString>(m_ptr, "VPhysXCollisionAttributes_t", "m_CollisionGroupString").Get();
}
void GVPhysXCollisionAttributes_t::SetCollisionGroupString(std::string value) {
    SetSchemaValue(m_ptr, "VPhysXCollisionAttributes_t", "m_CollisionGroupString", true, CUtlString(value.c_str()));
}
std::vector<CUtlString> GVPhysXCollisionAttributes_t::GetInteractAsStrings() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractAsStrings"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXCollisionAttributes_t::SetInteractAsStrings(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractAsStrings", true, value);
}
std::vector<CUtlString> GVPhysXCollisionAttributes_t::GetInteractWithStrings() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractWithStrings"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXCollisionAttributes_t::SetInteractWithStrings(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractWithStrings", true, value);
}
std::vector<CUtlString> GVPhysXCollisionAttributes_t::GetInteractExcludeStrings() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractExcludeStrings"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GVPhysXCollisionAttributes_t::SetInteractExcludeStrings(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "VPhysXCollisionAttributes_t", "m_InteractExcludeStrings", true, value);
}
std::string GVPhysXCollisionAttributes_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVPhysXCollisionAttributes_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVPhysXCollisionAttributes_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVPhysXCollisionAttributes_t>("VPhysXCollisionAttributes_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CollisionGroup", &GVPhysXCollisionAttributes_t::GetCollisionGroup, &GVPhysXCollisionAttributes_t::SetCollisionGroup)
        .addProperty("InteractAs", &GVPhysXCollisionAttributes_t::GetInteractAs, &GVPhysXCollisionAttributes_t::SetInteractAs)
        .addProperty("InteractWith", &GVPhysXCollisionAttributes_t::GetInteractWith, &GVPhysXCollisionAttributes_t::SetInteractWith)
        .addProperty("InteractExclude", &GVPhysXCollisionAttributes_t::GetInteractExclude, &GVPhysXCollisionAttributes_t::SetInteractExclude)
        .addProperty("CollisionGroupString", &GVPhysXCollisionAttributes_t::GetCollisionGroupString, &GVPhysXCollisionAttributes_t::SetCollisionGroupString)
        .addProperty("InteractAsStrings", &GVPhysXCollisionAttributes_t::GetInteractAsStrings, &GVPhysXCollisionAttributes_t::SetInteractAsStrings)
        .addProperty("InteractWithStrings", &GVPhysXCollisionAttributes_t::GetInteractWithStrings, &GVPhysXCollisionAttributes_t::SetInteractWithStrings)
        .addProperty("InteractExcludeStrings", &GVPhysXCollisionAttributes_t::GetInteractExcludeStrings, &GVPhysXCollisionAttributes_t::SetInteractExcludeStrings)
        .addFunction("ToPtr", &GVPhysXCollisionAttributes_t::ToPtr)
        .addFunction("IsValid", &GVPhysXCollisionAttributes_t::IsValid)
        .endClass();
}