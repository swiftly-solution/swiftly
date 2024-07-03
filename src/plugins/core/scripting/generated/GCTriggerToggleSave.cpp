#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerToggleSave::GCTriggerToggleSave(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerToggleSave::GCTriggerToggleSave(void *ptr) {
    m_ptr = ptr;
}
std::string GCTriggerToggleSave::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerToggleSave::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerToggleSave::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerToggleSave::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerToggleSave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerToggleSave>("CTriggerToggleSave")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCTriggerToggleSave::GetParent, &GCTriggerToggleSave::SetParent)
        .addFunction("ToPtr", &GCTriggerToggleSave::ToPtr)
        .addFunction("IsValid", &GCTriggerToggleSave::IsValid)
        .endClass();
}