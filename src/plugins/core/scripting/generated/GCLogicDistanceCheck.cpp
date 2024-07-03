#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicDistanceCheck::GCLogicDistanceCheck(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicDistanceCheck::GCLogicDistanceCheck(void *ptr) {
    m_ptr = ptr;
}
std::string GCLogicDistanceCheck::GetEntityA() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicDistanceCheck", "m_iszEntityA").String();
}
void GCLogicDistanceCheck::SetEntityA(std::string value) {
    SetSchemaValue(m_ptr, "CLogicDistanceCheck", "m_iszEntityA", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCLogicDistanceCheck::GetEntityB() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicDistanceCheck", "m_iszEntityB").String();
}
void GCLogicDistanceCheck::SetEntityB(std::string value) {
    SetSchemaValue(m_ptr, "CLogicDistanceCheck", "m_iszEntityB", false, CUtlSymbolLarge(value.c_str()));
}
float GCLogicDistanceCheck::GetZone1Distance() const {
    return GetSchemaValue<float>(m_ptr, "CLogicDistanceCheck", "m_flZone1Distance");
}
void GCLogicDistanceCheck::SetZone1Distance(float value) {
    SetSchemaValue(m_ptr, "CLogicDistanceCheck", "m_flZone1Distance", false, value);
}
float GCLogicDistanceCheck::GetZone2Distance() const {
    return GetSchemaValue<float>(m_ptr, "CLogicDistanceCheck", "m_flZone2Distance");
}
void GCLogicDistanceCheck::SetZone2Distance(float value) {
    SetSchemaValue(m_ptr, "CLogicDistanceCheck", "m_flZone2Distance", false, value);
}
GCEntityIOOutput GCLogicDistanceCheck::GetInZone1() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicDistanceCheck", "m_InZone1"));
    return value;
}
void GCLogicDistanceCheck::SetInZone1(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicDistanceCheck", "m_InZone1", false, value);
}
GCEntityIOOutput GCLogicDistanceCheck::GetInZone2() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicDistanceCheck", "m_InZone2"));
    return value;
}
void GCLogicDistanceCheck::SetInZone2(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicDistanceCheck", "m_InZone2", false, value);
}
GCEntityIOOutput GCLogicDistanceCheck::GetInZone3() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CLogicDistanceCheck", "m_InZone3"));
    return value;
}
void GCLogicDistanceCheck::SetInZone3(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CLogicDistanceCheck", "m_InZone3", false, value);
}
std::string GCLogicDistanceCheck::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicDistanceCheck::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCLogicDistanceCheck::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCLogicDistanceCheck::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicDistanceCheck(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicDistanceCheck>("CLogicDistanceCheck")
        .addConstructor<void (*)(std::string)>()
        .addProperty("EntityA", &GCLogicDistanceCheck::GetEntityA, &GCLogicDistanceCheck::SetEntityA)
        .addProperty("EntityB", &GCLogicDistanceCheck::GetEntityB, &GCLogicDistanceCheck::SetEntityB)
        .addProperty("Zone1Distance", &GCLogicDistanceCheck::GetZone1Distance, &GCLogicDistanceCheck::SetZone1Distance)
        .addProperty("Zone2Distance", &GCLogicDistanceCheck::GetZone2Distance, &GCLogicDistanceCheck::SetZone2Distance)
        .addProperty("InZone1", &GCLogicDistanceCheck::GetInZone1, &GCLogicDistanceCheck::SetInZone1)
        .addProperty("InZone2", &GCLogicDistanceCheck::GetInZone2, &GCLogicDistanceCheck::SetInZone2)
        .addProperty("InZone3", &GCLogicDistanceCheck::GetInZone3, &GCLogicDistanceCheck::SetInZone3)
        .addProperty("Parent", &GCLogicDistanceCheck::GetParent, &GCLogicDistanceCheck::SetParent)
        .addFunction("ToPtr", &GCLogicDistanceCheck::ToPtr)
        .addFunction("IsValid", &GCLogicDistanceCheck::IsValid)
        .endClass();
}