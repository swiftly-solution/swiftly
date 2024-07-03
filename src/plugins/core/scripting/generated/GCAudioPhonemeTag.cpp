#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAudioPhonemeTag::GCAudioPhonemeTag(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAudioPhonemeTag::GCAudioPhonemeTag(void *ptr) {
    m_ptr = ptr;
}
float GCAudioPhonemeTag::GetStartTime() const {
    return GetSchemaValue<float>(m_ptr, "CAudioPhonemeTag", "m_flStartTime");
}
void GCAudioPhonemeTag::SetStartTime(float value) {
    SetSchemaValue(m_ptr, "CAudioPhonemeTag", "m_flStartTime", false, value);
}
float GCAudioPhonemeTag::GetEndTime() const {
    return GetSchemaValue<float>(m_ptr, "CAudioPhonemeTag", "m_flEndTime");
}
void GCAudioPhonemeTag::SetEndTime(float value) {
    SetSchemaValue(m_ptr, "CAudioPhonemeTag", "m_flEndTime", false, value);
}
int32_t GCAudioPhonemeTag::GetPhonemeCode() const {
    return GetSchemaValue<int32_t>(m_ptr, "CAudioPhonemeTag", "m_nPhonemeCode");
}
void GCAudioPhonemeTag::SetPhonemeCode(int32_t value) {
    SetSchemaValue(m_ptr, "CAudioPhonemeTag", "m_nPhonemeCode", false, value);
}
std::string GCAudioPhonemeTag::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAudioPhonemeTag::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAudioPhonemeTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAudioPhonemeTag>("CAudioPhonemeTag")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StartTime", &GCAudioPhonemeTag::GetStartTime, &GCAudioPhonemeTag::SetStartTime)
        .addProperty("EndTime", &GCAudioPhonemeTag::GetEndTime, &GCAudioPhonemeTag::SetEndTime)
        .addProperty("PhonemeCode", &GCAudioPhonemeTag::GetPhonemeCode, &GCAudioPhonemeTag::SetPhonemeCode)
        .addFunction("ToPtr", &GCAudioPhonemeTag::ToPtr)
        .addFunction("IsValid", &GCAudioPhonemeTag::IsValid)
        .endClass();
}