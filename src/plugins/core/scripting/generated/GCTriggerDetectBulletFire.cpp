#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerDetectBulletFire::GCTriggerDetectBulletFire(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerDetectBulletFire::GCTriggerDetectBulletFire(void *ptr) {
    m_ptr = ptr;
}
bool GCTriggerDetectBulletFire::GetPlayerFireOnly() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerDetectBulletFire", "m_bPlayerFireOnly");
}
void GCTriggerDetectBulletFire::SetPlayerFireOnly(bool value) {
    SetSchemaValue(m_ptr, "CTriggerDetectBulletFire", "m_bPlayerFireOnly", false, value);
}
GCEntityIOOutput GCTriggerDetectBulletFire::GetOnDetectedBulletFire() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTriggerDetectBulletFire", "m_OnDetectedBulletFire"));
    return value;
}
void GCTriggerDetectBulletFire::SetOnDetectedBulletFire(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTriggerDetectBulletFire", "m_OnDetectedBulletFire", false, value);
}
std::string GCTriggerDetectBulletFire::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerDetectBulletFire::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerDetectBulletFire::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerDetectBulletFire::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerDetectBulletFire(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerDetectBulletFire>("CTriggerDetectBulletFire")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PlayerFireOnly", &GCTriggerDetectBulletFire::GetPlayerFireOnly, &GCTriggerDetectBulletFire::SetPlayerFireOnly)
        .addProperty("OnDetectedBulletFire", &GCTriggerDetectBulletFire::GetOnDetectedBulletFire, &GCTriggerDetectBulletFire::SetOnDetectedBulletFire)
        .addProperty("Parent", &GCTriggerDetectBulletFire::GetParent, &GCTriggerDetectBulletFire::SetParent)
        .addFunction("ToPtr", &GCTriggerDetectBulletFire::ToPtr)
        .addFunction("IsValid", &GCTriggerDetectBulletFire::IsValid)
        .endClass();
}