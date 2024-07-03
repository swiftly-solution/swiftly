#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointTeleport::GCPointTeleport(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointTeleport::GCPointTeleport(void *ptr) {
    m_ptr = ptr;
}
Vector GCPointTeleport::GetSaveOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CPointTeleport", "m_vSaveOrigin");
}
void GCPointTeleport::SetSaveOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CPointTeleport", "m_vSaveOrigin", false, value);
}
QAngle GCPointTeleport::GetSaveAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CPointTeleport", "m_vSaveAngles");
}
void GCPointTeleport::SetSaveAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CPointTeleport", "m_vSaveAngles", false, value);
}
bool GCPointTeleport::GetTeleportParentedEntities() const {
    return GetSchemaValue<bool>(m_ptr, "CPointTeleport", "m_bTeleportParentedEntities");
}
void GCPointTeleport::SetTeleportParentedEntities(bool value) {
    SetSchemaValue(m_ptr, "CPointTeleport", "m_bTeleportParentedEntities", false, value);
}
bool GCPointTeleport::GetTeleportUseCurrentAngle() const {
    return GetSchemaValue<bool>(m_ptr, "CPointTeleport", "m_bTeleportUseCurrentAngle");
}
void GCPointTeleport::SetTeleportUseCurrentAngle(bool value) {
    SetSchemaValue(m_ptr, "CPointTeleport", "m_bTeleportUseCurrentAngle", false, value);
}
std::string GCPointTeleport::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointTeleport::IsValid() {
    return (m_ptr != nullptr);
}
GCServerOnlyPointEntity GCPointTeleport::GetParent() const {
    GCServerOnlyPointEntity value(m_ptr);
    return value;
}
void GCPointTeleport::SetParent(GCServerOnlyPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointTeleport(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointTeleport>("CPointTeleport")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SaveOrigin", &GCPointTeleport::GetSaveOrigin, &GCPointTeleport::SetSaveOrigin)
        .addProperty("SaveAngles", &GCPointTeleport::GetSaveAngles, &GCPointTeleport::SetSaveAngles)
        .addProperty("TeleportParentedEntities", &GCPointTeleport::GetTeleportParentedEntities, &GCPointTeleport::SetTeleportParentedEntities)
        .addProperty("TeleportUseCurrentAngle", &GCPointTeleport::GetTeleportUseCurrentAngle, &GCPointTeleport::SetTeleportUseCurrentAngle)
        .addProperty("Parent", &GCPointTeleport::GetParent, &GCPointTeleport::SetParent)
        .addFunction("ToPtr", &GCPointTeleport::ToPtr)
        .addFunction("IsValid", &GCPointTeleport::IsValid)
        .endClass();
}