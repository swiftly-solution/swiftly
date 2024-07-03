#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerSave::GCTriggerSave(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerSave::GCTriggerSave(void *ptr) {
    m_ptr = ptr;
}
bool GCTriggerSave::GetForceNewLevelUnit() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerSave", "m_bForceNewLevelUnit");
}
void GCTriggerSave::SetForceNewLevelUnit(bool value) {
    SetSchemaValue(m_ptr, "CTriggerSave", "m_bForceNewLevelUnit", false, value);
}
float GCTriggerSave::GetDangerousTimer() const {
    return GetSchemaValue<float>(m_ptr, "CTriggerSave", "m_fDangerousTimer");
}
void GCTriggerSave::SetDangerousTimer(float value) {
    SetSchemaValue(m_ptr, "CTriggerSave", "m_fDangerousTimer", false, value);
}
int32_t GCTriggerSave::GetMinHitPoints() const {
    return GetSchemaValue<int32_t>(m_ptr, "CTriggerSave", "m_minHitPoints");
}
void GCTriggerSave::SetMinHitPoints(int32_t value) {
    SetSchemaValue(m_ptr, "CTriggerSave", "m_minHitPoints", false, value);
}
std::string GCTriggerSave::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerSave::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerSave::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerSave::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerSave(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerSave>("CTriggerSave")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ForceNewLevelUnit", &GCTriggerSave::GetForceNewLevelUnit, &GCTriggerSave::SetForceNewLevelUnit)
        .addProperty("DangerousTimer", &GCTriggerSave::GetDangerousTimer, &GCTriggerSave::SetDangerousTimer)
        .addProperty("MinHitPoints", &GCTriggerSave::GetMinHitPoints, &GCTriggerSave::SetMinHitPoints)
        .addProperty("Parent", &GCTriggerSave::GetParent, &GCTriggerSave::SetParent)
        .addFunction("ToPtr", &GCTriggerSave::ToPtr)
        .addFunction("IsValid", &GCTriggerSave::IsValid)
        .endClass();
}