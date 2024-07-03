#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCJiggleBoneUpdateNode::GCJiggleBoneUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCJiggleBoneUpdateNode::GCJiggleBoneUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GJiggleBoneSettingsList_t GCJiggleBoneUpdateNode::GetOpFixedData() const {
    GJiggleBoneSettingsList_t value(GetSchemaPtr(m_ptr, "CJiggleBoneUpdateNode", "m_opFixedData"));
    return value;
}
void GCJiggleBoneUpdateNode::SetOpFixedData(GJiggleBoneSettingsList_t value) {
    SetSchemaValue(m_ptr, "CJiggleBoneUpdateNode", "m_opFixedData", false, value);
}
std::string GCJiggleBoneUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCJiggleBoneUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCJiggleBoneUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCJiggleBoneUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCJiggleBoneUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCJiggleBoneUpdateNode>("CJiggleBoneUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OpFixedData", &GCJiggleBoneUpdateNode::GetOpFixedData, &GCJiggleBoneUpdateNode::SetOpFixedData)
        .addProperty("Parent", &GCJiggleBoneUpdateNode::GetParent, &GCJiggleBoneUpdateNode::SetParent)
        .addFunction("ToPtr", &GCJiggleBoneUpdateNode::ToPtr)
        .addFunction("IsValid", &GCJiggleBoneUpdateNode::IsValid)
        .endClass();
}