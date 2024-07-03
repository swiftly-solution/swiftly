#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmLegacyEvent::GCNmLegacyEvent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmLegacyEvent::GCNmLegacyEvent(void *ptr) {
    m_ptr = ptr;
}
std::string GCNmLegacyEvent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmLegacyEvent::IsValid() {
    return (m_ptr != nullptr);
}
GCNmEvent GCNmLegacyEvent::GetParent() const {
    GCNmEvent value(m_ptr);
    return value;
}
void GCNmLegacyEvent::SetParent(GCNmEvent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmLegacyEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmLegacyEvent>("CNmLegacyEvent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNmLegacyEvent::GetParent, &GCNmLegacyEvent::SetParent)
        .addFunction("ToPtr", &GCNmLegacyEvent::ToPtr)
        .addFunction("IsValid", &GCNmLegacyEvent::IsValid)
        .endClass();
}