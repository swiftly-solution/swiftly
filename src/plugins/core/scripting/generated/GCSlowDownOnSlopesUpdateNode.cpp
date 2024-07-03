#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSlowDownOnSlopesUpdateNode::GCSlowDownOnSlopesUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSlowDownOnSlopesUpdateNode::GCSlowDownOnSlopesUpdateNode(void *ptr) {
    m_ptr = ptr;
}
float GCSlowDownOnSlopesUpdateNode::GetSlowDownStrength() const {
    return GetSchemaValue<float>(m_ptr, "CSlowDownOnSlopesUpdateNode", "m_flSlowDownStrength");
}
void GCSlowDownOnSlopesUpdateNode::SetSlowDownStrength(float value) {
    SetSchemaValue(m_ptr, "CSlowDownOnSlopesUpdateNode", "m_flSlowDownStrength", false, value);
}
std::string GCSlowDownOnSlopesUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSlowDownOnSlopesUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCSlowDownOnSlopesUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCSlowDownOnSlopesUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSlowDownOnSlopesUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSlowDownOnSlopesUpdateNode>("CSlowDownOnSlopesUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SlowDownStrength", &GCSlowDownOnSlopesUpdateNode::GetSlowDownStrength, &GCSlowDownOnSlopesUpdateNode::SetSlowDownStrength)
        .addProperty("Parent", &GCSlowDownOnSlopesUpdateNode::GetParent, &GCSlowDownOnSlopesUpdateNode::SetParent)
        .addFunction("ToPtr", &GCSlowDownOnSlopesUpdateNode::ToPtr)
        .addFunction("IsValid", &GCSlowDownOnSlopesUpdateNode::IsValid)
        .endClass();
}