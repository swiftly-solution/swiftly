#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRagdollPropAttached::GCRagdollPropAttached(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRagdollPropAttached::GCRagdollPropAttached(void *ptr) {
    m_ptr = ptr;
}
uint32_t GCRagdollPropAttached::GetBoneIndexAttached() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CRagdollPropAttached", "m_boneIndexAttached");
}
void GCRagdollPropAttached::SetBoneIndexAttached(uint32_t value) {
    SetSchemaValue(m_ptr, "CRagdollPropAttached", "m_boneIndexAttached", false, value);
}
uint32_t GCRagdollPropAttached::GetRagdollAttachedObjectIndex() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CRagdollPropAttached", "m_ragdollAttachedObjectIndex");
}
void GCRagdollPropAttached::SetRagdollAttachedObjectIndex(uint32_t value) {
    SetSchemaValue(m_ptr, "CRagdollPropAttached", "m_ragdollAttachedObjectIndex", false, value);
}
Vector GCRagdollPropAttached::GetAttachmentPointBoneSpace() const {
    return GetSchemaValue<Vector>(m_ptr, "CRagdollPropAttached", "m_attachmentPointBoneSpace");
}
void GCRagdollPropAttached::SetAttachmentPointBoneSpace(Vector value) {
    SetSchemaValue(m_ptr, "CRagdollPropAttached", "m_attachmentPointBoneSpace", false, value);
}
Vector GCRagdollPropAttached::GetAttachmentPointRagdollSpace() const {
    return GetSchemaValue<Vector>(m_ptr, "CRagdollPropAttached", "m_attachmentPointRagdollSpace");
}
void GCRagdollPropAttached::SetAttachmentPointRagdollSpace(Vector value) {
    SetSchemaValue(m_ptr, "CRagdollPropAttached", "m_attachmentPointRagdollSpace", false, value);
}
bool GCRagdollPropAttached::GetShouldDetach() const {
    return GetSchemaValue<bool>(m_ptr, "CRagdollPropAttached", "m_bShouldDetach");
}
void GCRagdollPropAttached::SetShouldDetach(bool value) {
    SetSchemaValue(m_ptr, "CRagdollPropAttached", "m_bShouldDetach", false, value);
}
bool GCRagdollPropAttached::GetShouldDeleteAttachedActivationRecord() const {
    return GetSchemaValue<bool>(m_ptr, "CRagdollPropAttached", "m_bShouldDeleteAttachedActivationRecord");
}
void GCRagdollPropAttached::SetShouldDeleteAttachedActivationRecord(bool value) {
    SetSchemaValue(m_ptr, "CRagdollPropAttached", "m_bShouldDeleteAttachedActivationRecord", false, value);
}
std::string GCRagdollPropAttached::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRagdollPropAttached::IsValid() {
    return (m_ptr != nullptr);
}
GCRagdollProp GCRagdollPropAttached::GetParent() const {
    GCRagdollProp value(m_ptr);
    return value;
}
void GCRagdollPropAttached::SetParent(GCRagdollProp value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRagdollPropAttached(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollPropAttached>("CRagdollPropAttached")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BoneIndexAttached", &GCRagdollPropAttached::GetBoneIndexAttached, &GCRagdollPropAttached::SetBoneIndexAttached)
        .addProperty("RagdollAttachedObjectIndex", &GCRagdollPropAttached::GetRagdollAttachedObjectIndex, &GCRagdollPropAttached::SetRagdollAttachedObjectIndex)
        .addProperty("AttachmentPointBoneSpace", &GCRagdollPropAttached::GetAttachmentPointBoneSpace, &GCRagdollPropAttached::SetAttachmentPointBoneSpace)
        .addProperty("AttachmentPointRagdollSpace", &GCRagdollPropAttached::GetAttachmentPointRagdollSpace, &GCRagdollPropAttached::SetAttachmentPointRagdollSpace)
        .addProperty("ShouldDetach", &GCRagdollPropAttached::GetShouldDetach, &GCRagdollPropAttached::SetShouldDetach)
        .addProperty("ShouldDeleteAttachedActivationRecord", &GCRagdollPropAttached::GetShouldDeleteAttachedActivationRecord, &GCRagdollPropAttached::SetShouldDeleteAttachedActivationRecord)
        .addProperty("Parent", &GCRagdollPropAttached::GetParent, &GCRagdollPropAttached::SetParent)
        .addFunction("ToPtr", &GCRagdollPropAttached::ToPtr)
        .addFunction("IsValid", &GCRagdollPropAttached::IsValid)
        .endClass();
}