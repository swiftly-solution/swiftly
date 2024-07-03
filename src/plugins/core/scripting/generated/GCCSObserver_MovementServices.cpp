#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSObserver_MovementServices::GCCSObserver_MovementServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSObserver_MovementServices::GCCSObserver_MovementServices(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSObserver_MovementServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSObserver_MovementServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayer_MovementServices GCCSObserver_MovementServices::GetParent() const {
    GCPlayer_MovementServices value(m_ptr);
    return value;
}
void GCCSObserver_MovementServices::SetParent(GCPlayer_MovementServices value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSObserver_MovementServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSObserver_MovementServices>("CCSObserver_MovementServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSObserver_MovementServices::GetParent, &GCCSObserver_MovementServices::SetParent)
        .addFunction("ToPtr", &GCCSObserver_MovementServices::ToPtr)
        .addFunction("IsValid", &GCCSObserver_MovementServices::IsValid)
        .endClass();
}