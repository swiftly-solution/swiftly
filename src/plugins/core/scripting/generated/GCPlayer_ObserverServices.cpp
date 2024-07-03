#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayer_ObserverServices::GCPlayer_ObserverServices(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayer_ObserverServices::GCPlayer_ObserverServices(void *ptr) {
    m_ptr = ptr;
}
uint8_t GCPlayer_ObserverServices::GetObserverMode() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CPlayer_ObserverServices", "m_iObserverMode");
}
void GCPlayer_ObserverServices::SetObserverMode(uint8_t value) {
    SetSchemaValue(m_ptr, "CPlayer_ObserverServices", "m_iObserverMode", false, value);
}
GCBaseEntity GCPlayer_ObserverServices::GetObserverTarget() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPlayer_ObserverServices", "m_hObserverTarget"));
    return value;
}
void GCPlayer_ObserverServices::SetObserverTarget(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ObserverTarget' is not possible.\n");
}
uint64_t GCPlayer_ObserverServices::GetObserverLastMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CPlayer_ObserverServices", "m_iObserverLastMode");
}
void GCPlayer_ObserverServices::SetObserverLastMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CPlayer_ObserverServices", "m_iObserverLastMode", false, value);
}
bool GCPlayer_ObserverServices::GetForcedObserverMode() const {
    return GetSchemaValue<bool>(m_ptr, "CPlayer_ObserverServices", "m_bForcedObserverMode");
}
void GCPlayer_ObserverServices::SetForcedObserverMode(bool value) {
    SetSchemaValue(m_ptr, "CPlayer_ObserverServices", "m_bForcedObserverMode", false, value);
}
std::string GCPlayer_ObserverServices::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayer_ObserverServices::IsValid() {
    return (m_ptr != nullptr);
}
GCPlayerPawnComponent GCPlayer_ObserverServices::GetParent() const {
    GCPlayerPawnComponent value(m_ptr);
    return value;
}
void GCPlayer_ObserverServices::SetParent(GCPlayerPawnComponent value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPlayer_ObserverServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_ObserverServices>("CPlayer_ObserverServices")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ObserverMode", &GCPlayer_ObserverServices::GetObserverMode, &GCPlayer_ObserverServices::SetObserverMode)
        .addProperty("ObserverTarget", &GCPlayer_ObserverServices::GetObserverTarget, &GCPlayer_ObserverServices::SetObserverTarget)
        .addProperty("ObserverLastMode", &GCPlayer_ObserverServices::GetObserverLastMode, &GCPlayer_ObserverServices::SetObserverLastMode)
        .addProperty("ForcedObserverMode", &GCPlayer_ObserverServices::GetForcedObserverMode, &GCPlayer_ObserverServices::SetForcedObserverMode)
        .addProperty("Parent", &GCPlayer_ObserverServices::GetParent, &GCPlayer_ObserverServices::SetParent)
        .addFunction("ToPtr", &GCPlayer_ObserverServices::ToPtr)
        .addFunction("IsValid", &GCPlayer_ObserverServices::IsValid)
        .endClass();
}