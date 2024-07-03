#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDistanceRemainingMetricEvaluator::GCDistanceRemainingMetricEvaluator(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDistanceRemainingMetricEvaluator::GCDistanceRemainingMetricEvaluator(void *ptr) {
    m_ptr = ptr;
}
float GCDistanceRemainingMetricEvaluator::GetMaxDistance() const {
    return GetSchemaValue<float>(m_ptr, "CDistanceRemainingMetricEvaluator", "m_flMaxDistance");
}
void GCDistanceRemainingMetricEvaluator::SetMaxDistance(float value) {
    SetSchemaValue(m_ptr, "CDistanceRemainingMetricEvaluator", "m_flMaxDistance", false, value);
}
float GCDistanceRemainingMetricEvaluator::GetMinDistance() const {
    return GetSchemaValue<float>(m_ptr, "CDistanceRemainingMetricEvaluator", "m_flMinDistance");
}
void GCDistanceRemainingMetricEvaluator::SetMinDistance(float value) {
    SetSchemaValue(m_ptr, "CDistanceRemainingMetricEvaluator", "m_flMinDistance", false, value);
}
float GCDistanceRemainingMetricEvaluator::GetStartGoalFilterDistance() const {
    return GetSchemaValue<float>(m_ptr, "CDistanceRemainingMetricEvaluator", "m_flStartGoalFilterDistance");
}
void GCDistanceRemainingMetricEvaluator::SetStartGoalFilterDistance(float value) {
    SetSchemaValue(m_ptr, "CDistanceRemainingMetricEvaluator", "m_flStartGoalFilterDistance", false, value);
}
float GCDistanceRemainingMetricEvaluator::GetMaxGoalOvershootScale() const {
    return GetSchemaValue<float>(m_ptr, "CDistanceRemainingMetricEvaluator", "m_flMaxGoalOvershootScale");
}
void GCDistanceRemainingMetricEvaluator::SetMaxGoalOvershootScale(float value) {
    SetSchemaValue(m_ptr, "CDistanceRemainingMetricEvaluator", "m_flMaxGoalOvershootScale", false, value);
}
bool GCDistanceRemainingMetricEvaluator::GetFilterFixedMinDistance() const {
    return GetSchemaValue<bool>(m_ptr, "CDistanceRemainingMetricEvaluator", "m_bFilterFixedMinDistance");
}
void GCDistanceRemainingMetricEvaluator::SetFilterFixedMinDistance(bool value) {
    SetSchemaValue(m_ptr, "CDistanceRemainingMetricEvaluator", "m_bFilterFixedMinDistance", false, value);
}
bool GCDistanceRemainingMetricEvaluator::GetFilterGoalDistance() const {
    return GetSchemaValue<bool>(m_ptr, "CDistanceRemainingMetricEvaluator", "m_bFilterGoalDistance");
}
void GCDistanceRemainingMetricEvaluator::SetFilterGoalDistance(bool value) {
    SetSchemaValue(m_ptr, "CDistanceRemainingMetricEvaluator", "m_bFilterGoalDistance", false, value);
}
bool GCDistanceRemainingMetricEvaluator::GetFilterGoalOvershoot() const {
    return GetSchemaValue<bool>(m_ptr, "CDistanceRemainingMetricEvaluator", "m_bFilterGoalOvershoot");
}
void GCDistanceRemainingMetricEvaluator::SetFilterGoalOvershoot(bool value) {
    SetSchemaValue(m_ptr, "CDistanceRemainingMetricEvaluator", "m_bFilterGoalOvershoot", false, value);
}
std::string GCDistanceRemainingMetricEvaluator::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDistanceRemainingMetricEvaluator::IsValid() {
    return (m_ptr != nullptr);
}
GCMotionMetricEvaluator GCDistanceRemainingMetricEvaluator::GetParent() const {
    GCMotionMetricEvaluator value(m_ptr);
    return value;
}
void GCDistanceRemainingMetricEvaluator::SetParent(GCMotionMetricEvaluator value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCDistanceRemainingMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDistanceRemainingMetricEvaluator>("CDistanceRemainingMetricEvaluator")
        .addConstructor<void (*)(std::string)>()
        .addProperty("MaxDistance", &GCDistanceRemainingMetricEvaluator::GetMaxDistance, &GCDistanceRemainingMetricEvaluator::SetMaxDistance)
        .addProperty("MinDistance", &GCDistanceRemainingMetricEvaluator::GetMinDistance, &GCDistanceRemainingMetricEvaluator::SetMinDistance)
        .addProperty("StartGoalFilterDistance", &GCDistanceRemainingMetricEvaluator::GetStartGoalFilterDistance, &GCDistanceRemainingMetricEvaluator::SetStartGoalFilterDistance)
        .addProperty("MaxGoalOvershootScale", &GCDistanceRemainingMetricEvaluator::GetMaxGoalOvershootScale, &GCDistanceRemainingMetricEvaluator::SetMaxGoalOvershootScale)
        .addProperty("FilterFixedMinDistance", &GCDistanceRemainingMetricEvaluator::GetFilterFixedMinDistance, &GCDistanceRemainingMetricEvaluator::SetFilterFixedMinDistance)
        .addProperty("FilterGoalDistance", &GCDistanceRemainingMetricEvaluator::GetFilterGoalDistance, &GCDistanceRemainingMetricEvaluator::SetFilterGoalDistance)
        .addProperty("FilterGoalOvershoot", &GCDistanceRemainingMetricEvaluator::GetFilterGoalOvershoot, &GCDistanceRemainingMetricEvaluator::SetFilterGoalOvershoot)
        .addProperty("Parent", &GCDistanceRemainingMetricEvaluator::GetParent, &GCDistanceRemainingMetricEvaluator::SetParent)
        .addFunction("ToPtr", &GCDistanceRemainingMetricEvaluator::ToPtr)
        .addFunction("IsValid", &GCDistanceRemainingMetricEvaluator::IsValid)
        .endClass();
}