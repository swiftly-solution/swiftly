#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerGravity::GCTriggerGravity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerGravity::GCTriggerGravity(void *ptr) {
    m_ptr = ptr;
}
std::string GCTriggerGravity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerGravity::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerGravity::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerGravity::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerGravity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerGravity>("CTriggerGravity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCTriggerGravity::GetParent, &GCTriggerGravity::SetParent)
        .addFunction("ToPtr", &GCTriggerGravity::ToPtr)
        .addFunction("IsValid", &GCTriggerGravity::IsValid)
        .endClass();
}