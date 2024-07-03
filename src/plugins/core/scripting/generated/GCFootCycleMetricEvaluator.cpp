#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFootCycleMetricEvaluator::GCFootCycleMetricEvaluator(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFootCycleMetricEvaluator::GCFootCycleMetricEvaluator(void *ptr) {
    m_ptr = ptr;
}
std::vector<int32> GCFootCycleMetricEvaluator::GetFootIndices() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CFootCycleMetricEvaluator", "m_footIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFootCycleMetricEvaluator::SetFootIndices(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CFootCycleMetricEvaluator", "m_footIndices", false, value);
}
std::string GCFootCycleMetricEvaluator::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFootCycleMetricEvaluator::IsValid() {
    return (m_ptr != nullptr);
}
GCMotionMetricEvaluator GCFootCycleMetricEvaluator::GetParent() const {
    GCMotionMetricEvaluator value(m_ptr);
    return value;
}
void GCFootCycleMetricEvaluator::SetParent(GCMotionMetricEvaluator value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFootCycleMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootCycleMetricEvaluator>("CFootCycleMetricEvaluator")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FootIndices", &GCFootCycleMetricEvaluator::GetFootIndices, &GCFootCycleMetricEvaluator::SetFootIndices)
        .addProperty("Parent", &GCFootCycleMetricEvaluator::GetParent, &GCFootCycleMetricEvaluator::SetParent)
        .addFunction("ToPtr", &GCFootCycleMetricEvaluator::ToPtr)
        .addFunction("IsValid", &GCFootCycleMetricEvaluator::IsValid)
        .endClass();
}