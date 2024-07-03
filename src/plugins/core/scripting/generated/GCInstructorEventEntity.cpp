#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInstructorEventEntity::GCInstructorEventEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInstructorEventEntity::GCInstructorEventEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCInstructorEventEntity::GetName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInstructorEventEntity", "m_iszName").String();
}
void GCInstructorEventEntity::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CInstructorEventEntity", "m_iszName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCInstructorEventEntity::GetHintTargetEntity() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CInstructorEventEntity", "m_iszHintTargetEntity").String();
}
void GCInstructorEventEntity::SetHintTargetEntity(std::string value) {
    SetSchemaValue(m_ptr, "CInstructorEventEntity", "m_iszHintTargetEntity", false, CUtlSymbolLarge(value.c_str()));
}
GCBasePlayerPawn GCInstructorEventEntity::GetTargetPlayer() const {
    GCBasePlayerPawn value(*GetSchemaValuePtr<void*>(m_ptr, "CInstructorEventEntity", "m_hTargetPlayer"));
    return value;
}
void GCInstructorEventEntity::SetTargetPlayer(GCBasePlayerPawn* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'TargetPlayer' is not possible.\n");
}
std::string GCInstructorEventEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInstructorEventEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCInstructorEventEntity::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCInstructorEventEntity::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInstructorEventEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInstructorEventEntity>("CInstructorEventEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCInstructorEventEntity::GetName, &GCInstructorEventEntity::SetName)
        .addProperty("HintTargetEntity", &GCInstructorEventEntity::GetHintTargetEntity, &GCInstructorEventEntity::SetHintTargetEntity)
        .addProperty("TargetPlayer", &GCInstructorEventEntity::GetTargetPlayer, &GCInstructorEventEntity::SetTargetPlayer)
        .addProperty("Parent", &GCInstructorEventEntity::GetParent, &GCInstructorEventEntity::SetParent)
        .addFunction("ToPtr", &GCInstructorEventEntity::ToPtr)
        .addFunction("IsValid", &GCInstructorEventEntity::IsValid)
        .endClass();
}