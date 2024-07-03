#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSPlayerResource::GCCSPlayerResource(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSPlayerResource::GCCSPlayerResource(void *ptr) {
    m_ptr = ptr;
}
std::vector<bool> GCCSPlayerResource::GetHostageAlive() const {
    bool* outValue = GetSchemaValue<bool*>(m_ptr, "CCSPlayerResource", "m_bHostageAlive"); std::vector<bool> ret; for(int i = 0; i < 12; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSPlayerResource::SetHostageAlive(std::vector<bool> value) {
    bool* outValue = GetSchemaValue<bool*>(m_ptr, "CCSPlayerResource", "m_bHostageAlive"); for(int i = 0; i < 12; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerResource", "m_bHostageAlive", false, outValue);
}
std::vector<bool> GCCSPlayerResource::GetIsHostageFollowingSomeone() const {
    bool* outValue = GetSchemaValue<bool*>(m_ptr, "CCSPlayerResource", "m_isHostageFollowingSomeone"); std::vector<bool> ret; for(int i = 0; i < 12; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSPlayerResource::SetIsHostageFollowingSomeone(std::vector<bool> value) {
    bool* outValue = GetSchemaValue<bool*>(m_ptr, "CCSPlayerResource", "m_isHostageFollowingSomeone"); for(int i = 0; i < 12; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerResource", "m_isHostageFollowingSomeone", false, outValue);
}
std::vector<CEntityIndex> GCCSPlayerResource::GetHostageEntityIDs() const {
    CEntityIndex* outValue = GetSchemaValue<CEntityIndex*>(m_ptr, "CCSPlayerResource", "m_iHostageEntityIDs"); std::vector<CEntityIndex> ret; for(int i = 0; i < 12; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSPlayerResource::SetHostageEntityIDs(std::vector<CEntityIndex> value) {
    CEntityIndex* outValue = GetSchemaValue<CEntityIndex*>(m_ptr, "CCSPlayerResource", "m_iHostageEntityIDs"); for(int i = 0; i < 12; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerResource", "m_iHostageEntityIDs", false, outValue);
}
Vector GCCSPlayerResource::GetBombsiteCenterA() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSPlayerResource", "m_bombsiteCenterA");
}
void GCCSPlayerResource::SetBombsiteCenterA(Vector value) {
    SetSchemaValue(m_ptr, "CCSPlayerResource", "m_bombsiteCenterA", false, value);
}
Vector GCCSPlayerResource::GetBombsiteCenterB() const {
    return GetSchemaValue<Vector>(m_ptr, "CCSPlayerResource", "m_bombsiteCenterB");
}
void GCCSPlayerResource::SetBombsiteCenterB(Vector value) {
    SetSchemaValue(m_ptr, "CCSPlayerResource", "m_bombsiteCenterB", false, value);
}
std::vector<int32_t> GCCSPlayerResource::GetHostageRescueX() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSPlayerResource", "m_hostageRescueX"); std::vector<int32_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSPlayerResource::SetHostageRescueX(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSPlayerResource", "m_hostageRescueX"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerResource", "m_hostageRescueX", false, outValue);
}
std::vector<int32_t> GCCSPlayerResource::GetHostageRescueY() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSPlayerResource", "m_hostageRescueY"); std::vector<int32_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSPlayerResource::SetHostageRescueY(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSPlayerResource", "m_hostageRescueY"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerResource", "m_hostageRescueY", false, outValue);
}
std::vector<int32_t> GCCSPlayerResource::GetHostageRescueZ() const {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSPlayerResource", "m_hostageRescueZ"); std::vector<int32_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCCSPlayerResource::SetHostageRescueZ(std::vector<int32_t> value) {
    int32_t* outValue = GetSchemaValue<int32_t*>(m_ptr, "CCSPlayerResource", "m_hostageRescueZ"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CCSPlayerResource", "m_hostageRescueZ", false, outValue);
}
bool GCCSPlayerResource::GetEndMatchNextMapAllVoted() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerResource", "m_bEndMatchNextMapAllVoted");
}
void GCCSPlayerResource::SetEndMatchNextMapAllVoted(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerResource", "m_bEndMatchNextMapAllVoted", false, value);
}
bool GCCSPlayerResource::GetFoundGoalPositions() const {
    return GetSchemaValue<bool>(m_ptr, "CCSPlayerResource", "m_foundGoalPositions");
}
void GCCSPlayerResource::SetFoundGoalPositions(bool value) {
    SetSchemaValue(m_ptr, "CCSPlayerResource", "m_foundGoalPositions", false, value);
}
std::string GCCSPlayerResource::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSPlayerResource::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCCSPlayerResource::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCCSPlayerResource::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSPlayerResource(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayerResource>("CCSPlayerResource")
        .addConstructor<void (*)(std::string)>()
        .addProperty("HostageAlive", &GCCSPlayerResource::GetHostageAlive, &GCCSPlayerResource::SetHostageAlive)
        .addProperty("IsHostageFollowingSomeone", &GCCSPlayerResource::GetIsHostageFollowingSomeone, &GCCSPlayerResource::SetIsHostageFollowingSomeone)
        .addProperty("HostageEntityIDs", &GCCSPlayerResource::GetHostageEntityIDs, &GCCSPlayerResource::SetHostageEntityIDs)
        .addProperty("BombsiteCenterA", &GCCSPlayerResource::GetBombsiteCenterA, &GCCSPlayerResource::SetBombsiteCenterA)
        .addProperty("BombsiteCenterB", &GCCSPlayerResource::GetBombsiteCenterB, &GCCSPlayerResource::SetBombsiteCenterB)
        .addProperty("HostageRescueX", &GCCSPlayerResource::GetHostageRescueX, &GCCSPlayerResource::SetHostageRescueX)
        .addProperty("HostageRescueY", &GCCSPlayerResource::GetHostageRescueY, &GCCSPlayerResource::SetHostageRescueY)
        .addProperty("HostageRescueZ", &GCCSPlayerResource::GetHostageRescueZ, &GCCSPlayerResource::SetHostageRescueZ)
        .addProperty("EndMatchNextMapAllVoted", &GCCSPlayerResource::GetEndMatchNextMapAllVoted, &GCCSPlayerResource::SetEndMatchNextMapAllVoted)
        .addProperty("FoundGoalPositions", &GCCSPlayerResource::GetFoundGoalPositions, &GCCSPlayerResource::SetFoundGoalPositions)
        .addProperty("Parent", &GCCSPlayerResource::GetParent, &GCCSPlayerResource::SetParent)
        .addFunction("ToPtr", &GCCSPlayerResource::ToPtr)
        .addFunction("IsValid", &GCCSPlayerResource::IsValid)
        .endClass();
}