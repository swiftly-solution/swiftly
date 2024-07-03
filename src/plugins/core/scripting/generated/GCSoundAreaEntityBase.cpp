#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundAreaEntityBase::GCSoundAreaEntityBase(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundAreaEntityBase::GCSoundAreaEntityBase(void *ptr) {
    m_ptr = ptr;
}
bool GCSoundAreaEntityBase::GetDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CSoundAreaEntityBase", "m_bDisabled");
}
void GCSoundAreaEntityBase::SetDisabled(bool value) {
    SetSchemaValue(m_ptr, "CSoundAreaEntityBase", "m_bDisabled", false, value);
}
std::string GCSoundAreaEntityBase::GetSoundAreaType() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CSoundAreaEntityBase", "m_iszSoundAreaType").String();
}
void GCSoundAreaEntityBase::SetSoundAreaType(std::string value) {
    SetSchemaValue(m_ptr, "CSoundAreaEntityBase", "m_iszSoundAreaType", false, CUtlSymbolLarge(value.c_str()));
}
Vector GCSoundAreaEntityBase::GetPos() const {
    return GetSchemaValue<Vector>(m_ptr, "CSoundAreaEntityBase", "m_vPos");
}
void GCSoundAreaEntityBase::SetPos(Vector value) {
    SetSchemaValue(m_ptr, "CSoundAreaEntityBase", "m_vPos", false, value);
}
std::string GCSoundAreaEntityBase::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundAreaEntityBase::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCSoundAreaEntityBase::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCSoundAreaEntityBase::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundAreaEntityBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundAreaEntityBase>("CSoundAreaEntityBase")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Disabled", &GCSoundAreaEntityBase::GetDisabled, &GCSoundAreaEntityBase::SetDisabled)
        .addProperty("SoundAreaType", &GCSoundAreaEntityBase::GetSoundAreaType, &GCSoundAreaEntityBase::SetSoundAreaType)
        .addProperty("Pos", &GCSoundAreaEntityBase::GetPos, &GCSoundAreaEntityBase::SetPos)
        .addProperty("Parent", &GCSoundAreaEntityBase::GetParent, &GCSoundAreaEntityBase::SetParent)
        .addFunction("ToPtr", &GCSoundAreaEntityBase::ToPtr)
        .addFunction("IsValid", &GCSoundAreaEntityBase::IsValid)
        .endClass();
}