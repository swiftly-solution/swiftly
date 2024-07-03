#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFootPositionMetricEvaluator::GCFootPositionMetricEvaluator(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFootPositionMetricEvaluator::GCFootPositionMetricEvaluator(void *ptr) {
    m_ptr = ptr;
}
std::vector<int32> GCFootPositionMetricEvaluator::GetFootIndices() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CFootPositionMetricEvaluator", "m_footIndices"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCFootPositionMetricEvaluator::SetFootIndices(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CFootPositionMetricEvaluator", "m_footIndices", false, value);
}
bool GCFootPositionMetricEvaluator::GetIgnoreSlope() const {
    return GetSchemaValue<bool>(m_ptr, "CFootPositionMetricEvaluator", "m_bIgnoreSlope");
}
void GCFootPositionMetricEvaluator::SetIgnoreSlope(bool value) {
    SetSchemaValue(m_ptr, "CFootPositionMetricEvaluator", "m_bIgnoreSlope", false, value);
}
std::string GCFootPositionMetricEvaluator::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFootPositionMetricEvaluator::IsValid() {
    return (m_ptr != nullptr);
}
GCMotionMetricEvaluator GCFootPositionMetricEvaluator::GetParent() const {
    GCMotionMetricEvaluator value(m_ptr);
    return value;
}
void GCFootPositionMetricEvaluator::SetParent(GCMotionMetricEvaluator value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFootPositionMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootPositionMetricEvaluator>("CFootPositionMetricEvaluator")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FootIndices", &GCFootPositionMetricEvaluator::GetFootIndices, &GCFootPositionMetricEvaluator::SetFootIndices)
        .addProperty("IgnoreSlope", &GCFootPositionMetricEvaluator::GetIgnoreSlope, &GCFootPositionMetricEvaluator::SetIgnoreSlope)
        .addProperty("Parent", &GCFootPositionMetricEvaluator::GetParent, &GCFootPositionMetricEvaluator::SetParent)
        .addFunction("ToPtr", &GCFootPositionMetricEvaluator::ToPtr)
        .addFunction("IsValid", &GCFootPositionMetricEvaluator::IsValid)
        .endClass();
}