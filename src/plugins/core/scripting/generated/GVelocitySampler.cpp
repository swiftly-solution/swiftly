#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GVelocitySampler::GVelocitySampler(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GVelocitySampler::GVelocitySampler(void *ptr) {
    m_ptr = ptr;
}
Vector GVelocitySampler::GetPrevSample() const {
    return GetSchemaValue<Vector>(m_ptr, "VelocitySampler", "m_prevSample");
}
void GVelocitySampler::SetPrevSample(Vector value) {
    SetSchemaValue(m_ptr, "VelocitySampler", "m_prevSample", false, value);
}
float GVelocitySampler::GetPrevSampleTime() const {
    return GetSchemaValue<float>(m_ptr, "VelocitySampler", "m_fPrevSampleTime");
}
void GVelocitySampler::SetPrevSampleTime(float value) {
    SetSchemaValue(m_ptr, "VelocitySampler", "m_fPrevSampleTime", false, value);
}
float GVelocitySampler::GetIdealSampleRate() const {
    return GetSchemaValue<float>(m_ptr, "VelocitySampler", "m_fIdealSampleRate");
}
void GVelocitySampler::SetIdealSampleRate(float value) {
    SetSchemaValue(m_ptr, "VelocitySampler", "m_fIdealSampleRate", false, value);
}
std::string GVelocitySampler::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GVelocitySampler::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassVelocitySampler(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVelocitySampler>("VelocitySampler")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PrevSample", &GVelocitySampler::GetPrevSample, &GVelocitySampler::SetPrevSample)
        .addProperty("PrevSampleTime", &GVelocitySampler::GetPrevSampleTime, &GVelocitySampler::SetPrevSampleTime)
        .addProperty("IdealSampleRate", &GVelocitySampler::GetIdealSampleRate, &GVelocitySampler::SetIdealSampleRate)
        .addFunction("ToPtr", &GVelocitySampler::ToPtr)
        .addFunction("IsValid", &GVelocitySampler::IsValid)
        .endClass();
}