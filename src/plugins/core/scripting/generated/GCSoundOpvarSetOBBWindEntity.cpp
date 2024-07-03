#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundOpvarSetOBBWindEntity::GCSoundOpvarSetOBBWindEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundOpvarSetOBBWindEntity::GCSoundOpvarSetOBBWindEntity(void *ptr) {
    m_ptr = ptr;
}
Vector GCSoundOpvarSetOBBWindEntity::GetMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_vMins");
}
void GCSoundOpvarSetOBBWindEntity::SetMins(Vector value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_vMins", false, value);
}
Vector GCSoundOpvarSetOBBWindEntity::GetMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_vMaxs");
}
void GCSoundOpvarSetOBBWindEntity::SetMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_vMaxs", false, value);
}
Vector GCSoundOpvarSetOBBWindEntity::GetDistanceMins() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_vDistanceMins");
}
void GCSoundOpvarSetOBBWindEntity::SetDistanceMins(Vector value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_vDistanceMins", false, value);
}
Vector GCSoundOpvarSetOBBWindEntity::GetDistanceMaxs() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_vDistanceMaxs");
}
void GCSoundOpvarSetOBBWindEntity::SetDistanceMaxs(Vector value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_vDistanceMaxs", false, value);
}
float GCSoundOpvarSetOBBWindEntity::GetWindMin() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_flWindMin");
}
void GCSoundOpvarSetOBBWindEntity::SetWindMin(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_flWindMin", false, value);
}
float GCSoundOpvarSetOBBWindEntity::GetWindMax() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_flWindMax");
}
void GCSoundOpvarSetOBBWindEntity::SetWindMax(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_flWindMax", false, value);
}
float GCSoundOpvarSetOBBWindEntity::GetWindMapMin() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_flWindMapMin");
}
void GCSoundOpvarSetOBBWindEntity::SetWindMapMin(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_flWindMapMin", false, value);
}
float GCSoundOpvarSetOBBWindEntity::GetWindMapMax() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_flWindMapMax");
}
void GCSoundOpvarSetOBBWindEntity::SetWindMapMax(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetOBBWindEntity", "m_flWindMapMax", false, value);
}
std::string GCSoundOpvarSetOBBWindEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundOpvarSetOBBWindEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCSoundOpvarSetPointBase GCSoundOpvarSetOBBWindEntity::GetParent() const {
    GCSoundOpvarSetPointBase value(m_ptr);
    return value;
}
void GCSoundOpvarSetOBBWindEntity::SetParent(GCSoundOpvarSetPointBase value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundOpvarSetOBBWindEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundOpvarSetOBBWindEntity>("CSoundOpvarSetOBBWindEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Mins", &GCSoundOpvarSetOBBWindEntity::GetMins, &GCSoundOpvarSetOBBWindEntity::SetMins)
        .addProperty("Maxs", &GCSoundOpvarSetOBBWindEntity::GetMaxs, &GCSoundOpvarSetOBBWindEntity::SetMaxs)
        .addProperty("DistanceMins", &GCSoundOpvarSetOBBWindEntity::GetDistanceMins, &GCSoundOpvarSetOBBWindEntity::SetDistanceMins)
        .addProperty("DistanceMaxs", &GCSoundOpvarSetOBBWindEntity::GetDistanceMaxs, &GCSoundOpvarSetOBBWindEntity::SetDistanceMaxs)
        .addProperty("WindMin", &GCSoundOpvarSetOBBWindEntity::GetWindMin, &GCSoundOpvarSetOBBWindEntity::SetWindMin)
        .addProperty("WindMax", &GCSoundOpvarSetOBBWindEntity::GetWindMax, &GCSoundOpvarSetOBBWindEntity::SetWindMax)
        .addProperty("WindMapMin", &GCSoundOpvarSetOBBWindEntity::GetWindMapMin, &GCSoundOpvarSetOBBWindEntity::SetWindMapMin)
        .addProperty("WindMapMax", &GCSoundOpvarSetOBBWindEntity::GetWindMapMax, &GCSoundOpvarSetOBBWindEntity::SetWindMapMax)
        .addProperty("Parent", &GCSoundOpvarSetOBBWindEntity::GetParent, &GCSoundOpvarSetOBBWindEntity::SetParent)
        .addFunction("ToPtr", &GCSoundOpvarSetOBBWindEntity::ToPtr)
        .addFunction("IsValid", &GCSoundOpvarSetOBBWindEntity::IsValid)
        .endClass();
}