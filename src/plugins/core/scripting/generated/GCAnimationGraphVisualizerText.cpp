#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimationGraphVisualizerText::GCAnimationGraphVisualizerText(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimationGraphVisualizerText::GCAnimationGraphVisualizerText(void *ptr) {
    m_ptr = ptr;
}
Vector GCAnimationGraphVisualizerText::GetWsPosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CAnimationGraphVisualizerText", "m_vWsPosition");
}
void GCAnimationGraphVisualizerText::SetWsPosition(Vector value) {
    SetSchemaValue(m_ptr, "CAnimationGraphVisualizerText", "m_vWsPosition", false, value);
}
Color GCAnimationGraphVisualizerText::GetColor() const {
    return GetSchemaValue<Color>(m_ptr, "CAnimationGraphVisualizerText", "m_Color");
}
void GCAnimationGraphVisualizerText::SetColor(Color value) {
    SetSchemaValue(m_ptr, "CAnimationGraphVisualizerText", "m_Color", false, value);
}
std::string GCAnimationGraphVisualizerText::GetText() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CAnimationGraphVisualizerText", "m_Text").Get();
}
void GCAnimationGraphVisualizerText::SetText(std::string value) {
    SetSchemaValue(m_ptr, "CAnimationGraphVisualizerText", "m_Text", false, CUtlString(value.c_str()));
}
std::string GCAnimationGraphVisualizerText::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimationGraphVisualizerText::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimationGraphVisualizerPrimitiveBase GCAnimationGraphVisualizerText::GetParent() const {
    GCAnimationGraphVisualizerPrimitiveBase value(m_ptr);
    return value;
}
void GCAnimationGraphVisualizerText::SetParent(GCAnimationGraphVisualizerPrimitiveBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAnimationGraphVisualizerText(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimationGraphVisualizerText>("CAnimationGraphVisualizerText")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WsPosition", &GCAnimationGraphVisualizerText::GetWsPosition, &GCAnimationGraphVisualizerText::SetWsPosition)
        .addProperty("Color", &GCAnimationGraphVisualizerText::GetColor, &GCAnimationGraphVisualizerText::SetColor)
        .addProperty("Text", &GCAnimationGraphVisualizerText::GetText, &GCAnimationGraphVisualizerText::SetText)
        .addProperty("Parent", &GCAnimationGraphVisualizerText::GetParent, &GCAnimationGraphVisualizerText::SetParent)
        .addFunction("ToPtr", &GCAnimationGraphVisualizerText::ToPtr)
        .addFunction("IsValid", &GCAnimationGraphVisualizerText::IsValid)
        .endClass();
}