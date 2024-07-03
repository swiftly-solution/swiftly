#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTimeRemainingMetricEvaluator::GCTimeRemainingMetricEvaluator(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTimeRemainingMetricEvaluator::GCTimeRemainingMetricEvaluator(void *ptr) {
    m_ptr = ptr;
}
bool GCTimeRemainingMetricEvaluator::GetMatchByTimeRemaining() const {
    return GetSchemaValue<bool>(m_ptr, "CTimeRemainingMetricEvaluator", "m_bMatchByTimeRemaining");
}
void GCTimeRemainingMetricEvaluator::SetMatchByTimeRemaining(bool value) {
    SetSchemaValue(m_ptr, "CTimeRemainingMetricEvaluator", "m_bMatchByTimeRemaining", false, value);
}
float GCTimeRemainingMetricEvaluator::GetMaxTimeRemaining() const {
    return GetSchemaValue<float>(m_ptr, "CTimeRemainingMetricEvaluator", "m_flMaxTimeRemaining");
}
void GCTimeRemainingMetricEvaluator::SetMaxTimeRemaining(float value) {
    SetSchemaValue(m_ptr, "CTimeRemainingMetricEvaluator", "m_flMaxTimeRemaining", false, value);
}
bool GCTimeRemainingMetricEvaluator::GetFilterByTimeRemaining() const {
    return GetSchemaValue<bool>(m_ptr, "CTimeRemainingMetricEvaluator", "m_bFilterByTimeRemaining");
}
void GCTimeRemainingMetricEvaluator::SetFilterByTimeRemaining(bool value) {
    SetSchemaValue(m_ptr, "CTimeRemainingMetricEvaluator", "m_bFilterByTimeRemaining", false, value);
}
float GCTimeRemainingMetricEvaluator::GetMinTimeRemaining() const {
    return GetSchemaValue<float>(m_ptr, "CTimeRemainingMetricEvaluator", "m_flMinTimeRemaining");
}
void GCTimeRemainingMetricEvaluator::SetMinTimeRemaining(float value) {
    SetSchemaValue(m_ptr, "CTimeRemainingMetricEvaluator", "m_flMinTimeRemaining", false, value);
}
std::string GCTimeRemainingMetricEvaluator::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTimeRemainingMetricEvaluator::IsValid() {
    return (m_ptr != nullptr);
}
GCMotionMetricEvaluator GCTimeRemainingMetricEvaluator::GetParent() const {
    GCMotionMetricEvaluator value(m_ptr);
    return value;
}
void GCTimeRemainingMetricEvaluator::SetParent(GCMotionMetricEvaluator value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTimeRemainingMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTimeRemainingMetricEvaluator>("CTimeRemainingMetricEvaluator")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MatchByTimeRemaining", &GCTimeRemainingMetricEvaluator::GetMatchByTimeRemaining, &GCTimeRemainingMetricEvaluator::SetMatchByTimeRemaining)
        .addProperty("MaxTimeRemaining", &GCTimeRemainingMetricEvaluator::GetMaxTimeRemaining, &GCTimeRemainingMetricEvaluator::SetMaxTimeRemaining)
        .addProperty("FilterByTimeRemaining", &GCTimeRemainingMetricEvaluator::GetFilterByTimeRemaining, &GCTimeRemainingMetricEvaluator::SetFilterByTimeRemaining)
        .addProperty("MinTimeRemaining", &GCTimeRemainingMetricEvaluator::GetMinTimeRemaining, &GCTimeRemainingMetricEvaluator::SetMinTimeRemaining)
        .addProperty("Parent", &GCTimeRemainingMetricEvaluator::GetParent, &GCTimeRemainingMetricEvaluator::SetParent)
        .addFunction("ToPtr", &GCTimeRemainingMetricEvaluator::ToPtr)
        .addFunction("IsValid", &GCTimeRemainingMetricEvaluator::IsValid)
        .endClass();
}