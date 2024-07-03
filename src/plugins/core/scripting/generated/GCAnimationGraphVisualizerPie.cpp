#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimationGraphVisualizerPie::GCAnimationGraphVisualizerPie(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimationGraphVisualizerPie::GCAnimationGraphVisualizerPie(void *ptr) {
    m_ptr = ptr;
}
Vector GCAnimationGraphVisualizerPie::GetWsCenter() const {
    return GetSchemaValue<Vector>(m_ptr, "CAnimationGraphVisualizerPie", "m_vWsCenter");
}
void GCAnimationGraphVisualizerPie::SetWsCenter(Vector value) {
    SetSchemaValue(m_ptr, "CAnimationGraphVisualizerPie", "m_vWsCenter", false, value);
}
Vector GCAnimationGraphVisualizerPie::GetWsStart() const {
    return GetSchemaValue<Vector>(m_ptr, "CAnimationGraphVisualizerPie", "m_vWsStart");
}
void GCAnimationGraphVisualizerPie::SetWsStart(Vector value) {
    SetSchemaValue(m_ptr, "CAnimationGraphVisualizerPie", "m_vWsStart", false, value);
}
Vector GCAnimationGraphVisualizerPie::GetWsEnd() const {
    return GetSchemaValue<Vector>(m_ptr, "CAnimationGraphVisualizerPie", "m_vWsEnd");
}
void GCAnimationGraphVisualizerPie::SetWsEnd(Vector value) {
    SetSchemaValue(m_ptr, "CAnimationGraphVisualizerPie", "m_vWsEnd", false, value);
}
Color GCAnimationGraphVisualizerPie::GetColor() const {
    return GetSchemaValue<Color>(m_ptr, "CAnimationGraphVisualizerPie", "m_Color");
}
void GCAnimationGraphVisualizerPie::SetColor(Color value) {
    SetSchemaValue(m_ptr, "CAnimationGraphVisualizerPie", "m_Color", false, value);
}
std::string GCAnimationGraphVisualizerPie::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimationGraphVisualizerPie::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimationGraphVisualizerPrimitiveBase GCAnimationGraphVisualizerPie::GetParent() const {
    GCAnimationGraphVisualizerPrimitiveBase value(m_ptr);
    return value;
}
void GCAnimationGraphVisualizerPie::SetParent(GCAnimationGraphVisualizerPrimitiveBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAnimationGraphVisualizerPie(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimationGraphVisualizerPie>("CAnimationGraphVisualizerPie")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WsCenter", &GCAnimationGraphVisualizerPie::GetWsCenter, &GCAnimationGraphVisualizerPie::SetWsCenter)
        .addProperty("WsStart", &GCAnimationGraphVisualizerPie::GetWsStart, &GCAnimationGraphVisualizerPie::SetWsStart)
        .addProperty("WsEnd", &GCAnimationGraphVisualizerPie::GetWsEnd, &GCAnimationGraphVisualizerPie::SetWsEnd)
        .addProperty("Color", &GCAnimationGraphVisualizerPie::GetColor, &GCAnimationGraphVisualizerPie::SetColor)
        .addProperty("Parent", &GCAnimationGraphVisualizerPie::GetParent, &GCAnimationGraphVisualizerPie::SetParent)
        .addFunction("ToPtr", &GCAnimationGraphVisualizerPie::ToPtr)
        .addFunction("IsValid", &GCAnimationGraphVisualizerPie::IsValid)
        .endClass();
}