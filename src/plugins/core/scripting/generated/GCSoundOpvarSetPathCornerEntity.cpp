#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundOpvarSetPathCornerEntity::GCSoundOpvarSetPathCornerEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundOpvarSetPathCornerEntity::GCSoundOpvarSetPathCornerEntity(void *ptr) {
    m_ptr = ptr;
}
float GCSoundOpvarSetPathCornerEntity::GetDistMinSqr() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPathCornerEntity", "m_flDistMinSqr");
}
void GCSoundOpvarSetPathCornerEntity::SetDistMinSqr(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPathCornerEntity", "m_flDistMinSqr", false, value);
}
float GCSoundOpvarSetPathCornerEntity::GetDistMaxSqr() const {
    return GetSchemaValue<float>(m_ptr, "CSoundOpvarSetPathCornerEntity", "m_flDistMaxSqr");
}
void GCSoundOpvarSetPathCornerEntity::SetDistMaxSqr(float value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPathCornerEntity", "m_flDistMaxSqr", false, value);
}
std::string GCSoundOpvarSetPathCornerEntity::GetPathCornerEntityName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundOpvarSetPathCornerEntity", "m_iszPathCornerEntityName").String();
}
void GCSoundOpvarSetPathCornerEntity::SetPathCornerEntityName(std::string value) {
    SetSchemaValue(m_ptr, "CSoundOpvarSetPathCornerEntity", "m_iszPathCornerEntityName", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCSoundOpvarSetPathCornerEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundOpvarSetPathCornerEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCSoundOpvarSetPointEntity GCSoundOpvarSetPathCornerEntity::GetParent() const {
    GCSoundOpvarSetPointEntity value(m_ptr);
    return value;
}
void GCSoundOpvarSetPathCornerEntity::SetParent(GCSoundOpvarSetPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundOpvarSetPathCornerEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundOpvarSetPathCornerEntity>("CSoundOpvarSetPathCornerEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DistMinSqr", &GCSoundOpvarSetPathCornerEntity::GetDistMinSqr, &GCSoundOpvarSetPathCornerEntity::SetDistMinSqr)
        .addProperty("DistMaxSqr", &GCSoundOpvarSetPathCornerEntity::GetDistMaxSqr, &GCSoundOpvarSetPathCornerEntity::SetDistMaxSqr)
        .addProperty("PathCornerEntityName", &GCSoundOpvarSetPathCornerEntity::GetPathCornerEntityName, &GCSoundOpvarSetPathCornerEntity::SetPathCornerEntityName)
        .addProperty("Parent", &GCSoundOpvarSetPathCornerEntity::GetParent, &GCSoundOpvarSetPathCornerEntity::SetParent)
        .addFunction("ToPtr", &GCSoundOpvarSetPathCornerEntity::ToPtr)
        .addFunction("IsValid", &GCSoundOpvarSetPathCornerEntity::IsValid)
        .endClass();
}