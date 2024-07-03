#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMovementComponentUpdater::GCMovementComponentUpdater(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMovementComponentUpdater::GCMovementComponentUpdater(void *ptr) {
    m_ptr = ptr;
}
GCAnimInputDamping GCMovementComponentUpdater::GetFacingDamping() const {
    GCAnimInputDamping value(GetSchemaPtr(m_ptr, "CMovementComponentUpdater", "m_facingDamping"));
    return value;
}
void GCMovementComponentUpdater::SetFacingDamping(GCAnimInputDamping value) {
    SetSchemaValue(m_ptr, "CMovementComponentUpdater", "m_facingDamping", false, value);
}
int32_t GCMovementComponentUpdater::GetDefaultMotorIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "CMovementComponentUpdater", "m_nDefaultMotorIndex");
}
void GCMovementComponentUpdater::SetDefaultMotorIndex(int32_t value) {
    SetSchemaValue(m_ptr, "CMovementComponentUpdater", "m_nDefaultMotorIndex", false, value);
}
float GCMovementComponentUpdater::GetDefaultRunSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CMovementComponentUpdater", "m_flDefaultRunSpeed");
}
void GCMovementComponentUpdater::SetDefaultRunSpeed(float value) {
    SetSchemaValue(m_ptr, "CMovementComponentUpdater", "m_flDefaultRunSpeed", false, value);
}
bool GCMovementComponentUpdater::GetMoveVarsDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CMovementComponentUpdater", "m_bMoveVarsDisabled");
}
void GCMovementComponentUpdater::SetMoveVarsDisabled(bool value) {
    SetSchemaValue(m_ptr, "CMovementComponentUpdater", "m_bMoveVarsDisabled", false, value);
}
bool GCMovementComponentUpdater::GetNetworkPath() const {
    return GetSchemaValue<bool>(m_ptr, "CMovementComponentUpdater", "m_bNetworkPath");
}
void GCMovementComponentUpdater::SetNetworkPath(bool value) {
    SetSchemaValue(m_ptr, "CMovementComponentUpdater", "m_bNetworkPath", false, value);
}
bool GCMovementComponentUpdater::GetNetworkFacing() const {
    return GetSchemaValue<bool>(m_ptr, "CMovementComponentUpdater", "m_bNetworkFacing");
}
void GCMovementComponentUpdater::SetNetworkFacing(bool value) {
    SetSchemaValue(m_ptr, "CMovementComponentUpdater", "m_bNetworkFacing", false, value);
}
std::vector<GCAnimParamHandle> GCMovementComponentUpdater::GetParamHandles() const {
    GCAnimParamHandle* outValue = GetSchemaValue<GCAnimParamHandle*>(m_ptr, "CMovementComponentUpdater", "m_paramHandles"); std::vector<GCAnimParamHandle> ret; for(int i = 0; i < 30; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCMovementComponentUpdater::SetParamHandles(std::vector<GCAnimParamHandle> value) {
    GCAnimParamHandle* outValue = GetSchemaValue<GCAnimParamHandle*>(m_ptr, "CMovementComponentUpdater", "m_paramHandles"); for(int i = 0; i < 30; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CMovementComponentUpdater", "m_paramHandles", false, outValue);
}
std::string GCMovementComponentUpdater::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMovementComponentUpdater::IsValid() {
    return (m_ptr != nullptr);
}
GCAnimComponentUpdater GCMovementComponentUpdater::GetParent() const {
    GCAnimComponentUpdater value(m_ptr);
    return value;
}
void GCMovementComponentUpdater::SetParent(GCAnimComponentUpdater value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMovementComponentUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMovementComponentUpdater>("CMovementComponentUpdater")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FacingDamping", &GCMovementComponentUpdater::GetFacingDamping, &GCMovementComponentUpdater::SetFacingDamping)
        .addProperty("DefaultMotorIndex", &GCMovementComponentUpdater::GetDefaultMotorIndex, &GCMovementComponentUpdater::SetDefaultMotorIndex)
        .addProperty("DefaultRunSpeed", &GCMovementComponentUpdater::GetDefaultRunSpeed, &GCMovementComponentUpdater::SetDefaultRunSpeed)
        .addProperty("MoveVarsDisabled", &GCMovementComponentUpdater::GetMoveVarsDisabled, &GCMovementComponentUpdater::SetMoveVarsDisabled)
        .addProperty("NetworkPath", &GCMovementComponentUpdater::GetNetworkPath, &GCMovementComponentUpdater::SetNetworkPath)
        .addProperty("NetworkFacing", &GCMovementComponentUpdater::GetNetworkFacing, &GCMovementComponentUpdater::SetNetworkFacing)
        .addProperty("ParamHandles", &GCMovementComponentUpdater::GetParamHandles, &GCMovementComponentUpdater::SetParamHandles)
        .addProperty("Parent", &GCMovementComponentUpdater::GetParent, &GCMovementComponentUpdater::SetParent)
        .addFunction("ToPtr", &GCMovementComponentUpdater::ToPtr)
        .addFunction("IsValid", &GCMovementComponentUpdater::IsValid)
        .endClass();
}