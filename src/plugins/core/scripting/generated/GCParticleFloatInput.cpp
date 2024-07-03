#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleFloatInput::GCParticleFloatInput(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleFloatInput::GCParticleFloatInput(void *ptr) {
    m_ptr = ptr;
}
uint64_t GCParticleFloatInput::GetType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CParticleFloatInput", "m_nType");
}
void GCParticleFloatInput::SetType(uint64_t value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nType", false, value);
}
uint64_t GCParticleFloatInput::GetMapType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CParticleFloatInput", "m_nMapType");
}
void GCParticleFloatInput::SetMapType(uint64_t value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nMapType", false, value);
}
float GCParticleFloatInput::GetLiteralValue() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flLiteralValue");
}
void GCParticleFloatInput::SetLiteralValue(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flLiteralValue", false, value);
}
int32_t GCParticleFloatInput::GetControlPoint() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleFloatInput", "m_nControlPoint");
}
void GCParticleFloatInput::SetControlPoint(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nControlPoint", false, value);
}
GParticleAttributeIndex_t GCParticleFloatInput::GetScalarAttribute() const {
    GParticleAttributeIndex_t value(GetSchemaPtr(m_ptr, "CParticleFloatInput", "m_nScalarAttribute"));
    return value;
}
void GCParticleFloatInput::SetScalarAttribute(GParticleAttributeIndex_t value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nScalarAttribute", false, value);
}
GParticleAttributeIndex_t GCParticleFloatInput::GetVectorAttribute() const {
    GParticleAttributeIndex_t value(GetSchemaPtr(m_ptr, "CParticleFloatInput", "m_nVectorAttribute"));
    return value;
}
void GCParticleFloatInput::SetVectorAttribute(GParticleAttributeIndex_t value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nVectorAttribute", false, value);
}
int32_t GCParticleFloatInput::GetVectorComponent() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleFloatInput", "m_nVectorComponent");
}
void GCParticleFloatInput::SetVectorComponent(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nVectorComponent", false, value);
}
float GCParticleFloatInput::GetRandomMin() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flRandomMin");
}
void GCParticleFloatInput::SetRandomMin(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flRandomMin", false, value);
}
float GCParticleFloatInput::GetRandomMax() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flRandomMax");
}
void GCParticleFloatInput::SetRandomMax(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flRandomMax", false, value);
}
bool GCParticleFloatInput::GetHasRandomSignFlip() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleFloatInput", "m_bHasRandomSignFlip");
}
void GCParticleFloatInput::SetHasRandomSignFlip(bool value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_bHasRandomSignFlip", false, value);
}
int32_t GCParticleFloatInput::GetRandomSeed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleFloatInput", "m_nRandomSeed");
}
void GCParticleFloatInput::SetRandomSeed(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nRandomSeed", false, value);
}
uint64_t GCParticleFloatInput::GetRandomMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CParticleFloatInput", "m_nRandomMode");
}
void GCParticleFloatInput::SetRandomMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nRandomMode", false, value);
}
float GCParticleFloatInput::GetLOD0() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flLOD0");
}
void GCParticleFloatInput::SetLOD0(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flLOD0", false, value);
}
float GCParticleFloatInput::GetLOD1() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flLOD1");
}
void GCParticleFloatInput::SetLOD1(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flLOD1", false, value);
}
float GCParticleFloatInput::GetLOD2() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flLOD2");
}
void GCParticleFloatInput::SetLOD2(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flLOD2", false, value);
}
float GCParticleFloatInput::GetLOD3() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flLOD3");
}
void GCParticleFloatInput::SetLOD3(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flLOD3", false, value);
}
GParticleAttributeIndex_t GCParticleFloatInput::GetNoiseInputVectorAttribute() const {
    GParticleAttributeIndex_t value(GetSchemaPtr(m_ptr, "CParticleFloatInput", "m_nNoiseInputVectorAttribute"));
    return value;
}
void GCParticleFloatInput::SetNoiseInputVectorAttribute(GParticleAttributeIndex_t value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nNoiseInputVectorAttribute", false, value);
}
float GCParticleFloatInput::GetNoiseOutputMin() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNoiseOutputMin");
}
void GCParticleFloatInput::SetNoiseOutputMin(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNoiseOutputMin", false, value);
}
float GCParticleFloatInput::GetNoiseOutputMax() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNoiseOutputMax");
}
void GCParticleFloatInput::SetNoiseOutputMax(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNoiseOutputMax", false, value);
}
float GCParticleFloatInput::GetNoiseScale() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNoiseScale");
}
void GCParticleFloatInput::SetNoiseScale(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNoiseScale", false, value);
}
Vector GCParticleFloatInput::GetNoiseOffsetRate() const {
    return GetSchemaValue<Vector>(m_ptr, "CParticleFloatInput", "m_vecNoiseOffsetRate");
}
void GCParticleFloatInput::SetNoiseOffsetRate(Vector value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_vecNoiseOffsetRate", false, value);
}
float GCParticleFloatInput::GetNoiseOffset() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNoiseOffset");
}
void GCParticleFloatInput::SetNoiseOffset(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNoiseOffset", false, value);
}
int32_t GCParticleFloatInput::GetNoiseOctaves() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleFloatInput", "m_nNoiseOctaves");
}
void GCParticleFloatInput::SetNoiseOctaves(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nNoiseOctaves", false, value);
}
uint64_t GCParticleFloatInput::GetNoiseTurbulence() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CParticleFloatInput", "m_nNoiseTurbulence");
}
void GCParticleFloatInput::SetNoiseTurbulence(uint64_t value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nNoiseTurbulence", false, value);
}
uint64_t GCParticleFloatInput::GetNoiseType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CParticleFloatInput", "m_nNoiseType");
}
void GCParticleFloatInput::SetNoiseType(uint64_t value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nNoiseType", false, value);
}
uint64_t GCParticleFloatInput::GetNoiseModifier() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CParticleFloatInput", "m_nNoiseModifier");
}
void GCParticleFloatInput::SetNoiseModifier(uint64_t value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nNoiseModifier", false, value);
}
float GCParticleFloatInput::GetNoiseTurbulenceScale() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNoiseTurbulenceScale");
}
void GCParticleFloatInput::SetNoiseTurbulenceScale(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNoiseTurbulenceScale", false, value);
}
float GCParticleFloatInput::GetNoiseTurbulenceMix() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNoiseTurbulenceMix");
}
void GCParticleFloatInput::SetNoiseTurbulenceMix(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNoiseTurbulenceMix", false, value);
}
float GCParticleFloatInput::GetNoiseImgPreviewScale() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNoiseImgPreviewScale");
}
void GCParticleFloatInput::SetNoiseImgPreviewScale(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNoiseImgPreviewScale", false, value);
}
bool GCParticleFloatInput::GetNoiseImgPreviewLive() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleFloatInput", "m_bNoiseImgPreviewLive");
}
void GCParticleFloatInput::SetNoiseImgPreviewLive(bool value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_bNoiseImgPreviewLive", false, value);
}
float GCParticleFloatInput::GetNoCameraFallback() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNoCameraFallback");
}
void GCParticleFloatInput::SetNoCameraFallback(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNoCameraFallback", false, value);
}
bool GCParticleFloatInput::GetUseBoundsCenter() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleFloatInput", "m_bUseBoundsCenter");
}
void GCParticleFloatInput::SetUseBoundsCenter(bool value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_bUseBoundsCenter", false, value);
}
uint64_t GCParticleFloatInput::GetInputMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CParticleFloatInput", "m_nInputMode");
}
void GCParticleFloatInput::SetInputMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nInputMode", false, value);
}
float GCParticleFloatInput::GetMultFactor() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flMultFactor");
}
void GCParticleFloatInput::SetMultFactor(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flMultFactor", false, value);
}
float GCParticleFloatInput::GetInput0() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flInput0");
}
void GCParticleFloatInput::SetInput0(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flInput0", false, value);
}
float GCParticleFloatInput::GetInput1() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flInput1");
}
void GCParticleFloatInput::SetInput1(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flInput1", false, value);
}
float GCParticleFloatInput::GetOutput0() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flOutput0");
}
void GCParticleFloatInput::SetOutput0(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flOutput0", false, value);
}
float GCParticleFloatInput::GetOutput1() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flOutput1");
}
void GCParticleFloatInput::SetOutput1(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flOutput1", false, value);
}
float GCParticleFloatInput::GetNotchedRangeMin() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNotchedRangeMin");
}
void GCParticleFloatInput::SetNotchedRangeMin(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNotchedRangeMin", false, value);
}
float GCParticleFloatInput::GetNotchedRangeMax() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNotchedRangeMax");
}
void GCParticleFloatInput::SetNotchedRangeMax(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNotchedRangeMax", false, value);
}
float GCParticleFloatInput::GetNotchedOutputOutside() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNotchedOutputOutside");
}
void GCParticleFloatInput::SetNotchedOutputOutside(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNotchedOutputOutside", false, value);
}
float GCParticleFloatInput::GetNotchedOutputInside() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flNotchedOutputInside");
}
void GCParticleFloatInput::SetNotchedOutputInside(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flNotchedOutputInside", false, value);
}
uint64_t GCParticleFloatInput::GetBiasType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CParticleFloatInput", "m_nBiasType");
}
void GCParticleFloatInput::SetBiasType(uint64_t value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_nBiasType", false, value);
}
float GCParticleFloatInput::GetBiasParameter() const {
    return GetSchemaValue<float>(m_ptr, "CParticleFloatInput", "m_flBiasParameter");
}
void GCParticleFloatInput::SetBiasParameter(float value) {
    SetSchemaValue(m_ptr, "CParticleFloatInput", "m_flBiasParameter", false, value);
}
std::string GCParticleFloatInput::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleFloatInput::IsValid() {
    return (m_ptr != nullptr);
}
GCParticleInput GCParticleFloatInput::GetParent() const {
    GCParticleInput value(m_ptr);
    return value;
}
void GCParticleFloatInput::SetParent(GCParticleInput value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCParticleFloatInput(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleFloatInput>("CParticleFloatInput")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Type", &GCParticleFloatInput::GetType, &GCParticleFloatInput::SetType)
        .addProperty("MapType", &GCParticleFloatInput::GetMapType, &GCParticleFloatInput::SetMapType)
        .addProperty("LiteralValue", &GCParticleFloatInput::GetLiteralValue, &GCParticleFloatInput::SetLiteralValue)
        .addProperty("ControlPoint", &GCParticleFloatInput::GetControlPoint, &GCParticleFloatInput::SetControlPoint)
        .addProperty("ScalarAttribute", &GCParticleFloatInput::GetScalarAttribute, &GCParticleFloatInput::SetScalarAttribute)
        .addProperty("VectorAttribute", &GCParticleFloatInput::GetVectorAttribute, &GCParticleFloatInput::SetVectorAttribute)
        .addProperty("VectorComponent", &GCParticleFloatInput::GetVectorComponent, &GCParticleFloatInput::SetVectorComponent)
        .addProperty("RandomMin", &GCParticleFloatInput::GetRandomMin, &GCParticleFloatInput::SetRandomMin)
        .addProperty("RandomMax", &GCParticleFloatInput::GetRandomMax, &GCParticleFloatInput::SetRandomMax)
        .addProperty("HasRandomSignFlip", &GCParticleFloatInput::GetHasRandomSignFlip, &GCParticleFloatInput::SetHasRandomSignFlip)
        .addProperty("RandomSeed", &GCParticleFloatInput::GetRandomSeed, &GCParticleFloatInput::SetRandomSeed)
        .addProperty("RandomMode", &GCParticleFloatInput::GetRandomMode, &GCParticleFloatInput::SetRandomMode)
        .addProperty("LOD0", &GCParticleFloatInput::GetLOD0, &GCParticleFloatInput::SetLOD0)
        .addProperty("LOD1", &GCParticleFloatInput::GetLOD1, &GCParticleFloatInput::SetLOD1)
        .addProperty("LOD2", &GCParticleFloatInput::GetLOD2, &GCParticleFloatInput::SetLOD2)
        .addProperty("LOD3", &GCParticleFloatInput::GetLOD3, &GCParticleFloatInput::SetLOD3)
        .addProperty("NoiseInputVectorAttribute", &GCParticleFloatInput::GetNoiseInputVectorAttribute, &GCParticleFloatInput::SetNoiseInputVectorAttribute)
        .addProperty("NoiseOutputMin", &GCParticleFloatInput::GetNoiseOutputMin, &GCParticleFloatInput::SetNoiseOutputMin)
        .addProperty("NoiseOutputMax", &GCParticleFloatInput::GetNoiseOutputMax, &GCParticleFloatInput::SetNoiseOutputMax)
        .addProperty("NoiseScale", &GCParticleFloatInput::GetNoiseScale, &GCParticleFloatInput::SetNoiseScale)
        .addProperty("NoiseOffsetRate", &GCParticleFloatInput::GetNoiseOffsetRate, &GCParticleFloatInput::SetNoiseOffsetRate)
        .addProperty("NoiseOffset", &GCParticleFloatInput::GetNoiseOffset, &GCParticleFloatInput::SetNoiseOffset)
        .addProperty("NoiseOctaves", &GCParticleFloatInput::GetNoiseOctaves, &GCParticleFloatInput::SetNoiseOctaves)
        .addProperty("NoiseTurbulence", &GCParticleFloatInput::GetNoiseTurbulence, &GCParticleFloatInput::SetNoiseTurbulence)
        .addProperty("NoiseType", &GCParticleFloatInput::GetNoiseType, &GCParticleFloatInput::SetNoiseType)
        .addProperty("NoiseModifier", &GCParticleFloatInput::GetNoiseModifier, &GCParticleFloatInput::SetNoiseModifier)
        .addProperty("NoiseTurbulenceScale", &GCParticleFloatInput::GetNoiseTurbulenceScale, &GCParticleFloatInput::SetNoiseTurbulenceScale)
        .addProperty("NoiseTurbulenceMix", &GCParticleFloatInput::GetNoiseTurbulenceMix, &GCParticleFloatInput::SetNoiseTurbulenceMix)
        .addProperty("NoiseImgPreviewScale", &GCParticleFloatInput::GetNoiseImgPreviewScale, &GCParticleFloatInput::SetNoiseImgPreviewScale)
        .addProperty("NoiseImgPreviewLive", &GCParticleFloatInput::GetNoiseImgPreviewLive, &GCParticleFloatInput::SetNoiseImgPreviewLive)
        .addProperty("NoCameraFallback", &GCParticleFloatInput::GetNoCameraFallback, &GCParticleFloatInput::SetNoCameraFallback)
        .addProperty("UseBoundsCenter", &GCParticleFloatInput::GetUseBoundsCenter, &GCParticleFloatInput::SetUseBoundsCenter)
        .addProperty("InputMode", &GCParticleFloatInput::GetInputMode, &GCParticleFloatInput::SetInputMode)
        .addProperty("MultFactor", &GCParticleFloatInput::GetMultFactor, &GCParticleFloatInput::SetMultFactor)
        .addProperty("Input0", &GCParticleFloatInput::GetInput0, &GCParticleFloatInput::SetInput0)
        .addProperty("Input1", &GCParticleFloatInput::GetInput1, &GCParticleFloatInput::SetInput1)
        .addProperty("Output0", &GCParticleFloatInput::GetOutput0, &GCParticleFloatInput::SetOutput0)
        .addProperty("Output1", &GCParticleFloatInput::GetOutput1, &GCParticleFloatInput::SetOutput1)
        .addProperty("NotchedRangeMin", &GCParticleFloatInput::GetNotchedRangeMin, &GCParticleFloatInput::SetNotchedRangeMin)
        .addProperty("NotchedRangeMax", &GCParticleFloatInput::GetNotchedRangeMax, &GCParticleFloatInput::SetNotchedRangeMax)
        .addProperty("NotchedOutputOutside", &GCParticleFloatInput::GetNotchedOutputOutside, &GCParticleFloatInput::SetNotchedOutputOutside)
        .addProperty("NotchedOutputInside", &GCParticleFloatInput::GetNotchedOutputInside, &GCParticleFloatInput::SetNotchedOutputInside)
        .addProperty("BiasType", &GCParticleFloatInput::GetBiasType, &GCParticleFloatInput::SetBiasType)
        .addProperty("BiasParameter", &GCParticleFloatInput::GetBiasParameter, &GCParticleFloatInput::SetBiasParameter)
        .addProperty("Parent", &GCParticleFloatInput::GetParent, &GCParticleFloatInput::SetParent)
        .addFunction("ToPtr", &GCParticleFloatInput::ToPtr)
        .addFunction("IsValid", &GCParticleFloatInput::IsValid)
        .endClass();
}