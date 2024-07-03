#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GParticleChildrenInfo_t::GParticleChildrenInfo_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GParticleChildrenInfo_t::GParticleChildrenInfo_t(void *ptr) {
    m_ptr = ptr;
}
float GParticleChildrenInfo_t::GetDelay() const {
    return GetSchemaValue<float>(m_ptr, "ParticleChildrenInfo_t", "m_flDelay");
}
void GParticleChildrenInfo_t::SetDelay(float value) {
    SetSchemaValue(m_ptr, "ParticleChildrenInfo_t", "m_flDelay", true, value);
}
bool GParticleChildrenInfo_t::GetEndCap() const {
    return GetSchemaValue<bool>(m_ptr, "ParticleChildrenInfo_t", "m_bEndCap");
}
void GParticleChildrenInfo_t::SetEndCap(bool value) {
    SetSchemaValue(m_ptr, "ParticleChildrenInfo_t", "m_bEndCap", true, value);
}
bool GParticleChildrenInfo_t::GetDisableChild() const {
    return GetSchemaValue<bool>(m_ptr, "ParticleChildrenInfo_t", "m_bDisableChild");
}
void GParticleChildrenInfo_t::SetDisableChild(bool value) {
    SetSchemaValue(m_ptr, "ParticleChildrenInfo_t", "m_bDisableChild", true, value);
}
uint64_t GParticleChildrenInfo_t::GetDetailLevel() const {
    return GetSchemaValue<uint64_t>(m_ptr, "ParticleChildrenInfo_t", "m_nDetailLevel");
}
void GParticleChildrenInfo_t::SetDetailLevel(uint64_t value) {
    SetSchemaValue(m_ptr, "ParticleChildrenInfo_t", "m_nDetailLevel", true, value);
}
std::string GParticleChildrenInfo_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GParticleChildrenInfo_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassParticleChildrenInfo_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticleChildrenInfo_t>("ParticleChildrenInfo_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Delay", &GParticleChildrenInfo_t::GetDelay, &GParticleChildrenInfo_t::SetDelay)
        .addProperty("EndCap", &GParticleChildrenInfo_t::GetEndCap, &GParticleChildrenInfo_t::SetEndCap)
        .addProperty("DisableChild", &GParticleChildrenInfo_t::GetDisableChild, &GParticleChildrenInfo_t::SetDisableChild)
        .addProperty("DetailLevel", &GParticleChildrenInfo_t::GetDetailLevel, &GParticleChildrenInfo_t::SetDetailLevel)
        .addFunction("ToPtr", &GParticleChildrenInfo_t::ToPtr)
        .addFunction("IsValid", &GParticleChildrenInfo_t::IsValid)
        .endClass();
}