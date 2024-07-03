#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GTraceSettings_t::GTraceSettings_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GTraceSettings_t::GTraceSettings_t(void *ptr) {
    m_ptr = ptr;
}
float GTraceSettings_t::GetTraceHeight() const {
    return GetSchemaValue<float>(m_ptr, "TraceSettings_t", "m_flTraceHeight");
}
void GTraceSettings_t::SetTraceHeight(float value) {
    SetSchemaValue(m_ptr, "TraceSettings_t", "m_flTraceHeight", true, value);
}
float GTraceSettings_t::GetTraceRadius() const {
    return GetSchemaValue<float>(m_ptr, "TraceSettings_t", "m_flTraceRadius");
}
void GTraceSettings_t::SetTraceRadius(float value) {
    SetSchemaValue(m_ptr, "TraceSettings_t", "m_flTraceRadius", true, value);
}
std::string GTraceSettings_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GTraceSettings_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassTraceSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GTraceSettings_t>("TraceSettings_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TraceHeight", &GTraceSettings_t::GetTraceHeight, &GTraceSettings_t::SetTraceHeight)
        .addProperty("TraceRadius", &GTraceSettings_t::GetTraceRadius, &GTraceSettings_t::SetTraceRadius)
        .addFunction("ToPtr", &GTraceSettings_t::ToPtr)
        .addFunction("IsValid", &GTraceSettings_t::IsValid)
        .endClass();
}