#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimationGraphVisualizerLine::GCAnimationGraphVisualizerLine(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimationGraphVisualizerLine::GCAnimationGraphVisualizerLine(void *ptr) {
    m_ptr = ptr;
}
Vector GCAnimationGraphVisualizerLine::GetWsPositionStart() const {
    return GetSchemaValue<Vector>(m_ptr, "CAnimationGraphVisualizerLine", "m_vWsPositionStart");
}
void GCAnimationGraphVisualizerLine::SetWsPositionStart(Vector value) {
    SetSchemaValue(m_ptr, "CAnimationGraphVisualizerLine", "m_vWsPositionStart", false, value);
}
Vector GCAnimationGraphVisualizerLine::GetWsPositionEnd() const {
    return GetSchemaValue<Vector>(m_ptr, "CAnimationGraphVisualizerLine", "m_vWsPositionEnd");
}
void GCAnimationGraphVisualizerLine::SetWsPositionEnd(Vector value) {
    SetSchemaValue(m_ptr, "CAnimationGraphVisualizerLine", "m_vWsPositionEnd", false, value);
}
Color GCAnimationGraphVisualizerLine::GetColor() const {
    return GetSchemaValue<Color>(m_ptr, "CAnimationGraphVisualizerLine", "m_Color");
}
void GCAnimationGraphVisualizerLine::SetColor(Color value) {
    SetSchemaValue(m_ptr, "CAnimationGraphVisualizerLine", "m_Color", false, value);
}
std::string GCAnimationGraphVisualizerLine::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimationGraphVisualizerLine::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimationGraphVisualizerPrimitiveBase GCAnimationGraphVisualizerLine::GetParent() const {
    GCAnimationGraphVisualizerPrimitiveBase value(m_ptr);
    return value;
}
void GCAnimationGraphVisualizerLine::SetParent(GCAnimationGraphVisualizerPrimitiveBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAnimationGraphVisualizerLine(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimationGraphVisualizerLine>("CAnimationGraphVisualizerLine")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WsPositionStart", &GCAnimationGraphVisualizerLine::GetWsPositionStart, &GCAnimationGraphVisualizerLine::SetWsPositionStart)
        .addProperty("WsPositionEnd", &GCAnimationGraphVisualizerLine::GetWsPositionEnd, &GCAnimationGraphVisualizerLine::SetWsPositionEnd)
        .addProperty("Color", &GCAnimationGraphVisualizerLine::GetColor, &GCAnimationGraphVisualizerLine::SetColor)
        .addProperty("Parent", &GCAnimationGraphVisualizerLine::GetParent, &GCAnimationGraphVisualizerLine::SetParent)
        .addFunction("ToPtr", &GCAnimationGraphVisualizerLine::ToPtr)
        .addFunction("IsValid", &GCAnimationGraphVisualizerLine::IsValid)
        .endClass();
}