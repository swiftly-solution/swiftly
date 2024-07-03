#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmGraphDefinition__ChildGraphSlot_t::GCNmGraphDefinition__ChildGraphSlot_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmGraphDefinition__ChildGraphSlot_t::GCNmGraphDefinition__ChildGraphSlot_t(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmGraphDefinition__ChildGraphSlot_t::GetNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmGraphDefinition__ChildGraphSlot_t", "m_nNodeIdx");
}
void GCNmGraphDefinition__ChildGraphSlot_t::SetNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmGraphDefinition__ChildGraphSlot_t", "m_nNodeIdx", true, value);
}
int16_t GCNmGraphDefinition__ChildGraphSlot_t::GetDataSlotIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmGraphDefinition__ChildGraphSlot_t", "m_dataSlotIdx");
}
void GCNmGraphDefinition__ChildGraphSlot_t::SetDataSlotIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmGraphDefinition__ChildGraphSlot_t", "m_dataSlotIdx", true, value);
}
std::string GCNmGraphDefinition__ChildGraphSlot_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmGraphDefinition__ChildGraphSlot_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmGraphDefinition__ChildGraphSlot_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmGraphDefinition__ChildGraphSlot_t>("CNmGraphDefinition__ChildGraphSlot_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NodeIdx", &GCNmGraphDefinition__ChildGraphSlot_t::GetNodeIdx, &GCNmGraphDefinition__ChildGraphSlot_t::SetNodeIdx)
        .addProperty("DataSlotIdx", &GCNmGraphDefinition__ChildGraphSlot_t::GetDataSlotIdx, &GCNmGraphDefinition__ChildGraphSlot_t::SetDataSlotIdx)
        .addFunction("ToPtr", &GCNmGraphDefinition__ChildGraphSlot_t::ToPtr)
        .addFunction("IsValid", &GCNmGraphDefinition__ChildGraphSlot_t::IsValid)
        .endClass();
}