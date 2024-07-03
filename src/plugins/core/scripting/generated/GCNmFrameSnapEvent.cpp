#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNmFrameSnapEvent::GCNmFrameSnapEvent(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNmFrameSnapEvent::GCNmFrameSnapEvent(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCNmFrameSnapEvent::GetFrameSnapMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CNmFrameSnapEvent", "m_frameSnapMode");
}
void GCNmFrameSnapEvent::SetFrameSnapMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CNmFrameSnapEvent", "m_frameSnapMode", false, value);
}
std::string GCNmFrameSnapEvent::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNmFrameSnapEvent::IsValid() {
    return (m_ptr != nullptr);
}
GCNmEvent GCNmFrameSnapEvent::GetParent() const {
    GCNmEvent value(m_ptr);
    return value;
}
void GCNmFrameSnapEvent::SetParent(GCNmEvent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCNmFrameSnapEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNmFrameSnapEvent>("CNmFrameSnapEvent")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FrameSnapMode", &GCNmFrameSnapEvent::GetFrameSnapMode, &GCNmFrameSnapEvent::SetFrameSnapMode)
        .addProperty("Parent", &GCNmFrameSnapEvent::GetParent, &GCNmFrameSnapEvent::SetParent)
        .addFunction("ToPtr", &GCNmFrameSnapEvent::ToPtr)
        .addFunction("IsValid", &GCNmFrameSnapEvent::IsValid)
        .endClass();
}