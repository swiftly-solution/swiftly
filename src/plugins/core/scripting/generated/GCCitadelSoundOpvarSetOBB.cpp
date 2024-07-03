#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCitadelSoundOpvarSetOBB::GCCitadelSoundOpvarSetOBB(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCitadelSoundOpvarSetOBB::GCCitadelSoundOpvarSetOBB(void *ptr) {
    m_ptr = ptr;
}
std::string GCCitadelSoundOpvarSetOBB::GetStackName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CCitadelSoundOpvarSetOBB", "m_iszStackName").String();
}
void GCCitadelSoundOpvarSetOBB::SetStackName(std::string value) {
    SetSchemaValue(m_ptr, "CCitadelSoundOpvarSetOBB", "m_iszStackName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCCitadelSoundOpvarSetOBB::GetOperatorName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CCitadelSoundOpvarSetOBB", "m_iszOperatorName").String();
}
void GCCitadelSoundOpvarSetOBB::SetOperatorName(std::string value) {
    SetSchemaValue(m_ptr, "CCitadelSoundOpvarSetOBB", "m_iszOperatorName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCCitadelSoundOpvarSetOBB::GetOpvarName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CCitadelSoundOpvarSetOBB", "m_iszOpvarName").String();
}
void GCCitadelSoundOpvarSetOBB::SetOpvarName(std::string value) {
    SetSchemaValue(m_ptr, "CCitadelSoundOpvarSetOBB", "m_iszOpvarName", false, CUtlSymbolLarge(value.c_str()));
}
Vector GCCitadelSoundOpvarSetOBB::GetDistanceInnerMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CCitadelSoundOpvarSetOBB", "m_vDistanceInnerMins");
}
void GCCitadelSoundOpvarSetOBB::SetDistanceInnerMins(Vector value) {
    SetSchemaValue(m_ptr, "CCitadelSoundOpvarSetOBB", "m_vDistanceInnerMins", false, value);
}
Vector GCCitadelSoundOpvarSetOBB::GetDistanceInnerMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CCitadelSoundOpvarSetOBB", "m_vDistanceInnerMaxs");
}
void GCCitadelSoundOpvarSetOBB::SetDistanceInnerMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CCitadelSoundOpvarSetOBB", "m_vDistanceInnerMaxs", false, value);
}
Vector GCCitadelSoundOpvarSetOBB::GetDistanceOuterMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CCitadelSoundOpvarSetOBB", "m_vDistanceOuterMins");
}
void GCCitadelSoundOpvarSetOBB::SetDistanceOuterMins(Vector value) {
    SetSchemaValue(m_ptr, "CCitadelSoundOpvarSetOBB", "m_vDistanceOuterMins", false, value);
}
Vector GCCitadelSoundOpvarSetOBB::GetDistanceOuterMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CCitadelSoundOpvarSetOBB", "m_vDistanceOuterMaxs");
}
void GCCitadelSoundOpvarSetOBB::SetDistanceOuterMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CCitadelSoundOpvarSetOBB", "m_vDistanceOuterMaxs", false, value);
}
int32_t GCCitadelSoundOpvarSetOBB::GetAABBDirection() const {
    return GetSchemaValue<int32_t>(m_ptr, "CCitadelSoundOpvarSetOBB", "m_nAABBDirection");
}
void GCCitadelSoundOpvarSetOBB::SetAABBDirection(int32_t value) {
    SetSchemaValue(m_ptr, "CCitadelSoundOpvarSetOBB", "m_nAABBDirection", false, value);
}
std::string GCCitadelSoundOpvarSetOBB::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCitadelSoundOpvarSetOBB::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCCitadelSoundOpvarSetOBB::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCCitadelSoundOpvarSetOBB::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCitadelSoundOpvarSetOBB(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCitadelSoundOpvarSetOBB>("CCitadelSoundOpvarSetOBB")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StackName", &GCCitadelSoundOpvarSetOBB::GetStackName, &GCCitadelSoundOpvarSetOBB::SetStackName)
        .addProperty("OperatorName", &GCCitadelSoundOpvarSetOBB::GetOperatorName, &GCCitadelSoundOpvarSetOBB::SetOperatorName)
        .addProperty("OpvarName", &GCCitadelSoundOpvarSetOBB::GetOpvarName, &GCCitadelSoundOpvarSetOBB::SetOpvarName)
        .addProperty("DistanceInnerMins", &GCCitadelSoundOpvarSetOBB::GetDistanceInnerMins, &GCCitadelSoundOpvarSetOBB::SetDistanceInnerMins)
        .addProperty("DistanceInnerMaxs", &GCCitadelSoundOpvarSetOBB::GetDistanceInnerMaxs, &GCCitadelSoundOpvarSetOBB::SetDistanceInnerMaxs)
        .addProperty("DistanceOuterMins", &GCCitadelSoundOpvarSetOBB::GetDistanceOuterMins, &GCCitadelSoundOpvarSetOBB::SetDistanceOuterMins)
        .addProperty("DistanceOuterMaxs", &GCCitadelSoundOpvarSetOBB::GetDistanceOuterMaxs, &GCCitadelSoundOpvarSetOBB::SetDistanceOuterMaxs)
        .addProperty("AABBDirection", &GCCitadelSoundOpvarSetOBB::GetAABBDirection, &GCCitadelSoundOpvarSetOBB::SetAABBDirection)
        .addProperty("Parent", &GCCitadelSoundOpvarSetOBB::GetParent, &GCCitadelSoundOpvarSetOBB::SetParent)
        .addFunction("ToPtr", &GCCitadelSoundOpvarSetOBB::ToPtr)
        .addFunction("IsValid", &GCCitadelSoundOpvarSetOBB::IsValid)
        .endClass();
}