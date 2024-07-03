#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleCollectionRendererFloatInput::GCParticleCollectionRendererFloatInput(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleCollectionRendererFloatInput::GCParticleCollectionRendererFloatInput(void *ptr) {
    m_ptr = ptr;
}
std::string GCParticleCollectionRendererFloatInput::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleCollectionRendererFloatInput::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleCollectionFloatInput GCParticleCollectionRendererFloatInput::GetParent() const {
    GCParticleCollectionFloatInput value(m_ptr);
    return value;
}
void GCParticleCollectionRendererFloatInput::SetParent(GCParticleCollectionFloatInput value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCParticleCollectionRendererFloatInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleCollectionRendererFloatInput>("CParticleCollectionRendererFloatInput")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCParticleCollectionRendererFloatInput::GetParent, &GCParticleCollectionRendererFloatInput::SetParent)
        .addFunction("ToPtr", &GCParticleCollectionRendererFloatInput::ToPtr)
        .addFunction("IsValid", &GCParticleCollectionRendererFloatInput::IsValid)
        .endClass();
}