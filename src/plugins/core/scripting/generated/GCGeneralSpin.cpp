#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGeneralSpin::GCGeneralSpin(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGeneralSpin::GCGeneralSpin(void *ptr) {
    m_ptr = ptr;
}
int32_t GCGeneralSpin::GetSpinRateDegrees() const {
    return GetSchemaValue<int32_t>(m_ptr, "CGeneralSpin", "m_nSpinRateDegrees");
}
void GCGeneralSpin::SetSpinRateDegrees(int32_t value) {
    SetSchemaValue(m_ptr, "CGeneralSpin", "m_nSpinRateDegrees", false, value);
}
int32_t GCGeneralSpin::GetSpinRateMinDegrees() const {
    return GetSchemaValue<int32_t>(m_ptr, "CGeneralSpin", "m_nSpinRateMinDegrees");
}
void GCGeneralSpin::SetSpinRateMinDegrees(int32_t value) {
    SetSchemaValue(m_ptr, "CGeneralSpin", "m_nSpinRateMinDegrees", false, value);
}
float GCGeneralSpin::GetSpinRateStopTime() const {
    return GetSchemaValue<float>(m_ptr, "CGeneralSpin", "m_fSpinRateStopTime");
}
void GCGeneralSpin::SetSpinRateStopTime(float value) {
    SetSchemaValue(m_ptr, "CGeneralSpin", "m_fSpinRateStopTime", false, value);
}
std::string GCGeneralSpin::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGeneralSpin::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleFunctionOperator GCGeneralSpin::GetParent() const {
    GCParticleFunctionOperator value(m_ptr);
    return value;
}
void GCGeneralSpin::SetParent(GCParticleFunctionOperator value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCGeneralSpin(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGeneralSpin>("CGeneralSpin")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SpinRateDegrees", &GCGeneralSpin::GetSpinRateDegrees, &GCGeneralSpin::SetSpinRateDegrees)
        .addProperty("SpinRateMinDegrees", &GCGeneralSpin::GetSpinRateMinDegrees, &GCGeneralSpin::SetSpinRateMinDegrees)
        .addProperty("SpinRateStopTime", &GCGeneralSpin::GetSpinRateStopTime, &GCGeneralSpin::SetSpinRateStopTime)
        .addProperty("Parent", &GCGeneralSpin::GetParent, &GCGeneralSpin::SetParent)
        .addFunction("ToPtr", &GCGeneralSpin::ToPtr)
        .addFunction("IsValid", &GCGeneralSpin::IsValid)
        .endClass();
}