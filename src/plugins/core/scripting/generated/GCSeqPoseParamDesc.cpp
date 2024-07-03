#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSeqPoseParamDesc::GCSeqPoseParamDesc(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSeqPoseParamDesc::GCSeqPoseParamDesc(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCSeqPoseParamDesc::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CSeqPoseParamDesc", "m_sName");
}
void GCSeqPoseParamDesc::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CSeqPoseParamDesc", "m_sName", false, value);
}
float GCSeqPoseParamDesc::GetStart() const {
    return GetSchemaValue<float>(m_ptr, "CSeqPoseParamDesc", "m_flStart");
}
void GCSeqPoseParamDesc::SetStart(float value) {
    SetSchemaValue(m_ptr, "CSeqPoseParamDesc", "m_flStart", false, value);
}
float GCSeqPoseParamDesc::GetEnd() const {
    return GetSchemaValue<float>(m_ptr, "CSeqPoseParamDesc", "m_flEnd");
}
void GCSeqPoseParamDesc::SetEnd(float value) {
    SetSchemaValue(m_ptr, "CSeqPoseParamDesc", "m_flEnd", false, value);
}
float GCSeqPoseParamDesc::GetLoop() const {
    return GetSchemaValue<float>(m_ptr, "CSeqPoseParamDesc", "m_flLoop");
}
void GCSeqPoseParamDesc::SetLoop(float value) {
    SetSchemaValue(m_ptr, "CSeqPoseParamDesc", "m_flLoop", false, value);
}
bool GCSeqPoseParamDesc::GetLooping() const {
    return GetSchemaValue<bool>(m_ptr, "CSeqPoseParamDesc", "m_bLooping");
}
void GCSeqPoseParamDesc::SetLooping(bool value) {
    SetSchemaValue(m_ptr, "CSeqPoseParamDesc", "m_bLooping", false, value);
}
std::string GCSeqPoseParamDesc::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSeqPoseParamDesc::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSeqPoseParamDesc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqPoseParamDesc>("CSeqPoseParamDesc")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCSeqPoseParamDesc::GetName, &GCSeqPoseParamDesc::SetName)
        .addProperty("Start", &GCSeqPoseParamDesc::GetStart, &GCSeqPoseParamDesc::SetStart)
        .addProperty("End", &GCSeqPoseParamDesc::GetEnd, &GCSeqPoseParamDesc::SetEnd)
        .addProperty("Loop", &GCSeqPoseParamDesc::GetLoop, &GCSeqPoseParamDesc::SetLoop)
        .addProperty("Looping", &GCSeqPoseParamDesc::GetLooping, &GCSeqPoseParamDesc::SetLooping)
        .addFunction("ToPtr", &GCSeqPoseParamDesc::ToPtr)
        .addFunction("IsValid", &GCSeqPoseParamDesc::IsValid)
        .endClass();
}