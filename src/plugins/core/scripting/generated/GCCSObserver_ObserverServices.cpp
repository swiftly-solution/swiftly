#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSObserver_ObserverServices::GCCSObserver_ObserverServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSObserver_ObserverServices::GCCSObserver_ObserverServices(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSObserver_ObserverServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSObserver_ObserverServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayer_ObserverServices GCCSObserver_ObserverServices::GetParent() const {
    GCPlayer_ObserverServices value(m_ptr);
    return value;
}
void GCCSObserver_ObserverServices::SetParent(GCPlayer_ObserverServices value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSObserver_ObserverServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSObserver_ObserverServices>("CCSObserver_ObserverServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSObserver_ObserverServices::GetParent, &GCCSObserver_ObserverServices::SetParent)
        .addFunction("ToPtr", &GCCSObserver_ObserverServices::ToPtr)
        .addFunction("IsValid", &GCCSObserver_ObserverServices::IsValid)
        .endClass();
}