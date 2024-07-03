#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSObserver_ViewModelServices::GCCSObserver_ViewModelServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSObserver_ViewModelServices::GCCSObserver_ViewModelServices(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSObserver_ViewModelServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSObserver_ViewModelServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayer_ViewModelServices GCCSObserver_ViewModelServices::GetParent() const {
    GCPlayer_ViewModelServices value(m_ptr);
    return value;
}
void GCCSObserver_ViewModelServices::SetParent(GCPlayer_ViewModelServices value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSObserver_ViewModelServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSObserver_ViewModelServices>("CCSObserver_ViewModelServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSObserver_ViewModelServices::GetParent, &GCCSObserver_ViewModelServices::SetParent)
        .addFunction("ToPtr", &GCCSObserver_ViewModelServices::ToPtr)
        .addFunction("IsValid", &GCCSObserver_ViewModelServices::IsValid)
        .endClass();
}