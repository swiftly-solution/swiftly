#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimEventListener::GCAnimEventListener(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimEventListener::GCAnimEventListener(void *ptr) {
    m_ptr = ptr;
}
std::string GCAnimEventListener::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimEventListener::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimEventListenerBase GCAnimEventListener::GetParent() const {
    GCAnimEventListenerBase value(m_ptr);
    return value;
}
void GCAnimEventListener::SetParent(GCAnimEventListenerBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAnimEventListener(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimEventListener>("CAnimEventListener")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCAnimEventListener::GetParent, &GCAnimEventListener::SetParent)
        .addFunction("ToPtr", &GCAnimEventListener::ToPtr)
        .addFunction("IsValid", &GCAnimEventListener::IsValid)
        .endClass();
}