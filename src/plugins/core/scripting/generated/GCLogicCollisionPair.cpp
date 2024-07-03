#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLogicCollisionPair::GCLogicCollisionPair(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLogicCollisionPair::GCLogicCollisionPair(void *ptr) {
    m_ptr = ptr;
}
std::string GCLogicCollisionPair::GetNameAttach1() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicCollisionPair", "m_nameAttach1").String();
}
void GCLogicCollisionPair::SetNameAttach1(std::string value) {
    SetSchemaValue(m_ptr, "CLogicCollisionPair", "m_nameAttach1", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCLogicCollisionPair::GetNameAttach2() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CLogicCollisionPair", "m_nameAttach2").String();
}
void GCLogicCollisionPair::SetNameAttach2(std::string value) {
    SetSchemaValue(m_ptr, "CLogicCollisionPair", "m_nameAttach2", false, CUtlSymbolLarge(value.c_str()));
}
bool GCLogicCollisionPair::GetSupportMultipleEntitiesWithSameName() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicCollisionPair", "m_supportMultipleEntitiesWithSameName");
}
void GCLogicCollisionPair::SetSupportMultipleEntitiesWithSameName(bool value) {
    SetSchemaValue(m_ptr, "CLogicCollisionPair", "m_supportMultipleEntitiesWithSameName", false, value);
}
bool GCLogicCollisionPair::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicCollisionPair", "m_disabled");
}
void GCLogicCollisionPair::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CLogicCollisionPair", "m_disabled", false, value);
}
bool GCLogicCollisionPair::GetSucceeded() const {
    return GetSchemaValue<bool>(m_ptr, "CLogicCollisionPair", "m_succeeded");
}
void GCLogicCollisionPair::SetSucceeded(bool value) {
    SetSchemaValue(m_ptr, "CLogicCollisionPair", "m_succeeded", false, value);
}
std::string GCLogicCollisionPair::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLogicCollisionPair::IsValid() {
    return (m_ptr != nullptr);
}
GCLogicalEntity GCLogicCollisionPair::GetParent() const {
    GCLogicalEntity value(m_ptr);
    return value;
}
void GCLogicCollisionPair::SetParent(GCLogicalEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLogicCollisionPair(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicCollisionPair>("CLogicCollisionPair")
        .addConstructor<void (*)(std::string)>()
        .addProperty("NameAttach1", &GCLogicCollisionPair::GetNameAttach1, &GCLogicCollisionPair::SetNameAttach1)
        .addProperty("NameAttach2", &GCLogicCollisionPair::GetNameAttach2, &GCLogicCollisionPair::SetNameAttach2)
        .addProperty("SupportMultipleEntitiesWithSameName", &GCLogicCollisionPair::GetSupportMultipleEntitiesWithSameName, &GCLogicCollisionPair::SetSupportMultipleEntitiesWithSameName)
        .addProperty("Disabled", &GCLogicCollisionPair::GetDisabled, &GCLogicCollisionPair::SetDisabled)
        .addProperty("Succeeded", &GCLogicCollisionPair::GetSucceeded, &GCLogicCollisionPair::SetSucceeded)
        .addProperty("Parent", &GCLogicCollisionPair::GetParent, &GCLogicCollisionPair::SetParent)
        .addFunction("ToPtr", &GCLogicCollisionPair::ToPtr)
        .addFunction("IsValid", &GCLogicCollisionPair::IsValid)
        .endClass();
}