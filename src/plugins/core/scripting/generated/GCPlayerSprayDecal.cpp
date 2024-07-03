#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPlayerSprayDecal::GCPlayerSprayDecal(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPlayerSprayDecal::GCPlayerSprayDecal(void *ptr) {
    m_ptr = ptr;
}
int32_t GCPlayerSprayDecal::GetUniqueID() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPlayerSprayDecal", "m_nUniqueID");
}
void GCPlayerSprayDecal::SetUniqueID(int32_t value) {
    SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_nUniqueID", false, value);
}
uint32_t GCPlayerSprayDecal::GetAccountID() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CPlayerSprayDecal", "m_unAccountID");
}
void GCPlayerSprayDecal::SetAccountID(uint32_t value) {
    SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_unAccountID", false, value);
}
uint32_t GCPlayerSprayDecal::GetTraceID() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CPlayerSprayDecal", "m_unTraceID");
}
void GCPlayerSprayDecal::SetTraceID(uint32_t value) {
    SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_unTraceID", false, value);
}
uint32_t GCPlayerSprayDecal::GetRtGcTime() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CPlayerSprayDecal", "m_rtGcTime");
}
void GCPlayerSprayDecal::SetRtGcTime(uint32_t value) {
    SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_rtGcTime", false, value);
}
Vector GCPlayerSprayDecal::GetEndPos() const {
    return GetSchemaValue<Vector>(m_ptr, "CPlayerSprayDecal", "m_vecEndPos");
}
void GCPlayerSprayDecal::SetEndPos(Vector value) {
    SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_vecEndPos", false, value);
}
Vector GCPlayerSprayDecal::GetStart() const {
    return GetSchemaValue<Vector>(m_ptr, "CPlayerSprayDecal", "m_vecStart");
}
void GCPlayerSprayDecal::SetStart(Vector value) {
    SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_vecStart", false, value);
}
Vector GCPlayerSprayDecal::GetLeft() const {
    return GetSchemaValue<Vector>(m_ptr, "CPlayerSprayDecal", "m_vecLeft");
}
void GCPlayerSprayDecal::SetLeft(Vector value) {
    SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_vecLeft", false, value);
}
Vector GCPlayerSprayDecal::GetNormal() const {
    return GetSchemaValue<Vector>(m_ptr, "CPlayerSprayDecal", "m_vecNormal");
}
void GCPlayerSprayDecal::SetNormal(Vector value) {
    SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_vecNormal", false, value);
}
int32_t GCPlayerSprayDecal::GetPlayer() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPlayerSprayDecal", "m_nPlayer");
}
void GCPlayerSprayDecal::SetPlayer(int32_t value) {
    SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_nPlayer", false, value);
}
int32_t GCPlayerSprayDecal::GetEntity() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPlayerSprayDecal", "m_nEntity");
}
void GCPlayerSprayDecal::SetEntity(int32_t value) {
    SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_nEntity", false, value);
}
int32_t GCPlayerSprayDecal::GetHitbox() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPlayerSprayDecal", "m_nHitbox");
}
void GCPlayerSprayDecal::SetHitbox(int32_t value) {
    SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_nHitbox", false, value);
}
float GCPlayerSprayDecal::GetCreationTime() const {
    return GetSchemaValue<float>(m_ptr, "CPlayerSprayDecal", "m_flCreationTime");
}
void GCPlayerSprayDecal::SetCreationTime(float value) {
    SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_flCreationTime", false, value);
}
int32_t GCPlayerSprayDecal::GetTintID() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPlayerSprayDecal", "m_nTintID");
}
void GCPlayerSprayDecal::SetTintID(int32_t value) {
    SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_nTintID", false, value);
}
uint8_t GCPlayerSprayDecal::GetVersion() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CPlayerSprayDecal", "m_nVersion");
}
void GCPlayerSprayDecal::SetVersion(uint8_t value) {
    SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_nVersion", false, value);
}
std::vector<uint8_t> GCPlayerSprayDecal::GetSignature() const {
    uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "CPlayerSprayDecal", "m_ubSignature"); std::vector<uint8_t> ret; for(int i = 0; i < 128; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCPlayerSprayDecal::SetSignature(std::vector<uint8_t> value) {
    uint8_t* outValue = GetSchemaValue<uint8_t*>(m_ptr, "CPlayerSprayDecal", "m_ubSignature"); for(int i = 0; i < 128; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CPlayerSprayDecal", "m_ubSignature", false, outValue);
}
std::string GCPlayerSprayDecal::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPlayerSprayDecal::IsValid() {
    return (m_ptr != nullptr);
}
GCModelPointEntity GCPlayerSprayDecal::GetParent() const {
    GCModelPointEntity value(m_ptr);
    return value;
}
void GCPlayerSprayDecal::SetParent(GCModelPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPlayerSprayDecal(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayerSprayDecal>("CPlayerSprayDecal")
        .addConstructor<void (*)(std::string)>()
        .addProperty("UniqueID", &GCPlayerSprayDecal::GetUniqueID, &GCPlayerSprayDecal::SetUniqueID)
        .addProperty("AccountID", &GCPlayerSprayDecal::GetAccountID, &GCPlayerSprayDecal::SetAccountID)
        .addProperty("TraceID", &GCPlayerSprayDecal::GetTraceID, &GCPlayerSprayDecal::SetTraceID)
        .addProperty("RtGcTime", &GCPlayerSprayDecal::GetRtGcTime, &GCPlayerSprayDecal::SetRtGcTime)
        .addProperty("EndPos", &GCPlayerSprayDecal::GetEndPos, &GCPlayerSprayDecal::SetEndPos)
        .addProperty("Start", &GCPlayerSprayDecal::GetStart, &GCPlayerSprayDecal::SetStart)
        .addProperty("Left", &GCPlayerSprayDecal::GetLeft, &GCPlayerSprayDecal::SetLeft)
        .addProperty("Normal", &GCPlayerSprayDecal::GetNormal, &GCPlayerSprayDecal::SetNormal)
        .addProperty("Player", &GCPlayerSprayDecal::GetPlayer, &GCPlayerSprayDecal::SetPlayer)
        .addProperty("Entity", &GCPlayerSprayDecal::GetEntity, &GCPlayerSprayDecal::SetEntity)
        .addProperty("Hitbox", &GCPlayerSprayDecal::GetHitbox, &GCPlayerSprayDecal::SetHitbox)
        .addProperty("CreationTime", &GCPlayerSprayDecal::GetCreationTime, &GCPlayerSprayDecal::SetCreationTime)
        .addProperty("TintID", &GCPlayerSprayDecal::GetTintID, &GCPlayerSprayDecal::SetTintID)
        .addProperty("Version", &GCPlayerSprayDecal::GetVersion, &GCPlayerSprayDecal::SetVersion)
        .addProperty("Signature", &GCPlayerSprayDecal::GetSignature, &GCPlayerSprayDecal::SetSignature)
        .addProperty("Parent", &GCPlayerSprayDecal::GetParent, &GCPlayerSprayDecal::SetParent)
        .addFunction("ToPtr", &GCPlayerSprayDecal::ToPtr)
        .addFunction("IsValid", &GCPlayerSprayDecal::IsValid)
        .endClass();
}