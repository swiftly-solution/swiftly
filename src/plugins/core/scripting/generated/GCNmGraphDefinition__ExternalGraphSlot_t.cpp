#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmGraphDefinition__ExternalGraphSlot_t::GCNmGraphDefinition__ExternalGraphSlot_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmGraphDefinition__ExternalGraphSlot_t::GCNmGraphDefinition__ExternalGraphSlot_t(void *ptr) {
    m_ptr = ptr;
}
int16_t GCNmGraphDefinition__ExternalGraphSlot_t::GetNodeIdx() const {
    return GetSchemaValue<int16_t>(m_ptr, "CNmGraphDefinition__ExternalGraphSlot_t", "m_nNodeIdx");
}
void GCNmGraphDefinition__ExternalGraphSlot_t::SetNodeIdx(int16_t value) {
    SetSchemaValue(m_ptr, "CNmGraphDefinition__ExternalGraphSlot_t", "m_nNodeIdx", true, value);
}
std::string GCNmGraphDefinition__ExternalGraphSlot_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmGraphDefinition__ExternalGraphSlot_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNmGraphDefinition__ExternalGraphSlot_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmGraphDefinition__ExternalGraphSlot_t>("CNmGraphDefinition__ExternalGraphSlot_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NodeIdx", &GCNmGraphDefinition__ExternalGraphSlot_t::GetNodeIdx, &GCNmGraphDefinition__ExternalGraphSlot_t::SetNodeIdx)
        .addFunction("ToPtr", &GCNmGraphDefinition__ExternalGraphSlot_t::ToPtr)
        .addFunction("IsValid", &GCNmGraphDefinition__ExternalGraphSlot_t::IsValid)
        .endClass();
}