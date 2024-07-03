#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerTripWire::GCTriggerTripWire(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerTripWire::GCTriggerTripWire(void *ptr) {
    m_ptr = ptr;
}
std::string GCTriggerTripWire::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerTripWire::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerTripWire::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerTripWire::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerTripWire(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerTripWire>("CTriggerTripWire")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCTriggerTripWire::GetParent, &GCTriggerTripWire::SetParent)
        .addFunction("ToPtr", &GCTriggerTripWire::ToPtr)
        .addFunction("IsValid", &GCTriggerTripWire::IsValid)
        .endClass();
}