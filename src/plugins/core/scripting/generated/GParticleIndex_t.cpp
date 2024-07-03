#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GParticleIndex_t::GParticleIndex_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GParticleIndex_t::GParticleIndex_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GParticleIndex_t::GetValue() const {
    return GetSchemaValue<int32_t>(m_ptr, "ParticleIndex_t", "m_Value");
}
void GParticleIndex_t::SetValue(int32_t value) {
    SetSchemaValue(m_ptr, "ParticleIndex_t", "m_Value", true, value);
}
std::string GParticleIndex_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GParticleIndex_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassParticleIndex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GParticleIndex_t>("ParticleIndex_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GParticleIndex_t::GetValue, &GParticleIndex_t::SetValue)
        .addFunction("ToPtr", &GParticleIndex_t::ToPtr)
        .addFunction("IsValid", &GParticleIndex_t::IsValid)
        .endClass();
}