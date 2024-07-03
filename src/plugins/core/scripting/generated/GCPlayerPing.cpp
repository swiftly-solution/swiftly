#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayerPing::GCPlayerPing(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayerPing::GCPlayerPing(void *ptr) {
    m_ptr = ptr;
}
GCCSPlayerPawn GCPlayerPing::GetPlayer() const {
    GCCSPlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CPlayerPing", "m_hPlayer"));
    return value;
}
void GCPlayerPing::SetPlayer(GCCSPlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Player' is not possible.\n");
}
GCBaseEntity GCPlayerPing::GetPingedEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CPlayerPing", "m_hPingedEntity"));
    return value;
}
void GCPlayerPing::SetPingedEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PingedEntity' is not possible.\n");
}
int32_t GCPlayerPing::GetType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPlayerPing", "m_iType");
}
void GCPlayerPing::SetType(int32_t value) {
    SetSchemaValue(m_ptr, "CPlayerPing", "m_iType", false, value);
}
bool GCPlayerPing::GetUrgent() const {
    return GetSchemaValue<bool>(m_ptr, "CPlayerPing", "m_bUrgent");
}
void GCPlayerPing::SetUrgent(bool value) {
    SetSchemaValue(m_ptr, "CPlayerPing", "m_bUrgent", false, value);
}
std::string GCPlayerPing::GetPlaceName() const {
    return GetSchemaValuePtr<char>(m_ptr, "CPlayerPing", "m_szPlaceName");
}
void GCPlayerPing::SetPlaceName(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CPlayerPing", "m_szPlaceName", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 18);
}
std::string GCPlayerPing::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayerPing::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCPlayerPing::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCPlayerPing::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPlayerPing(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayerPing>("CPlayerPing")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Player", &GCPlayerPing::GetPlayer, &GCPlayerPing::SetPlayer)
        .addProperty("PingedEntity", &GCPlayerPing::GetPingedEntity, &GCPlayerPing::SetPingedEntity)
        .addProperty("Type", &GCPlayerPing::GetType, &GCPlayerPing::SetType)
        .addProperty("Urgent", &GCPlayerPing::GetUrgent, &GCPlayerPing::SetUrgent)
        .addProperty("PlaceName", &GCPlayerPing::GetPlaceName, &GCPlayerPing::SetPlaceName)
        .addProperty("Parent", &GCPlayerPing::GetParent, &GCPlayerPing::SetParent)
        .addFunction("ToPtr", &GCPlayerPing::ToPtr)
        .addFunction("IsValid", &GCPlayerPing::IsValid)
        .endClass();
}