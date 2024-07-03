#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointGiveAmmo::GCPointGiveAmmo(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointGiveAmmo::GCPointGiveAmmo(void *ptr) {
    m_ptr = ptr;
}
GCBaseEntity GCPointGiveAmmo::GetActivator() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPointGiveAmmo", "m_pActivator"));
    return value;
}
void GCPointGiveAmmo::SetActivator(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Activator' is not possible.\n");
}
std::string GCPointGiveAmmo::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointGiveAmmo::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCPointGiveAmmo::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCPointGiveAmmo::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointGiveAmmo(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointGiveAmmo>("CPointGiveAmmo")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Activator", &GCPointGiveAmmo::GetActivator, &GCPointGiveAmmo::SetActivator)
        .addProperty("Parent", &GCPointGiveAmmo::GetParent, &GCPointGiveAmmo::SetParent)
        .addFunction("ToPtr", &GCPointGiveAmmo::ToPtr)
        .addFunction("IsValid", &GCPointGiveAmmo::IsValid)
        .endClass();
}