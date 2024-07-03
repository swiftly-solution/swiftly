#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFutureFacingMetricEvaluator::GCFutureFacingMetricEvaluator(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFutureFacingMetricEvaluator::GCFutureFacingMetricEvaluator(void *ptr) {
    m_ptr = ptr;
}
float GCFutureFacingMetricEvaluator::GetDistance() const {
    return GetSchemaValue<float>(m_ptr, "CFutureFacingMetricEvaluator", "m_flDistance");
}
void GCFutureFacingMetricEvaluator::SetDistance(float value) {
    SetSchemaValue(m_ptr, "CFutureFacingMetricEvaluator", "m_flDistance", false, value);
}
float GCFutureFacingMetricEvaluator::GetTime() const {
    return GetSchemaValue<float>(m_ptr, "CFutureFacingMetricEvaluator", "m_flTime");
}
void GCFutureFacingMetricEvaluator::SetTime(float value) {
    SetSchemaValue(m_ptr, "CFutureFacingMetricEvaluator", "m_flTime", false, value);
}
std::string GCFutureFacingMetricEvaluator::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFutureFacingMetricEvaluator::IsValid() {
    return (m_ptr != nullptr);
}
GCMotionMetricEvaluator GCFutureFacingMetricEvaluator::GetParent() const {
    GCMotionMetricEvaluator value(m_ptr);
    return value;
}
void GCFutureFacingMetricEvaluator::SetParent(GCMotionMetricEvaluator value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFutureFacingMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFutureFacingMetricEvaluator>("CFutureFacingMetricEvaluator")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Distance", &GCFutureFacingMetricEvaluator::GetDistance, &GCFutureFacingMetricEvaluator::SetDistance)
        .addProperty("Time", &GCFutureFacingMetricEvaluator::GetTime, &GCFutureFacingMetricEvaluator::SetTime)
        .addProperty("Parent", &GCFutureFacingMetricEvaluator::GetParent, &GCFutureFacingMetricEvaluator::SetParent)
        .addFunction("ToPtr", &GCFutureFacingMetricEvaluator::ToPtr)
        .addFunction("IsValid", &GCFutureFacingMetricEvaluator::IsValid)
        .endClass();
}