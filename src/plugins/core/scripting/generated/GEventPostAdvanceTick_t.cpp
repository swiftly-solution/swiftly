#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventPostAdvanceTick_t::GEventPostAdvanceTick_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventPostAdvanceTick_t::GEventPostAdvanceTick_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GEventPostAdvanceTick_t::GetCurrentTick() const {
    return GetSchemaValue<int32_t>(m_ptr, "EventPostAdvanceTick_t", "m_nCurrentTick");
}
void GEventPostAdvanceTick_t::SetCurrentTick(int32_t value) {
    SetSchemaValue(m_ptr, "EventPostAdvanceTick_t", "m_nCurrentTick", true, value);
}
int32_t GEventPostAdvanceTick_t::GetCurrentTickThisFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "EventPostAdvanceTick_t", "m_nCurrentTickThisFrame");
}
void GEventPostAdvanceTick_t::SetCurrentTickThisFrame(int32_t value) {
    SetSchemaValue(m_ptr, "EventPostAdvanceTick_t", "m_nCurrentTickThisFrame", true, value);
}
int32_t GEventPostAdvanceTick_t::GetTotalTicksThisFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "EventPostAdvanceTick_t", "m_nTotalTicksThisFrame");
}
void GEventPostAdvanceTick_t::SetTotalTicksThisFrame(int32_t value) {
    SetSchemaValue(m_ptr, "EventPostAdvanceTick_t", "m_nTotalTicksThisFrame", true, value);
}
int32_t GEventPostAdvanceTick_t::GetTotalTicks() const {
    return GetSchemaValue<int32_t>(m_ptr, "EventPostAdvanceTick_t", "m_nTotalTicks");
}
void GEventPostAdvanceTick_t::SetTotalTicks(int32_t value) {
    SetSchemaValue(m_ptr, "EventPostAdvanceTick_t", "m_nTotalTicks", true, value);
}
std::string GEventPostAdvanceTick_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventPostAdvanceTick_t::IsValid() {
    return (m_ptr != nullptr);
}
GEventSimulate_t GEventPostAdvanceTick_t::GetParent() const {
    GEventSimulate_t value(m_ptr);
    return value;
}
void GEventPostAdvanceTick_t::SetParent(GEventSimulate_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassEventPostAdvanceTick_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventPostAdvanceTick_t>("EventPostAdvanceTick_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CurrentTick", &GEventPostAdvanceTick_t::GetCurrentTick, &GEventPostAdvanceTick_t::SetCurrentTick)
        .addProperty("CurrentTickThisFrame", &GEventPostAdvanceTick_t::GetCurrentTickThisFrame, &GEventPostAdvanceTick_t::SetCurrentTickThisFrame)
        .addProperty("TotalTicksThisFrame", &GEventPostAdvanceTick_t::GetTotalTicksThisFrame, &GEventPostAdvanceTick_t::SetTotalTicksThisFrame)
        .addProperty("TotalTicks", &GEventPostAdvanceTick_t::GetTotalTicks, &GEventPostAdvanceTick_t::SetTotalTicks)
        .addProperty("Parent", &GEventPostAdvanceTick_t::GetParent, &GEventPostAdvanceTick_t::SetParent)
        .addFunction("ToPtr", &GEventPostAdvanceTick_t::ToPtr)
        .addFunction("IsValid", &GEventPostAdvanceTick_t::IsValid)
        .endClass();
}