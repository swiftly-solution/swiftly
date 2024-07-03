#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GNmCompressionSettings_t__QuantizationRange_t::GNmCompressionSettings_t__QuantizationRange_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GNmCompressionSettings_t__QuantizationRange_t::GNmCompressionSettings_t__QuantizationRange_t(void *ptr) {
    m_ptr = ptr;
}
float GNmCompressionSettings_t__QuantizationRange_t::GetRangeStart() const {
    return GetSchemaValue<float>(m_ptr, "NmCompressionSettings_t__QuantizationRange_t", "m_flRangeStart");
}
void GNmCompressionSettings_t__QuantizationRange_t::SetRangeStart(float value) {
    SetSchemaValue(m_ptr, "NmCompressionSettings_t__QuantizationRange_t", "m_flRangeStart", true, value);
}
float GNmCompressionSettings_t__QuantizationRange_t::GetRangeLength() const {
    return GetSchemaValue<float>(m_ptr, "NmCompressionSettings_t__QuantizationRange_t", "m_flRangeLength");
}
void GNmCompressionSettings_t__QuantizationRange_t::SetRangeLength(float value) {
    SetSchemaValue(m_ptr, "NmCompressionSettings_t__QuantizationRange_t", "m_flRangeLength", true, value);
}
std::string GNmCompressionSettings_t__QuantizationRange_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GNmCompressionSettings_t__QuantizationRange_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassNmCompressionSettings_t__QuantizationRange_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GNmCompressionSettings_t__QuantizationRange_t>("NmCompressionSettings_t__QuantizationRange_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("RangeStart", &GNmCompressionSettings_t__QuantizationRange_t::GetRangeStart, &GNmCompressionSettings_t__QuantizationRange_t::SetRangeStart)
        .addProperty("RangeLength", &GNmCompressionSettings_t__QuantizationRange_t::GetRangeLength, &GNmCompressionSettings_t__QuantizationRange_t::SetRangeLength)
        .addFunction("ToPtr", &GNmCompressionSettings_t__QuantizationRange_t::ToPtr)
        .addFunction("IsValid", &GNmCompressionSettings_t__QuantizationRange_t::IsValid)
        .endClass();
}