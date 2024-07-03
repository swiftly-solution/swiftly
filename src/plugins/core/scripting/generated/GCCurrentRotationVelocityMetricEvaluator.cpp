#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCurrentRotationVelocityMetricEvaluator::GCCurrentRotationVelocityMetricEvaluator(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCurrentRotationVelocityMetricEvaluator::GCCurrentRotationVelocityMetricEvaluator(void *ptr) {
    m_ptr = ptr;
}
std::string GCCurrentRotationVelocityMetricEvaluator::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCurrentRotationVelocityMetricEvaluator::IsValid() {
    return (m_ptr != nullptr);
}
GCMotionMetricEvaluator GCCurrentRotationVelocityMetricEvaluator::GetParent() const {
    GCMotionMetricEvaluator value(m_ptr);
    return value;
}
void GCCurrentRotationVelocityMetricEvaluator::SetParent(GCMotionMetricEvaluator value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCurrentRotationVelocityMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCurrentRotationVelocityMetricEvaluator>("CCurrentRotationVelocityMetricEvaluator")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCurrentRotationVelocityMetricEvaluator::GetParent, &GCCurrentRotationVelocityMetricEvaluator::SetParent)
        .addFunction("ToPtr", &GCCurrentRotationVelocityMetricEvaluator::ToPtr)
        .addFunction("IsValid", &GCCurrentRotationVelocityMetricEvaluator::IsValid)
        .endClass();
}