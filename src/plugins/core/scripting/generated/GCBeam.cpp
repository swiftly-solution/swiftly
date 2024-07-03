#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBeam::GCBeam(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBeam::GCBeam(void *ptr) {
    m_ptr = ptr;
}
float GCBeam::GetFrameRate() const {
    return GetSchemaValue<float>(m_ptr, "CBeam", "m_flFrameRate");
}
void GCBeam::SetFrameRate(float value) {
    SetSchemaValue(m_ptr, "CBeam", "m_flFrameRate", false, value);
}
float GCBeam::GetHDRColorScale() const {
    return GetSchemaValue<float>(m_ptr, "CBeam", "m_flHDRColorScale");
}
void GCBeam::SetHDRColorScale(float value) {
    SetSchemaValue(m_ptr, "CBeam", "m_flHDRColorScale", false, value);
}
float GCBeam::GetFireTime() const {
    return GetSchemaValue<float>(m_ptr, "CBeam", "m_flFireTime");
}
void GCBeam::SetFireTime(float value) {
    SetSchemaValue(m_ptr, "CBeam", "m_flFireTime", false, value);
}
float GCBeam::GetDamage() const {
    return GetSchemaValue<float>(m_ptr, "CBeam", "m_flDamage");
}
void GCBeam::SetDamage(float value) {
    SetSchemaValue(m_ptr, "CBeam", "m_flDamage", false, value);
}
uint8_t GCBeam::GetNumBeamEnts() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CBeam", "m_nNumBeamEnts");
}
void GCBeam::SetNumBeamEnts(uint8_t value) {
    SetSchemaValue(m_ptr, "CBeam", "m_nNumBeamEnts", false, value);
}
uint64_t GCBeam::GetBeamType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBeam", "m_nBeamType");
}
void GCBeam::SetBeamType(uint64_t value) {
    SetSchemaValue(m_ptr, "CBeam", "m_nBeamType", false, value);
}
uint32_t GCBeam::GetBeamFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CBeam", "m_nBeamFlags");
}
void GCBeam::SetBeamFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "CBeam", "m_nBeamFlags", false, value);
}
std::vector<GCBaseEntity*> GCBeam::GetAttachEntity() const {
    GCBaseEntity** outValue = GetSchemaValue<GCBaseEntity**>(m_ptr, "CBeam", "m_hAttachEntity"); std::vector<GCBaseEntity*> ret; for(int i = 0; i < 10; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCBeam::SetAttachEntity(std::vector<GCBaseEntity*> value) {
    GCBaseEntity** outValue = GetSchemaValue<GCBaseEntity**>(m_ptr, "CBeam", "m_hAttachEntity"); for(int i = 0; i < 10; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CBeam", "m_hAttachEntity", false, outValue);
}
float GCBeam::GetWidth() const {
    return GetSchemaValue<float>(m_ptr, "CBeam", "m_fWidth");
}
void GCBeam::SetWidth(float value) {
    SetSchemaValue(m_ptr, "CBeam", "m_fWidth", false, value);
}
float GCBeam::GetEndWidth() const {
    return GetSchemaValue<float>(m_ptr, "CBeam", "m_fEndWidth");
}
void GCBeam::SetEndWidth(float value) {
    SetSchemaValue(m_ptr, "CBeam", "m_fEndWidth", false, value);
}
float GCBeam::GetFadeLength() const {
    return GetSchemaValue<float>(m_ptr, "CBeam", "m_fFadeLength");
}
void GCBeam::SetFadeLength(float value) {
    SetSchemaValue(m_ptr, "CBeam", "m_fFadeLength", false, value);
}
float GCBeam::GetHaloScale() const {
    return GetSchemaValue<float>(m_ptr, "CBeam", "m_fHaloScale");
}
void GCBeam::SetHaloScale(float value) {
    SetSchemaValue(m_ptr, "CBeam", "m_fHaloScale", false, value);
}
float GCBeam::GetAmplitude() const {
    return GetSchemaValue<float>(m_ptr, "CBeam", "m_fAmplitude");
}
void GCBeam::SetAmplitude(float value) {
    SetSchemaValue(m_ptr, "CBeam", "m_fAmplitude", false, value);
}
float GCBeam::GetStartFrame() const {
    return GetSchemaValue<float>(m_ptr, "CBeam", "m_fStartFrame");
}
void GCBeam::SetStartFrame(float value) {
    SetSchemaValue(m_ptr, "CBeam", "m_fStartFrame", false, value);
}
float GCBeam::GetSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CBeam", "m_fSpeed");
}
void GCBeam::SetSpeed(float value) {
    SetSchemaValue(m_ptr, "CBeam", "m_fSpeed", false, value);
}
float GCBeam::GetFrame() const {
    return GetSchemaValue<float>(m_ptr, "CBeam", "m_flFrame");
}
void GCBeam::SetFrame(float value) {
    SetSchemaValue(m_ptr, "CBeam", "m_flFrame", false, value);
}
uint64_t GCBeam::GetClipStyle() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CBeam", "m_nClipStyle");
}
void GCBeam::SetClipStyle(uint64_t value) {
    SetSchemaValue(m_ptr, "CBeam", "m_nClipStyle", false, value);
}
bool GCBeam::GetTurnedOff() const {
    return GetSchemaValue<bool>(m_ptr, "CBeam", "m_bTurnedOff");
}
void GCBeam::SetTurnedOff(bool value) {
    SetSchemaValue(m_ptr, "CBeam", "m_bTurnedOff", false, value);
}
Vector GCBeam::GetEndPos() const {
    return GetSchemaValue<Vector>(m_ptr, "CBeam", "m_vecEndPos");
}
void GCBeam::SetEndPos(Vector value) {
    SetSchemaValue(m_ptr, "CBeam", "m_vecEndPos", false, value);
}
GCBaseEntity GCBeam::GetEndEntity() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CBeam", "m_hEndEntity"));
    return value;
}
void GCBeam::SetEndEntity(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'EndEntity' is not possible.\n");
}
int32_t GCBeam::GetDissolveType() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBeam", "m_nDissolveType");
}
void GCBeam::SetDissolveType(int32_t value) {
    SetSchemaValue(m_ptr, "CBeam", "m_nDissolveType", false, value);
}
std::string GCBeam::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBeam::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCBeam::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCBeam::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBeam(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBeam>("CBeam")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FrameRate", &GCBeam::GetFrameRate, &GCBeam::SetFrameRate)
        .addProperty("HDRColorScale", &GCBeam::GetHDRColorScale, &GCBeam::SetHDRColorScale)
        .addProperty("FireTime", &GCBeam::GetFireTime, &GCBeam::SetFireTime)
        .addProperty("Damage", &GCBeam::GetDamage, &GCBeam::SetDamage)
        .addProperty("NumBeamEnts", &GCBeam::GetNumBeamEnts, &GCBeam::SetNumBeamEnts)
        .addProperty("BeamType", &GCBeam::GetBeamType, &GCBeam::SetBeamType)
        .addProperty("BeamFlags", &GCBeam::GetBeamFlags, &GCBeam::SetBeamFlags)
        .addProperty("AttachEntity", &GCBeam::GetAttachEntity, &GCBeam::SetAttachEntity)
        .addProperty("Width", &GCBeam::GetWidth, &GCBeam::SetWidth)
        .addProperty("EndWidth", &GCBeam::GetEndWidth, &GCBeam::SetEndWidth)
        .addProperty("FadeLength", &GCBeam::GetFadeLength, &GCBeam::SetFadeLength)
        .addProperty("HaloScale", &GCBeam::GetHaloScale, &GCBeam::SetHaloScale)
        .addProperty("Amplitude", &GCBeam::GetAmplitude, &GCBeam::SetAmplitude)
        .addProperty("StartFrame", &GCBeam::GetStartFrame, &GCBeam::SetStartFrame)
        .addProperty("Speed", &GCBeam::GetSpeed, &GCBeam::SetSpeed)
        .addProperty("Frame", &GCBeam::GetFrame, &GCBeam::SetFrame)
        .addProperty("ClipStyle", &GCBeam::GetClipStyle, &GCBeam::SetClipStyle)
        .addProperty("TurnedOff", &GCBeam::GetTurnedOff, &GCBeam::SetTurnedOff)
        .addProperty("EndPos", &GCBeam::GetEndPos, &GCBeam::SetEndPos)
        .addProperty("EndEntity", &GCBeam::GetEndEntity, &GCBeam::SetEndEntity)
        .addProperty("DissolveType", &GCBeam::GetDissolveType, &GCBeam::SetDissolveType)
        .addProperty("Parent", &GCBeam::GetParent, &GCBeam::SetParent)
        .addFunction("ToPtr", &GCBeam::ToPtr)
        .addFunction("IsValid", &GCBeam::IsValid)
        .endClass();
}