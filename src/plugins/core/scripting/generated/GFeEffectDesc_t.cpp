#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeEffectDesc_t::GFeEffectDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeEffectDesc_t::GFeEffectDesc_t(void *ptr) {
    m_ptr = ptr;
}
std::string GFeEffectDesc_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "FeEffectDesc_t", "sName").Get();
}
void GFeEffectDesc_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "FeEffectDesc_t", "sName", true, CUtlString(value.c_str()));
}
uint32_t GFeEffectDesc_t::GetNameHash() const {
    return GetSchemaValue<uint32_t>(m_ptr, "FeEffectDesc_t", "nNameHash");
}
void GFeEffectDesc_t::SetNameHash(uint32_t value) {
    SetSchemaValue(m_ptr, "FeEffectDesc_t", "nNameHash", true, value);
}
int32_t GFeEffectDesc_t::GetType() const {
    return GetSchemaValue<int32_t>(m_ptr, "FeEffectDesc_t", "nType");
}
void GFeEffectDesc_t::SetType(int32_t value) {
    SetSchemaValue(m_ptr, "FeEffectDesc_t", "nType", true, value);
}
std::string GFeEffectDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeEffectDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeEffectDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeEffectDesc_t>("FeEffectDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GFeEffectDesc_t::GetName, &GFeEffectDesc_t::SetName)
        .addProperty("NameHash", &GFeEffectDesc_t::GetNameHash, &GFeEffectDesc_t::SetNameHash)
        .addProperty("Type", &GFeEffectDesc_t::GetType, &GFeEffectDesc_t::SetType)
        .addFunction("ToPtr", &GFeEffectDesc_t::ToPtr)
        .addFunction("IsValid", &GFeEffectDesc_t::IsValid)
        .endClass();
}