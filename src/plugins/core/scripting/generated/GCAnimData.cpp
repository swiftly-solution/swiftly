#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimData::GCAnimData(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimData::GCAnimData(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCAnimData::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimData", "m_name");
}
void GCAnimData::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimData", "m_name", false, value);
}
std::vector<GCAnimDesc> GCAnimData::GetAnimArray() const {
    CUtlVector<GCAnimDesc>* vec = GetSchemaValue<CUtlVector<GCAnimDesc>*>(m_ptr, "CAnimData", "m_animArray"); std::vector<GCAnimDesc> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimData::SetAnimArray(std::vector<GCAnimDesc> value) {
    SetSchemaValueCUtlVector<GCAnimDesc>(m_ptr, "CAnimData", "m_animArray", false, value);
}
std::vector<GCAnimDecoder> GCAnimData::GetDecoderArray() const {
    CUtlVector<GCAnimDecoder>* vec = GetSchemaValue<CUtlVector<GCAnimDecoder>*>(m_ptr, "CAnimData", "m_decoderArray"); std::vector<GCAnimDecoder> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimData::SetDecoderArray(std::vector<GCAnimDecoder> value) {
    SetSchemaValueCUtlVector<GCAnimDecoder>(m_ptr, "CAnimData", "m_decoderArray", false, value);
}
int32_t GCAnimData::GetMaxUniqueFrameIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimData", "m_nMaxUniqueFrameIndex");
}
void GCAnimData::SetMaxUniqueFrameIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimData", "m_nMaxUniqueFrameIndex", false, value);
}
std::vector<GCAnimFrameSegment> GCAnimData::GetSegmentArray() const {
    CUtlVector<GCAnimFrameSegment>* vec = GetSchemaValue<CUtlVector<GCAnimFrameSegment>*>(m_ptr, "CAnimData", "m_segmentArray"); std::vector<GCAnimFrameSegment> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimData::SetSegmentArray(std::vector<GCAnimFrameSegment> value) {
    SetSchemaValueCUtlVector<GCAnimFrameSegment>(m_ptr, "CAnimData", "m_segmentArray", false, value);
}
std::string GCAnimData::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimData::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimData>("CAnimData")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCAnimData::GetName, &GCAnimData::SetName)
        .addProperty("AnimArray", &GCAnimData::GetAnimArray, &GCAnimData::SetAnimArray)
        .addProperty("DecoderArray", &GCAnimData::GetDecoderArray, &GCAnimData::SetDecoderArray)
        .addProperty("MaxUniqueFrameIndex", &GCAnimData::GetMaxUniqueFrameIndex, &GCAnimData::SetMaxUniqueFrameIndex)
        .addProperty("SegmentArray", &GCAnimData::GetSegmentArray, &GCAnimData::SetSegmentArray)
        .addFunction("ToPtr", &GCAnimData::ToPtr)
        .addFunction("IsValid", &GCAnimData::IsValid)
        .endClass();
}