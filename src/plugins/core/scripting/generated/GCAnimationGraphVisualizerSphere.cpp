#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimationGraphVisualizerSphere::GCAnimationGraphVisualizerSphere(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimationGraphVisualizerSphere::GCAnimationGraphVisualizerSphere(void *ptr) {
    m_ptr = ptr;
}
Vector GCAnimationGraphVisualizerSphere::GetWsPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CAnimationGraphVisualizerSphere", "m_vWsPosition");
}
void GCAnimationGraphVisualizerSphere::SetWsPosition(Vector value) {
    SetSchemaValue(m_ptr, "CAnimationGraphVisualizerSphere", "m_vWsPosition", false, value);
}
float GCAnimationGraphVisualizerSphere::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CAnimationGraphVisualizerSphere", "m_flRadius");
}
void GCAnimationGraphVisualizerSphere::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CAnimationGraphVisualizerSphere", "m_flRadius", false, value);
}
Color GCAnimationGraphVisualizerSphere::GetColor() const {
    return GetSchemaValue<Color>(m_ptr, "CAnimationGraphVisualizerSphere", "m_Color");
}
void GCAnimationGraphVisualizerSphere::SetColor(Color value) {
    SetSchemaValue(m_ptr, "CAnimationGraphVisualizerSphere", "m_Color", false, value);
}
std::string GCAnimationGraphVisualizerSphere::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimationGraphVisualizerSphere::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimationGraphVisualizerPrimitiveBase GCAnimationGraphVisualizerSphere::GetParent() const {
    GCAnimationGraphVisualizerPrimitiveBase value(m_ptr);
    return value;
}
void GCAnimationGraphVisualizerSphere::SetParent(GCAnimationGraphVisualizerPrimitiveBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAnimationGraphVisualizerSphere(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimationGraphVisualizerSphere>("CAnimationGraphVisualizerSphere")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WsPosition", &GCAnimationGraphVisualizerSphere::GetWsPosition, &GCAnimationGraphVisualizerSphere::SetWsPosition)
        .addProperty("Radius", &GCAnimationGraphVisualizerSphere::GetRadius, &GCAnimationGraphVisualizerSphere::SetRadius)
        .addProperty("Color", &GCAnimationGraphVisualizerSphere::GetColor, &GCAnimationGraphVisualizerSphere::SetColor)
        .addProperty("Parent", &GCAnimationGraphVisualizerSphere::GetParent, &GCAnimationGraphVisualizerSphere::SetParent)
        .addFunction("ToPtr", &GCAnimationGraphVisualizerSphere::ToPtr)
        .addFunction("IsValid", &GCAnimationGraphVisualizerSphere::IsValid)
        .endClass();
}