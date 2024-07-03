#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCTriggerPush::GCTriggerPush(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCTriggerPush::GCTriggerPush(void *ptr) {
    m_ptr = ptr;
}
QAngle GCTriggerPush::GetPushEntitySpace() const {
    return GetSchemaValue<QAngle>(m_ptr, "CTriggerPush", "m_angPushEntitySpace");
}
void GCTriggerPush::SetPushEntitySpace(QAngle value) {
    SetSchemaValue(m_ptr, "CTriggerPush", "m_angPushEntitySpace", false, value);
}
Vector GCTriggerPush::GetPushDirEntitySpace() const {
    return GetSchemaValue<Vector>(m_ptr, "CTriggerPush", "m_vecPushDirEntitySpace");
}
void GCTriggerPush::SetPushDirEntitySpace(Vector value) {
    SetSchemaValue(m_ptr, "CTriggerPush", "m_vecPushDirEntitySpace", false, value);
}
bool GCTriggerPush::GetTriggerOnStartTouch() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerPush", "m_bTriggerOnStartTouch");
}
void GCTriggerPush::SetTriggerOnStartTouch(bool value) {
    SetSchemaValue(m_ptr, "CTriggerPush", "m_bTriggerOnStartTouch", false, value);
}
bool GCTriggerPush::GetUsePathSimple() const {
    return GetSchemaValue<bool>(m_ptr, "CTriggerPush", "m_bUsePathSimple");
}
void GCTriggerPush::SetUsePathSimple(bool value) {
    SetSchemaValue(m_ptr, "CTriggerPush", "m_bUsePathSimple", false, value);
}
std::string GCTriggerPush::GetPathSimpleName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CTriggerPush", "m_iszPathSimpleName").String();
}
void GCTriggerPush::SetPathSimpleName(std::string value) {
    SetSchemaValue(m_ptr, "CTriggerPush", "m_iszPathSimpleName", false, CUtlSymbolLarge(value.c_str()));
}
GCPathSimple GCTriggerPush::GetPathSimple() const {
    GCPathSimple value(*GetSchemaValuePtr<void*>(m_ptr, "CTriggerPush", "m_PathSimple"));
    return value;
}
void GCTriggerPush::SetPathSimple(GCPathSimple* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PathSimple' is not possible.\n");
}
uint32_t GCTriggerPush::GetSplinePushType() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CTriggerPush", "m_splinePushType");
}
void GCTriggerPush::SetSplinePushType(uint32_t value) {
    SetSchemaValue(m_ptr, "CTriggerPush", "m_splinePushType", false, value);
}
std::string GCTriggerPush::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCTriggerPush::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseTrigger GCTriggerPush::GetParent() const {
    GCBaseTrigger value(m_ptr);
    return value;
}
void GCTriggerPush::SetParent(GCBaseTrigger value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCTriggerPush(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerPush>("CTriggerPush")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PushEntitySpace", &GCTriggerPush::GetPushEntitySpace, &GCTriggerPush::SetPushEntitySpace)
        .addProperty("PushDirEntitySpace", &GCTriggerPush::GetPushDirEntitySpace, &GCTriggerPush::SetPushDirEntitySpace)
        .addProperty("TriggerOnStartTouch", &GCTriggerPush::GetTriggerOnStartTouch, &GCTriggerPush::SetTriggerOnStartTouch)
        .addProperty("UsePathSimple", &GCTriggerPush::GetUsePathSimple, &GCTriggerPush::SetUsePathSimple)
        .addProperty("PathSimpleName", &GCTriggerPush::GetPathSimpleName, &GCTriggerPush::SetPathSimpleName)
        .addProperty("PathSimple", &GCTriggerPush::GetPathSimple, &GCTriggerPush::SetPathSimple)
        .addProperty("SplinePushType", &GCTriggerPush::GetSplinePushType, &GCTriggerPush::SetSplinePushType)
        .addProperty("Parent", &GCTriggerPush::GetParent, &GCTriggerPush::SetParent)
        .addFunction("ToPtr", &GCTriggerPush::ToPtr)
        .addFunction("IsValid", &GCTriggerPush::IsValid)
        .endClass();
}