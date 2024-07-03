#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GConstraintSoundInfo::GConstraintSoundInfo(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GConstraintSoundInfo::GConstraintSoundInfo(void *ptr) {
    m_ptr = ptr;
}
GVelocitySampler GConstraintSoundInfo::GetSampler() const {
    GVelocitySampler value(GetSchemaPtr(m_ptr, "ConstraintSoundInfo", "m_vSampler"));
    return value;
}
void GConstraintSoundInfo::SetSampler(GVelocitySampler value) {
    SetSchemaValue(m_ptr, "ConstraintSoundInfo", "m_vSampler", false, value);
}
GSimpleConstraintSoundProfile GConstraintSoundInfo::GetSoundProfile() const {
    GSimpleConstraintSoundProfile value(GetSchemaPtr(m_ptr, "ConstraintSoundInfo", "m_soundProfile"));
    return value;
}
void GConstraintSoundInfo::SetSoundProfile(GSimpleConstraintSoundProfile value) {
    SetSchemaValue(m_ptr, "ConstraintSoundInfo", "m_soundProfile", false, value);
}
Vector GConstraintSoundInfo::GetForwardAxis() const {
    return GetSchemaValue<Vector>(m_ptr, "ConstraintSoundInfo", "m_forwardAxis");
}
void GConstraintSoundInfo::SetForwardAxis(Vector value) {
    SetSchemaValue(m_ptr, "ConstraintSoundInfo", "m_forwardAxis", false, value);
}
std::string GConstraintSoundInfo::GetTravelSoundFwd() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "ConstraintSoundInfo", "m_iszTravelSoundFwd").String();
}
void GConstraintSoundInfo::SetTravelSoundFwd(std::string value) {
    SetSchemaValue(m_ptr, "ConstraintSoundInfo", "m_iszTravelSoundFwd", false, CUtlSymbolLarge(value.c_str()));
}
std::string GConstraintSoundInfo::GetTravelSoundBack() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "ConstraintSoundInfo", "m_iszTravelSoundBack").String();
}
void GConstraintSoundInfo::SetTravelSoundBack(std::string value) {
    SetSchemaValue(m_ptr, "ConstraintSoundInfo", "m_iszTravelSoundBack", false, CUtlSymbolLarge(value.c_str()));
}
std::vector<CUtlSymbolLarge> GConstraintSoundInfo::GetReversalSounds() const {
    CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "ConstraintSoundInfo", "m_iszReversalSounds"); std::vector<CUtlSymbolLarge> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GConstraintSoundInfo::SetReversalSounds(std::vector<CUtlSymbolLarge> value) {
    CUtlSymbolLarge* outValue = GetSchemaValue<CUtlSymbolLarge*>(m_ptr, "ConstraintSoundInfo", "m_iszReversalSounds"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "ConstraintSoundInfo", "m_iszReversalSounds", false, outValue);
}
bool GConstraintSoundInfo::GetPlayTravelSound() const {
    return GetSchemaValue<bool>(m_ptr, "ConstraintSoundInfo", "m_bPlayTravelSound");
}
void GConstraintSoundInfo::SetPlayTravelSound(bool value) {
    SetSchemaValue(m_ptr, "ConstraintSoundInfo", "m_bPlayTravelSound", false, value);
}
bool GConstraintSoundInfo::GetPlayReversalSound() const {
    return GetSchemaValue<bool>(m_ptr, "ConstraintSoundInfo", "m_bPlayReversalSound");
}
void GConstraintSoundInfo::SetPlayReversalSound(bool value) {
    SetSchemaValue(m_ptr, "ConstraintSoundInfo", "m_bPlayReversalSound", false, value);
}
std::string GConstraintSoundInfo::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GConstraintSoundInfo::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassConstraintSoundInfo(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GConstraintSoundInfo>("ConstraintSoundInfo")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Sampler", &GConstraintSoundInfo::GetSampler, &GConstraintSoundInfo::SetSampler)
        .addProperty("SoundProfile", &GConstraintSoundInfo::GetSoundProfile, &GConstraintSoundInfo::SetSoundProfile)
        .addProperty("ForwardAxis", &GConstraintSoundInfo::GetForwardAxis, &GConstraintSoundInfo::SetForwardAxis)
        .addProperty("TravelSoundFwd", &GConstraintSoundInfo::GetTravelSoundFwd, &GConstraintSoundInfo::SetTravelSoundFwd)
        .addProperty("TravelSoundBack", &GConstraintSoundInfo::GetTravelSoundBack, &GConstraintSoundInfo::SetTravelSoundBack)
        .addProperty("ReversalSounds", &GConstraintSoundInfo::GetReversalSounds, &GConstraintSoundInfo::SetReversalSounds)
        .addProperty("PlayTravelSound", &GConstraintSoundInfo::GetPlayTravelSound, &GConstraintSoundInfo::SetPlayTravelSound)
        .addProperty("PlayReversalSound", &GConstraintSoundInfo::GetPlayReversalSound, &GConstraintSoundInfo::SetPlayReversalSound)
        .addFunction("ToPtr", &GConstraintSoundInfo::ToPtr)
        .addFunction("IsValid", &GConstraintSoundInfo::IsValid)
        .endClass();
}