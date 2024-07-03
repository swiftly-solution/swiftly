#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDirectPlaybackTagData::GCDirectPlaybackTagData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDirectPlaybackTagData::GCDirectPlaybackTagData(void *ptr) {
    m_ptr = ptr;
}
std::string GCDirectPlaybackTagData::GetSequenceName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CDirectPlaybackTagData", "m_sequenceName").Get();
}
void GCDirectPlaybackTagData::SetSequenceName(std::string value) {
    SetSchemaValue(m_ptr, "CDirectPlaybackTagData", "m_sequenceName", false, CUtlString(value.c_str()));
}
std::vector<GTagSpan_t> GCDirectPlaybackTagData::GetTags() const {
    CUtlVector<GTagSpan_t>* vec = GetSchemaValue<CUtlVector<GTagSpan_t>*>(m_ptr, "CDirectPlaybackTagData", "m_tags"); std::vector<GTagSpan_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCDirectPlaybackTagData::SetTags(std::vector<GTagSpan_t> value) {
    SetSchemaValueCUtlVector<GTagSpan_t>(m_ptr, "CDirectPlaybackTagData", "m_tags", false, value);
}
std::string GCDirectPlaybackTagData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDirectPlaybackTagData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCDirectPlaybackTagData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDirectPlaybackTagData>("CDirectPlaybackTagData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SequenceName", &GCDirectPlaybackTagData::GetSequenceName, &GCDirectPlaybackTagData::SetSequenceName)
        .addProperty("Tags", &GCDirectPlaybackTagData::GetTags, &GCDirectPlaybackTagData::SetTags)
        .addFunction("ToPtr", &GCDirectPlaybackTagData::ToPtr)
        .addFunction("IsValid", &GCDirectPlaybackTagData::IsValid)
        .endClass();
}