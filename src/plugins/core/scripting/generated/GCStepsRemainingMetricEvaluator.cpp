#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCStepsRemainingMetricEvaluator::GCStepsRemainingMetricEvaluator(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCStepsRemainingMetricEvaluator::GCStepsRemainingMetricEvaluator(void *ptr) {
    m_ptr = ptr;
}
std::vector<int32> GCStepsRemainingMetricEvaluator::GetFootIndices() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CStepsRemainingMetricEvaluator", "m_footIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCStepsRemainingMetricEvaluator::SetFootIndices(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CStepsRemainingMetricEvaluator", "m_footIndices", false, value);
}
float GCStepsRemainingMetricEvaluator::GetMinStepsRemaining() const {
    return GetSchemaValue<float>(m_ptr, "CStepsRemainingMetricEvaluator", "m_flMinStepsRemaining");
}
void GCStepsRemainingMetricEvaluator::SetMinStepsRemaining(float value) {
    SetSchemaValue(m_ptr, "CStepsRemainingMetricEvaluator", "m_flMinStepsRemaining", false, value);
}
std::string GCStepsRemainingMetricEvaluator::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCStepsRemainingMetricEvaluator::IsValid() {
    return (m_ptr != nullptr);
}
GCMotionMetricEvaluator GCStepsRemainingMetricEvaluator::GetParent() const {
    GCMotionMetricEvaluator value(m_ptr);
    return value;
}
void GCStepsRemainingMetricEvaluator::SetParent(GCMotionMetricEvaluator value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCStepsRemainingMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStepsRemainingMetricEvaluator>("CStepsRemainingMetricEvaluator")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FootIndices", &GCStepsRemainingMetricEvaluator::GetFootIndices, &GCStepsRemainingMetricEvaluator::SetFootIndices)
        .addProperty("MinStepsRemaining", &GCStepsRemainingMetricEvaluator::GetMinStepsRemaining, &GCStepsRemainingMetricEvaluator::SetMinStepsRemaining)
        .addProperty("Parent", &GCStepsRemainingMetricEvaluator::GetParent, &GCStepsRemainingMetricEvaluator::SetParent)
        .addFunction("ToPtr", &GCStepsRemainingMetricEvaluator::ToPtr)
        .addFunction("IsValid", &GCStepsRemainingMetricEvaluator::IsValid)
        .endClass();
}