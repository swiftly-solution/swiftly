#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoGameEventProxy::GCInfoGameEventProxy(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoGameEventProxy::GCInfoGameEventProxy(void *ptr) {
    m_ptr = ptr;
}
std::string GCInfoGameEventProxy::GetEventName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInfoGameEventProxy", "m_iszEventName").String();
}
void GCInfoGameEventProxy::SetEventName(std::string value) {
    SetSchemaValue(m_ptr, "CInfoGameEventProxy", "m_iszEventName", false, CUtlSymbolLarge(value.c_str()));
}
float GCInfoGameEventProxy::GetRange() const {
    return GetSchemaValue<float>(m_ptr, "CInfoGameEventProxy", "m_flRange");
}
void GCInfoGameEventProxy::SetRange(float value) {
    SetSchemaValue(m_ptr, "CInfoGameEventProxy", "m_flRange", false, value);
}
std::string GCInfoGameEventProxy::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoGameEventProxy::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCInfoGameEventProxy::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCInfoGameEventProxy::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoGameEventProxy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoGameEventProxy>("CInfoGameEventProxy")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EventName", &GCInfoGameEventProxy::GetEventName, &GCInfoGameEventProxy::SetEventName)
        .addProperty("Range", &GCInfoGameEventProxy::GetRange, &GCInfoGameEventProxy::SetRange)
        .addProperty("Parent", &GCInfoGameEventProxy::GetParent, &GCInfoGameEventProxy::SetParent)
        .addFunction("ToPtr", &GCInfoGameEventProxy::ToPtr)
        .addFunction("IsValid", &GCInfoGameEventProxy::IsValid)
        .endClass();
}