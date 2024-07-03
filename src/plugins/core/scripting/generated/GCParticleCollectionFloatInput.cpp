#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleCollectionFloatInput::GCParticleCollectionFloatInput(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleCollectionFloatInput::GCParticleCollectionFloatInput(void *ptr) {
    m_ptr = ptr;
}
std::string GCParticleCollectionFloatInput::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleCollectionFloatInput::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleFloatInput GCParticleCollectionFloatInput::GetParent() const {
    GCParticleFloatInput value(m_ptr);
    return value;
}
void GCParticleCollectionFloatInput::SetParent(GCParticleFloatInput value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCParticleCollectionFloatInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleCollectionFloatInput>("CParticleCollectionFloatInput")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCParticleCollectionFloatInput::GetParent, &GCParticleCollectionFloatInput::SetParent)
        .addFunction("ToPtr", &GCParticleCollectionFloatInput::ToPtr)
        .addFunction("IsValid", &GCParticleCollectionFloatInput::IsValid)
        .endClass();
}