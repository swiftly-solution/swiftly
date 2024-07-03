#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMotionGraphConfig::GCMotionGraphConfig(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMotionGraphConfig::GCMotionGraphConfig(void *ptr) {
    m_ptr = ptr;
}
std::vector<float> GCMotionGraphConfig::GetParamValues() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CMotionGraphConfig", "m_paramValues"); std::vector<float> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCMotionGraphConfig::SetParamValues(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CMotionGraphConfig", "m_paramValues"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMotionGraphConfig", "m_paramValues", false, outValue);
}
float GCMotionGraphConfig::GetDuration() const {
    return GetSchemaValue<float>(m_ptr, "CMotionGraphConfig", "m_flDuration");
}
void GCMotionGraphConfig::SetDuration(float value) {
    SetSchemaValue(m_ptr, "CMotionGraphConfig", "m_flDuration", false, value);
}
GMotionIndex GCMotionGraphConfig::GetMotionIndex() const {
    GMotionIndex value(GetSchemaPtr(m_ptr, "CMotionGraphConfig", "m_nMotionIndex"));
    return value;
}
void GCMotionGraphConfig::SetMotionIndex(GMotionIndex value) {
    SetSchemaValue(m_ptr, "CMotionGraphConfig", "m_nMotionIndex", false, value);
}
int32_t GCMotionGraphConfig::GetSampleStart() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMotionGraphConfig", "m_nSampleStart");
}
void GCMotionGraphConfig::SetSampleStart(int32_t value) {
    SetSchemaValue(m_ptr, "CMotionGraphConfig", "m_nSampleStart", false, value);
}
int32_t GCMotionGraphConfig::GetSampleCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMotionGraphConfig", "m_nSampleCount");
}
void GCMotionGraphConfig::SetSampleCount(int32_t value) {
    SetSchemaValue(m_ptr, "CMotionGraphConfig", "m_nSampleCount", false, value);
}
std::string GCMotionGraphConfig::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMotionGraphConfig::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCMotionGraphConfig(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionGraphConfig>("CMotionGraphConfig")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ParamValues", &GCMotionGraphConfig::GetParamValues, &GCMotionGraphConfig::SetParamValues)
        .addProperty("Duration", &GCMotionGraphConfig::GetDuration, &GCMotionGraphConfig::SetDuration)
        .addProperty("MotionIndex", &GCMotionGraphConfig::GetMotionIndex, &GCMotionGraphConfig::SetMotionIndex)
        .addProperty("SampleStart", &GCMotionGraphConfig::GetSampleStart, &GCMotionGraphConfig::SetSampleStart)
        .addProperty("SampleCount", &GCMotionGraphConfig::GetSampleCount, &GCMotionGraphConfig::SetSampleCount)
        .addFunction("ToPtr", &GCMotionGraphConfig::ToPtr)
        .addFunction("IsValid", &GCMotionGraphConfig::IsValid)
        .endClass();
}