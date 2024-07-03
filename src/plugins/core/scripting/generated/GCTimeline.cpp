#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTimeline::GCTimeline(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTimeline::GCTimeline(void *ptr) {
    m_ptr = ptr;
}
std::vector<float> GCTimeline::GetValues() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CTimeline", "m_flValues"); std::vector<float> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCTimeline::SetValues(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "CTimeline", "m_flValues"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CTimeline", "m_flValues", false, outValue);
}
std::vector<int32_t> GCTimeline::GetValueCounts() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CTimeline", "m_nValueCounts"); std::vector<int32_t> ret; for(int i = 0; i < 64; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCTimeline::SetValueCounts(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CTimeline", "m_nValueCounts"); for(int i = 0; i < 64; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CTimeline", "m_nValueCounts", false, outValue);
}
int32_t GCTimeline::GetBucketCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTimeline", "m_nBucketCount");
}
void GCTimeline::SetBucketCount(int32_t value) {
    SetSchemaValue(m_ptr, "CTimeline", "m_nBucketCount", false, value);
}
float GCTimeline::GetInterval() const {
    return GetSchemaValue<float>(m_ptr, "CTimeline", "m_flInterval");
}
void GCTimeline::SetInterval(float value) {
    SetSchemaValue(m_ptr, "CTimeline", "m_flInterval", false, value);
}
float GCTimeline::GetFinalValue() const {
    return GetSchemaValue<float>(m_ptr, "CTimeline", "m_flFinalValue");
}
void GCTimeline::SetFinalValue(float value) {
    SetSchemaValue(m_ptr, "CTimeline", "m_flFinalValue", false, value);
}
uint64_t GCTimeline::GetCompressionType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CTimeline", "m_nCompressionType");
}
void GCTimeline::SetCompressionType(uint64_t value) {
    SetSchemaValue(m_ptr, "CTimeline", "m_nCompressionType", false, value);
}
bool GCTimeline::GetStopped() const {
    return GetSchemaValue<bool>(m_ptr, "CTimeline", "m_bStopped");
}
void GCTimeline::SetStopped(bool value) {
    SetSchemaValue(m_ptr, "CTimeline", "m_bStopped", false, value);
}
std::string GCTimeline::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTimeline::IsValid() {
    return (m_ptr != nullptr);
}
GIntervalTimer GCTimeline::GetParent() const {
    GIntervalTimer value(m_ptr);
    return value;
}
void GCTimeline::SetParent(GIntervalTimer value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTimeline(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTimeline>("CTimeline")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Values", &GCTimeline::GetValues, &GCTimeline::SetValues)
        .addProperty("ValueCounts", &GCTimeline::GetValueCounts, &GCTimeline::SetValueCounts)
        .addProperty("BucketCount", &GCTimeline::GetBucketCount, &GCTimeline::SetBucketCount)
        .addProperty("Interval", &GCTimeline::GetInterval, &GCTimeline::SetInterval)
        .addProperty("FinalValue", &GCTimeline::GetFinalValue, &GCTimeline::SetFinalValue)
        .addProperty("CompressionType", &GCTimeline::GetCompressionType, &GCTimeline::SetCompressionType)
        .addProperty("Stopped", &GCTimeline::GetStopped, &GCTimeline::SetStopped)
        .addProperty("Parent", &GCTimeline::GetParent, &GCTimeline::SetParent)
        .addFunction("ToPtr", &GCTimeline::ToPtr)
        .addFunction("IsValid", &GCTimeline::IsValid)
        .endClass();
}