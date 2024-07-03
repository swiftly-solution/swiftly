#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerDetectExplosion::GCTriggerDetectExplosion(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerDetectExplosion::GCTriggerDetectExplosion(void *ptr) {
    m_ptr = ptr;
}
GCEntityIOOutput GCTriggerDetectExplosion::GetOnDetectedExplosion() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CTriggerDetectExplosion", "m_OnDetectedExplosion"));
    return value;
}
void GCTriggerDetectExplosion::SetOnDetectedExplosion(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CTriggerDetectExplosion", "m_OnDetectedExplosion", false, value);
}
std::string GCTriggerDetectExplosion::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerDetectExplosion::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerDetectExplosion::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerDetectExplosion::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerDetectExplosion(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerDetectExplosion>("CTriggerDetectExplosion")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OnDetectedExplosion", &GCTriggerDetectExplosion::GetOnDetectedExplosion, &GCTriggerDetectExplosion::SetOnDetectedExplosion)
        .addProperty("Parent", &GCTriggerDetectExplosion::GetParent, &GCTriggerDetectExplosion::SetParent)
        .addFunction("ToPtr", &GCTriggerDetectExplosion::ToPtr)
        .addFunction("IsValid", &GCTriggerDetectExplosion::IsValid)
        .endClass();
}