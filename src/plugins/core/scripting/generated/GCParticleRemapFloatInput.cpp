#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleRemapFloatInput::GCParticleRemapFloatInput(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleRemapFloatInput::GCParticleRemapFloatInput(void *ptr) {
    m_ptr = ptr;
}
std::string GCParticleRemapFloatInput::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleRemapFloatInput::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleFloatInput GCParticleRemapFloatInput::GetParent() const {
    GCParticleFloatInput value(m_ptr);
    return value;
}
void GCParticleRemapFloatInput::SetParent(GCParticleFloatInput value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCParticleRemapFloatInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleRemapFloatInput>("CParticleRemapFloatInput")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCParticleRemapFloatInput::GetParent, &GCParticleRemapFloatInput::SetParent)
        .addFunction("ToPtr", &GCParticleRemapFloatInput::ToPtr)
        .addFunction("IsValid", &GCParticleRemapFloatInput::IsValid)
        .endClass();
}