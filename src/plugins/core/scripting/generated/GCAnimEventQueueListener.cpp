#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimEventQueueListener::GCAnimEventQueueListener(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimEventQueueListener::GCAnimEventQueueListener(void *ptr) {
    m_ptr = ptr;
}
std::string GCAnimEventQueueListener::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimEventQueueListener::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimEventListenerBase GCAnimEventQueueListener::GetParent() const {
    GCAnimEventListenerBase value(m_ptr);
    return value;
}
void GCAnimEventQueueListener::SetParent(GCAnimEventListenerBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAnimEventQueueListener(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimEventQueueListener>("CAnimEventQueueListener")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCAnimEventQueueListener::GetParent, &GCAnimEventQueueListener::SetParent)
        .addFunction("ToPtr", &GCAnimEventQueueListener::ToPtr)
        .addFunction("IsValid", &GCAnimEventQueueListener::IsValid)
        .endClass();
}