#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSequenceGroupData::GCSequenceGroupData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSequenceGroupData::GCSequenceGroupData(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCSequenceGroupData::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CSequenceGroupData", "m_sName");
}
void GCSequenceGroupData::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CSequenceGroupData", "m_sName", false, value);
}
uint32_t GCSequenceGroupData::GetFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CSequenceGroupData", "m_nFlags");
}
void GCSequenceGroupData::SetFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "CSequenceGroupData", "m_nFlags", false, value);
}
std::vector<CBufferString> GCSequenceGroupData::GetLocalSequenceNameArray() const {
    CUtlVector<CBufferString>* vec = GetSchemaValue<CUtlVector<CBufferString>*>(m_ptr, "CSequenceGroupData", "m_localSequenceNameArray"); std::vector<CBufferString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSequenceGroupData::SetLocalSequenceNameArray(std::vector<CBufferString> value) {
    SetSchemaValueCUtlVector<CBufferString>(m_ptr, "CSequenceGroupData", "m_localSequenceNameArray", false, value);
}
std::vector<GCSeqS1SeqDesc> GCSequenceGroupData::GetLocalS1SeqDescArray() const {
    CUtlVector<GCSeqS1SeqDesc>* vec = GetSchemaValue<CUtlVector<GCSeqS1SeqDesc>*>(m_ptr, "CSequenceGroupData", "m_localS1SeqDescArray"); std::vector<GCSeqS1SeqDesc> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSequenceGroupData::SetLocalS1SeqDescArray(std::vector<GCSeqS1SeqDesc> value) {
    SetSchemaValueCUtlVector<GCSeqS1SeqDesc>(m_ptr, "CSequenceGroupData", "m_localS1SeqDescArray", false, value);
}
std::vector<GCSeqS1SeqDesc> GCSequenceGroupData::GetLocalMultiSeqDescArray() const {
    CUtlVector<GCSeqS1SeqDesc>* vec = GetSchemaValue<CUtlVector<GCSeqS1SeqDesc>*>(m_ptr, "CSequenceGroupData", "m_localMultiSeqDescArray"); std::vector<GCSeqS1SeqDesc> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSequenceGroupData::SetLocalMultiSeqDescArray(std::vector<GCSeqS1SeqDesc> value) {
    SetSchemaValueCUtlVector<GCSeqS1SeqDesc>(m_ptr, "CSequenceGroupData", "m_localMultiSeqDescArray", false, value);
}
std::vector<GCSeqSynthAnimDesc> GCSequenceGroupData::GetLocalSynthAnimDescArray() const {
    CUtlVector<GCSeqSynthAnimDesc>* vec = GetSchemaValue<CUtlVector<GCSeqSynthAnimDesc>*>(m_ptr, "CSequenceGroupData", "m_localSynthAnimDescArray"); std::vector<GCSeqSynthAnimDesc> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSequenceGroupData::SetLocalSynthAnimDescArray(std::vector<GCSeqSynthAnimDesc> value) {
    SetSchemaValueCUtlVector<GCSeqSynthAnimDesc>(m_ptr, "CSequenceGroupData", "m_localSynthAnimDescArray", false, value);
}
std::vector<GCSeqCmdSeqDesc> GCSequenceGroupData::GetLocalCmdSeqDescArray() const {
    CUtlVector<GCSeqCmdSeqDesc>* vec = GetSchemaValue<CUtlVector<GCSeqCmdSeqDesc>*>(m_ptr, "CSequenceGroupData", "m_localCmdSeqDescArray"); std::vector<GCSeqCmdSeqDesc> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSequenceGroupData::SetLocalCmdSeqDescArray(std::vector<GCSeqCmdSeqDesc> value) {
    SetSchemaValueCUtlVector<GCSeqCmdSeqDesc>(m_ptr, "CSequenceGroupData", "m_localCmdSeqDescArray", false, value);
}
std::vector<GCSeqBoneMaskList> GCSequenceGroupData::GetLocalBoneMaskArray() const {
    CUtlVector<GCSeqBoneMaskList>* vec = GetSchemaValue<CUtlVector<GCSeqBoneMaskList>*>(m_ptr, "CSequenceGroupData", "m_localBoneMaskArray"); std::vector<GCSeqBoneMaskList> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSequenceGroupData::SetLocalBoneMaskArray(std::vector<GCSeqBoneMaskList> value) {
    SetSchemaValueCUtlVector<GCSeqBoneMaskList>(m_ptr, "CSequenceGroupData", "m_localBoneMaskArray", false, value);
}
std::vector<GCSeqScaleSet> GCSequenceGroupData::GetLocalScaleSetArray() const {
    CUtlVector<GCSeqScaleSet>* vec = GetSchemaValue<CUtlVector<GCSeqScaleSet>*>(m_ptr, "CSequenceGroupData", "m_localScaleSetArray"); std::vector<GCSeqScaleSet> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSequenceGroupData::SetLocalScaleSetArray(std::vector<GCSeqScaleSet> value) {
    SetSchemaValueCUtlVector<GCSeqScaleSet>(m_ptr, "CSequenceGroupData", "m_localScaleSetArray", false, value);
}
std::vector<CBufferString> GCSequenceGroupData::GetLocalBoneNameArray() const {
    CUtlVector<CBufferString>* vec = GetSchemaValue<CUtlVector<CBufferString>*>(m_ptr, "CSequenceGroupData", "m_localBoneNameArray"); std::vector<CBufferString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSequenceGroupData::SetLocalBoneNameArray(std::vector<CBufferString> value) {
    SetSchemaValueCUtlVector<CBufferString>(m_ptr, "CSequenceGroupData", "m_localBoneNameArray", false, value);
}
CBufferString GCSequenceGroupData::GetLocalNodeName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CSequenceGroupData", "m_localNodeName");
}
void GCSequenceGroupData::SetLocalNodeName(CBufferString value) {
    SetSchemaValue(m_ptr, "CSequenceGroupData", "m_localNodeName", false, value);
}
std::vector<GCSeqPoseParamDesc> GCSequenceGroupData::GetLocalPoseParamArray() const {
    CUtlVector<GCSeqPoseParamDesc>* vec = GetSchemaValue<CUtlVector<GCSeqPoseParamDesc>*>(m_ptr, "CSequenceGroupData", "m_localPoseParamArray"); std::vector<GCSeqPoseParamDesc> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSequenceGroupData::SetLocalPoseParamArray(std::vector<GCSeqPoseParamDesc> value) {
    SetSchemaValueCUtlVector<GCSeqPoseParamDesc>(m_ptr, "CSequenceGroupData", "m_localPoseParamArray", false, value);
}
std::vector<GCSeqIKLock> GCSequenceGroupData::GetLocalIKAutoplayLockArray() const {
    CUtlVector<GCSeqIKLock>* vec = GetSchemaValue<CUtlVector<GCSeqIKLock>*>(m_ptr, "CSequenceGroupData", "m_localIKAutoplayLockArray"); std::vector<GCSeqIKLock> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSequenceGroupData::SetLocalIKAutoplayLockArray(std::vector<GCSeqIKLock> value) {
    SetSchemaValueCUtlVector<GCSeqIKLock>(m_ptr, "CSequenceGroupData", "m_localIKAutoplayLockArray", false, value);
}
std::string GCSequenceGroupData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSequenceGroupData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSequenceGroupData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSequenceGroupData>("CSequenceGroupData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCSequenceGroupData::GetName, &GCSequenceGroupData::SetName)
        .addProperty("Flags", &GCSequenceGroupData::GetFlags, &GCSequenceGroupData::SetFlags)
        .addProperty("LocalSequenceNameArray", &GCSequenceGroupData::GetLocalSequenceNameArray, &GCSequenceGroupData::SetLocalSequenceNameArray)
        .addProperty("LocalS1SeqDescArray", &GCSequenceGroupData::GetLocalS1SeqDescArray, &GCSequenceGroupData::SetLocalS1SeqDescArray)
        .addProperty("LocalMultiSeqDescArray", &GCSequenceGroupData::GetLocalMultiSeqDescArray, &GCSequenceGroupData::SetLocalMultiSeqDescArray)
        .addProperty("LocalSynthAnimDescArray", &GCSequenceGroupData::GetLocalSynthAnimDescArray, &GCSequenceGroupData::SetLocalSynthAnimDescArray)
        .addProperty("LocalCmdSeqDescArray", &GCSequenceGroupData::GetLocalCmdSeqDescArray, &GCSequenceGroupData::SetLocalCmdSeqDescArray)
        .addProperty("LocalBoneMaskArray", &GCSequenceGroupData::GetLocalBoneMaskArray, &GCSequenceGroupData::SetLocalBoneMaskArray)
        .addProperty("LocalScaleSetArray", &GCSequenceGroupData::GetLocalScaleSetArray, &GCSequenceGroupData::SetLocalScaleSetArray)
        .addProperty("LocalBoneNameArray", &GCSequenceGroupData::GetLocalBoneNameArray, &GCSequenceGroupData::SetLocalBoneNameArray)
        .addProperty("LocalNodeName", &GCSequenceGroupData::GetLocalNodeName, &GCSequenceGroupData::SetLocalNodeName)
        .addProperty("LocalPoseParamArray", &GCSequenceGroupData::GetLocalPoseParamArray, &GCSequenceGroupData::SetLocalPoseParamArray)
        .addProperty("LocalIKAutoplayLockArray", &GCSequenceGroupData::GetLocalIKAutoplayLockArray, &GCSequenceGroupData::SetLocalIKAutoplayLockArray)
        .addFunction("ToPtr", &GCSequenceGroupData::ToPtr)
        .addFunction("IsValid", &GCSequenceGroupData::IsValid)
        .endClass();
}