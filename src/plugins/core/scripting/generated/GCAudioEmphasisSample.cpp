#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAudioEmphasisSample::GCAudioEmphasisSample(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAudioEmphasisSample::GCAudioEmphasisSample(void *ptr) {
    m_ptr = ptr;
}
float GCAudioEmphasisSample::GetTime() const {
    return GetSchemaValue<float>(m_ptr, "CAudioEmphasisSample", "m_flTime");
}
void GCAudioEmphasisSample::SetTime(float value) {
    SetSchemaValue(m_ptr, "CAudioEmphasisSample", "m_flTime", false, value);
}
float GCAudioEmphasisSample::GetValue() const {
    return GetSchemaValue<float>(m_ptr, "CAudioEmphasisSample", "m_flValue");
}
void GCAudioEmphasisSample::SetValue(float value) {
    SetSchemaValue(m_ptr, "CAudioEmphasisSample", "m_flValue", false, value);
}
std::string GCAudioEmphasisSample::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAudioEmphasisSample::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAudioEmphasisSample(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAudioEmphasisSample>("CAudioEmphasisSample")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Time", &GCAudioEmphasisSample::GetTime, &GCAudioEmphasisSample::SetTime)
        .addProperty("Value", &GCAudioEmphasisSample::GetValue, &GCAudioEmphasisSample::SetValue)
        .addFunction("ToPtr", &GCAudioEmphasisSample::ToPtr)
        .addFunction("IsValid", &GCAudioEmphasisSample::IsValid)
        .endClass();
}