#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerHostageReset::GCTriggerHostageReset(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerHostageReset::GCTriggerHostageReset(void *ptr) {
    m_ptr = ptr;
}
std::string GCTriggerHostageReset::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerHostageReset::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerHostageReset::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerHostageReset::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerHostageReset(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerHostageReset>("CTriggerHostageReset")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCTriggerHostageReset::GetParent, &GCTriggerHostageReset::SetParent)
        .addFunction("ToPtr", &GCTriggerHostageReset::ToPtr)
        .addFunction("IsValid", &GCTriggerHostageReset::IsValid)
        .endClass();
}