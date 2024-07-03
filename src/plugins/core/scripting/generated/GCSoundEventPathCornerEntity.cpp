#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundEventPathCornerEntity::GCSoundEventPathCornerEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundEventPathCornerEntity::GCSoundEventPathCornerEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCSoundEventPathCornerEntity::GetPathCorner() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundEventPathCornerEntity", "m_iszPathCorner").String();
}
void GCSoundEventPathCornerEntity::SetPathCorner(std::string value) {
    SetSchemaValue(m_ptr, "CSoundEventPathCornerEntity", "m_iszPathCorner", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCSoundEventPathCornerEntity::GetCountMax() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSoundEventPathCornerEntity", "m_iCountMax");
}
void GCSoundEventPathCornerEntity::SetCountMax(int32_t value) {
    SetSchemaValue(m_ptr, "CSoundEventPathCornerEntity", "m_iCountMax", false, value);
}
float GCSoundEventPathCornerEntity::GetDistanceMax() const {
    return GetSchemaValue<float>(m_ptr, "CSoundEventPathCornerEntity", "m_flDistanceMax");
}
void GCSoundEventPathCornerEntity::SetDistanceMax(float value) {
    SetSchemaValue(m_ptr, "CSoundEventPathCornerEntity", "m_flDistanceMax", false, value);
}
float GCSoundEventPathCornerEntity::GetDistMaxSqr() const {
    return GetSchemaValue<float>(m_ptr, "CSoundEventPathCornerEntity", "m_flDistMaxSqr");
}
void GCSoundEventPathCornerEntity::SetDistMaxSqr(float value) {
    SetSchemaValue(m_ptr, "CSoundEventPathCornerEntity", "m_flDistMaxSqr", false, value);
}
float GCSoundEventPathCornerEntity::GetDotProductMax() const {
    return GetSchemaValue<float>(m_ptr, "CSoundEventPathCornerEntity", "m_flDotProductMax");
}
void GCSoundEventPathCornerEntity::SetDotProductMax(float value) {
    SetSchemaValue(m_ptr, "CSoundEventPathCornerEntity", "m_flDotProductMax", false, value);
}
bool GCSoundEventPathCornerEntity::GetPlaying() const {
    return GetSchemaValue<bool>(m_ptr, "CSoundEventPathCornerEntity", "m_bPlaying");
}
void GCSoundEventPathCornerEntity::SetPlaying(bool value) {
    SetSchemaValue(m_ptr, "CSoundEventPathCornerEntity", "m_bPlaying", false, value);
}
std::string GCSoundEventPathCornerEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundEventPathCornerEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCSoundEventEntity GCSoundEventPathCornerEntity::GetParent() const {
    GCSoundEventEntity value(m_ptr);
    return value;
}
void GCSoundEventPathCornerEntity::SetParent(GCSoundEventEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundEventPathCornerEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundEventPathCornerEntity>("CSoundEventPathCornerEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PathCorner", &GCSoundEventPathCornerEntity::GetPathCorner, &GCSoundEventPathCornerEntity::SetPathCorner)
        .addProperty("CountMax", &GCSoundEventPathCornerEntity::GetCountMax, &GCSoundEventPathCornerEntity::SetCountMax)
        .addProperty("DistanceMax", &GCSoundEventPathCornerEntity::GetDistanceMax, &GCSoundEventPathCornerEntity::SetDistanceMax)
        .addProperty("DistMaxSqr", &GCSoundEventPathCornerEntity::GetDistMaxSqr, &GCSoundEventPathCornerEntity::SetDistMaxSqr)
        .addProperty("DotProductMax", &GCSoundEventPathCornerEntity::GetDotProductMax, &GCSoundEventPathCornerEntity::SetDotProductMax)
        .addProperty("Playing", &GCSoundEventPathCornerEntity::GetPlaying, &GCSoundEventPathCornerEntity::SetPlaying)
        .addProperty("Parent", &GCSoundEventPathCornerEntity::GetParent, &GCSoundEventPathCornerEntity::SetParent)
        .addFunction("ToPtr", &GCSoundEventPathCornerEntity::ToPtr)
        .addFunction("IsValid", &GCSoundEventPathCornerEntity::IsValid)
        .endClass();
}