#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFootStepTrigger::GFootStepTrigger(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFootStepTrigger::GFootStepTrigger(void *ptr) {
    m_ptr = ptr;
}
std::vector<int32> GFootStepTrigger::GetTags() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "FootStepTrigger", "m_tags"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GFootStepTrigger::SetTags(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "FootStepTrigger", "m_tags", false, value);
}
int32_t GFootStepTrigger::GetFootIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "FootStepTrigger", "m_nFootIndex");
}
void GFootStepTrigger::SetFootIndex(int32_t value) {
    SetSchemaValue(m_ptr, "FootStepTrigger", "m_nFootIndex", false, value);
}
uint64_t GFootStepTrigger::GetTriggerPhase() const {
    return GetSchemaValue<uint64_t>(m_ptr, "FootStepTrigger", "m_triggerPhase");
}
void GFootStepTrigger::SetTriggerPhase(uint64_t value) {
    SetSchemaValue(m_ptr, "FootStepTrigger", "m_triggerPhase", false, value);
}
std::string GFootStepTrigger::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFootStepTrigger::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFootStepTrigger(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFootStepTrigger>("FootStepTrigger")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Tags", &GFootStepTrigger::GetTags, &GFootStepTrigger::SetTags)
        .addProperty("FootIndex", &GFootStepTrigger::GetFootIndex, &GFootStepTrigger::SetFootIndex)
        .addProperty("TriggerPhase", &GFootStepTrigger::GetTriggerPhase, &GFootStepTrigger::SetTriggerPhase)
        .addFunction("ToPtr", &GFootStepTrigger::ToPtr)
        .addFunction("IsValid", &GFootStepTrigger::IsValid)
        .endClass();
}