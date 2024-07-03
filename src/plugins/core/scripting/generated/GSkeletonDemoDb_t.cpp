#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSkeletonDemoDb_t::GSkeletonDemoDb_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSkeletonDemoDb_t::GSkeletonDemoDb_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<GSkeletonAnimCapture_t*> GSkeletonDemoDb_t::GetAnimCaptures() const {
    CUtlVector<GSkeletonAnimCapture_t*>* vec = GetSchemaValue<CUtlVector<GSkeletonAnimCapture_t*>*>(m_ptr, "SkeletonDemoDb_t", "m_AnimCaptures"); std::vector<GSkeletonAnimCapture_t*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GSkeletonDemoDb_t::SetAnimCaptures(std::vector<GSkeletonAnimCapture_t*> value) {
    SetSchemaValueCUtlVector<GSkeletonAnimCapture_t*>(m_ptr, "SkeletonDemoDb_t", "m_AnimCaptures", true, value);
}
std::vector<GSkeletonAnimCapture_t> GSkeletonDemoDb_t::GetCameraTrack() const {
    CUtlVector<GSkeletonAnimCapture_t>* vec = GetSchemaValue<CUtlVector<GSkeletonAnimCapture_t>*>(m_ptr, "SkeletonDemoDb_t", "m_CameraTrack"); std::vector<GSkeletonAnimCapture_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GSkeletonDemoDb_t::SetCameraTrack(std::vector<GSkeletonAnimCapture_t> value) {
    SetSchemaValueCUtlVector<GSkeletonAnimCapture_t>(m_ptr, "SkeletonDemoDb_t", "m_CameraTrack", true, value);
}
float GSkeletonDemoDb_t::GetRecordingTime() const {
    return GetSchemaValue<float>(m_ptr, "SkeletonDemoDb_t", "m_flRecordingTime");
}
void GSkeletonDemoDb_t::SetRecordingTime(float value) {
    SetSchemaValue(m_ptr, "SkeletonDemoDb_t", "m_flRecordingTime", true, value);
}
std::string GSkeletonDemoDb_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSkeletonDemoDb_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSkeletonDemoDb_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSkeletonDemoDb_t>("SkeletonDemoDb_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("AnimCaptures", &GSkeletonDemoDb_t::GetAnimCaptures, &GSkeletonDemoDb_t::SetAnimCaptures)
        .addProperty("CameraTrack", &GSkeletonDemoDb_t::GetCameraTrack, &GSkeletonDemoDb_t::SetCameraTrack)
        .addProperty("RecordingTime", &GSkeletonDemoDb_t::GetRecordingTime, &GSkeletonDemoDb_t::SetRecordingTime)
        .addFunction("ToPtr", &GSkeletonDemoDb_t::ToPtr)
        .addFunction("IsValid", &GSkeletonDemoDb_t::IsValid)
        .endClass();
}