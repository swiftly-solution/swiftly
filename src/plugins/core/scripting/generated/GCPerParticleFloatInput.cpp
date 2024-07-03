#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPerParticleFloatInput::GCPerParticleFloatInput(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPerParticleFloatInput::GCPerParticleFloatInput(void *ptr) {
    m_ptr = ptr;
}
std::string GCPerParticleFloatInput::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPerParticleFloatInput::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleFloatInput GCPerParticleFloatInput::GetParent() const {
    GCParticleFloatInput value(m_ptr);
    return value;
}
void GCPerParticleFloatInput::SetParent(GCParticleFloatInput value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPerParticleFloatInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPerParticleFloatInput>("CPerParticleFloatInput")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPerParticleFloatInput::GetParent, &GCPerParticleFloatInput::SetParent)
        .addFunction("ToPtr", &GCPerParticleFloatInput::ToPtr)
        .addFunction("IsValid", &GCPerParticleFloatInput::IsValid)
        .endClass();
}