#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleFunctionRenderer::GCParticleFunctionRenderer(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleFunctionRenderer::GCParticleFunctionRenderer(void *ptr) {
    m_ptr = ptr;
}
GCParticleVisibilityInputs GCParticleFunctionRenderer::GetVisibilityInputs() const {
    GCParticleVisibilityInputs value(GetSchemaPtr(m_ptr, "CParticleFunctionRenderer", "VisibilityInputs"));
    return value;
}
void GCParticleFunctionRenderer::SetVisibilityInputs(GCParticleVisibilityInputs value) {
    SetSchemaValue(m_ptr, "CParticleFunctionRenderer", "VisibilityInputs", false, value);
}
bool GCParticleFunctionRenderer::GetCannotBeRefracted() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleFunctionRenderer", "m_bCannotBeRefracted");
}
void GCParticleFunctionRenderer::SetCannotBeRefracted(bool value) {
    SetSchemaValue(m_ptr, "CParticleFunctionRenderer", "m_bCannotBeRefracted", false, value);
}
bool GCParticleFunctionRenderer::GetSkipRenderingOnMobile() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleFunctionRenderer", "m_bSkipRenderingOnMobile");
}
void GCParticleFunctionRenderer::SetSkipRenderingOnMobile(bool value) {
    SetSchemaValue(m_ptr, "CParticleFunctionRenderer", "m_bSkipRenderingOnMobile", false, value);
}
std::string GCParticleFunctionRenderer::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleFunctionRenderer::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleFunction GCParticleFunctionRenderer::GetParent() const {
    GCParticleFunction value(m_ptr);
    return value;
}
void GCParticleFunctionRenderer::SetParent(GCParticleFunction value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCParticleFunctionRenderer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleFunctionRenderer>("CParticleFunctionRenderer")
        .addConstructor<void (*)(std::string)>()
        .addProperty("VisibilityInputs", &GCParticleFunctionRenderer::GetVisibilityInputs, &GCParticleFunctionRenderer::SetVisibilityInputs)
        .addProperty("CannotBeRefracted", &GCParticleFunctionRenderer::GetCannotBeRefracted, &GCParticleFunctionRenderer::SetCannotBeRefracted)
        .addProperty("SkipRenderingOnMobile", &GCParticleFunctionRenderer::GetSkipRenderingOnMobile, &GCParticleFunctionRenderer::SetSkipRenderingOnMobile)
        .addProperty("Parent", &GCParticleFunctionRenderer::GetParent, &GCParticleFunctionRenderer::SetParent)
        .addFunction("ToPtr", &GCParticleFunctionRenderer::ToPtr)
        .addFunction("IsValid", &GCParticleFunctionRenderer::IsValid)
        .endClass();
}