#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSmoothFunc::GCSmoothFunc(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSmoothFunc::GCSmoothFunc(void *ptr) {
    m_ptr = ptr;
}
float GCSmoothFunc::GetSmoothAmplitude() const {
    return GetSchemaValue<float>(m_ptr, "CSmoothFunc", "m_flSmoothAmplitude");
}
void GCSmoothFunc::SetSmoothAmplitude(float value) {
    SetSchemaValue(m_ptr, "CSmoothFunc", "m_flSmoothAmplitude", false, value);
}
float GCSmoothFunc::GetSmoothBias() const {
    return GetSchemaValue<float>(m_ptr, "CSmoothFunc", "m_flSmoothBias");
}
void GCSmoothFunc::SetSmoothBias(float value) {
    SetSchemaValue(m_ptr, "CSmoothFunc", "m_flSmoothBias", false, value);
}
float GCSmoothFunc::GetSmoothDuration() const {
    return GetSchemaValue<float>(m_ptr, "CSmoothFunc", "m_flSmoothDuration");
}
void GCSmoothFunc::SetSmoothDuration(float value) {
    SetSchemaValue(m_ptr, "CSmoothFunc", "m_flSmoothDuration", false, value);
}
float GCSmoothFunc::GetSmoothRemainingTime() const {
    return GetSchemaValue<float>(m_ptr, "CSmoothFunc", "m_flSmoothRemainingTime");
}
void GCSmoothFunc::SetSmoothRemainingTime(float value) {
    SetSchemaValue(m_ptr, "CSmoothFunc", "m_flSmoothRemainingTime", false, value);
}
int32_t GCSmoothFunc::GetSmoothDir() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSmoothFunc", "m_nSmoothDir");
}
void GCSmoothFunc::SetSmoothDir(int32_t value) {
    SetSchemaValue(m_ptr, "CSmoothFunc", "m_nSmoothDir", false, value);
}
std::string GCSmoothFunc::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSmoothFunc::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSmoothFunc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSmoothFunc>("CSmoothFunc")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SmoothAmplitude", &GCSmoothFunc::GetSmoothAmplitude, &GCSmoothFunc::SetSmoothAmplitude)
        .addProperty("SmoothBias", &GCSmoothFunc::GetSmoothBias, &GCSmoothFunc::SetSmoothBias)
        .addProperty("SmoothDuration", &GCSmoothFunc::GetSmoothDuration, &GCSmoothFunc::SetSmoothDuration)
        .addProperty("SmoothRemainingTime", &GCSmoothFunc::GetSmoothRemainingTime, &GCSmoothFunc::SetSmoothRemainingTime)
        .addProperty("SmoothDir", &GCSmoothFunc::GetSmoothDir, &GCSmoothFunc::SetSmoothDir)
        .addFunction("ToPtr", &GCSmoothFunc::ToPtr)
        .addFunction("IsValid", &GCSmoothFunc::IsValid)
        .endClass();
}