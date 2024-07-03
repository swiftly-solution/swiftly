#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GParticleAttributeIndex_t::GParticleAttributeIndex_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GParticleAttributeIndex_t::GParticleAttributeIndex_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GParticleAttributeIndex_t::GetValue() const {
    return GetSchemaValue<int32_t>(m_ptr, "ParticleAttributeIndex_t", "m_Value");
}
void GParticleAttributeIndex_t::SetValue(int32_t value) {
    SetSchemaValue(m_ptr, "ParticleAttributeIndex_t", "m_Value", true, value);
}
std::string GParticleAttributeIndex_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GParticleAttributeIndex_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassParticleAttributeIndex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticleAttributeIndex_t>("ParticleAttributeIndex_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GParticleAttributeIndex_t::GetValue, &GParticleAttributeIndex_t::SetValue)
        .addFunction("ToPtr", &GParticleAttributeIndex_t::ToPtr)
        .addFunction("IsValid", &GParticleAttributeIndex_t::IsValid)
        .endClass();
}