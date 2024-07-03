#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerCallback::GCTriggerCallback(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerCallback::GCTriggerCallback(void *ptr) {
    m_ptr = ptr;
}
std::string GCTriggerCallback::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerCallback::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerCallback::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerCallback::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerCallback(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerCallback>("CTriggerCallback")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCTriggerCallback::GetParent, &GCTriggerCallback::SetParent)
        .addFunction("ToPtr", &GCTriggerCallback::ToPtr)
        .addFunction("IsValid", &GCTriggerCallback::IsValid)
        .endClass();
}