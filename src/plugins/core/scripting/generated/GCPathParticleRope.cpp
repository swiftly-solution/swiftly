#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPathParticleRope::GCPathParticleRope(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPathParticleRope::GCPathParticleRope(void *ptr) {
    m_ptr = ptr;
}
bool GCPathParticleRope::GetStartActive() const {
    return GetSchemaValue<bool>(m_ptr, "CPathParticleRope", "m_bStartActive");
}
void GCPathParticleRope::SetStartActive(bool value) {
    SetSchemaValue(m_ptr, "CPathParticleRope", "m_bStartActive", false, value);
}
float GCPathParticleRope::GetMaxSimulationTime() const {
    return GetSchemaValue<float>(m_ptr, "CPathParticleRope", "m_flMaxSimulationTime");
}
void GCPathParticleRope::SetMaxSimulationTime(float value) {
    SetSchemaValue(m_ptr, "CPathParticleRope", "m_flMaxSimulationTime", false, value);
}
std::string GCPathParticleRope::GetEffectName() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CPathParticleRope", "m_iszEffectName").String();
}
void GCPathParticleRope::SetEffectName(std::string value) {
    SetSchemaValue(m_ptr, "CPathParticleRope", "m_iszEffectName", false, CUtlSymbolLarge(value.c_str()));
}
std::vector<CUtlSymbolLarge> GCPathParticleRope::GetPathNodes_Name() const {
    CUtlVector<CUtlSymbolLarge>* vec = GetSchemaValue<CUtlVector<CUtlSymbolLarge>*>(m_ptr, "CPathParticleRope", "m_PathNodes_Name"); std::vector<CUtlSymbolLarge> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCPathParticleRope::SetPathNodes_Name(std::vector<CUtlSymbolLarge> value) {
    SetSchemaValueCUtlVector<CUtlSymbolLarge>(m_ptr, "CPathParticleRope", "m_PathNodes_Name", false, value);
}
float GCPathParticleRope::GetParticleSpacing() const {
    return GetSchemaValue<float>(m_ptr, "CPathParticleRope", "m_flParticleSpacing");
}
void GCPathParticleRope::SetParticleSpacing(float value) {
    SetSchemaValue(m_ptr, "CPathParticleRope", "m_flParticleSpacing", false, value);
}
float GCPathParticleRope::GetSlack() const {
    return GetSchemaValue<float>(m_ptr, "CPathParticleRope", "m_flSlack");
}
void GCPathParticleRope::SetSlack(float value) {
    SetSchemaValue(m_ptr, "CPathParticleRope", "m_flSlack", false, value);
}
float GCPathParticleRope::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "CPathParticleRope", "m_flRadius");
}
void GCPathParticleRope::SetRadius(float value) {
    SetSchemaValue(m_ptr, "CPathParticleRope", "m_flRadius", false, value);
}
Color GCPathParticleRope::GetColorTint() const {
    return GetSchemaValue<Color>(m_ptr, "CPathParticleRope", "m_ColorTint");
}
void GCPathParticleRope::SetColorTint(Color value) {
    SetSchemaValue(m_ptr, "CPathParticleRope", "m_ColorTint", false, value);
}
int32_t GCPathParticleRope::GetEffectState() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPathParticleRope", "m_nEffectState");
}
void GCPathParticleRope::SetEffectState(int32_t value) {
    SetSchemaValue(m_ptr, "CPathParticleRope", "m_nEffectState", false, value);
}
std::vector<Vector> GCPathParticleRope::GetPathNodes_Position() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CPathParticleRope", "m_PathNodes_Position"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCPathParticleRope::SetPathNodes_Position(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "CPathParticleRope", "m_PathNodes_Position", false, value);
}
std::vector<Vector> GCPathParticleRope::GetPathNodes_TangentIn() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CPathParticleRope", "m_PathNodes_TangentIn"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCPathParticleRope::SetPathNodes_TangentIn(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "CPathParticleRope", "m_PathNodes_TangentIn", false, value);
}
std::vector<Vector> GCPathParticleRope::GetPathNodes_TangentOut() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CPathParticleRope", "m_PathNodes_TangentOut"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCPathParticleRope::SetPathNodes_TangentOut(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "CPathParticleRope", "m_PathNodes_TangentOut", false, value);
}
std::vector<Vector> GCPathParticleRope::GetPathNodes_Color() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "CPathParticleRope", "m_PathNodes_Color"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCPathParticleRope::SetPathNodes_Color(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "CPathParticleRope", "m_PathNodes_Color", false, value);
}
std::vector<bool> GCPathParticleRope::GetPathNodes_PinEnabled() const {
    CUtlVector<bool>* vec = GetSchemaValue<CUtlVector<bool>*>(m_ptr, "CPathParticleRope", "m_PathNodes_PinEnabled"); std::vector<bool> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCPathParticleRope::SetPathNodes_PinEnabled(std::vector<bool> value) {
    SetSchemaValueCUtlVector<bool>(m_ptr, "CPathParticleRope", "m_PathNodes_PinEnabled", false, value);
}
std::vector<float32> GCPathParticleRope::GetPathNodes_RadiusScale() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CPathParticleRope", "m_PathNodes_RadiusScale"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCPathParticleRope::SetPathNodes_RadiusScale(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CPathParticleRope", "m_PathNodes_RadiusScale", false, value);
}
std::string GCPathParticleRope::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPathParticleRope::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCPathParticleRope::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCPathParticleRope::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPathParticleRope(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathParticleRope>("CPathParticleRope")
        .addConstructor<void (*)(std::string)>()
        .addProperty("StartActive", &GCPathParticleRope::GetStartActive, &GCPathParticleRope::SetStartActive)
        .addProperty("MaxSimulationTime", &GCPathParticleRope::GetMaxSimulationTime, &GCPathParticleRope::SetMaxSimulationTime)
        .addProperty("EffectName", &GCPathParticleRope::GetEffectName, &GCPathParticleRope::SetEffectName)
        .addProperty("PathNodes_Name", &GCPathParticleRope::GetPathNodes_Name, &GCPathParticleRope::SetPathNodes_Name)
        .addProperty("ParticleSpacing", &GCPathParticleRope::GetParticleSpacing, &GCPathParticleRope::SetParticleSpacing)
        .addProperty("Slack", &GCPathParticleRope::GetSlack, &GCPathParticleRope::SetSlack)
        .addProperty("Radius", &GCPathParticleRope::GetRadius, &GCPathParticleRope::SetRadius)
        .addProperty("ColorTint", &GCPathParticleRope::GetColorTint, &GCPathParticleRope::SetColorTint)
        .addProperty("EffectState", &GCPathParticleRope::GetEffectState, &GCPathParticleRope::SetEffectState)
        .addProperty("PathNodes_Position", &GCPathParticleRope::GetPathNodes_Position, &GCPathParticleRope::SetPathNodes_Position)
        .addProperty("PathNodes_TangentIn", &GCPathParticleRope::GetPathNodes_TangentIn, &GCPathParticleRope::SetPathNodes_TangentIn)
        .addProperty("PathNodes_TangentOut", &GCPathParticleRope::GetPathNodes_TangentOut, &GCPathParticleRope::SetPathNodes_TangentOut)
        .addProperty("PathNodes_Color", &GCPathParticleRope::GetPathNodes_Color, &GCPathParticleRope::SetPathNodes_Color)
        .addProperty("PathNodes_PinEnabled", &GCPathParticleRope::GetPathNodes_PinEnabled, &GCPathParticleRope::SetPathNodes_PinEnabled)
        .addProperty("PathNodes_RadiusScale", &GCPathParticleRope::GetPathNodes_RadiusScale, &GCPathParticleRope::SetPathNodes_RadiusScale)
        .addProperty("Parent", &GCPathParticleRope::GetParent, &GCPathParticleRope::SetParent)
        .addFunction("ToPtr", &GCPathParticleRope::ToPtr)
        .addFunction("IsValid", &GCPathParticleRope::IsValid)
        .endClass();
}