#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCServerRagdollTrigger::GCServerRagdollTrigger(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCServerRagdollTrigger::GCServerRagdollTrigger(void *ptr) {
    m_ptr = ptr;
}
std::string GCServerRagdollTrigger::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCServerRagdollTrigger::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCServerRagdollTrigger::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCServerRagdollTrigger::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCServerRagdollTrigger(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCServerRagdollTrigger>("CServerRagdollTrigger")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCServerRagdollTrigger::GetParent, &GCServerRagdollTrigger::SetParent)
        .addFunction("ToPtr", &GCServerRagdollTrigger::ToPtr)
        .addFunction("IsValid", &GCServerRagdollTrigger::IsValid)
        .endClass();
}