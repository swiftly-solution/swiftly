#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSObserver_UseServices::GCCSObserver_UseServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSObserver_UseServices::GCCSObserver_UseServices(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSObserver_UseServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSObserver_UseServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayer_UseServices GCCSObserver_UseServices::GetParent() const {
    GCPlayer_UseServices value(m_ptr);
    return value;
}
void GCCSObserver_UseServices::SetParent(GCPlayer_UseServices value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSObserver_UseServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSObserver_UseServices>("CCSObserver_UseServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSObserver_UseServices::GetParent, &GCCSObserver_UseServices::SetParent)
        .addFunction("ToPtr", &GCCSObserver_UseServices::ToPtr)
        .addFunction("IsValid", &GCCSObserver_UseServices::IsValid)
        .endClass();
}