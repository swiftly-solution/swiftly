#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPathMetricEvaluator::GCPathMetricEvaluator(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPathMetricEvaluator::GCPathMetricEvaluator(void *ptr) {
    m_ptr = ptr;
}
std::vector<float32> GCPathMetricEvaluator::GetPathTimeSamples() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CPathMetricEvaluator", "m_pathTimeSamples"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCPathMetricEvaluator::SetPathTimeSamples(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CPathMetricEvaluator", "m_pathTimeSamples", false, value);
}
float GCPathMetricEvaluator::GetDistance() const {
    return GetSchemaValue<float>(m_ptr, "CPathMetricEvaluator", "m_flDistance");
}
void GCPathMetricEvaluator::SetDistance(float value) {
    SetSchemaValue(m_ptr, "CPathMetricEvaluator", "m_flDistance", false, value);
}
bool GCPathMetricEvaluator::GetExtrapolateMovement() const {
    return GetSchemaValue<bool>(m_ptr, "CPathMetricEvaluator", "m_bExtrapolateMovement");
}
void GCPathMetricEvaluator::SetExtrapolateMovement(bool value) {
    SetSchemaValue(m_ptr, "CPathMetricEvaluator", "m_bExtrapolateMovement", false, value);
}
float GCPathMetricEvaluator::GetMinExtrapolationSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CPathMetricEvaluator", "m_flMinExtrapolationSpeed");
}
void GCPathMetricEvaluator::SetMinExtrapolationSpeed(float value) {
    SetSchemaValue(m_ptr, "CPathMetricEvaluator", "m_flMinExtrapolationSpeed", false, value);
}
std::string GCPathMetricEvaluator::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPathMetricEvaluator::IsValid() {
    return (m_ptr != nullptr);
}
GCMotionMetricEvaluator GCPathMetricEvaluator::GetParent() const {
    GCMotionMetricEvaluator value(m_ptr);
    return value;
}
void GCPathMetricEvaluator::SetParent(GCMotionMetricEvaluator value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPathMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathMetricEvaluator>("CPathMetricEvaluator")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PathTimeSamples", &GCPathMetricEvaluator::GetPathTimeSamples, &GCPathMetricEvaluator::SetPathTimeSamples)
        .addProperty("Distance", &GCPathMetricEvaluator::GetDistance, &GCPathMetricEvaluator::SetDistance)
        .addProperty("ExtrapolateMovement", &GCPathMetricEvaluator::GetExtrapolateMovement, &GCPathMetricEvaluator::SetExtrapolateMovement)
        .addProperty("MinExtrapolationSpeed", &GCPathMetricEvaluator::GetMinExtrapolationSpeed, &GCPathMetricEvaluator::SetMinExtrapolationSpeed)
        .addProperty("Parent", &GCPathMetricEvaluator::GetParent, &GCPathMetricEvaluator::SetParent)
        .addFunction("ToPtr", &GCPathMetricEvaluator::ToPtr)
        .addFunction("IsValid", &GCPathMetricEvaluator::IsValid)
        .endClass();
}