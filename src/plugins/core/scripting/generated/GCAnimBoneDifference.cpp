#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimBoneDifference::GCAnimBoneDifference(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimBoneDifference::GCAnimBoneDifference(void *ptr) {
    m_ptr = ptr;
}
CBufferString GCAnimBoneDifference::GetName() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimBoneDifference", "m_name");
}
void GCAnimBoneDifference::SetName(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimBoneDifference", "m_name", false, value);
}
CBufferString GCAnimBoneDifference::GetParent() const {
    return GetSchemaValue<CBufferString>(m_ptr, "CAnimBoneDifference", "m_parent");
}
void GCAnimBoneDifference::SetParent(CBufferString value) {
    SetSchemaValue(m_ptr, "CAnimBoneDifference", "m_parent", false, value);
}
Vector GCAnimBoneDifference::GetPosError() const {
    return GetSchemaValue<Vector>(m_ptr, "CAnimBoneDifference", "m_posError");
}
void GCAnimBoneDifference::SetPosError(Vector value) {
    SetSchemaValue(m_ptr, "CAnimBoneDifference", "m_posError", false, value);
}
bool GCAnimBoneDifference::GetHasRotation() const {
    return GetSchemaValue<bool>(m_ptr, "CAnimBoneDifference", "m_bHasRotation");
}
void GCAnimBoneDifference::SetHasRotation(bool value) {
    SetSchemaValue(m_ptr, "CAnimBoneDifference", "m_bHasRotation", false, value);
}
bool GCAnimBoneDifference::GetHasMovement() const {
    return GetSchemaValue<bool>(m_ptr, "CAnimBoneDifference", "m_bHasMovement");
}
void GCAnimBoneDifference::SetHasMovement(bool value) {
    SetSchemaValue(m_ptr, "CAnimBoneDifference", "m_bHasMovement", false, value);
}
std::string GCAnimBoneDifference::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimBoneDifference::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimBoneDifference(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimBoneDifference>("CAnimBoneDifference")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GCAnimBoneDifference::GetName, &GCAnimBoneDifference::SetName)
        .addProperty("Parent", &GCAnimBoneDifference::GetParent, &GCAnimBoneDifference::SetParent)
        .addProperty("PosError", &GCAnimBoneDifference::GetPosError, &GCAnimBoneDifference::SetPosError)
        .addProperty("HasRotation", &GCAnimBoneDifference::GetHasRotation, &GCAnimBoneDifference::SetHasRotation)
        .addProperty("HasMovement", &GCAnimBoneDifference::GetHasMovement, &GCAnimBoneDifference::SetHasMovement)
        .addFunction("ToPtr", &GCAnimBoneDifference::ToPtr)
        .addFunction("IsValid", &GCAnimBoneDifference::IsValid)
        .endClass();
}