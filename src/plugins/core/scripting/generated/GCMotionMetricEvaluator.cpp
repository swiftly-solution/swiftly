#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMotionMetricEvaluator::GCMotionMetricEvaluator(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMotionMetricEvaluator::GCMotionMetricEvaluator(void *ptr) {
    m_ptr = ptr;
}
std::vector<float32> GCMotionMetricEvaluator::GetMeans() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CMotionMetricEvaluator", "m_means"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMotionMetricEvaluator::SetMeans(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CMotionMetricEvaluator", "m_means", false, value);
}
std::vector<float32> GCMotionMetricEvaluator::GetStandardDeviations() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CMotionMetricEvaluator", "m_standardDeviations"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMotionMetricEvaluator::SetStandardDeviations(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CMotionMetricEvaluator", "m_standardDeviations", false, value);
}
float GCMotionMetricEvaluator::GetWeight() const {
    return GetSchemaValue<float>(m_ptr, "CMotionMetricEvaluator", "m_flWeight");
}
void GCMotionMetricEvaluator::SetWeight(float value) {
    SetSchemaValue(m_ptr, "CMotionMetricEvaluator", "m_flWeight", false, value);
}
int32_t GCMotionMetricEvaluator::GetDimensionStartIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMotionMetricEvaluator", "m_nDimensionStartIndex");
}
void GCMotionMetricEvaluator::SetDimensionStartIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CMotionMetricEvaluator", "m_nDimensionStartIndex", false, value);
}
std::string GCMotionMetricEvaluator::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMotionMetricEvaluator::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCMotionMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionMetricEvaluator>("CMotionMetricEvaluator")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Means", &GCMotionMetricEvaluator::GetMeans, &GCMotionMetricEvaluator::SetMeans)
        .addProperty("StandardDeviations", &GCMotionMetricEvaluator::GetStandardDeviations, &GCMotionMetricEvaluator::SetStandardDeviations)
        .addProperty("Weight", &GCMotionMetricEvaluator::GetWeight, &GCMotionMetricEvaluator::SetWeight)
        .addProperty("DimensionStartIndex", &GCMotionMetricEvaluator::GetDimensionStartIndex, &GCMotionMetricEvaluator::SetDimensionStartIndex)
        .addFunction("ToPtr", &GCMotionMetricEvaluator::ToPtr)
        .addFunction("IsValid", &GCMotionMetricEvaluator::IsValid)
        .endClass();
}