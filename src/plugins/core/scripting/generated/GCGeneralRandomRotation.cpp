#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGeneralRandomRotation::GCGeneralRandomRotation(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGeneralRandomRotation::GCGeneralRandomRotation(void *ptr) {
    m_ptr = ptr;
}
GParticleAttributeIndex_t GCGeneralRandomRotation::GetFieldOutput() const {
    GParticleAttributeIndex_t value(GetSchemaPtr(m_ptr, "CGeneralRandomRotation", "m_nFieldOutput"));
    return value;
}
void GCGeneralRandomRotation::SetFieldOutput(GParticleAttributeIndex_t value) {
    SetSchemaValue(m_ptr, "CGeneralRandomRotation", "m_nFieldOutput", false, value);
}
float GCGeneralRandomRotation::GetDegrees() const {
    return GetSchemaValue<float>(m_ptr, "CGeneralRandomRotation", "m_flDegrees");
}
void GCGeneralRandomRotation::SetDegrees(float value) {
    SetSchemaValue(m_ptr, "CGeneralRandomRotation", "m_flDegrees", false, value);
}
float GCGeneralRandomRotation::GetDegreesMin() const {
    return GetSchemaValue<float>(m_ptr, "CGeneralRandomRotation", "m_flDegreesMin");
}
void GCGeneralRandomRotation::SetDegreesMin(float value) {
    SetSchemaValue(m_ptr, "CGeneralRandomRotation", "m_flDegreesMin", false, value);
}
float GCGeneralRandomRotation::GetDegreesMax() const {
    return GetSchemaValue<float>(m_ptr, "CGeneralRandomRotation", "m_flDegreesMax");
}
void GCGeneralRandomRotation::SetDegreesMax(float value) {
    SetSchemaValue(m_ptr, "CGeneralRandomRotation", "m_flDegreesMax", false, value);
}
float GCGeneralRandomRotation::GetRotationRandExponent() const {
    return GetSchemaValue<float>(m_ptr, "CGeneralRandomRotation", "m_flRotationRandExponent");
}
void GCGeneralRandomRotation::SetRotationRandExponent(float value) {
    SetSchemaValue(m_ptr, "CGeneralRandomRotation", "m_flRotationRandExponent", false, value);
}
bool GCGeneralRandomRotation::GetRandomlyFlipDirection() const {
    return GetSchemaValue<bool>(m_ptr, "CGeneralRandomRotation", "m_bRandomlyFlipDirection");
}
void GCGeneralRandomRotation::SetRandomlyFlipDirection(bool value) {
    SetSchemaValue(m_ptr, "CGeneralRandomRotation", "m_bRandomlyFlipDirection", false, value);
}
std::string GCGeneralRandomRotation::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGeneralRandomRotation::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleFunctionInitializer GCGeneralRandomRotation::GetParent() const {
    GCParticleFunctionInitializer value(m_ptr);
    return value;
}
void GCGeneralRandomRotation::SetParent(GCParticleFunctionInitializer value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCGeneralRandomRotation(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGeneralRandomRotation>("CGeneralRandomRotation")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FieldOutput", &GCGeneralRandomRotation::GetFieldOutput, &GCGeneralRandomRotation::SetFieldOutput)
        .addProperty("Degrees", &GCGeneralRandomRotation::GetDegrees, &GCGeneralRandomRotation::SetDegrees)
        .addProperty("DegreesMin", &GCGeneralRandomRotation::GetDegreesMin, &GCGeneralRandomRotation::SetDegreesMin)
        .addProperty("DegreesMax", &GCGeneralRandomRotation::GetDegreesMax, &GCGeneralRandomRotation::SetDegreesMax)
        .addProperty("RotationRandExponent", &GCGeneralRandomRotation::GetRotationRandExponent, &GCGeneralRandomRotation::SetRotationRandExponent)
        .addProperty("RandomlyFlipDirection", &GCGeneralRandomRotation::GetRandomlyFlipDirection, &GCGeneralRandomRotation::SetRandomlyFlipDirection)
        .addProperty("Parent", &GCGeneralRandomRotation::GetParent, &GCGeneralRandomRotation::SetParent)
        .addFunction("ToPtr", &GCGeneralRandomRotation::ToPtr)
        .addFunction("IsValid", &GCGeneralRandomRotation::IsValid)
        .endClass();
}