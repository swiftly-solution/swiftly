#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCopyRecipientFilter::GCCopyRecipientFilter(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCopyRecipientFilter::GCCopyRecipientFilter(void *ptr) {
    m_ptr = ptr;
}
int32_t GCCopyRecipientFilter::GetFlags() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCopyRecipientFilter", "m_Flags");
}
void GCCopyRecipientFilter::SetFlags(int32_t value) {
    SetSchemaValue(m_ptr, "CCopyRecipientFilter", "m_Flags", false, value);
}
std::vector<int32_t> GCCopyRecipientFilter::GetRecipients() const {
    CUtlVector<int32_t>* vec = GetSchemaValue<CUtlVector<int32_t>*>(m_ptr, "CCopyRecipientFilter", "m_Recipients"); std::vector<int32_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCCopyRecipientFilter::SetRecipients(std::vector<int32_t> value) {
    SetSchemaValueCUtlVector<int32_t>(m_ptr, "CCopyRecipientFilter", "m_Recipients", false, value);
}
std::string GCCopyRecipientFilter::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCopyRecipientFilter::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCCopyRecipientFilter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCopyRecipientFilter>("CCopyRecipientFilter")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Flags", &GCCopyRecipientFilter::GetFlags, &GCCopyRecipientFilter::SetFlags)
        .addProperty("Recipients", &GCCopyRecipientFilter::GetRecipients, &GCCopyRecipientFilter::SetRecipients)
        .addFunction("ToPtr", &GCCopyRecipientFilter::ToPtr)
        .addFunction("IsValid", &GCCopyRecipientFilter::IsValid)
        .endClass();
}