#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCompositeMaterialMatchFilter_t::GCompositeMaterialMatchFilter_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCompositeMaterialMatchFilter_t::GCompositeMaterialMatchFilter_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCompositeMaterialMatchFilter_t::GetCompositeMaterialMatchFilterType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CompositeMaterialMatchFilter_t", "m_nCompositeMaterialMatchFilterType");
}
void GCompositeMaterialMatchFilter_t::SetCompositeMaterialMatchFilterType(uint64_t value) {
    SetSchemaValue(m_ptr, "CompositeMaterialMatchFilter_t", "m_nCompositeMaterialMatchFilterType", true, value);
}
std::string GCompositeMaterialMatchFilter_t::GetStrMatchFilter() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialMatchFilter_t", "m_strMatchFilter").Get();
}
void GCompositeMaterialMatchFilter_t::SetStrMatchFilter(std::string value) {
    SetSchemaValue(m_ptr, "CompositeMaterialMatchFilter_t", "m_strMatchFilter", true, CUtlString(value.c_str()));
}
std::string GCompositeMaterialMatchFilter_t::GetStrMatchValue() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CompositeMaterialMatchFilter_t", "m_strMatchValue").Get();
}
void GCompositeMaterialMatchFilter_t::SetStrMatchValue(std::string value) {
    SetSchemaValue(m_ptr, "CompositeMaterialMatchFilter_t", "m_strMatchValue", true, CUtlString(value.c_str()));
}
bool GCompositeMaterialMatchFilter_t::GetPassWhenTrue() const {
    return GetSchemaValue<bool>(m_ptr, "CompositeMaterialMatchFilter_t", "m_bPassWhenTrue");
}
void GCompositeMaterialMatchFilter_t::SetPassWhenTrue(bool value) {
    SetSchemaValue(m_ptr, "CompositeMaterialMatchFilter_t", "m_bPassWhenTrue", true, value);
}
std::string GCompositeMaterialMatchFilter_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCompositeMaterialMatchFilter_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCompositeMaterialMatchFilter_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCompositeMaterialMatchFilter_t>("CompositeMaterialMatchFilter_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CompositeMaterialMatchFilterType", &GCompositeMaterialMatchFilter_t::GetCompositeMaterialMatchFilterType, &GCompositeMaterialMatchFilter_t::SetCompositeMaterialMatchFilterType)
        .addProperty("StrMatchFilter", &GCompositeMaterialMatchFilter_t::GetStrMatchFilter, &GCompositeMaterialMatchFilter_t::SetStrMatchFilter)
        .addProperty("StrMatchValue", &GCompositeMaterialMatchFilter_t::GetStrMatchValue, &GCompositeMaterialMatchFilter_t::SetStrMatchValue)
        .addProperty("PassWhenTrue", &GCompositeMaterialMatchFilter_t::GetPassWhenTrue, &GCompositeMaterialMatchFilter_t::SetPassWhenTrue)
        .addFunction("ToPtr", &GCompositeMaterialMatchFilter_t::ToPtr)
        .addFunction("IsValid", &GCompositeMaterialMatchFilter_t::IsValid)
        .endClass();
}