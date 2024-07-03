#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerLerpObject::GCTriggerLerpObject(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerLerpObject::GCTriggerLerpObject(void *ptr) {
    m_ptr = ptr;
}
std::string GCTriggerLerpObject::GetLerpTarget() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerLerpObject", "m_iszLerpTarget").String();
}
void GCTriggerLerpObject::SetLerpTarget(std::string value) {
    SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_iszLerpTarget", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseEntity GCTriggerLerpObject::GetLerpTarget1() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CTriggerLerpObject", "m_hLerpTarget"));
    return value;
}
void GCTriggerLerpObject::SetLerpTarget1(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'LerpTarget1' is not possible.\n");
}
std::string GCTriggerLerpObject::GetLerpTargetAttachment() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerLerpObject", "m_iszLerpTargetAttachment").String();
}
void GCTriggerLerpObject::SetLerpTargetAttachment(std::string value) {
    SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_iszLerpTargetAttachment", false, CUtlSymbolLarge(value.c_str()));
}
float GCTriggerLerpObject::GetLerpDuration() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerLerpObject", "m_flLerpDuration");
}
void GCTriggerLerpObject::SetLerpDuration(float value) {
    SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_flLerpDuration", false, value);
}
bool GCTriggerLerpObject::GetLerpRestoreMoveType() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerLerpObject", "m_bLerpRestoreMoveType");
}
void GCTriggerLerpObject::SetLerpRestoreMoveType(bool value) {
    SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_bLerpRestoreMoveType", false, value);
}
bool GCTriggerLerpObject::GetSingleLerpObject() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerLerpObject", "m_bSingleLerpObject");
}
void GCTriggerLerpObject::SetSingleLerpObject(bool value) {
    SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_bSingleLerpObject", false, value);
}
std::vector<Glerpdata_t> GCTriggerLerpObject::GetLerpingObjects() const {
    CUtlVector<Glerpdata_t>* vec = GetSchemaValue<CUtlVector<Glerpdata_t>*>(m_ptr, "CTriggerLerpObject", "m_vecLerpingObjects"); std::vector<Glerpdata_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCTriggerLerpObject::SetLerpingObjects(std::vector<Glerpdata_t> value) {
    SetSchemaValueCUtlVector<Glerpdata_t>(m_ptr, "CTriggerLerpObject", "m_vecLerpingObjects", false, value);
}
std::string GCTriggerLerpObject::GetLerpEffect() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerLerpObject", "m_iszLerpEffect").String();
}
void GCTriggerLerpObject::SetLerpEffect(std::string value) {
    SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_iszLerpEffect", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCTriggerLerpObject::GetLerpSound() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerLerpObject", "m_iszLerpSound").String();
}
void GCTriggerLerpObject::SetLerpSound(std::string value) {
    SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_iszLerpSound", false, CUtlSymbolLarge(value.c_str()));
}
bool GCTriggerLerpObject::GetAttachTouchingObject() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerLerpObject", "m_bAttachTouchingObject");
}
void GCTriggerLerpObject::SetAttachTouchingObject(bool value) {
    SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_bAttachTouchingObject", false, value);
}
GCBaseEntity GCTriggerLerpObject::GetEntityToWaitForDisconnect() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CTriggerLerpObject", "m_hEntityToWaitForDisconnect"));
    return value;
}
void GCTriggerLerpObject::SetEntityToWaitForDisconnect(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'EntityToWaitForDisconnect' is not possible.\n");
}
GCEntityIOOutput GCTriggerLerpObject::GetOnLerpStarted() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTriggerLerpObject", "m_OnLerpStarted"));
    return value;
}
void GCTriggerLerpObject::SetOnLerpStarted(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_OnLerpStarted", false, value);
}
GCEntityIOOutput GCTriggerLerpObject::GetOnLerpFinished() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTriggerLerpObject", "m_OnLerpFinished"));
    return value;
}
void GCTriggerLerpObject::SetOnLerpFinished(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTriggerLerpObject", "m_OnLerpFinished", false, value);
}
std::string GCTriggerLerpObject::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerLerpObject::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerLerpObject::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerLerpObject::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerLerpObject(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerLerpObject>("CTriggerLerpObject")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LerpTarget", &GCTriggerLerpObject::GetLerpTarget, &GCTriggerLerpObject::SetLerpTarget)
        .addProperty("LerpTarget1", &GCTriggerLerpObject::GetLerpTarget1, &GCTriggerLerpObject::SetLerpTarget1)
        .addProperty("LerpTargetAttachment", &GCTriggerLerpObject::GetLerpTargetAttachment, &GCTriggerLerpObject::SetLerpTargetAttachment)
        .addProperty("LerpDuration", &GCTriggerLerpObject::GetLerpDuration, &GCTriggerLerpObject::SetLerpDuration)
        .addProperty("LerpRestoreMoveType", &GCTriggerLerpObject::GetLerpRestoreMoveType, &GCTriggerLerpObject::SetLerpRestoreMoveType)
        .addProperty("SingleLerpObject", &GCTriggerLerpObject::GetSingleLerpObject, &GCTriggerLerpObject::SetSingleLerpObject)
        .addProperty("LerpingObjects", &GCTriggerLerpObject::GetLerpingObjects, &GCTriggerLerpObject::SetLerpingObjects)
        .addProperty("LerpEffect", &GCTriggerLerpObject::GetLerpEffect, &GCTriggerLerpObject::SetLerpEffect)
        .addProperty("LerpSound", &GCTriggerLerpObject::GetLerpSound, &GCTriggerLerpObject::SetLerpSound)
        .addProperty("AttachTouchingObject", &GCTriggerLerpObject::GetAttachTouchingObject, &GCTriggerLerpObject::SetAttachTouchingObject)
        .addProperty("EntityToWaitForDisconnect", &GCTriggerLerpObject::GetEntityToWaitForDisconnect, &GCTriggerLerpObject::SetEntityToWaitForDisconnect)
        .addProperty("OnLerpStarted", &GCTriggerLerpObject::GetOnLerpStarted, &GCTriggerLerpObject::SetOnLerpStarted)
        .addProperty("OnLerpFinished", &GCTriggerLerpObject::GetOnLerpFinished, &GCTriggerLerpObject::SetOnLerpFinished)
        .addProperty("Parent", &GCTriggerLerpObject::GetParent, &GCTriggerLerpObject::SetParent)
        .addFunction("ToPtr", &GCTriggerLerpObject::ToPtr)
        .addFunction("IsValid", &GCTriggerLerpObject::IsValid)
        .endClass();
}