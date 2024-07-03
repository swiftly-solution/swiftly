#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPathHelperUpdateNode::GCPathHelperUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPathHelperUpdateNode::GCPathHelperUpdateNode(void *ptr) {
    m_ptr = ptr;
}
float GCPathHelperUpdateNode::GetStoppingRadius() const {
    return GetSchemaValue<float>(m_ptr, "CPathHelperUpdateNode", "m_flStoppingRadius");
}
void GCPathHelperUpdateNode::SetStoppingRadius(float value) {
    SetSchemaValue(m_ptr, "CPathHelperUpdateNode", "m_flStoppingRadius", false, value);
}
float GCPathHelperUpdateNode::GetStoppingSpeedScale() const {
    return GetSchemaValue<float>(m_ptr, "CPathHelperUpdateNode", "m_flStoppingSpeedScale");
}
void GCPathHelperUpdateNode::SetStoppingSpeedScale(float value) {
    SetSchemaValue(m_ptr, "CPathHelperUpdateNode", "m_flStoppingSpeedScale", false, value);
}
std::string GCPathHelperUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPathHelperUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCPathHelperUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCPathHelperUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPathHelperUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathHelperUpdateNode>("CPathHelperUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StoppingRadius", &GCPathHelperUpdateNode::GetStoppingRadius, &GCPathHelperUpdateNode::SetStoppingRadius)
        .addProperty("StoppingSpeedScale", &GCPathHelperUpdateNode::GetStoppingSpeedScale, &GCPathHelperUpdateNode::SetStoppingSpeedScale)
        .addProperty("Parent", &GCPathHelperUpdateNode::GetParent, &GCPathHelperUpdateNode::SetParent)
        .addFunction("ToPtr", &GCPathHelperUpdateNode::ToPtr)
        .addFunction("IsValid", &GCPathHelperUpdateNode::IsValid)
        .endClass();
}