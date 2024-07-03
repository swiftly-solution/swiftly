#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCKeepUpright::GCKeepUpright(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCKeepUpright::GCKeepUpright(void *ptr) {
    m_ptr = ptr;
}
Vector GCKeepUpright::GetWorldGoalAxis() const {
    return GetSchemaValue<Vector>(m_ptr, "CKeepUpright", "m_worldGoalAxis");
}
void GCKeepUpright::SetWorldGoalAxis(Vector value) {
    SetSchemaValue(m_ptr, "CKeepUpright", "m_worldGoalAxis", false, value);
}
Vector GCKeepUpright::GetLocalTestAxis() const {
    return GetSchemaValue<Vector>(m_ptr, "CKeepUpright", "m_localTestAxis");
}
void GCKeepUpright::SetLocalTestAxis(Vector value) {
    SetSchemaValue(m_ptr, "CKeepUpright", "m_localTestAxis", false, value);
}
std::string GCKeepUpright::GetNameAttach() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CKeepUpright", "m_nameAttach").String();
}
void GCKeepUpright::SetNameAttach(std::string value) {
    SetSchemaValue(m_ptr, "CKeepUpright", "m_nameAttach", false, CUtlSymbolLarge(value.c_str()));
}
GCBaseEntity GCKeepUpright::GetAttachedObject() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CKeepUpright", "m_attachedObject"));
    return value;
}
void GCKeepUpright::SetAttachedObject(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'AttachedObject' is not possible.\n");
}
float GCKeepUpright::GetAngularLimit() const {
    return GetSchemaValue<float>(m_ptr, "CKeepUpright", "m_angularLimit");
}
void GCKeepUpright::SetAngularLimit(float value) {
    SetSchemaValue(m_ptr, "CKeepUpright", "m_angularLimit", false, value);
}
bool GCKeepUpright::GetActive() const {
    return GetSchemaValue<bool>(m_ptr, "CKeepUpright", "m_bActive");
}
void GCKeepUpright::SetActive(bool value) {
    SetSchemaValue(m_ptr, "CKeepUpright", "m_bActive", false, value);
}
bool GCKeepUpright::GetDampAllRotation() const {
    return GetSchemaValue<bool>(m_ptr, "CKeepUpright", "m_bDampAllRotation");
}
void GCKeepUpright::SetDampAllRotation(bool value) {
    SetSchemaValue(m_ptr, "CKeepUpright", "m_bDampAllRotation", false, value);
}
std::string GCKeepUpright::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCKeepUpright::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCKeepUpright::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCKeepUpright::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCKeepUpright(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCKeepUpright>("CKeepUpright")
        .addConstructor<void (*)(std::string)>()
        .addProperty("WorldGoalAxis", &GCKeepUpright::GetWorldGoalAxis, &GCKeepUpright::SetWorldGoalAxis)
        .addProperty("LocalTestAxis", &GCKeepUpright::GetLocalTestAxis, &GCKeepUpright::SetLocalTestAxis)
        .addProperty("NameAttach", &GCKeepUpright::GetNameAttach, &GCKeepUpright::SetNameAttach)
        .addProperty("AttachedObject", &GCKeepUpright::GetAttachedObject, &GCKeepUpright::SetAttachedObject)
        .addProperty("AngularLimit", &GCKeepUpright::GetAngularLimit, &GCKeepUpright::SetAngularLimit)
        .addProperty("Active", &GCKeepUpright::GetActive, &GCKeepUpright::SetActive)
        .addProperty("DampAllRotation", &GCKeepUpright::GetDampAllRotation, &GCKeepUpright::SetDampAllRotation)
        .addProperty("Parent", &GCKeepUpright::GetParent, &GCKeepUpright::SetParent)
        .addFunction("ToPtr", &GCKeepUpright::ToPtr)
        .addFunction("IsValid", &GCKeepUpright::IsValid)
        .endClass();
}