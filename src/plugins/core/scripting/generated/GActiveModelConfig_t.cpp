#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GActiveModelConfig_t::GActiveModelConfig_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GActiveModelConfig_t::GActiveModelConfig_t(void *ptr) {
    m_ptr = ptr;
}
GModelConfigHandle_t GActiveModelConfig_t::GetHandle() const {
    GModelConfigHandle_t value(GetSchemaPtr(m_ptr, "ActiveModelConfig_t", "m_Handle"));
    return value;
}
void GActiveModelConfig_t::SetHandle(GModelConfigHandle_t value) {
    SetSchemaValue(m_ptr, "ActiveModelConfig_t", "m_Handle", true, value);
}
std::string GActiveModelConfig_t::GetName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "ActiveModelConfig_t", "m_Name").String();
}
void GActiveModelConfig_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "ActiveModelConfig_t", "m_Name", true, CUtlSymbolLarge(value.c_str()));
}
std::vector<GCBaseModelEntity*> GActiveModelConfig_t::GetAssociatedEntities() const {
    CUtlVector<GCBaseModelEntity*>* vec = GetSchemaValue<CUtlVector<GCBaseModelEntity*>*>(m_ptr, "ActiveModelConfig_t", "m_AssociatedEntities"); std::vector<GCBaseModelEntity*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GActiveModelConfig_t::SetAssociatedEntities(std::vector<GCBaseModelEntity*> value) {
    SetSchemaValueCUtlVector<GCBaseModelEntity*>(m_ptr, "ActiveModelConfig_t", "m_AssociatedEntities", true, value);
}
std::vector<CUtlSymbolLarge> GActiveModelConfig_t::GetAssociatedEntityNames() const {
    CUtlVector<CUtlSymbolLarge>* vec = GetSchemaValue<CUtlVector<CUtlSymbolLarge>*>(m_ptr, "ActiveModelConfig_t", "m_AssociatedEntityNames"); std::vector<CUtlSymbolLarge> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GActiveModelConfig_t::SetAssociatedEntityNames(std::vector<CUtlSymbolLarge> value) {
    SetSchemaValueCUtlVector<CUtlSymbolLarge>(m_ptr, "ActiveModelConfig_t", "m_AssociatedEntityNames", true, value);
}
std::string GActiveModelConfig_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GActiveModelConfig_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassActiveModelConfig_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GActiveModelConfig_t>("ActiveModelConfig_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Handle", &GActiveModelConfig_t::GetHandle, &GActiveModelConfig_t::SetHandle)
        .addProperty("Name", &GActiveModelConfig_t::GetName, &GActiveModelConfig_t::SetName)
        .addProperty("AssociatedEntities", &GActiveModelConfig_t::GetAssociatedEntities, &GActiveModelConfig_t::SetAssociatedEntities)
        .addProperty("AssociatedEntityNames", &GActiveModelConfig_t::GetAssociatedEntityNames, &GActiveModelConfig_t::SetAssociatedEntityNames)
        .addFunction("ToPtr", &GActiveModelConfig_t::ToPtr)
        .addFunction("IsValid", &GActiveModelConfig_t::IsValid)
        .endClass();
}