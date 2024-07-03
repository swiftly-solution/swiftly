#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCurrentVelocityMetricEvaluator::GCCurrentVelocityMetricEvaluator(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCurrentVelocityMetricEvaluator::GCCurrentVelocityMetricEvaluator(void *ptr) {
    m_ptr = ptr;
}
std::string GCCurrentVelocityMetricEvaluator::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCurrentVelocityMetricEvaluator::IsValid() {
    return (m_ptr != nullptr);
}
GCMotionMetricEvaluator GCCurrentVelocityMetricEvaluator::GetParent() const {
    GCMotionMetricEvaluator value(m_ptr);
    return value;
}
void GCCurrentVelocityMetricEvaluator::SetParent(GCMotionMetricEvaluator value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCurrentVelocityMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCurrentVelocityMetricEvaluator>("CCurrentVelocityMetricEvaluator")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCurrentVelocityMetricEvaluator::GetParent, &GCCurrentVelocityMetricEvaluator::SetParent)
        .addFunction("ToPtr", &GCCurrentVelocityMetricEvaluator::ToPtr)
        .addFunction("IsValid", &GCCurrentVelocityMetricEvaluator::IsValid)
        .endClass();
}