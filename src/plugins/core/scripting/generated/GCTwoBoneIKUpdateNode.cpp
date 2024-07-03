#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTwoBoneIKUpdateNode::GCTwoBoneIKUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTwoBoneIKUpdateNode::GCTwoBoneIKUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GTwoBoneIKSettings_t GCTwoBoneIKUpdateNode::GetOpFixedData() const {
    GTwoBoneIKSettings_t value(GetSchemaPtr(m_ptr, "CTwoBoneIKUpdateNode", "m_opFixedData"));
    return value;
}
void GCTwoBoneIKUpdateNode::SetOpFixedData(GTwoBoneIKSettings_t value) {
    SetSchemaValue(m_ptr, "CTwoBoneIKUpdateNode", "m_opFixedData", false, value);
}
std::string GCTwoBoneIKUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTwoBoneIKUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCTwoBoneIKUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCTwoBoneIKUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTwoBoneIKUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTwoBoneIKUpdateNode>("CTwoBoneIKUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OpFixedData", &GCTwoBoneIKUpdateNode::GetOpFixedData, &GCTwoBoneIKUpdateNode::SetOpFixedData)
        .addProperty("Parent", &GCTwoBoneIKUpdateNode::GetParent, &GCTwoBoneIKUpdateNode::SetParent)
        .addFunction("ToPtr", &GCTwoBoneIKUpdateNode::ToPtr)
        .addFunction("IsValid", &GCTwoBoneIKUpdateNode::IsValid)
        .endClass();
}