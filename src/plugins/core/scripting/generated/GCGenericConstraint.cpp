#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGenericConstraint::GCGenericConstraint(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGenericConstraint::GCGenericConstraint(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCGenericConstraint::GetLinearMotionX() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CGenericConstraint", "m_nLinearMotionX");
}
void GCGenericConstraint::SetLinearMotionX(uint64_t value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_nLinearMotionX", false, value);
}
uint64_t GCGenericConstraint::GetLinearMotionY() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CGenericConstraint", "m_nLinearMotionY");
}
void GCGenericConstraint::SetLinearMotionY(uint64_t value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_nLinearMotionY", false, value);
}
uint64_t GCGenericConstraint::GetLinearMotionZ() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CGenericConstraint", "m_nLinearMotionZ");
}
void GCGenericConstraint::SetLinearMotionZ(uint64_t value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_nLinearMotionZ", false, value);
}
float GCGenericConstraint::GetLinearFrequencyX() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flLinearFrequencyX");
}
void GCGenericConstraint::SetLinearFrequencyX(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flLinearFrequencyX", false, value);
}
float GCGenericConstraint::GetLinearFrequencyY() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flLinearFrequencyY");
}
void GCGenericConstraint::SetLinearFrequencyY(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flLinearFrequencyY", false, value);
}
float GCGenericConstraint::GetLinearFrequencyZ() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flLinearFrequencyZ");
}
void GCGenericConstraint::SetLinearFrequencyZ(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flLinearFrequencyZ", false, value);
}
float GCGenericConstraint::GetLinearDampingRatioX() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flLinearDampingRatioX");
}
void GCGenericConstraint::SetLinearDampingRatioX(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flLinearDampingRatioX", false, value);
}
float GCGenericConstraint::GetLinearDampingRatioY() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flLinearDampingRatioY");
}
void GCGenericConstraint::SetLinearDampingRatioY(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flLinearDampingRatioY", false, value);
}
float GCGenericConstraint::GetLinearDampingRatioZ() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flLinearDampingRatioZ");
}
void GCGenericConstraint::SetLinearDampingRatioZ(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flLinearDampingRatioZ", false, value);
}
float GCGenericConstraint::GetMaxLinearImpulseX() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flMaxLinearImpulseX");
}
void GCGenericConstraint::SetMaxLinearImpulseX(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flMaxLinearImpulseX", false, value);
}
float GCGenericConstraint::GetMaxLinearImpulseY() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flMaxLinearImpulseY");
}
void GCGenericConstraint::SetMaxLinearImpulseY(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flMaxLinearImpulseY", false, value);
}
float GCGenericConstraint::GetMaxLinearImpulseZ() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flMaxLinearImpulseZ");
}
void GCGenericConstraint::SetMaxLinearImpulseZ(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flMaxLinearImpulseZ", false, value);
}
float GCGenericConstraint::GetBreakAfterTimeX() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeX");
}
void GCGenericConstraint::SetBreakAfterTimeX(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeX", false, value);
}
float GCGenericConstraint::GetBreakAfterTimeY() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeY");
}
void GCGenericConstraint::SetBreakAfterTimeY(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeY", false, value);
}
float GCGenericConstraint::GetBreakAfterTimeZ() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeZ");
}
void GCGenericConstraint::SetBreakAfterTimeZ(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeZ", false, value);
}
float GCGenericConstraint::GetBreakAfterTimeStartTimeX() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeStartTimeX");
}
void GCGenericConstraint::SetBreakAfterTimeStartTimeX(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeStartTimeX", false, value);
}
float GCGenericConstraint::GetBreakAfterTimeStartTimeY() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeStartTimeY");
}
void GCGenericConstraint::SetBreakAfterTimeStartTimeY(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeStartTimeY", false, value);
}
float GCGenericConstraint::GetBreakAfterTimeStartTimeZ() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeStartTimeZ");
}
void GCGenericConstraint::SetBreakAfterTimeStartTimeZ(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeStartTimeZ", false, value);
}
float GCGenericConstraint::GetBreakAfterTimeThresholdX() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeThresholdX");
}
void GCGenericConstraint::SetBreakAfterTimeThresholdX(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeThresholdX", false, value);
}
float GCGenericConstraint::GetBreakAfterTimeThresholdY() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeThresholdY");
}
void GCGenericConstraint::SetBreakAfterTimeThresholdY(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeThresholdY", false, value);
}
float GCGenericConstraint::GetBreakAfterTimeThresholdZ() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeThresholdZ");
}
void GCGenericConstraint::SetBreakAfterTimeThresholdZ(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flBreakAfterTimeThresholdZ", false, value);
}
float GCGenericConstraint::GetNotifyForceX() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flNotifyForceX");
}
void GCGenericConstraint::SetNotifyForceX(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flNotifyForceX", false, value);
}
float GCGenericConstraint::GetNotifyForceY() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flNotifyForceY");
}
void GCGenericConstraint::SetNotifyForceY(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flNotifyForceY", false, value);
}
float GCGenericConstraint::GetNotifyForceZ() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flNotifyForceZ");
}
void GCGenericConstraint::SetNotifyForceZ(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flNotifyForceZ", false, value);
}
float GCGenericConstraint::GetNotifyForceMinTimeX() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flNotifyForceMinTimeX");
}
void GCGenericConstraint::SetNotifyForceMinTimeX(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flNotifyForceMinTimeX", false, value);
}
float GCGenericConstraint::GetNotifyForceMinTimeY() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flNotifyForceMinTimeY");
}
void GCGenericConstraint::SetNotifyForceMinTimeY(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flNotifyForceMinTimeY", false, value);
}
float GCGenericConstraint::GetNotifyForceMinTimeZ() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flNotifyForceMinTimeZ");
}
void GCGenericConstraint::SetNotifyForceMinTimeZ(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flNotifyForceMinTimeZ", false, value);
}
float GCGenericConstraint::GetNotifyForceLastTimeX() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flNotifyForceLastTimeX");
}
void GCGenericConstraint::SetNotifyForceLastTimeX(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flNotifyForceLastTimeX", false, value);
}
float GCGenericConstraint::GetNotifyForceLastTimeY() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flNotifyForceLastTimeY");
}
void GCGenericConstraint::SetNotifyForceLastTimeY(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flNotifyForceLastTimeY", false, value);
}
float GCGenericConstraint::GetNotifyForceLastTimeZ() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flNotifyForceLastTimeZ");
}
void GCGenericConstraint::SetNotifyForceLastTimeZ(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flNotifyForceLastTimeZ", false, value);
}
bool GCGenericConstraint::GetAxisNotifiedX() const {
    return GetSchemaValue<bool>(m_ptr, "CGenericConstraint", "m_bAxisNotifiedX");
}
void GCGenericConstraint::SetAxisNotifiedX(bool value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_bAxisNotifiedX", false, value);
}
bool GCGenericConstraint::GetAxisNotifiedY() const {
    return GetSchemaValue<bool>(m_ptr, "CGenericConstraint", "m_bAxisNotifiedY");
}
void GCGenericConstraint::SetAxisNotifiedY(bool value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_bAxisNotifiedY", false, value);
}
bool GCGenericConstraint::GetAxisNotifiedZ() const {
    return GetSchemaValue<bool>(m_ptr, "CGenericConstraint", "m_bAxisNotifiedZ");
}
void GCGenericConstraint::SetAxisNotifiedZ(bool value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_bAxisNotifiedZ", false, value);
}
uint64_t GCGenericConstraint::GetAngularMotionX() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CGenericConstraint", "m_nAngularMotionX");
}
void GCGenericConstraint::SetAngularMotionX(uint64_t value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_nAngularMotionX", false, value);
}
uint64_t GCGenericConstraint::GetAngularMotionY() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CGenericConstraint", "m_nAngularMotionY");
}
void GCGenericConstraint::SetAngularMotionY(uint64_t value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_nAngularMotionY", false, value);
}
uint64_t GCGenericConstraint::GetAngularMotionZ() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CGenericConstraint", "m_nAngularMotionZ");
}
void GCGenericConstraint::SetAngularMotionZ(uint64_t value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_nAngularMotionZ", false, value);
}
float GCGenericConstraint::GetAngularFrequencyX() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flAngularFrequencyX");
}
void GCGenericConstraint::SetAngularFrequencyX(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flAngularFrequencyX", false, value);
}
float GCGenericConstraint::GetAngularFrequencyY() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flAngularFrequencyY");
}
void GCGenericConstraint::SetAngularFrequencyY(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flAngularFrequencyY", false, value);
}
float GCGenericConstraint::GetAngularFrequencyZ() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flAngularFrequencyZ");
}
void GCGenericConstraint::SetAngularFrequencyZ(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flAngularFrequencyZ", false, value);
}
float GCGenericConstraint::GetAngularDampingRatioX() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flAngularDampingRatioX");
}
void GCGenericConstraint::SetAngularDampingRatioX(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flAngularDampingRatioX", false, value);
}
float GCGenericConstraint::GetAngularDampingRatioY() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flAngularDampingRatioY");
}
void GCGenericConstraint::SetAngularDampingRatioY(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flAngularDampingRatioY", false, value);
}
float GCGenericConstraint::GetAngularDampingRatioZ() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flAngularDampingRatioZ");
}
void GCGenericConstraint::SetAngularDampingRatioZ(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flAngularDampingRatioZ", false, value);
}
float GCGenericConstraint::GetMaxAngularImpulseX() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flMaxAngularImpulseX");
}
void GCGenericConstraint::SetMaxAngularImpulseX(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flMaxAngularImpulseX", false, value);
}
float GCGenericConstraint::GetMaxAngularImpulseY() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flMaxAngularImpulseY");
}
void GCGenericConstraint::SetMaxAngularImpulseY(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flMaxAngularImpulseY", false, value);
}
float GCGenericConstraint::GetMaxAngularImpulseZ() const {
    return GetSchemaValue<float>(m_ptr, "CGenericConstraint", "m_flMaxAngularImpulseZ");
}
void GCGenericConstraint::SetMaxAngularImpulseZ(float value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_flMaxAngularImpulseZ", false, value);
}
GCEntityIOOutput GCGenericConstraint::GetNotifyForceReachedX() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CGenericConstraint", "m_NotifyForceReachedX"));
    return value;
}
void GCGenericConstraint::SetNotifyForceReachedX(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_NotifyForceReachedX", false, value);
}
GCEntityIOOutput GCGenericConstraint::GetNotifyForceReachedY() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CGenericConstraint", "m_NotifyForceReachedY"));
    return value;
}
void GCGenericConstraint::SetNotifyForceReachedY(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_NotifyForceReachedY", false, value);
}
GCEntityIOOutput GCGenericConstraint::GetNotifyForceReachedZ() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CGenericConstraint", "m_NotifyForceReachedZ"));
    return value;
}
void GCGenericConstraint::SetNotifyForceReachedZ(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CGenericConstraint", "m_NotifyForceReachedZ", false, value);
}
std::string GCGenericConstraint::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGenericConstraint::IsValid() {
    return (m_ptr != nullptr);
}
GCPhysConstraint GCGenericConstraint::GetParent() const {
    GCPhysConstraint value(m_ptr);
    return value;
}
void GCGenericConstraint::SetParent(GCPhysConstraint value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCGenericConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGenericConstraint>("CGenericConstraint")
        .addConstructor<void (*)(std::string)>()
        .addProperty("LinearMotionX", &GCGenericConstraint::GetLinearMotionX, &GCGenericConstraint::SetLinearMotionX)
        .addProperty("LinearMotionY", &GCGenericConstraint::GetLinearMotionY, &GCGenericConstraint::SetLinearMotionY)
        .addProperty("LinearMotionZ", &GCGenericConstraint::GetLinearMotionZ, &GCGenericConstraint::SetLinearMotionZ)
        .addProperty("LinearFrequencyX", &GCGenericConstraint::GetLinearFrequencyX, &GCGenericConstraint::SetLinearFrequencyX)
        .addProperty("LinearFrequencyY", &GCGenericConstraint::GetLinearFrequencyY, &GCGenericConstraint::SetLinearFrequencyY)
        .addProperty("LinearFrequencyZ", &GCGenericConstraint::GetLinearFrequencyZ, &GCGenericConstraint::SetLinearFrequencyZ)
        .addProperty("LinearDampingRatioX", &GCGenericConstraint::GetLinearDampingRatioX, &GCGenericConstraint::SetLinearDampingRatioX)
        .addProperty("LinearDampingRatioY", &GCGenericConstraint::GetLinearDampingRatioY, &GCGenericConstraint::SetLinearDampingRatioY)
        .addProperty("LinearDampingRatioZ", &GCGenericConstraint::GetLinearDampingRatioZ, &GCGenericConstraint::SetLinearDampingRatioZ)
        .addProperty("MaxLinearImpulseX", &GCGenericConstraint::GetMaxLinearImpulseX, &GCGenericConstraint::SetMaxLinearImpulseX)
        .addProperty("MaxLinearImpulseY", &GCGenericConstraint::GetMaxLinearImpulseY, &GCGenericConstraint::SetMaxLinearImpulseY)
        .addProperty("MaxLinearImpulseZ", &GCGenericConstraint::GetMaxLinearImpulseZ, &GCGenericConstraint::SetMaxLinearImpulseZ)
        .addProperty("BreakAfterTimeX", &GCGenericConstraint::GetBreakAfterTimeX, &GCGenericConstraint::SetBreakAfterTimeX)
        .addProperty("BreakAfterTimeY", &GCGenericConstraint::GetBreakAfterTimeY, &GCGenericConstraint::SetBreakAfterTimeY)
        .addProperty("BreakAfterTimeZ", &GCGenericConstraint::GetBreakAfterTimeZ, &GCGenericConstraint::SetBreakAfterTimeZ)
        .addProperty("BreakAfterTimeStartTimeX", &GCGenericConstraint::GetBreakAfterTimeStartTimeX, &GCGenericConstraint::SetBreakAfterTimeStartTimeX)
        .addProperty("BreakAfterTimeStartTimeY", &GCGenericConstraint::GetBreakAfterTimeStartTimeY, &GCGenericConstraint::SetBreakAfterTimeStartTimeY)
        .addProperty("BreakAfterTimeStartTimeZ", &GCGenericConstraint::GetBreakAfterTimeStartTimeZ, &GCGenericConstraint::SetBreakAfterTimeStartTimeZ)
        .addProperty("BreakAfterTimeThresholdX", &GCGenericConstraint::GetBreakAfterTimeThresholdX, &GCGenericConstraint::SetBreakAfterTimeThresholdX)
        .addProperty("BreakAfterTimeThresholdY", &GCGenericConstraint::GetBreakAfterTimeThresholdY, &GCGenericConstraint::SetBreakAfterTimeThresholdY)
        .addProperty("BreakAfterTimeThresholdZ", &GCGenericConstraint::GetBreakAfterTimeThresholdZ, &GCGenericConstraint::SetBreakAfterTimeThresholdZ)
        .addProperty("NotifyForceX", &GCGenericConstraint::GetNotifyForceX, &GCGenericConstraint::SetNotifyForceX)
        .addProperty("NotifyForceY", &GCGenericConstraint::GetNotifyForceY, &GCGenericConstraint::SetNotifyForceY)
        .addProperty("NotifyForceZ", &GCGenericConstraint::GetNotifyForceZ, &GCGenericConstraint::SetNotifyForceZ)
        .addProperty("NotifyForceMinTimeX", &GCGenericConstraint::GetNotifyForceMinTimeX, &GCGenericConstraint::SetNotifyForceMinTimeX)
        .addProperty("NotifyForceMinTimeY", &GCGenericConstraint::GetNotifyForceMinTimeY, &GCGenericConstraint::SetNotifyForceMinTimeY)
        .addProperty("NotifyForceMinTimeZ", &GCGenericConstraint::GetNotifyForceMinTimeZ, &GCGenericConstraint::SetNotifyForceMinTimeZ)
        .addProperty("NotifyForceLastTimeX", &GCGenericConstraint::GetNotifyForceLastTimeX, &GCGenericConstraint::SetNotifyForceLastTimeX)
        .addProperty("NotifyForceLastTimeY", &GCGenericConstraint::GetNotifyForceLastTimeY, &GCGenericConstraint::SetNotifyForceLastTimeY)
        .addProperty("NotifyForceLastTimeZ", &GCGenericConstraint::GetNotifyForceLastTimeZ, &GCGenericConstraint::SetNotifyForceLastTimeZ)
        .addProperty("AxisNotifiedX", &GCGenericConstraint::GetAxisNotifiedX, &GCGenericConstraint::SetAxisNotifiedX)
        .addProperty("AxisNotifiedY", &GCGenericConstraint::GetAxisNotifiedY, &GCGenericConstraint::SetAxisNotifiedY)
        .addProperty("AxisNotifiedZ", &GCGenericConstraint::GetAxisNotifiedZ, &GCGenericConstraint::SetAxisNotifiedZ)
        .addProperty("AngularMotionX", &GCGenericConstraint::GetAngularMotionX, &GCGenericConstraint::SetAngularMotionX)
        .addProperty("AngularMotionY", &GCGenericConstraint::GetAngularMotionY, &GCGenericConstraint::SetAngularMotionY)
        .addProperty("AngularMotionZ", &GCGenericConstraint::GetAngularMotionZ, &GCGenericConstraint::SetAngularMotionZ)
        .addProperty("AngularFrequencyX", &GCGenericConstraint::GetAngularFrequencyX, &GCGenericConstraint::SetAngularFrequencyX)
        .addProperty("AngularFrequencyY", &GCGenericConstraint::GetAngularFrequencyY, &GCGenericConstraint::SetAngularFrequencyY)
        .addProperty("AngularFrequencyZ", &GCGenericConstraint::GetAngularFrequencyZ, &GCGenericConstraint::SetAngularFrequencyZ)
        .addProperty("AngularDampingRatioX", &GCGenericConstraint::GetAngularDampingRatioX, &GCGenericConstraint::SetAngularDampingRatioX)
        .addProperty("AngularDampingRatioY", &GCGenericConstraint::GetAngularDampingRatioY, &GCGenericConstraint::SetAngularDampingRatioY)
        .addProperty("AngularDampingRatioZ", &GCGenericConstraint::GetAngularDampingRatioZ, &GCGenericConstraint::SetAngularDampingRatioZ)
        .addProperty("MaxAngularImpulseX", &GCGenericConstraint::GetMaxAngularImpulseX, &GCGenericConstraint::SetMaxAngularImpulseX)
        .addProperty("MaxAngularImpulseY", &GCGenericConstraint::GetMaxAngularImpulseY, &GCGenericConstraint::SetMaxAngularImpulseY)
        .addProperty("MaxAngularImpulseZ", &GCGenericConstraint::GetMaxAngularImpulseZ, &GCGenericConstraint::SetMaxAngularImpulseZ)
        .addProperty("NotifyForceReachedX", &GCGenericConstraint::GetNotifyForceReachedX, &GCGenericConstraint::SetNotifyForceReachedX)
        .addProperty("NotifyForceReachedY", &GCGenericConstraint::GetNotifyForceReachedY, &GCGenericConstraint::SetNotifyForceReachedY)
        .addProperty("NotifyForceReachedZ", &GCGenericConstraint::GetNotifyForceReachedZ, &GCGenericConstraint::SetNotifyForceReachedZ)
        .addProperty("Parent", &GCGenericConstraint::GetParent, &GCGenericConstraint::SetParent)
        .addFunction("ToPtr", &GCGenericConstraint::ToPtr)
        .addFunction("IsValid", &GCGenericConstraint::IsValid)
        .endClass();
}