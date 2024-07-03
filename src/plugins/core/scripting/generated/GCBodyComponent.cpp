#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBodyComponent::GCBodyComponent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBodyComponent::GCBodyComponent(void *ptr) {
    m_ptr = ptr;
}
GCGameSceneNode GCBodyComponent::GetSceneNode() const {
    GCGameSceneNode value(*GetSchemaValuePtr<void*>(m_ptr, "CBodyComponent", "m_pSceneNode"));
    return value;
}
void GCBodyComponent::SetSceneNode(GCGameSceneNode* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'SceneNode' is not possible.\n");
}
GCNetworkVarChainer GCBodyComponent::Get__pChainEntity() const {
    GCNetworkVarChainer value(GetSchemaPtr(m_ptr, "CBodyComponent", "__m_pChainEntity"));
    return value;
}
void GCBodyComponent::Set__pChainEntity(GCNetworkVarChainer value) {
    SetSchemaValue(m_ptr, "CBodyComponent", "__m_pChainEntity", false, value);
}
std::string GCBodyComponent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBodyComponent::IsValid() {
    return (m_ptr != nullptr);
}
GCEntityComponent GCBodyComponent::GetParent() const {
    GCEntityComponent value(m_ptr);
    return value;
}
void GCBodyComponent::SetParent(GCEntityComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBodyComponent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBodyComponent>("CBodyComponent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SceneNode", &GCBodyComponent::GetSceneNode, &GCBodyComponent::SetSceneNode)
        .addProperty("__pChainEntity", &GCBodyComponent::Get__pChainEntity, &GCBodyComponent::Set__pChainEntity)
        .addProperty("Parent", &GCBodyComponent::GetParent, &GCBodyComponent::SetParent)
        .addFunction("ToPtr", &GCBodyComponent::ToPtr)
        .addFunction("IsValid", &GCBodyComponent::IsValid)
        .endClass();
}