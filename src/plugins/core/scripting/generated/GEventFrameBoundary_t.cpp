#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventFrameBoundary_t::GEventFrameBoundary_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventFrameBoundary_t::GEventFrameBoundary_t(void *ptr) {
    m_ptr = ptr;
}
float GEventFrameBoundary_t::GetFrameTime() const {
    return GetSchemaValue<float>(m_ptr, "EventFrameBoundary_t", "m_flFrameTime");
}
void GEventFrameBoundary_t::SetFrameTime(float value) {
    SetSchemaValue(m_ptr, "EventFrameBoundary_t", "m_flFrameTime", true, value);
}
std::string GEventFrameBoundary_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventFrameBoundary_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventFrameBoundary_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventFrameBoundary_t>("EventFrameBoundary_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FrameTime", &GEventFrameBoundary_t::GetFrameTime, &GEventFrameBoundary_t::SetFrameTime)
        .addFunction("ToPtr", &GEventFrameBoundary_t::ToPtr)
        .addFunction("IsValid", &GEventFrameBoundary_t::IsValid)
        .endClass();
}