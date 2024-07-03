#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBonePositionMetricEvaluator::GCBonePositionMetricEvaluator(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBonePositionMetricEvaluator::GCBonePositionMetricEvaluator(void *ptr) {
    m_ptr = ptr;
}
int32_t GCBonePositionMetricEvaluator::GetBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBonePositionMetricEvaluator", "m_nBoneIndex");
}
void GCBonePositionMetricEvaluator::SetBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CBonePositionMetricEvaluator", "m_nBoneIndex", false, value);
}
std::string GCBonePositionMetricEvaluator::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBonePositionMetricEvaluator::IsValid() {
    return (m_ptr != nullptr);
}
GCMotionMetricEvaluator GCBonePositionMetricEvaluator::GetParent() const {
    GCMotionMetricEvaluator value(m_ptr);
    return value;
}
void GCBonePositionMetricEvaluator::SetParent(GCMotionMetricEvaluator value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBonePositionMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBonePositionMetricEvaluator>("CBonePositionMetricEvaluator")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BoneIndex", &GCBonePositionMetricEvaluator::GetBoneIndex, &GCBonePositionMetricEvaluator::SetBoneIndex)
        .addProperty("Parent", &GCBonePositionMetricEvaluator::GetParent, &GCBonePositionMetricEvaluator::SetParent)
        .addFunction("ToPtr", &GCBonePositionMetricEvaluator::ToPtr)
        .addFunction("IsValid", &GCBonePositionMetricEvaluator::IsValid)
        .endClass();
}