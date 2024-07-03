#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GParticlePreviewBodyGroup_t::GParticlePreviewBodyGroup_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GParticlePreviewBodyGroup_t::GParticlePreviewBodyGroup_t(void *ptr) {
    m_ptr = ptr;
}
std::string GParticlePreviewBodyGroup_t::GetBodyGroupName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ParticlePreviewBodyGroup_t", "m_bodyGroupName").Get();
}
void GParticlePreviewBodyGroup_t::SetBodyGroupName(std::string value) {
    SetSchemaValue(m_ptr, "ParticlePreviewBodyGroup_t", "m_bodyGroupName", true, CUtlString(value.c_str()));
}
int32_t GParticlePreviewBodyGroup_t::GetValue() const {
    return GetSchemaValue<int32_t>(m_ptr, "ParticlePreviewBodyGroup_t", "m_nValue");
}
void GParticlePreviewBodyGroup_t::SetValue(int32_t value) {
    SetSchemaValue(m_ptr, "ParticlePreviewBodyGroup_t", "m_nValue", true, value);
}
std::string GParticlePreviewBodyGroup_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GParticlePreviewBodyGroup_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassParticlePreviewBodyGroup_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticlePreviewBodyGroup_t>("ParticlePreviewBodyGroup_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BodyGroupName", &GParticlePreviewBodyGroup_t::GetBodyGroupName, &GParticlePreviewBodyGroup_t::SetBodyGroupName)
        .addProperty("Value", &GParticlePreviewBodyGroup_t::GetValue, &GParticlePreviewBodyGroup_t::SetValue)
        .addFunction("ToPtr", &GParticlePreviewBodyGroup_t::ToPtr)
        .addFunction("IsValid", &GParticlePreviewBodyGroup_t::IsValid)
        .endClass();
}