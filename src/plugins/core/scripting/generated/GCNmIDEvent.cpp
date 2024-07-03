#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmIDEvent::GCNmIDEvent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmIDEvent::GCNmIDEvent(void *ptr) {
    m_ptr = ptr;
}
std::string GCNmIDEvent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmIDEvent::IsValid() {
    return (m_ptr != nullptr);
}
GCNmEvent GCNmIDEvent::GetParent() const {
    GCNmEvent value(m_ptr);
    return value;
}
void GCNmIDEvent::SetParent(GCNmEvent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmIDEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmIDEvent>("CNmIDEvent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCNmIDEvent::GetParent, &GCNmIDEvent::SetParent)
        .addFunction("ToPtr", &GCNmIDEvent::ToPtr)
        .addFunction("IsValid", &GCNmIDEvent::IsValid)
        .endClass();
}