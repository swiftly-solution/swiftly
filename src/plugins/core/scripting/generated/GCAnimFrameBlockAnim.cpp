#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimFrameBlockAnim::GCAnimFrameBlockAnim(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimFrameBlockAnim::GCAnimFrameBlockAnim(void *ptr) {
    m_ptr = ptr;
}
int32_t GCAnimFrameBlockAnim::GetStartFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimFrameBlockAnim", "m_nStartFrame");
}
void GCAnimFrameBlockAnim::SetStartFrame(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimFrameBlockAnim", "m_nStartFrame", false, value);
}
int32_t GCAnimFrameBlockAnim::GetEndFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAnimFrameBlockAnim", "m_nEndFrame");
}
void GCAnimFrameBlockAnim::SetEndFrame(int32_t value) {
    SetSchemaValue(m_ptr, "CAnimFrameBlockAnim", "m_nEndFrame", false, value);
}
std::vector<int32> GCAnimFrameBlockAnim::GetSegmentIndexArray() const {
    CUtlVector<int32>* vec = GetSchemaValue<CUtlVector<int32>*>(m_ptr, "CAnimFrameBlockAnim", "m_segmentIndexArray"); std::vector<int32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCAnimFrameBlockAnim::SetSegmentIndexArray(std::vector<int32> value) {
    SetSchemaValueCUtlVector<int32>(m_ptr, "CAnimFrameBlockAnim", "m_segmentIndexArray", false, value);
}
std::string GCAnimFrameBlockAnim::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimFrameBlockAnim::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimFrameBlockAnim(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimFrameBlockAnim>("CAnimFrameBlockAnim")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StartFrame", &GCAnimFrameBlockAnim::GetStartFrame, &GCAnimFrameBlockAnim::SetStartFrame)
        .addProperty("EndFrame", &GCAnimFrameBlockAnim::GetEndFrame, &GCAnimFrameBlockAnim::SetEndFrame)
        .addProperty("SegmentIndexArray", &GCAnimFrameBlockAnim::GetSegmentIndexArray, &GCAnimFrameBlockAnim::SetSegmentIndexArray)
        .addFunction("ToPtr", &GCAnimFrameBlockAnim::ToPtr)
        .addFunction("IsValid", &GCAnimFrameBlockAnim::IsValid)
        .endClass();
}