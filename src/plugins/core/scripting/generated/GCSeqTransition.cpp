#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSeqTransition::GCSeqTransition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSeqTransition::GCSeqTransition(void *ptr) {
    m_ptr = ptr;
}
float GCSeqTransition::GetFadeInTime() const {
    return GetSchemaValue<float>(m_ptr, "CSeqTransition", "m_flFadeInTime");
}
void GCSeqTransition::SetFadeInTime(float value) {
    SetSchemaValue(m_ptr, "CSeqTransition", "m_flFadeInTime", false, value);
}
float GCSeqTransition::GetFadeOutTime() const {
    return GetSchemaValue<float>(m_ptr, "CSeqTransition", "m_flFadeOutTime");
}
void GCSeqTransition::SetFadeOutTime(float value) {
    SetSchemaValue(m_ptr, "CSeqTransition", "m_flFadeOutTime", false, value);
}
std::string GCSeqTransition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSeqTransition::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCSeqTransition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqTransition>("CSeqTransition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FadeInTime", &GCSeqTransition::GetFadeInTime, &GCSeqTransition::SetFadeInTime)
        .addProperty("FadeOutTime", &GCSeqTransition::GetFadeOutTime, &GCSeqTransition::SetFadeOutTime)
        .addFunction("ToPtr", &GCSeqTransition::ToPtr)
        .addFunction("IsValid", &GCSeqTransition::IsValid)
        .endClass();
}