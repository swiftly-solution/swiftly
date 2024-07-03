#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventAdvanceTick_t::GEventAdvanceTick_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventAdvanceTick_t::GEventAdvanceTick_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GEventAdvanceTick_t::GetCurrentTick() const {
    return GetSchemaValue<int32_t>(m_ptr, "EventAdvanceTick_t", "m_nCurrentTick");
}
void GEventAdvanceTick_t::SetCurrentTick(int32_t value) {
    SetSchemaValue(m_ptr, "EventAdvanceTick_t", "m_nCurrentTick", true, value);
}
int32_t GEventAdvanceTick_t::GetCurrentTickThisFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "EventAdvanceTick_t", "m_nCurrentTickThisFrame");
}
void GEventAdvanceTick_t::SetCurrentTickThisFrame(int32_t value) {
    SetSchemaValue(m_ptr, "EventAdvanceTick_t", "m_nCurrentTickThisFrame", true, value);
}
int32_t GEventAdvanceTick_t::GetTotalTicksThisFrame() const {
    return GetSchemaValue<int32_t>(m_ptr, "EventAdvanceTick_t", "m_nTotalTicksThisFrame");
}
void GEventAdvanceTick_t::SetTotalTicksThisFrame(int32_t value) {
    SetSchemaValue(m_ptr, "EventAdvanceTick_t", "m_nTotalTicksThisFrame", true, value);
}
int32_t GEventAdvanceTick_t::GetTotalTicks() const {
    return GetSchemaValue<int32_t>(m_ptr, "EventAdvanceTick_t", "m_nTotalTicks");
}
void GEventAdvanceTick_t::SetTotalTicks(int32_t value) {
    SetSchemaValue(m_ptr, "EventAdvanceTick_t", "m_nTotalTicks", true, value);
}
std::string GEventAdvanceTick_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventAdvanceTick_t::IsValid() {
    return (m_ptr != nullptr);
}
GEventSimulate_t GEventAdvanceTick_t::GetParent() const {
    GEventSimulate_t value(m_ptr);
    return value;
}
void GEventAdvanceTick_t::SetParent(GEventSimulate_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassEventAdvanceTick_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventAdvanceTick_t>("EventAdvanceTick_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CurrentTick", &GEventAdvanceTick_t::GetCurrentTick, &GEventAdvanceTick_t::SetCurrentTick)
        .addProperty("CurrentTickThisFrame", &GEventAdvanceTick_t::GetCurrentTickThisFrame, &GEventAdvanceTick_t::SetCurrentTickThisFrame)
        .addProperty("TotalTicksThisFrame", &GEventAdvanceTick_t::GetTotalTicksThisFrame, &GEventAdvanceTick_t::SetTotalTicksThisFrame)
        .addProperty("TotalTicks", &GEventAdvanceTick_t::GetTotalTicks, &GEventAdvanceTick_t::SetTotalTicks)
        .addProperty("Parent", &GEventAdvanceTick_t::GetParent, &GEventAdvanceTick_t::SetParent)
        .addFunction("ToPtr", &GEventAdvanceTick_t::ToPtr)
        .addFunction("IsValid", &GEventAdvanceTick_t::IsValid)
        .endClass();
}