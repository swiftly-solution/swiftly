#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimEncodedFrames::GCAnimEncodedFrames(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimEncodedFrames::GCAnimEncodedFrames(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCAnimEncodedFrames::GetFileName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimEncodedFrames", "m_fileName");
}
void GCAnimEncodedFrames::SetFileName(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimEncodedFrames", "m_fileName", false, value);
}
int32_t GCAnimEncodedFrames::GetFrames() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimEncodedFrames", "m_nFrames");
}
void GCAnimEncodedFrames::SetFrames(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimEncodedFrames", "m_nFrames", false, value);
}
int32_t GCAnimEncodedFrames::GetFramesPerBlock() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimEncodedFrames", "m_nFramesPerBlock");
}
void GCAnimEncodedFrames::SetFramesPerBlock(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimEncodedFrames", "m_nFramesPerBlock", false, value);
}
std::vector<GCAnimFrameBlockAnim> GCAnimEncodedFrames::GetFrameblockArray() const {
    CUtlVector<GCAnimFrameBlockAnim>* vec = GetSchemaValue<CUtlVector<GCAnimFrameBlockAnim>*>(m_ptr, "CAnimEncodedFrames", "m_frameblockArray"); std::vector<GCAnimFrameBlockAnim> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimEncodedFrames::SetFrameblockArray(std::vector<GCAnimFrameBlockAnim> value) {
    SetSchemaValueCUtlVector<GCAnimFrameBlockAnim>(m_ptr, "CAnimEncodedFrames", "m_frameblockArray", false, value);
}
GCAnimEncodeDifference GCAnimEncodedFrames::GetUsageDifferences() const {
    GCAnimEncodeDifference value(GetSchemaPtr(m_ptr, "CAnimEncodedFrames", "m_usageDifferences"));
    return value;
}
void GCAnimEncodedFrames::SetUsageDifferences(GCAnimEncodeDifference value) {
    SetSchemaValue(m_ptr, "CAnimEncodedFrames", "m_usageDifferences", false, value);
}
std::string GCAnimEncodedFrames::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimEncodedFrames::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimEncodedFrames(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimEncodedFrames>("CAnimEncodedFrames")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FileName", &GCAnimEncodedFrames::GetFileName, &GCAnimEncodedFrames::SetFileName)
        .addProperty("Frames", &GCAnimEncodedFrames::GetFrames, &GCAnimEncodedFrames::SetFrames)
        .addProperty("FramesPerBlock", &GCAnimEncodedFrames::GetFramesPerBlock, &GCAnimEncodedFrames::SetFramesPerBlock)
        .addProperty("FrameblockArray", &GCAnimEncodedFrames::GetFrameblockArray, &GCAnimEncodedFrames::SetFrameblockArray)
        .addProperty("UsageDifferences", &GCAnimEncodedFrames::GetUsageDifferences, &GCAnimEncodedFrames::SetUsageDifferences)
        .addFunction("ToPtr", &GCAnimEncodedFrames::ToPtr)
        .addFunction("IsValid", &GCAnimEncodedFrames::IsValid)
        .endClass();
}