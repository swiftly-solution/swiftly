#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFutureVelocityMetricEvaluator::GCFutureVelocityMetricEvaluator(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFutureVelocityMetricEvaluator::GCFutureVelocityMetricEvaluator(void *ptr) {
    m_ptr = ptr;
}
float GCFutureVelocityMetricEvaluator::GetDistance() const {
    return GetSchemaValue<float>(m_ptr, "CFutureVelocityMetricEvaluator", "m_flDistance");
}
void GCFutureVelocityMetricEvaluator::SetDistance(float value) {
    SetSchemaValue(m_ptr, "CFutureVelocityMetricEvaluator", "m_flDistance", false, value);
}
float GCFutureVelocityMetricEvaluator::GetStoppingDistance() const {
    return GetSchemaValue<float>(m_ptr, "CFutureVelocityMetricEvaluator", "m_flStoppingDistance");
}
void GCFutureVelocityMetricEvaluator::SetStoppingDistance(float value) {
    SetSchemaValue(m_ptr, "CFutureVelocityMetricEvaluator", "m_flStoppingDistance", false, value);
}
float GCFutureVelocityMetricEvaluator::GetTargetSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CFutureVelocityMetricEvaluator", "m_flTargetSpeed");
}
void GCFutureVelocityMetricEvaluator::SetTargetSpeed(float value) {
    SetSchemaValue(m_ptr, "CFutureVelocityMetricEvaluator", "m_flTargetSpeed", false, value);
}
uint64_t GCFutureVelocityMetricEvaluator::GetMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CFutureVelocityMetricEvaluator", "m_eMode");
}
void GCFutureVelocityMetricEvaluator::SetMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CFutureVelocityMetricEvaluator", "m_eMode", false, value);
}
std::string GCFutureVelocityMetricEvaluator::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFutureVelocityMetricEvaluator::IsValid() {
    return (m_ptr != nullptr);
}
GCMotionMetricEvaluator GCFutureVelocityMetricEvaluator::GetParent() const {
    GCMotionMetricEvaluator value(m_ptr);
    return value;
}
void GCFutureVelocityMetricEvaluator::SetParent(GCMotionMetricEvaluator value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFutureVelocityMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFutureVelocityMetricEvaluator>("CFutureVelocityMetricEvaluator")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Distance", &GCFutureVelocityMetricEvaluator::GetDistance, &GCFutureVelocityMetricEvaluator::SetDistance)
        .addProperty("StoppingDistance", &GCFutureVelocityMetricEvaluator::GetStoppingDistance, &GCFutureVelocityMetricEvaluator::SetStoppingDistance)
        .addProperty("TargetSpeed", &GCFutureVelocityMetricEvaluator::GetTargetSpeed, &GCFutureVelocityMetricEvaluator::SetTargetSpeed)
        .addProperty("Mode", &GCFutureVelocityMetricEvaluator::GetMode, &GCFutureVelocityMetricEvaluator::SetMode)
        .addProperty("Parent", &GCFutureVelocityMetricEvaluator::GetParent, &GCFutureVelocityMetricEvaluator::SetParent)
        .addFunction("ToPtr", &GCFutureVelocityMetricEvaluator::ToPtr)
        .addFunction("IsValid", &GCFutureVelocityMetricEvaluator::IsValid)
        .endClass();
}