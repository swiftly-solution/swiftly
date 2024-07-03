#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicDistanceAutosave::GCLogicDistanceAutosave(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicDistanceAutosave::GCLogicDistanceAutosave(void *ptr) {
    m_ptr = ptr;
}
std::string GCLogicDistanceAutosave::GetTargetEntity() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicDistanceAutosave", "m_iszTargetEntity").String();
}
void GCLogicDistanceAutosave::SetTargetEntity(std::string value) {
    SetSchemaValue(m_ptr, "CLogicDistanceAutosave", "m_iszTargetEntity", false, CUtlSymbolLarge(value.c_str()));
}
float GCLogicDistanceAutosave::GetDistanceToPlayer() const {
    return GetSchemaValue<float>(m_ptr, "CLogicDistanceAutosave", "m_flDistanceToPlayer");
}
void GCLogicDistanceAutosave::SetDistanceToPlayer(float value) {
    SetSchemaValue(m_ptr, "CLogicDistanceAutosave", "m_flDistanceToPlayer", false, value);
}
bool GCLogicDistanceAutosave::GetForceNewLevelUnit() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicDistanceAutosave", "m_bForceNewLevelUnit");
}
void GCLogicDistanceAutosave::SetForceNewLevelUnit(bool value) {
    SetSchemaValue(m_ptr, "CLogicDistanceAutosave", "m_bForceNewLevelUnit", false, value);
}
bool GCLogicDistanceAutosave::GetCheckCough() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicDistanceAutosave", "m_bCheckCough");
}
void GCLogicDistanceAutosave::SetCheckCough(bool value) {
    SetSchemaValue(m_ptr, "CLogicDistanceAutosave", "m_bCheckCough", false, value);
}
bool GCLogicDistanceAutosave::GetThinkDangerous() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicDistanceAutosave", "m_bThinkDangerous");
}
void GCLogicDistanceAutosave::SetThinkDangerous(bool value) {
    SetSchemaValue(m_ptr, "CLogicDistanceAutosave", "m_bThinkDangerous", false, value);
}
float GCLogicDistanceAutosave::GetDangerousTime() const {
    return GetSchemaValue<float>(m_ptr, "CLogicDistanceAutosave", "m_flDangerousTime");
}
void GCLogicDistanceAutosave::SetDangerousTime(float value) {
    SetSchemaValue(m_ptr, "CLogicDistanceAutosave", "m_flDangerousTime", false, value);
}
std::string GCLogicDistanceAutosave::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicDistanceAutosave::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCLogicDistanceAutosave::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCLogicDistanceAutosave::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicDistanceAutosave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicDistanceAutosave>("CLogicDistanceAutosave")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TargetEntity", &GCLogicDistanceAutosave::GetTargetEntity, &GCLogicDistanceAutosave::SetTargetEntity)
        .addProperty("DistanceToPlayer", &GCLogicDistanceAutosave::GetDistanceToPlayer, &GCLogicDistanceAutosave::SetDistanceToPlayer)
        .addProperty("ForceNewLevelUnit", &GCLogicDistanceAutosave::GetForceNewLevelUnit, &GCLogicDistanceAutosave::SetForceNewLevelUnit)
        .addProperty("CheckCough", &GCLogicDistanceAutosave::GetCheckCough, &GCLogicDistanceAutosave::SetCheckCough)
        .addProperty("ThinkDangerous", &GCLogicDistanceAutosave::GetThinkDangerous, &GCLogicDistanceAutosave::SetThinkDangerous)
        .addProperty("DangerousTime", &GCLogicDistanceAutosave::GetDangerousTime, &GCLogicDistanceAutosave::SetDangerousTime)
        .addProperty("Parent", &GCLogicDistanceAutosave::GetParent, &GCLogicDistanceAutosave::SetParent)
        .addFunction("ToPtr", &GCLogicDistanceAutosave::ToPtr)
        .addFunction("IsValid", &GCLogicDistanceAutosave::IsValid)
        .endClass();
}