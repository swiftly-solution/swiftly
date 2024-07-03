#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleVecInput::GCParticleVecInput(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleVecInput::GCParticleVecInput(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCParticleVecInput::GetType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CParticleVecInput", "m_nType");
}
void GCParticleVecInput::SetType(uint64_t value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_nType", false, value);
}
Vector GCParticleVecInput::GetLiteralValue() const {
    return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vLiteralValue");
}
void GCParticleVecInput::SetLiteralValue(Vector value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_vLiteralValue", false, value);
}
Color GCParticleVecInput::GetLiteralColor() const {
    return GetSchemaValue<Color>(m_ptr, "CParticleVecInput", "m_LiteralColor");
}
void GCParticleVecInput::SetLiteralColor(Color value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_LiteralColor", false, value);
}
bool GCParticleVecInput::GetFollowNamedValue() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleVecInput", "m_bFollowNamedValue");
}
void GCParticleVecInput::SetFollowNamedValue(bool value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_bFollowNamedValue", false, value);
}
GParticleAttributeIndex_t GCParticleVecInput::GetVectorAttribute() const {
    GParticleAttributeIndex_t value(GetSchemaPtr(m_ptr, "CParticleVecInput", "m_nVectorAttribute"));
    return value;
}
void GCParticleVecInput::SetVectorAttribute(GParticleAttributeIndex_t value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_nVectorAttribute", false, value);
}
Vector GCParticleVecInput::GetVectorAttributeScale() const {
    return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vVectorAttributeScale");
}
void GCParticleVecInput::SetVectorAttributeScale(Vector value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_vVectorAttributeScale", false, value);
}
int32_t GCParticleVecInput::GetControlPoint() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleVecInput", "m_nControlPoint");
}
void GCParticleVecInput::SetControlPoint(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_nControlPoint", false, value);
}
int32_t GCParticleVecInput::GetDeltaControlPoint() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleVecInput", "m_nDeltaControlPoint");
}
void GCParticleVecInput::SetDeltaControlPoint(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_nDeltaControlPoint", false, value);
}
Vector GCParticleVecInput::GetCPValueScale() const {
    return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vCPValueScale");
}
void GCParticleVecInput::SetCPValueScale(Vector value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_vCPValueScale", false, value);
}
Vector GCParticleVecInput::GetCPRelativePosition() const {
    return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vCPRelativePosition");
}
void GCParticleVecInput::SetCPRelativePosition(Vector value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_vCPRelativePosition", false, value);
}
Vector GCParticleVecInput::GetCPRelativeDir() const {
    return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vCPRelativeDir");
}
void GCParticleVecInput::SetCPRelativeDir(Vector value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_vCPRelativeDir", false, value);
}
GCParticleFloatInput GCParticleVecInput::GetFloatComponentX() const {
    GCParticleFloatInput value(GetSchemaPtr(m_ptr, "CParticleVecInput", "m_FloatComponentX"));
    return value;
}
void GCParticleVecInput::SetFloatComponentX(GCParticleFloatInput value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_FloatComponentX", false, value);
}
GCParticleFloatInput GCParticleVecInput::GetFloatComponentY() const {
    GCParticleFloatInput value(GetSchemaPtr(m_ptr, "CParticleVecInput", "m_FloatComponentY"));
    return value;
}
void GCParticleVecInput::SetFloatComponentY(GCParticleFloatInput value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_FloatComponentY", false, value);
}
GCParticleFloatInput GCParticleVecInput::GetFloatComponentZ() const {
    GCParticleFloatInput value(GetSchemaPtr(m_ptr, "CParticleVecInput", "m_FloatComponentZ"));
    return value;
}
void GCParticleVecInput::SetFloatComponentZ(GCParticleFloatInput value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_FloatComponentZ", false, value);
}
GCParticleFloatInput GCParticleVecInput::GetFloatInterp() const {
    GCParticleFloatInput value(GetSchemaPtr(m_ptr, "CParticleVecInput", "m_FloatInterp"));
    return value;
}
void GCParticleVecInput::SetFloatInterp(GCParticleFloatInput value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_FloatInterp", false, value);
}
float GCParticleVecInput::GetInterpInput0() const {
    return GetSchemaValue<float>(m_ptr, "CParticleVecInput", "m_flInterpInput0");
}
void GCParticleVecInput::SetInterpInput0(float value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_flInterpInput0", false, value);
}
float GCParticleVecInput::GetInterpInput1() const {
    return GetSchemaValue<float>(m_ptr, "CParticleVecInput", "m_flInterpInput1");
}
void GCParticleVecInput::SetInterpInput1(float value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_flInterpInput1", false, value);
}
Vector GCParticleVecInput::GetInterpOutput0() const {
    return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vInterpOutput0");
}
void GCParticleVecInput::SetInterpOutput0(Vector value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_vInterpOutput0", false, value);
}
Vector GCParticleVecInput::GetInterpOutput1() const {
    return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vInterpOutput1");
}
void GCParticleVecInput::SetInterpOutput1(Vector value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_vInterpOutput1", false, value);
}
Vector GCParticleVecInput::GetRandomMin() const {
    return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vRandomMin");
}
void GCParticleVecInput::SetRandomMin(Vector value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_vRandomMin", false, value);
}
Vector GCParticleVecInput::GetRandomMax() const {
    return GetSchemaValue<Vector>(m_ptr, "CParticleVecInput", "m_vRandomMax");
}
void GCParticleVecInput::SetRandomMax(Vector value) {
    SetSchemaValue(m_ptr, "CParticleVecInput", "m_vRandomMax", false, value);
}
std::string GCParticleVecInput::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleVecInput::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleInput GCParticleVecInput::GetParent() const {
    GCParticleInput value(m_ptr);
    return value;
}
void GCParticleVecInput::SetParent(GCParticleInput value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCParticleVecInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleVecInput>("CParticleVecInput")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Type", &GCParticleVecInput::GetType, &GCParticleVecInput::SetType)
        .addProperty("LiteralValue", &GCParticleVecInput::GetLiteralValue, &GCParticleVecInput::SetLiteralValue)
        .addProperty("LiteralColor", &GCParticleVecInput::GetLiteralColor, &GCParticleVecInput::SetLiteralColor)
        .addProperty("FollowNamedValue", &GCParticleVecInput::GetFollowNamedValue, &GCParticleVecInput::SetFollowNamedValue)
        .addProperty("VectorAttribute", &GCParticleVecInput::GetVectorAttribute, &GCParticleVecInput::SetVectorAttribute)
        .addProperty("VectorAttributeScale", &GCParticleVecInput::GetVectorAttributeScale, &GCParticleVecInput::SetVectorAttributeScale)
        .addProperty("ControlPoint", &GCParticleVecInput::GetControlPoint, &GCParticleVecInput::SetControlPoint)
        .addProperty("DeltaControlPoint", &GCParticleVecInput::GetDeltaControlPoint, &GCParticleVecInput::SetDeltaControlPoint)
        .addProperty("CPValueScale", &GCParticleVecInput::GetCPValueScale, &GCParticleVecInput::SetCPValueScale)
        .addProperty("CPRelativePosition", &GCParticleVecInput::GetCPRelativePosition, &GCParticleVecInput::SetCPRelativePosition)
        .addProperty("CPRelativeDir", &GCParticleVecInput::GetCPRelativeDir, &GCParticleVecInput::SetCPRelativeDir)
        .addProperty("FloatComponentX", &GCParticleVecInput::GetFloatComponentX, &GCParticleVecInput::SetFloatComponentX)
        .addProperty("FloatComponentY", &GCParticleVecInput::GetFloatComponentY, &GCParticleVecInput::SetFloatComponentY)
        .addProperty("FloatComponentZ", &GCParticleVecInput::GetFloatComponentZ, &GCParticleVecInput::SetFloatComponentZ)
        .addProperty("FloatInterp", &GCParticleVecInput::GetFloatInterp, &GCParticleVecInput::SetFloatInterp)
        .addProperty("InterpInput0", &GCParticleVecInput::GetInterpInput0, &GCParticleVecInput::SetInterpInput0)
        .addProperty("InterpInput1", &GCParticleVecInput::GetInterpInput1, &GCParticleVecInput::SetInterpInput1)
        .addProperty("InterpOutput0", &GCParticleVecInput::GetInterpOutput0, &GCParticleVecInput::SetInterpOutput0)
        .addProperty("InterpOutput1", &GCParticleVecInput::GetInterpOutput1, &GCParticleVecInput::SetInterpOutput1)
        .addProperty("RandomMin", &GCParticleVecInput::GetRandomMin, &GCParticleVecInput::SetRandomMin)
        .addProperty("RandomMax", &GCParticleVecInput::GetRandomMax, &GCParticleVecInput::SetRandomMax)
        .addProperty("Parent", &GCParticleVecInput::GetParent, &GCParticleVecInput::SetParent)
        .addFunction("ToPtr", &GCParticleVecInput::ToPtr)
        .addFunction("IsValid", &GCParticleVecInput::IsValid)
        .endClass();
}