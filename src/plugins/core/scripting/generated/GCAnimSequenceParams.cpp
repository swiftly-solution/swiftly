#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimSequenceParams::GCAnimSequenceParams(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimSequenceParams::GCAnimSequenceParams(void *ptr) {
    m_ptr = ptr;
}
float GCAnimSequenceParams::GetFadeInTime() const {
    return GetSchemaValue<float>(m_ptr, "CAnimSequenceParams", "m_flFadeInTime");
}
void GCAnimSequenceParams::SetFadeInTime(float value) {
    SetSchemaValue(m_ptr, "CAnimSequenceParams", "m_flFadeInTime", false, value);
}
float GCAnimSequenceParams::GetFadeOutTime() const {
    return GetSchemaValue<float>(m_ptr, "CAnimSequenceParams", "m_flFadeOutTime");
}
void GCAnimSequenceParams::SetFadeOutTime(float value) {
    SetSchemaValue(m_ptr, "CAnimSequenceParams", "m_flFadeOutTime", false, value);
}
std::string GCAnimSequenceParams::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimSequenceParams::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimSequenceParams(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimSequenceParams>("CAnimSequenceParams")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FadeInTime", &GCAnimSequenceParams::GetFadeInTime, &GCAnimSequenceParams::SetFadeInTime)
        .addProperty("FadeOutTime", &GCAnimSequenceParams::GetFadeOutTime, &GCAnimSequenceParams::SetFadeOutTime)
        .addFunction("ToPtr", &GCAnimSequenceParams::ToPtr)
        .addFunction("IsValid", &GCAnimSequenceParams::IsValid)
        .endClass();
}