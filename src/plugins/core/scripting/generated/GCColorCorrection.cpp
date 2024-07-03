#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCColorCorrection::GCColorCorrection(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCColorCorrection::GCColorCorrection(void *ptr) {
    m_ptr = ptr;
}
float GCColorCorrection::GetFadeInDuration() const {
    return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_flFadeInDuration");
}
void GCColorCorrection::SetFadeInDuration(float value) {
    SetSchemaValue(m_ptr, "CColorCorrection", "m_flFadeInDuration", false, value);
}
float GCColorCorrection::GetFadeOutDuration() const {
    return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_flFadeOutDuration");
}
void GCColorCorrection::SetFadeOutDuration(float value) {
    SetSchemaValue(m_ptr, "CColorCorrection", "m_flFadeOutDuration", false, value);
}
float GCColorCorrection::GetStartFadeInWeight() const {
    return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_flStartFadeInWeight");
}
void GCColorCorrection::SetStartFadeInWeight(float value) {
    SetSchemaValue(m_ptr, "CColorCorrection", "m_flStartFadeInWeight", false, value);
}
float GCColorCorrection::GetStartFadeOutWeight() const {
    return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_flStartFadeOutWeight");
}
void GCColorCorrection::SetStartFadeOutWeight(float value) {
    SetSchemaValue(m_ptr, "CColorCorrection", "m_flStartFadeOutWeight", false, value);
}
float GCColorCorrection::GetTimeStartFadeIn() const {
    return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_flTimeStartFadeIn");
}
void GCColorCorrection::SetTimeStartFadeIn(float value) {
    SetSchemaValue(m_ptr, "CColorCorrection", "m_flTimeStartFadeIn", false, value);
}
float GCColorCorrection::GetTimeStartFadeOut() const {
    return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_flTimeStartFadeOut");
}
void GCColorCorrection::SetTimeStartFadeOut(float value) {
    SetSchemaValue(m_ptr, "CColorCorrection", "m_flTimeStartFadeOut", false, value);
}
float GCColorCorrection::GetMaxWeight() const {
    return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_flMaxWeight");
}
void GCColorCorrection::SetMaxWeight(float value) {
    SetSchemaValue(m_ptr, "CColorCorrection", "m_flMaxWeight", false, value);
}
bool GCColorCorrection::GetStartDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CColorCorrection", "m_bStartDisabled");
}
void GCColorCorrection::SetStartDisabled(bool value) {
    SetSchemaValue(m_ptr, "CColorCorrection", "m_bStartDisabled", false, value);
}
bool GCColorCorrection::GetEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CColorCorrection", "m_bEnabled");
}
void GCColorCorrection::SetEnabled(bool value) {
    SetSchemaValue(m_ptr, "CColorCorrection", "m_bEnabled", false, value);
}
bool GCColorCorrection::GetMaster() const {
    return GetSchemaValue<bool>(m_ptr, "CColorCorrection", "m_bMaster");
}
void GCColorCorrection::SetMaster(bool value) {
    SetSchemaValue(m_ptr, "CColorCorrection", "m_bMaster", false, value);
}
bool GCColorCorrection::GetClientSide() const {
    return GetSchemaValue<bool>(m_ptr, "CColorCorrection", "m_bClientSide");
}
void GCColorCorrection::SetClientSide(bool value) {
    SetSchemaValue(m_ptr, "CColorCorrection", "m_bClientSide", false, value);
}
bool GCColorCorrection::GetExclusive() const {
    return GetSchemaValue<bool>(m_ptr, "CColorCorrection", "m_bExclusive");
}
void GCColorCorrection::SetExclusive(bool value) {
    SetSchemaValue(m_ptr, "CColorCorrection", "m_bExclusive", false, value);
}
float GCColorCorrection::GetMinFalloff() const {
    return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_MinFalloff");
}
void GCColorCorrection::SetMinFalloff(float value) {
    SetSchemaValue(m_ptr, "CColorCorrection", "m_MinFalloff", false, value);
}
float GCColorCorrection::GetMaxFalloff() const {
    return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_MaxFalloff");
}
void GCColorCorrection::SetMaxFalloff(float value) {
    SetSchemaValue(m_ptr, "CColorCorrection", "m_MaxFalloff", false, value);
}
float GCColorCorrection::GetCurWeight() const {
    return GetSchemaValue<float>(m_ptr, "CColorCorrection", "m_flCurWeight");
}
void GCColorCorrection::SetCurWeight(float value) {
    SetSchemaValue(m_ptr, "CColorCorrection", "m_flCurWeight", false, value);
}
std::string GCColorCorrection::GetNetlookupFilename() const {
    return GetSchemaValuePtr<char>(m_ptr, "CColorCorrection", "m_netlookupFilename");
}
void GCColorCorrection::SetNetlookupFilename(std::string value) {
    WriteSchemaPtrValue(m_ptr, "CColorCorrection", "m_netlookupFilename", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), 512);
}
std::string GCColorCorrection::GetLookupFilename() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CColorCorrection", "m_lookupFilename").String();
}
void GCColorCorrection::SetLookupFilename(std::string value) {
    SetSchemaValue(m_ptr, "CColorCorrection", "m_lookupFilename", false, CUtlSymbolLarge(value.c_str()));
}
std::string GCColorCorrection::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCColorCorrection::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCColorCorrection::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCColorCorrection::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCColorCorrection(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCColorCorrection>("CColorCorrection")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FadeInDuration", &GCColorCorrection::GetFadeInDuration, &GCColorCorrection::SetFadeInDuration)
        .addProperty("FadeOutDuration", &GCColorCorrection::GetFadeOutDuration, &GCColorCorrection::SetFadeOutDuration)
        .addProperty("StartFadeInWeight", &GCColorCorrection::GetStartFadeInWeight, &GCColorCorrection::SetStartFadeInWeight)
        .addProperty("StartFadeOutWeight", &GCColorCorrection::GetStartFadeOutWeight, &GCColorCorrection::SetStartFadeOutWeight)
        .addProperty("TimeStartFadeIn", &GCColorCorrection::GetTimeStartFadeIn, &GCColorCorrection::SetTimeStartFadeIn)
        .addProperty("TimeStartFadeOut", &GCColorCorrection::GetTimeStartFadeOut, &GCColorCorrection::SetTimeStartFadeOut)
        .addProperty("MaxWeight", &GCColorCorrection::GetMaxWeight, &GCColorCorrection::SetMaxWeight)
        .addProperty("StartDisabled", &GCColorCorrection::GetStartDisabled, &GCColorCorrection::SetStartDisabled)
        .addProperty("Enabled", &GCColorCorrection::GetEnabled, &GCColorCorrection::SetEnabled)
        .addProperty("Master", &GCColorCorrection::GetMaster, &GCColorCorrection::SetMaster)
        .addProperty("ClientSide", &GCColorCorrection::GetClientSide, &GCColorCorrection::SetClientSide)
        .addProperty("Exclusive", &GCColorCorrection::GetExclusive, &GCColorCorrection::SetExclusive)
        .addProperty("MinFalloff", &GCColorCorrection::GetMinFalloff, &GCColorCorrection::SetMinFalloff)
        .addProperty("MaxFalloff", &GCColorCorrection::GetMaxFalloff, &GCColorCorrection::SetMaxFalloff)
        .addProperty("CurWeight", &GCColorCorrection::GetCurWeight, &GCColorCorrection::SetCurWeight)
        .addProperty("NetlookupFilename", &GCColorCorrection::GetNetlookupFilename, &GCColorCorrection::SetNetlookupFilename)
        .addProperty("LookupFilename", &GCColorCorrection::GetLookupFilename, &GCColorCorrection::SetLookupFilename)
        .addProperty("Parent", &GCColorCorrection::GetParent, &GCColorCorrection::SetParent)
        .addFunction("ToPtr", &GCColorCorrection::ToPtr)
        .addFunction("IsValid", &GCColorCorrection::IsValid)
        .endClass();
}