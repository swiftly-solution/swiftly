#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GNmCompressionSettings_t::GNmCompressionSettings_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GNmCompressionSettings_t::GNmCompressionSettings_t(void *ptr) {
    m_ptr = ptr;
}
GNmCompressionSettings_t GNmCompressionSettings_t::GetTranslationRangeX() const {
    GNmCompressionSettings_t value(GetSchemaPtr(m_ptr, "NmCompressionSettings_t", "m_translationRangeX"));
    return value;
}
void GNmCompressionSettings_t::SetTranslationRangeX(GNmCompressionSettings_t value) {
    SetSchemaValue(m_ptr, "NmCompressionSettings_t", "m_translationRangeX", true, value);
}
GNmCompressionSettings_t GNmCompressionSettings_t::GetTranslationRangeY() const {
    GNmCompressionSettings_t value(GetSchemaPtr(m_ptr, "NmCompressionSettings_t", "m_translationRangeY"));
    return value;
}
void GNmCompressionSettings_t::SetTranslationRangeY(GNmCompressionSettings_t value) {
    SetSchemaValue(m_ptr, "NmCompressionSettings_t", "m_translationRangeY", true, value);
}
GNmCompressionSettings_t GNmCompressionSettings_t::GetTranslationRangeZ() const {
    GNmCompressionSettings_t value(GetSchemaPtr(m_ptr, "NmCompressionSettings_t", "m_translationRangeZ"));
    return value;
}
void GNmCompressionSettings_t::SetTranslationRangeZ(GNmCompressionSettings_t value) {
    SetSchemaValue(m_ptr, "NmCompressionSettings_t", "m_translationRangeZ", true, value);
}
GNmCompressionSettings_t GNmCompressionSettings_t::GetScaleRange() const {
    GNmCompressionSettings_t value(GetSchemaPtr(m_ptr, "NmCompressionSettings_t", "m_scaleRange"));
    return value;
}
void GNmCompressionSettings_t::SetScaleRange(GNmCompressionSettings_t value) {
    SetSchemaValue(m_ptr, "NmCompressionSettings_t", "m_scaleRange", true, value);
}
Quaternion GNmCompressionSettings_t::GetConstantRotation() const {
    return GetSchemaValue<Quaternion>(m_ptr, "NmCompressionSettings_t", "m_constantRotation");
}
void GNmCompressionSettings_t::SetConstantRotation(Quaternion value) {
    SetSchemaValue(m_ptr, "NmCompressionSettings_t", "m_constantRotation", true, value);
}
bool GNmCompressionSettings_t::GetIsRotationStatic() const {
    return GetSchemaValue<bool>(m_ptr, "NmCompressionSettings_t", "m_bIsRotationStatic");
}
void GNmCompressionSettings_t::SetIsRotationStatic(bool value) {
    SetSchemaValue(m_ptr, "NmCompressionSettings_t", "m_bIsRotationStatic", true, value);
}
bool GNmCompressionSettings_t::GetIsTranslationStatic() const {
    return GetSchemaValue<bool>(m_ptr, "NmCompressionSettings_t", "m_bIsTranslationStatic");
}
void GNmCompressionSettings_t::SetIsTranslationStatic(bool value) {
    SetSchemaValue(m_ptr, "NmCompressionSettings_t", "m_bIsTranslationStatic", true, value);
}
bool GNmCompressionSettings_t::GetIsScaleStatic() const {
    return GetSchemaValue<bool>(m_ptr, "NmCompressionSettings_t", "m_bIsScaleStatic");
}
void GNmCompressionSettings_t::SetIsScaleStatic(bool value) {
    SetSchemaValue(m_ptr, "NmCompressionSettings_t", "m_bIsScaleStatic", true, value);
}
std::string GNmCompressionSettings_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GNmCompressionSettings_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassNmCompressionSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GNmCompressionSettings_t>("NmCompressionSettings_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TranslationRangeX", &GNmCompressionSettings_t::GetTranslationRangeX, &GNmCompressionSettings_t::SetTranslationRangeX)
        .addProperty("TranslationRangeY", &GNmCompressionSettings_t::GetTranslationRangeY, &GNmCompressionSettings_t::SetTranslationRangeY)
        .addProperty("TranslationRangeZ", &GNmCompressionSettings_t::GetTranslationRangeZ, &GNmCompressionSettings_t::SetTranslationRangeZ)
        .addProperty("ScaleRange", &GNmCompressionSettings_t::GetScaleRange, &GNmCompressionSettings_t::SetScaleRange)
        .addProperty("ConstantRotation", &GNmCompressionSettings_t::GetConstantRotation, &GNmCompressionSettings_t::SetConstantRotation)
        .addProperty("IsRotationStatic", &GNmCompressionSettings_t::GetIsRotationStatic, &GNmCompressionSettings_t::SetIsRotationStatic)
        .addProperty("IsTranslationStatic", &GNmCompressionSettings_t::GetIsTranslationStatic, &GNmCompressionSettings_t::SetIsTranslationStatic)
        .addProperty("IsScaleStatic", &GNmCompressionSettings_t::GetIsScaleStatic, &GNmCompressionSettings_t::SetIsScaleStatic)
        .addFunction("ToPtr", &GNmCompressionSettings_t::ToPtr)
        .addFunction("IsValid", &GNmCompressionSettings_t::IsValid)
        .endClass();
}