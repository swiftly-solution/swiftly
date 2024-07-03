#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFootDefinition::GCFootDefinition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFootDefinition::GCFootDefinition(void *ptr) {
    m_ptr = ptr;
}
std::string GCFootDefinition::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CFootDefinition", "m_name").Get();
}
void GCFootDefinition::SetName(std::string value) {
    SetSchemaValue(m_ptr, "CFootDefinition", "m_name", false, CUtlString(value.c_str()));
}
std::string GCFootDefinition::GetAnkleBoneName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CFootDefinition", "m_ankleBoneName").Get();
}
void GCFootDefinition::SetAnkleBoneName(std::string value) {
    SetSchemaValue(m_ptr, "CFootDefinition", "m_ankleBoneName", false, CUtlString(value.c_str()));
}
std::string GCFootDefinition::GetToeBoneName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CFootDefinition", "m_toeBoneName").Get();
}
void GCFootDefinition::SetToeBoneName(std::string value) {
    SetSchemaValue(m_ptr, "CFootDefinition", "m_toeBoneName", false, CUtlString(value.c_str()));
}
Vector GCFootDefinition::GetBallOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "CFootDefinition", "m_vBallOffset");
}
void GCFootDefinition::SetBallOffset(Vector value) {
    SetSchemaValue(m_ptr, "CFootDefinition", "m_vBallOffset", false, value);
}
Vector GCFootDefinition::GetHeelOffset() const {
    return GetSchemaValue<Vector>(m_ptr, "CFootDefinition", "m_vHeelOffset");
}
void GCFootDefinition::SetHeelOffset(Vector value) {
    SetSchemaValue(m_ptr, "CFootDefinition", "m_vHeelOffset", false, value);
}
float GCFootDefinition::GetFootLength() const {
    return GetSchemaValue<float>(m_ptr, "CFootDefinition", "m_flFootLength");
}
void GCFootDefinition::SetFootLength(float value) {
    SetSchemaValue(m_ptr, "CFootDefinition", "m_flFootLength", false, value);
}
float GCFootDefinition::GetBindPoseDirectionMS() const {
    return GetSchemaValue<float>(m_ptr, "CFootDefinition", "m_flBindPoseDirectionMS");
}
void GCFootDefinition::SetBindPoseDirectionMS(float value) {
    SetSchemaValue(m_ptr, "CFootDefinition", "m_flBindPoseDirectionMS", false, value);
}
float GCFootDefinition::GetTraceHeight() const {
    return GetSchemaValue<float>(m_ptr, "CFootDefinition", "m_flTraceHeight");
}
void GCFootDefinition::SetTraceHeight(float value) {
    SetSchemaValue(m_ptr, "CFootDefinition", "m_flTraceHeight", false, value);
}
float GCFootDefinition::GetTraceRadius() const {
    return GetSchemaValue<float>(m_ptr, "CFootDefinition", "m_flTraceRadius");
}
void GCFootDefinition::SetTraceRadius(float value) {
    SetSchemaValue(m_ptr, "CFootDefinition", "m_flTraceRadius", false, value);
}
std::string GCFootDefinition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFootDefinition::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCFootDefinition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootDefinition>("CFootDefinition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCFootDefinition::GetName, &GCFootDefinition::SetName)
        .addProperty("AnkleBoneName", &GCFootDefinition::GetAnkleBoneName, &GCFootDefinition::SetAnkleBoneName)
        .addProperty("ToeBoneName", &GCFootDefinition::GetToeBoneName, &GCFootDefinition::SetToeBoneName)
        .addProperty("BallOffset", &GCFootDefinition::GetBallOffset, &GCFootDefinition::SetBallOffset)
        .addProperty("HeelOffset", &GCFootDefinition::GetHeelOffset, &GCFootDefinition::SetHeelOffset)
        .addProperty("FootLength", &GCFootDefinition::GetFootLength, &GCFootDefinition::SetFootLength)
        .addProperty("BindPoseDirectionMS", &GCFootDefinition::GetBindPoseDirectionMS, &GCFootDefinition::SetBindPoseDirectionMS)
        .addProperty("TraceHeight", &GCFootDefinition::GetTraceHeight, &GCFootDefinition::SetTraceHeight)
        .addProperty("TraceRadius", &GCFootDefinition::GetTraceRadius, &GCFootDefinition::SetTraceRadius)
        .addFunction("ToPtr", &GCFootDefinition::ToPtr)
        .addFunction("IsValid", &GCFootDefinition::IsValid)
        .endClass();
}