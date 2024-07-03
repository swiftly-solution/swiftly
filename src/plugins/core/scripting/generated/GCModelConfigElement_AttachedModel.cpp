#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCModelConfigElement_AttachedModel::GCModelConfigElement_AttachedModel(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCModelConfigElement_AttachedModel::GCModelConfigElement_AttachedModel(void *ptr) {
    m_ptr = ptr;
}
std::string GCModelConfigElement_AttachedModel::GetInstanceName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_AttachedModel", "m_InstanceName").Get();
}
void GCModelConfigElement_AttachedModel::SetInstanceName(std::string value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_InstanceName", false, CUtlString(value.c_str()));
}
std::string GCModelConfigElement_AttachedModel::GetEntityClass() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_AttachedModel", "m_EntityClass").Get();
}
void GCModelConfigElement_AttachedModel::SetEntityClass(std::string value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_EntityClass", false, CUtlString(value.c_str()));
}
Vector GCModelConfigElement_AttachedModel::GetOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "CModelConfigElement_AttachedModel", "m_vOffset");
}
void GCModelConfigElement_AttachedModel::SetOffset(Vector value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_vOffset", false, value);
}
QAngle GCModelConfigElement_AttachedModel::GetAngOffset() const {
    return GetSchemaValue<QAngle>(m_ptr, "CModelConfigElement_AttachedModel", "m_aAngOffset");
}
void GCModelConfigElement_AttachedModel::SetAngOffset(QAngle value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_aAngOffset", false, value);
}
std::string GCModelConfigElement_AttachedModel::GetAttachmentName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_AttachedModel", "m_AttachmentName").Get();
}
void GCModelConfigElement_AttachedModel::SetAttachmentName(std::string value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_AttachmentName", false, CUtlString(value.c_str()));
}
std::string GCModelConfigElement_AttachedModel::GetLocalAttachmentOffsetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_AttachedModel", "m_LocalAttachmentOffsetName").Get();
}
void GCModelConfigElement_AttachedModel::SetLocalAttachmentOffsetName(std::string value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_LocalAttachmentOffsetName", false, CUtlString(value.c_str()));
}
uint64_t GCModelConfigElement_AttachedModel::GetAttachmentType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CModelConfigElement_AttachedModel", "m_AttachmentType");
}
void GCModelConfigElement_AttachedModel::SetAttachmentType(uint64_t value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_AttachmentType", false, value);
}
bool GCModelConfigElement_AttachedModel::GetBoneMergeFlex() const {
    return GetSchemaValue<bool>(m_ptr, "CModelConfigElement_AttachedModel", "m_bBoneMergeFlex");
}
void GCModelConfigElement_AttachedModel::SetBoneMergeFlex(bool value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_bBoneMergeFlex", false, value);
}
bool GCModelConfigElement_AttachedModel::GetUserSpecifiedColor() const {
    return GetSchemaValue<bool>(m_ptr, "CModelConfigElement_AttachedModel", "m_bUserSpecifiedColor");
}
void GCModelConfigElement_AttachedModel::SetUserSpecifiedColor(bool value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_bUserSpecifiedColor", false, value);
}
bool GCModelConfigElement_AttachedModel::GetUserSpecifiedMaterialGroup() const {
    return GetSchemaValue<bool>(m_ptr, "CModelConfigElement_AttachedModel", "m_bUserSpecifiedMaterialGroup");
}
void GCModelConfigElement_AttachedModel::SetUserSpecifiedMaterialGroup(bool value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_bUserSpecifiedMaterialGroup", false, value);
}
bool GCModelConfigElement_AttachedModel::GetAcceptParentMaterialDrivenDecals() const {
    return GetSchemaValue<bool>(m_ptr, "CModelConfigElement_AttachedModel", "m_bAcceptParentMaterialDrivenDecals");
}
void GCModelConfigElement_AttachedModel::SetAcceptParentMaterialDrivenDecals(bool value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_bAcceptParentMaterialDrivenDecals", false, value);
}
std::string GCModelConfigElement_AttachedModel::GetBodygroupOnOtherModels() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_AttachedModel", "m_BodygroupOnOtherModels").Get();
}
void GCModelConfigElement_AttachedModel::SetBodygroupOnOtherModels(std::string value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_BodygroupOnOtherModels", false, CUtlString(value.c_str()));
}
std::string GCModelConfigElement_AttachedModel::GetMaterialGroupOnOtherModels() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_AttachedModel", "m_MaterialGroupOnOtherModels").Get();
}
void GCModelConfigElement_AttachedModel::SetMaterialGroupOnOtherModels(std::string value) {
    SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_MaterialGroupOnOtherModels", false, CUtlString(value.c_str()));
}
std::string GCModelConfigElement_AttachedModel::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCModelConfigElement_AttachedModel::IsValid() {
    return (m_ptr != nullptr);
}
GCModelConfigElement GCModelConfigElement_AttachedModel::GetParent() const {
    GCModelConfigElement value(m_ptr);
    return value;
}
void GCModelConfigElement_AttachedModel::SetParent(GCModelConfigElement value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCModelConfigElement_AttachedModel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_AttachedModel>("CModelConfigElement_AttachedModel")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InstanceName", &GCModelConfigElement_AttachedModel::GetInstanceName, &GCModelConfigElement_AttachedModel::SetInstanceName)
        .addProperty("EntityClass", &GCModelConfigElement_AttachedModel::GetEntityClass, &GCModelConfigElement_AttachedModel::SetEntityClass)
        .addProperty("Offset", &GCModelConfigElement_AttachedModel::GetOffset, &GCModelConfigElement_AttachedModel::SetOffset)
        .addProperty("AngOffset", &GCModelConfigElement_AttachedModel::GetAngOffset, &GCModelConfigElement_AttachedModel::SetAngOffset)
        .addProperty("AttachmentName", &GCModelConfigElement_AttachedModel::GetAttachmentName, &GCModelConfigElement_AttachedModel::SetAttachmentName)
        .addProperty("LocalAttachmentOffsetName", &GCModelConfigElement_AttachedModel::GetLocalAttachmentOffsetName, &GCModelConfigElement_AttachedModel::SetLocalAttachmentOffsetName)
        .addProperty("AttachmentType", &GCModelConfigElement_AttachedModel::GetAttachmentType, &GCModelConfigElement_AttachedModel::SetAttachmentType)
        .addProperty("BoneMergeFlex", &GCModelConfigElement_AttachedModel::GetBoneMergeFlex, &GCModelConfigElement_AttachedModel::SetBoneMergeFlex)
        .addProperty("UserSpecifiedColor", &GCModelConfigElement_AttachedModel::GetUserSpecifiedColor, &GCModelConfigElement_AttachedModel::SetUserSpecifiedColor)
        .addProperty("UserSpecifiedMaterialGroup", &GCModelConfigElement_AttachedModel::GetUserSpecifiedMaterialGroup, &GCModelConfigElement_AttachedModel::SetUserSpecifiedMaterialGroup)
        .addProperty("AcceptParentMaterialDrivenDecals", &GCModelConfigElement_AttachedModel::GetAcceptParentMaterialDrivenDecals, &GCModelConfigElement_AttachedModel::SetAcceptParentMaterialDrivenDecals)
        .addProperty("BodygroupOnOtherModels", &GCModelConfigElement_AttachedModel::GetBodygroupOnOtherModels, &GCModelConfigElement_AttachedModel::SetBodygroupOnOtherModels)
        .addProperty("MaterialGroupOnOtherModels", &GCModelConfigElement_AttachedModel::GetMaterialGroupOnOtherModels, &GCModelConfigElement_AttachedModel::SetMaterialGroupOnOtherModels)
        .addProperty("Parent", &GCModelConfigElement_AttachedModel::GetParent, &GCModelConfigElement_AttachedModel::SetParent)
        .addFunction("ToPtr", &GCModelConfigElement_AttachedModel::ToPtr)
        .addFunction("IsValid", &GCModelConfigElement_AttachedModel::IsValid)
        .endClass();
}