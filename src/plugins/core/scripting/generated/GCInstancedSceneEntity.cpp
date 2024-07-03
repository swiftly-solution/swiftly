#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInstancedSceneEntity::GCInstancedSceneEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInstancedSceneEntity::GCInstancedSceneEntity(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCInstancedSceneEntity::GetOwner() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CInstancedSceneEntity", "m_hOwner"));
    return value;
}
void GCInstancedSceneEntity::SetOwner(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Owner' is not possible.\n");
}
bool GCInstancedSceneEntity::GetHadOwner() const {
    return GetSchemaValue<bool>(m_ptr, "CInstancedSceneEntity", "m_bHadOwner");
}
void GCInstancedSceneEntity::SetHadOwner(bool value) {
    SetSchemaValue(m_ptr, "CInstancedSceneEntity", "m_bHadOwner", false, value);
}
float GCInstancedSceneEntity::GetPostSpeakDelay() const {
    return GetSchemaValue<float>(m_ptr, "CInstancedSceneEntity", "m_flPostSpeakDelay");
}
void GCInstancedSceneEntity::SetPostSpeakDelay(float value) {
    SetSchemaValue(m_ptr, "CInstancedSceneEntity", "m_flPostSpeakDelay", false, value);
}
float GCInstancedSceneEntity::GetPreDelay() const {
    return GetSchemaValue<float>(m_ptr, "CInstancedSceneEntity", "m_flPreDelay");
}
void GCInstancedSceneEntity::SetPreDelay(float value) {
    SetSchemaValue(m_ptr, "CInstancedSceneEntity", "m_flPreDelay", false, value);
}
bool GCInstancedSceneEntity::GetIsBackground() const {
    return GetSchemaValue<bool>(m_ptr, "CInstancedSceneEntity", "m_bIsBackground");
}
void GCInstancedSceneEntity::SetIsBackground(bool value) {
    SetSchemaValue(m_ptr, "CInstancedSceneEntity", "m_bIsBackground", false, value);
}
bool GCInstancedSceneEntity::GetRemoveOnCompletion() const {
    return GetSchemaValue<bool>(m_ptr, "CInstancedSceneEntity", "m_bRemoveOnCompletion");
}
void GCInstancedSceneEntity::SetRemoveOnCompletion(bool value) {
    SetSchemaValue(m_ptr, "CInstancedSceneEntity", "m_bRemoveOnCompletion", false, value);
}
GCBaseEntity GCInstancedSceneEntity::GetTarget() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CInstancedSceneEntity", "m_hTarget"));
    return value;
}
void GCInstancedSceneEntity::SetTarget(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Target' is not possible.\n");
}
std::string GCInstancedSceneEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInstancedSceneEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCSceneEntity GCInstancedSceneEntity::GetParent() const {
    GCSceneEntity value(m_ptr);
    return value;
}
void GCInstancedSceneEntity::SetParent(GCSceneEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInstancedSceneEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInstancedSceneEntity>("CInstancedSceneEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Owner", &GCInstancedSceneEntity::GetOwner, &GCInstancedSceneEntity::SetOwner)
        .addProperty("HadOwner", &GCInstancedSceneEntity::GetHadOwner, &GCInstancedSceneEntity::SetHadOwner)
        .addProperty("PostSpeakDelay", &GCInstancedSceneEntity::GetPostSpeakDelay, &GCInstancedSceneEntity::SetPostSpeakDelay)
        .addProperty("PreDelay", &GCInstancedSceneEntity::GetPreDelay, &GCInstancedSceneEntity::SetPreDelay)
        .addProperty("IsBackground", &GCInstancedSceneEntity::GetIsBackground, &GCInstancedSceneEntity::SetIsBackground)
        .addProperty("RemoveOnCompletion", &GCInstancedSceneEntity::GetRemoveOnCompletion, &GCInstancedSceneEntity::SetRemoveOnCompletion)
        .addProperty("Target", &GCInstancedSceneEntity::GetTarget, &GCInstancedSceneEntity::SetTarget)
        .addProperty("Parent", &GCInstancedSceneEntity::GetParent, &GCInstancedSceneEntity::SetParent)
        .addFunction("ToPtr", &GCInstancedSceneEntity::ToPtr)
        .addFunction("IsValid", &GCInstancedSceneEntity::IsValid)
        .endClass();
}