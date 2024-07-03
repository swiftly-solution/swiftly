#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerBombReset::GCTriggerBombReset(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerBombReset::GCTriggerBombReset(void *ptr) {
    m_ptr = ptr;
}
std::string GCTriggerBombReset::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerBombReset::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerBombReset::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerBombReset::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerBombReset(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerBombReset>("CTriggerBombReset")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCTriggerBombReset::GetParent, &GCTriggerBombReset::SetParent)
        .addFunction("ToPtr", &GCTriggerBombReset::ToPtr)
        .addFunction("IsValid", &GCTriggerBombReset::IsValid)
        .endClass();
}