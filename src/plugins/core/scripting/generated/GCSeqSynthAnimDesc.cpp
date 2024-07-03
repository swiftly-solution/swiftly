#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSeqSynthAnimDesc::GCSeqSynthAnimDesc(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSeqSynthAnimDesc::GCSeqSynthAnimDesc(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCSeqSynthAnimDesc::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CSeqSynthAnimDesc", "m_sName");
}
void GCSeqSynthAnimDesc::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CSeqSynthAnimDesc", "m_sName", false, value);
}
GCSeqSeqDescFlag GCSeqSynthAnimDesc::GetFlags() const {
    GCSeqSeqDescFlag value(GetSchemaPtr(m_ptr, "CSeqSynthAnimDesc", "m_flags"));
    return value;
}
void GCSeqSynthAnimDesc::SetFlags(GCSeqSeqDescFlag value) {
    SetSchemaValue(m_ptr, "CSeqSynthAnimDesc", "m_flags", false, value);
}
GCSeqTransition GCSeqSynthAnimDesc::GetTransition() const {
    GCSeqTransition value(GetSchemaPtr(m_ptr, "CSeqSynthAnimDesc", "m_transition"));
    return value;
}
void GCSeqSynthAnimDesc::SetTransition(GCSeqTransition value) {
    SetSchemaValue(m_ptr, "CSeqSynthAnimDesc", "m_transition", false, value);
}
int16_t GCSeqSynthAnimDesc::GetLocalBaseReference() const {
    return GetSchemaValue<int16_t>(m_ptr, "CSeqSynthAnimDesc", "m_nLocalBaseReference");
}
void GCSeqSynthAnimDesc::SetLocalBaseReference(int16_t value) {
    SetSchemaValue(m_ptr, "CSeqSynthAnimDesc", "m_nLocalBaseReference", false, value);
}
int16_t GCSeqSynthAnimDesc::GetLocalBoneMask() const {
    return GetSchemaValue<int16_t>(m_ptr, "CSeqSynthAnimDesc", "m_nLocalBoneMask");
}
void GCSeqSynthAnimDesc::SetLocalBoneMask(int16_t value) {
    SetSchemaValue(m_ptr, "CSeqSynthAnimDesc", "m_nLocalBoneMask", false, value);
}
std::vector<GCAnimActivity> GCSeqSynthAnimDesc::GetActivityArray() const {
    CUtlVector<GCAnimActivity>* vec = GetSchemaValue<CUtlVector<GCAnimActivity>*>(m_ptr, "CSeqSynthAnimDesc", "m_activityArray"); std::vector<GCAnimActivity> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSeqSynthAnimDesc::SetActivityArray(std::vector<GCAnimActivity> value) {
    SetSchemaValueCUtlVector<GCAnimActivity>(m_ptr, "CSeqSynthAnimDesc", "m_activityArray", false, value);
}
std::string GCSeqSynthAnimDesc::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSeqSynthAnimDesc::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSeqSynthAnimDesc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqSynthAnimDesc>("CSeqSynthAnimDesc")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCSeqSynthAnimDesc::GetName, &GCSeqSynthAnimDesc::SetName)
        .addProperty("Flags", &GCSeqSynthAnimDesc::GetFlags, &GCSeqSynthAnimDesc::SetFlags)
        .addProperty("Transition", &GCSeqSynthAnimDesc::GetTransition, &GCSeqSynthAnimDesc::SetTransition)
        .addProperty("LocalBaseReference", &GCSeqSynthAnimDesc::GetLocalBaseReference, &GCSeqSynthAnimDesc::SetLocalBaseReference)
        .addProperty("LocalBoneMask", &GCSeqSynthAnimDesc::GetLocalBoneMask, &GCSeqSynthAnimDesc::SetLocalBoneMask)
        .addProperty("ActivityArray", &GCSeqSynthAnimDesc::GetActivityArray, &GCSeqSynthAnimDesc::SetActivityArray)
        .addFunction("ToPtr", &GCSeqSynthAnimDesc::ToPtr)
        .addFunction("IsValid", &GCSeqSynthAnimDesc::IsValid)
        .endClass();
}