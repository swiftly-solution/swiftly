#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimationGraphVisualizerAxis::GCAnimationGraphVisualizerAxis(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimationGraphVisualizerAxis::GCAnimationGraphVisualizerAxis(void *ptr) {
    m_ptr = ptr;
}
float GCAnimationGraphVisualizerAxis::GetAxisSize() const {
    return GetSchemaValue<float>(m_ptr, "CAnimationGraphVisualizerAxis", "m_flAxisSize");
}
void GCAnimationGraphVisualizerAxis::SetAxisSize(float value) {
    SetSchemaValue(m_ptr, "CAnimationGraphVisualizerAxis", "m_flAxisSize", false, value);
}
std::string GCAnimationGraphVisualizerAxis::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimationGraphVisualizerAxis::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimationGraphVisualizerPrimitiveBase GCAnimationGraphVisualizerAxis::GetParent() const {
    GCAnimationGraphVisualizerPrimitiveBase value(m_ptr);
    return value;
}
void GCAnimationGraphVisualizerAxis::SetParent(GCAnimationGraphVisualizerPrimitiveBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAnimationGraphVisualizerAxis(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimationGraphVisualizerAxis>("CAnimationGraphVisualizerAxis")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AxisSize", &GCAnimationGraphVisualizerAxis::GetAxisSize, &GCAnimationGraphVisualizerAxis::SetAxisSize)
        .addProperty("Parent", &GCAnimationGraphVisualizerAxis::GetParent, &GCAnimationGraphVisualizerAxis::SetParent)
        .addFunction("ToPtr", &GCAnimationGraphVisualizerAxis::ToPtr)
        .addFunction("IsValid", &GCAnimationGraphVisualizerAxis::IsValid)
        .endClass();
}