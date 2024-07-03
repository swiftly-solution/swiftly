#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPerParticleVecInput::GCPerParticleVecInput(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPerParticleVecInput::GCPerParticleVecInput(void *ptr) {
    m_ptr = ptr;
}
std::string GCPerParticleVecInput::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPerParticleVecInput::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleVecInput GCPerParticleVecInput::GetParent() const {
    GCParticleVecInput value(m_ptr);
    return value;
}
void GCPerParticleVecInput::SetParent(GCParticleVecInput value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPerParticleVecInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPerParticleVecInput>("CPerParticleVecInput")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPerParticleVecInput::GetParent, &GCPerParticleVecInput::SetParent)
        .addFunction("ToPtr", &GCPerParticleVecInput::ToPtr)
        .addFunction("IsValid", &GCPerParticleVecInput::IsValid)
        .endClass();
}