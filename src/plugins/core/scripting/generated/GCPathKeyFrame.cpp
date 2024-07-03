#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPathKeyFrame::GCPathKeyFrame(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPathKeyFrame::GCPathKeyFrame(void *ptr) {
    m_ptr = ptr;
}
Vector GCPathKeyFrame::GetOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CPathKeyFrame", "m_Origin");
}
void GCPathKeyFrame::SetOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CPathKeyFrame", "m_Origin", false, value);
}
QAngle GCPathKeyFrame::GetAngles() const {
    return GetSchemaValue<QAngle>(m_ptr, "CPathKeyFrame", "m_Angles");
}
void GCPathKeyFrame::SetAngles(QAngle value) {
    SetSchemaValue(m_ptr, "CPathKeyFrame", "m_Angles", false, value);
}
Quaternion GCPathKeyFrame::GetAngle() const {
    return GetSchemaValue<Quaternion>(m_ptr, "CPathKeyFrame", "m_qAngle");
}
void GCPathKeyFrame::SetAngle(Quaternion value) {
    SetSchemaValue(m_ptr, "CPathKeyFrame", "m_qAngle", false, value);
}
std::string GCPathKeyFrame::GetNextKey() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPathKeyFrame", "m_iNextKey").String();
}
void GCPathKeyFrame::SetNextKey(std::string value) {
    SetSchemaValue(m_ptr, "CPathKeyFrame", "m_iNextKey", false, CUtlSymbolLarge(value.c_str()));
}
float GCPathKeyFrame::GetNextTime() const {
    return GetSchemaValue<float>(m_ptr, "CPathKeyFrame", "m_flNextTime");
}
void GCPathKeyFrame::SetNextTime(float value) {
    SetSchemaValue(m_ptr, "CPathKeyFrame", "m_flNextTime", false, value);
}
GCPathKeyFrame GCPathKeyFrame::GetNextKey1() const {
    GCPathKeyFrame value(*GetSchemaValuePtr<void*>(m_ptr, "CPathKeyFrame", "m_pNextKey"));
    return value;
}
void GCPathKeyFrame::SetNextKey1(GCPathKeyFrame* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'NextKey1' is not possible.\n");
}
GCPathKeyFrame GCPathKeyFrame::GetPrevKey() const {
    GCPathKeyFrame value(*GetSchemaValuePtr<void*>(m_ptr, "CPathKeyFrame", "m_pPrevKey"));
    return value;
}
void GCPathKeyFrame::SetPrevKey(GCPathKeyFrame* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PrevKey' is not possible.\n");
}
float GCPathKeyFrame::GetMoveSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CPathKeyFrame", "m_flMoveSpeed");
}
void GCPathKeyFrame::SetMoveSpeed(float value) {
    SetSchemaValue(m_ptr, "CPathKeyFrame", "m_flMoveSpeed", false, value);
}
std::string GCPathKeyFrame::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPathKeyFrame::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCPathKeyFrame::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCPathKeyFrame::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPathKeyFrame(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathKeyFrame>("CPathKeyFrame")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Origin", &GCPathKeyFrame::GetOrigin, &GCPathKeyFrame::SetOrigin)
        .addProperty("Angles", &GCPathKeyFrame::GetAngles, &GCPathKeyFrame::SetAngles)
        .addProperty("Angle", &GCPathKeyFrame::GetAngle, &GCPathKeyFrame::SetAngle)
        .addProperty("NextKey", &GCPathKeyFrame::GetNextKey, &GCPathKeyFrame::SetNextKey)
        .addProperty("NextTime", &GCPathKeyFrame::GetNextTime, &GCPathKeyFrame::SetNextTime)
        .addProperty("NextKey1", &GCPathKeyFrame::GetNextKey1, &GCPathKeyFrame::SetNextKey1)
        .addProperty("PrevKey", &GCPathKeyFrame::GetPrevKey, &GCPathKeyFrame::SetPrevKey)
        .addProperty("MoveSpeed", &GCPathKeyFrame::GetMoveSpeed, &GCPathKeyFrame::SetMoveSpeed)
        .addProperty("Parent", &GCPathKeyFrame::GetParent, &GCPathKeyFrame::SetParent)
        .addFunction("ToPtr", &GCPathKeyFrame::ToPtr)
        .addFunction("IsValid", &GCPathKeyFrame::IsValid)
        .endClass();
}