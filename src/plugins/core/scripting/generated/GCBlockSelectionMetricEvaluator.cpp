#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBlockSelectionMetricEvaluator::GCBlockSelectionMetricEvaluator(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBlockSelectionMetricEvaluator::GCBlockSelectionMetricEvaluator(void *ptr) {
    m_ptr = ptr;
}
std::string GCBlockSelectionMetricEvaluator::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBlockSelectionMetricEvaluator::IsValid() {
    return (m_ptr != nullptr);
}
GCMotionMetricEvaluator GCBlockSelectionMetricEvaluator::GetParent() const {
    GCMotionMetricEvaluator value(m_ptr);
    return value;
}
void GCBlockSelectionMetricEvaluator::SetParent(GCMotionMetricEvaluator value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBlockSelectionMetricEvaluator(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBlockSelectionMetricEvaluator>("CBlockSelectionMetricEvaluator")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCBlockSelectionMetricEvaluator::GetParent, &GCBlockSelectionMetricEvaluator::SetParent)
        .addFunction("ToPtr", &GCBlockSelectionMetricEvaluator::ToPtr)
        .addFunction("IsValid", &GCBlockSelectionMetricEvaluator::IsValid)
        .endClass();
}