#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBoneVelocityMetricEvaluator::GCBoneVelocityMetricEvaluator(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBoneVelocityMetricEvaluator::GCBoneVelocityMetricEvaluator(void *ptr) {
    m_ptr = ptr;
}
int32_t GCBoneVelocityMetricEvaluator::GetBoneIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBoneVelocityMetricEvaluator", "m_nBoneIndex");
}
void GCBoneVelocityMetricEvaluator::SetBoneIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CBoneVelocityMetricEvaluator", "m_nBoneIndex", false, value);
}
std::string GCBoneVelocityMetricEvaluator::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBoneVelocityMetricEvaluator::IsValid() {
    return (m_ptr != nullptr);
}
GCMotionMetricEvaluator GCBoneVelocityMetricEvaluator::GetParent() const {
    GCMotionMetricEvaluator value(m_ptr);
    return value;
}
void GCBoneVelocityMetricEvaluator::SetParent(GCMotionMetricEvaluator value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBoneVelocityMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBoneVelocityMetricEvaluator>("CBoneVelocityMetricEvaluator")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BoneIndex", &GCBoneVelocityMetricEvaluator::GetBoneIndex, &GCBoneVelocityMetricEvaluator::SetBoneIndex)
        .addProperty("Parent", &GCBoneVelocityMetricEvaluator::GetParent, &GCBoneVelocityMetricEvaluator::SetParent)
        .addFunction("ToPtr", &GCBoneVelocityMetricEvaluator::ToPtr)
        .addFunction("IsValid", &GCBoneVelocityMetricEvaluator::IsValid)
        .endClass();
}