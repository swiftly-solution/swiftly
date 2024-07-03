#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSeqS1SeqDesc::GCSeqS1SeqDesc(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSeqS1SeqDesc::GCSeqS1SeqDesc(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCSeqS1SeqDesc::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CSeqS1SeqDesc", "m_sName");
}
void GCSeqS1SeqDesc::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CSeqS1SeqDesc", "m_sName", false, value);
}
GCSeqSeqDescFlag GCSeqS1SeqDesc::GetFlags() const {
    GCSeqSeqDescFlag value(GetSchemaPtr(m_ptr, "CSeqS1SeqDesc", "m_flags"));
    return value;
}
void GCSeqS1SeqDesc::SetFlags(GCSeqSeqDescFlag value) {
    SetSchemaValue(m_ptr, "CSeqS1SeqDesc", "m_flags", false, value);
}
GCSeqMultiFetch GCSeqS1SeqDesc::GetFetch() const {
    GCSeqMultiFetch value(GetSchemaPtr(m_ptr, "CSeqS1SeqDesc", "m_fetch"));
    return value;
}
void GCSeqS1SeqDesc::SetFetch(GCSeqMultiFetch value) {
    SetSchemaValue(m_ptr, "CSeqS1SeqDesc", "m_fetch", false, value);
}
int32_t GCSeqS1SeqDesc::GetLocalWeightlist() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSeqS1SeqDesc", "m_nLocalWeightlist");
}
void GCSeqS1SeqDesc::SetLocalWeightlist(int32_t value) {
    SetSchemaValue(m_ptr, "CSeqS1SeqDesc", "m_nLocalWeightlist", false, value);
}
std::vector<GCSeqAutoLayer> GCSeqS1SeqDesc::GetAutoLayerArray() const {
    CUtlVector<GCSeqAutoLayer>* vec = GetSchemaValue<CUtlVector<GCSeqAutoLayer>*>(m_ptr, "CSeqS1SeqDesc", "m_autoLayerArray"); std::vector<GCSeqAutoLayer> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSeqS1SeqDesc::SetAutoLayerArray(std::vector<GCSeqAutoLayer> value) {
    SetSchemaValueCUtlVector<GCSeqAutoLayer>(m_ptr, "CSeqS1SeqDesc", "m_autoLayerArray", false, value);
}
std::vector<GCSeqIKLock> GCSeqS1SeqDesc::GetIKLockArray() const {
    CUtlVector<GCSeqIKLock>* vec = GetSchemaValue<CUtlVector<GCSeqIKLock>*>(m_ptr, "CSeqS1SeqDesc", "m_IKLockArray"); std::vector<GCSeqIKLock> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSeqS1SeqDesc::SetIKLockArray(std::vector<GCSeqIKLock> value) {
    SetSchemaValueCUtlVector<GCSeqIKLock>(m_ptr, "CSeqS1SeqDesc", "m_IKLockArray", false, value);
}
GCSeqTransition GCSeqS1SeqDesc::GetTransition() const {
    GCSeqTransition value(GetSchemaPtr(m_ptr, "CSeqS1SeqDesc", "m_transition"));
    return value;
}
void GCSeqS1SeqDesc::SetTransition(GCSeqTransition value) {
    SetSchemaValue(m_ptr, "CSeqS1SeqDesc", "m_transition", false, value);
}
CBufferString GCSeqS1SeqDesc::GetLegacyKeyValueText() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CSeqS1SeqDesc", "m_LegacyKeyValueText");
}
void GCSeqS1SeqDesc::SetLegacyKeyValueText(CBufferString value) {
    SetSchemaValue(m_ptr, "CSeqS1SeqDesc", "m_LegacyKeyValueText", false, value);
}
std::vector<GCAnimActivity> GCSeqS1SeqDesc::GetActivityArray() const {
    CUtlVector<GCAnimActivity>* vec = GetSchemaValue<CUtlVector<GCAnimActivity>*>(m_ptr, "CSeqS1SeqDesc", "m_activityArray"); std::vector<GCAnimActivity> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSeqS1SeqDesc::SetActivityArray(std::vector<GCAnimActivity> value) {
    SetSchemaValueCUtlVector<GCAnimActivity>(m_ptr, "CSeqS1SeqDesc", "m_activityArray", false, value);
}
std::vector<GCFootMotion> GCSeqS1SeqDesc::GetFootMotion() const {
    CUtlVector<GCFootMotion>* vec = GetSchemaValue<CUtlVector<GCFootMotion>*>(m_ptr, "CSeqS1SeqDesc", "m_footMotion"); std::vector<GCFootMotion> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSeqS1SeqDesc::SetFootMotion(std::vector<GCFootMotion> value) {
    SetSchemaValueCUtlVector<GCFootMotion>(m_ptr, "CSeqS1SeqDesc", "m_footMotion", false, value);
}
std::string GCSeqS1SeqDesc::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSeqS1SeqDesc::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSeqS1SeqDesc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqS1SeqDesc>("CSeqS1SeqDesc")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCSeqS1SeqDesc::GetName, &GCSeqS1SeqDesc::SetName)
        .addProperty("Flags", &GCSeqS1SeqDesc::GetFlags, &GCSeqS1SeqDesc::SetFlags)
        .addProperty("Fetch", &GCSeqS1SeqDesc::GetFetch, &GCSeqS1SeqDesc::SetFetch)
        .addProperty("LocalWeightlist", &GCSeqS1SeqDesc::GetLocalWeightlist, &GCSeqS1SeqDesc::SetLocalWeightlist)
        .addProperty("AutoLayerArray", &GCSeqS1SeqDesc::GetAutoLayerArray, &GCSeqS1SeqDesc::SetAutoLayerArray)
        .addProperty("IKLockArray", &GCSeqS1SeqDesc::GetIKLockArray, &GCSeqS1SeqDesc::SetIKLockArray)
        .addProperty("Transition", &GCSeqS1SeqDesc::GetTransition, &GCSeqS1SeqDesc::SetTransition)
        .addProperty("LegacyKeyValueText", &GCSeqS1SeqDesc::GetLegacyKeyValueText, &GCSeqS1SeqDesc::SetLegacyKeyValueText)
        .addProperty("ActivityArray", &GCSeqS1SeqDesc::GetActivityArray, &GCSeqS1SeqDesc::SetActivityArray)
        .addProperty("FootMotion", &GCSeqS1SeqDesc::GetFootMotion, &GCSeqS1SeqDesc::SetFootMotion)
        .addFunction("ToPtr", &GCSeqS1SeqDesc::ToPtr)
        .addFunction("IsValid", &GCSeqS1SeqDesc::IsValid)
        .endClass();
}