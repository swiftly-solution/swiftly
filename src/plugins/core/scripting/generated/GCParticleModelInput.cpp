#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleModelInput::GCParticleModelInput(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleModelInput::GCParticleModelInput(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCParticleModelInput::GetType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CParticleModelInput", "m_nType");
}
void GCParticleModelInput::SetType(uint64_t value) {
    SetSchemaValue(m_ptr, "CParticleModelInput", "m_nType", false, value);
}
int32_t GCParticleModelInput::GetControlPoint() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleModelInput", "m_nControlPoint");
}
void GCParticleModelInput::SetControlPoint(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleModelInput", "m_nControlPoint", false, value);
}
std::string GCParticleModelInput::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleModelInput::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleInput GCParticleModelInput::GetParent() const {
    GCParticleInput value(m_ptr);
    return value;
}
void GCParticleModelInput::SetParent(GCParticleInput value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCParticleModelInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleModelInput>("CParticleModelInput")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Type", &GCParticleModelInput::GetType, &GCParticleModelInput::SetType)
        .addProperty("ControlPoint", &GCParticleModelInput::GetControlPoint, &GCParticleModelInput::SetControlPoint)
        .addProperty("Parent", &GCParticleModelInput::GetParent, &GCParticleModelInput::SetParent)
        .addFunction("ToPtr", &GCParticleModelInput::ToPtr)
        .addFunction("IsValid", &GCParticleModelInput::IsValid)
        .endClass();
}