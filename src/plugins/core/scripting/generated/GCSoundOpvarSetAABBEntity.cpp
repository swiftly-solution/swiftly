#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundOpvarSetAABBEntity::GCSoundOpvarSetAABBEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundOpvarSetAABBEntity::GCSoundOpvarSetAABBEntity(void *ptr) {
    m_ptr = ptr;
}
Vector GCSoundOpvarSetAABBEntity::GetDistanceInnerMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetAABBEntity", "m_vDistanceInnerMins");
}
void GCSoundOpvarSetAABBEntity::SetDistanceInnerMins(Vector value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_vDistanceInnerMins", false, value);
}
Vector GCSoundOpvarSetAABBEntity::GetDistanceInnerMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetAABBEntity", "m_vDistanceInnerMaxs");
}
void GCSoundOpvarSetAABBEntity::SetDistanceInnerMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_vDistanceInnerMaxs", false, value);
}
Vector GCSoundOpvarSetAABBEntity::GetDistanceOuterMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetAABBEntity", "m_vDistanceOuterMins");
}
void GCSoundOpvarSetAABBEntity::SetDistanceOuterMins(Vector value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_vDistanceOuterMins", false, value);
}
Vector GCSoundOpvarSetAABBEntity::GetDistanceOuterMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetAABBEntity", "m_vDistanceOuterMaxs");
}
void GCSoundOpvarSetAABBEntity::SetDistanceOuterMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_vDistanceOuterMaxs", false, value);
}
int32_t GCSoundOpvarSetAABBEntity::GetAABBDirection() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSoundOpvarSetAABBEntity", "m_nAABBDirection");
}
void GCSoundOpvarSetAABBEntity::SetAABBDirection(int32_t value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_nAABBDirection", false, value);
}
Vector GCSoundOpvarSetAABBEntity::GetInnerMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetAABBEntity", "m_vInnerMins");
}
void GCSoundOpvarSetAABBEntity::SetInnerMins(Vector value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_vInnerMins", false, value);
}
Vector GCSoundOpvarSetAABBEntity::GetInnerMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetAABBEntity", "m_vInnerMaxs");
}
void GCSoundOpvarSetAABBEntity::SetInnerMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_vInnerMaxs", false, value);
}
Vector GCSoundOpvarSetAABBEntity::GetOuterMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetAABBEntity", "m_vOuterMins");
}
void GCSoundOpvarSetAABBEntity::SetOuterMins(Vector value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_vOuterMins", false, value);
}
Vector GCSoundOpvarSetAABBEntity::GetOuterMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetAABBEntity", "m_vOuterMaxs");
}
void GCSoundOpvarSetAABBEntity::SetOuterMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetAABBEntity", "m_vOuterMaxs", false, value);
}
std::string GCSoundOpvarSetAABBEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundOpvarSetAABBEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCSoundOpvarSetPointEntity GCSoundOpvarSetAABBEntity::GetParent() const {
    GCSoundOpvarSetPointEntity value(m_ptr);
    return value;
}
void GCSoundOpvarSetAABBEntity::SetParent(GCSoundOpvarSetPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundOpvarSetAABBEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundOpvarSetAABBEntity>("CSoundOpvarSetAABBEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DistanceInnerMins", &GCSoundOpvarSetAABBEntity::GetDistanceInnerMins, &GCSoundOpvarSetAABBEntity::SetDistanceInnerMins)
        .addProperty("DistanceInnerMaxs", &GCSoundOpvarSetAABBEntity::GetDistanceInnerMaxs, &GCSoundOpvarSetAABBEntity::SetDistanceInnerMaxs)
        .addProperty("DistanceOuterMins", &GCSoundOpvarSetAABBEntity::GetDistanceOuterMins, &GCSoundOpvarSetAABBEntity::SetDistanceOuterMins)
        .addProperty("DistanceOuterMaxs", &GCSoundOpvarSetAABBEntity::GetDistanceOuterMaxs, &GCSoundOpvarSetAABBEntity::SetDistanceOuterMaxs)
        .addProperty("AABBDirection", &GCSoundOpvarSetAABBEntity::GetAABBDirection, &GCSoundOpvarSetAABBEntity::SetAABBDirection)
        .addProperty("InnerMins", &GCSoundOpvarSetAABBEntity::GetInnerMins, &GCSoundOpvarSetAABBEntity::SetInnerMins)
        .addProperty("InnerMaxs", &GCSoundOpvarSetAABBEntity::GetInnerMaxs, &GCSoundOpvarSetAABBEntity::SetInnerMaxs)
        .addProperty("OuterMins", &GCSoundOpvarSetAABBEntity::GetOuterMins, &GCSoundOpvarSetAABBEntity::SetOuterMins)
        .addProperty("OuterMaxs", &GCSoundOpvarSetAABBEntity::GetOuterMaxs, &GCSoundOpvarSetAABBEntity::SetOuterMaxs)
        .addProperty("Parent", &GCSoundOpvarSetAABBEntity::GetParent, &GCSoundOpvarSetAABBEntity::SetParent)
        .addFunction("ToPtr", &GCSoundOpvarSetAABBEntity::ToPtr)
        .addFunction("IsValid", &GCSoundOpvarSetAABBEntity::IsValid)
        .endClass();
}