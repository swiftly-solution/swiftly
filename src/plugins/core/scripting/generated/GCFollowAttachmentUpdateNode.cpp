#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFollowAttachmentUpdateNode::GCFollowAttachmentUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFollowAttachmentUpdateNode::GCFollowAttachmentUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GFollowAttachmentSettings_t GCFollowAttachmentUpdateNode::GetOpFixedData() const {
    GFollowAttachmentSettings_t value(GetSchemaPtr(m_ptr, "CFollowAttachmentUpdateNode", "m_opFixedData"));
    return value;
}
void GCFollowAttachmentUpdateNode::SetOpFixedData(GFollowAttachmentSettings_t value) {
    SetSchemaValue(m_ptr, "CFollowAttachmentUpdateNode", "m_opFixedData", false, value);
}
std::string GCFollowAttachmentUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFollowAttachmentUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCUnaryUpdateNode GCFollowAttachmentUpdateNode::GetParent() const {
    GCUnaryUpdateNode value(m_ptr);
    return value;
}
void GCFollowAttachmentUpdateNode::SetParent(GCUnaryUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFollowAttachmentUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFollowAttachmentUpdateNode>("CFollowAttachmentUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OpFixedData", &GCFollowAttachmentUpdateNode::GetOpFixedData, &GCFollowAttachmentUpdateNode::SetOpFixedData)
        .addProperty("Parent", &GCFollowAttachmentUpdateNode::GetParent, &GCFollowAttachmentUpdateNode::SetParent)
        .addFunction("ToPtr", &GCFollowAttachmentUpdateNode::ToPtr)
        .addFunction("IsValid", &GCFollowAttachmentUpdateNode::IsValid)
        .endClass();
}