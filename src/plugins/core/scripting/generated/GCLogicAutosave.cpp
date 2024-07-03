#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicAutosave::GCLogicAutosave(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicAutosave::GCLogicAutosave(void *ptr) {
    m_ptr = ptr;
}
bool GCLogicAutosave::GetForceNewLevelUnit() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicAutosave", "m_bForceNewLevelUnit");
}
void GCLogicAutosave::SetForceNewLevelUnit(bool value) {
    SetSchemaValue(m_ptr, "CLogicAutosave", "m_bForceNewLevelUnit", false, value);
}
int32_t GCLogicAutosave::GetMinHitPoints() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicAutosave", "m_minHitPoints");
}
void GCLogicAutosave::SetMinHitPoints(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicAutosave", "m_minHitPoints", false, value);
}
int32_t GCLogicAutosave::GetMinHitPointsToCommit() const {
    return GetSchemaValue<int32_t>(m_ptr, "CLogicAutosave", "m_minHitPointsToCommit");
}
void GCLogicAutosave::SetMinHitPointsToCommit(int32_t value) {
    SetSchemaValue(m_ptr, "CLogicAutosave", "m_minHitPointsToCommit", false, value);
}
std::string GCLogicAutosave::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicAutosave::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCLogicAutosave::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCLogicAutosave::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicAutosave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicAutosave>("CLogicAutosave")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ForceNewLevelUnit", &GCLogicAutosave::GetForceNewLevelUnit, &GCLogicAutosave::SetForceNewLevelUnit)
        .addProperty("MinHitPoints", &GCLogicAutosave::GetMinHitPoints, &GCLogicAutosave::SetMinHitPoints)
        .addProperty("MinHitPointsToCommit", &GCLogicAutosave::GetMinHitPointsToCommit, &GCLogicAutosave::SetMinHitPointsToCommit)
        .addProperty("Parent", &GCLogicAutosave::GetParent, &GCLogicAutosave::SetParent)
        .addFunction("ToPtr", &GCLogicAutosave::ToPtr)
        .addFunction("IsValid", &GCLogicAutosave::IsValid)
        .endClass();
}