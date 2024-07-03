#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCDynamicProp::GCDynamicProp(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCDynamicProp::GCDynamicProp(void *ptr) {
    m_ptr = ptr;
}
bool GCDynamicProp::GetCreateNavObstacle() const {
    return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bCreateNavObstacle");
}
void GCDynamicProp::SetCreateNavObstacle(bool value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_bCreateNavObstacle", false, value);
}
bool GCDynamicProp::GetUseHitboxesForRenderBox() const {
    return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bUseHitboxesForRenderBox");
}
void GCDynamicProp::SetUseHitboxesForRenderBox(bool value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_bUseHitboxesForRenderBox", false, value);
}
bool GCDynamicProp::GetUseAnimGraph() const {
    return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bUseAnimGraph");
}
void GCDynamicProp::SetUseAnimGraph(bool value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_bUseAnimGraph", false, value);
}
GCEntityIOOutput GCDynamicProp::GetOutputAnimBegun() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CDynamicProp", "m_pOutputAnimBegun"));
    return value;
}
void GCDynamicProp::SetOutputAnimBegun(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_pOutputAnimBegun", false, value);
}
GCEntityIOOutput GCDynamicProp::GetOutputAnimOver() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CDynamicProp", "m_pOutputAnimOver"));
    return value;
}
void GCDynamicProp::SetOutputAnimOver(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_pOutputAnimOver", false, value);
}
GCEntityIOOutput GCDynamicProp::GetOutputAnimLoopCycleOver() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CDynamicProp", "m_pOutputAnimLoopCycleOver"));
    return value;
}
void GCDynamicProp::SetOutputAnimLoopCycleOver(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_pOutputAnimLoopCycleOver", false, value);
}
GCEntityIOOutput GCDynamicProp::GetOnAnimReachedStart() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CDynamicProp", "m_OnAnimReachedStart"));
    return value;
}
void GCDynamicProp::SetOnAnimReachedStart(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_OnAnimReachedStart", false, value);
}
GCEntityIOOutput GCDynamicProp::GetOnAnimReachedEnd() const {
    GCEntityIOOutput value(GetSchemaPtr(m_ptr, "CDynamicProp", "m_OnAnimReachedEnd"));
    return value;
}
void GCDynamicProp::SetOnAnimReachedEnd(GCEntityIOOutput value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_OnAnimReachedEnd", false, value);
}
std::string GCDynamicProp::GetIdleAnim() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CDynamicProp", "m_iszIdleAnim").String();
}
void GCDynamicProp::SetIdleAnim(std::string value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_iszIdleAnim", false, CUtlSymbolLarge(value.c_str()));
}
uint64_t GCDynamicProp::GetIdleAnimLoopMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CDynamicProp", "m_nIdleAnimLoopMode");
}
void GCDynamicProp::SetIdleAnimLoopMode(uint64_t value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_nIdleAnimLoopMode", false, value);
}
bool GCDynamicProp::GetRandomizeCycle() const {
    return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bRandomizeCycle");
}
void GCDynamicProp::SetRandomizeCycle(bool value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_bRandomizeCycle", false, value);
}
bool GCDynamicProp::GetStartDisabled() const {
    return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bStartDisabled");
}
void GCDynamicProp::SetStartDisabled(bool value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_bStartDisabled", false, value);
}
bool GCDynamicProp::GetFiredStartEndOutput() const {
    return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bFiredStartEndOutput");
}
void GCDynamicProp::SetFiredStartEndOutput(bool value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_bFiredStartEndOutput", false, value);
}
bool GCDynamicProp::GetForceNpcExclude() const {
    return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bForceNpcExclude");
}
void GCDynamicProp::SetForceNpcExclude(bool value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_bForceNpcExclude", false, value);
}
bool GCDynamicProp::GetCreateNonSolid() const {
    return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bCreateNonSolid");
}
void GCDynamicProp::SetCreateNonSolid(bool value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_bCreateNonSolid", false, value);
}
bool GCDynamicProp::GetIsOverrideProp() const {
    return GetSchemaValue<bool>(m_ptr, "CDynamicProp", "m_bIsOverrideProp");
}
void GCDynamicProp::SetIsOverrideProp(bool value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_bIsOverrideProp", false, value);
}
int32_t GCDynamicProp::GetInitialGlowState() const {
    return GetSchemaValue<int32_t>(m_ptr, "CDynamicProp", "m_iInitialGlowState");
}
void GCDynamicProp::SetInitialGlowState(int32_t value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_iInitialGlowState", false, value);
}
int32_t GCDynamicProp::GetGlowRange() const {
    return GetSchemaValue<int32_t>(m_ptr, "CDynamicProp", "m_nGlowRange");
}
void GCDynamicProp::SetGlowRange(int32_t value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_nGlowRange", false, value);
}
int32_t GCDynamicProp::GetGlowRangeMin() const {
    return GetSchemaValue<int32_t>(m_ptr, "CDynamicProp", "m_nGlowRangeMin");
}
void GCDynamicProp::SetGlowRangeMin(int32_t value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_nGlowRangeMin", false, value);
}
Color GCDynamicProp::GetGlowColor() const {
    return GetSchemaValue<Color>(m_ptr, "CDynamicProp", "m_glowColor");
}
void GCDynamicProp::SetGlowColor(Color value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_glowColor", false, value);
}
int32_t GCDynamicProp::GetGlowTeam() const {
    return GetSchemaValue<int32_t>(m_ptr, "CDynamicProp", "m_nGlowTeam");
}
void GCDynamicProp::SetGlowTeam(int32_t value) {
    SetSchemaValue(m_ptr, "CDynamicProp", "m_nGlowTeam", false, value);
}
std::string GCDynamicProp::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCDynamicProp::IsValid() {
    return (m_ptr != nullptr);
}
GCBreakableProp GCDynamicProp::GetParent() const {
    GCBreakableProp value(m_ptr);
    return value;
}
void GCDynamicProp::SetParent(GCBreakableProp value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCDynamicProp(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDynamicProp>("CDynamicProp")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CreateNavObstacle", &GCDynamicProp::GetCreateNavObstacle, &GCDynamicProp::SetCreateNavObstacle)
        .addProperty("UseHitboxesForRenderBox", &GCDynamicProp::GetUseHitboxesForRenderBox, &GCDynamicProp::SetUseHitboxesForRenderBox)
        .addProperty("UseAnimGraph", &GCDynamicProp::GetUseAnimGraph, &GCDynamicProp::SetUseAnimGraph)
        .addProperty("OutputAnimBegun", &GCDynamicProp::GetOutputAnimBegun, &GCDynamicProp::SetOutputAnimBegun)
        .addProperty("OutputAnimOver", &GCDynamicProp::GetOutputAnimOver, &GCDynamicProp::SetOutputAnimOver)
        .addProperty("OutputAnimLoopCycleOver", &GCDynamicProp::GetOutputAnimLoopCycleOver, &GCDynamicProp::SetOutputAnimLoopCycleOver)
        .addProperty("OnAnimReachedStart", &GCDynamicProp::GetOnAnimReachedStart, &GCDynamicProp::SetOnAnimReachedStart)
        .addProperty("OnAnimReachedEnd", &GCDynamicProp::GetOnAnimReachedEnd, &GCDynamicProp::SetOnAnimReachedEnd)
        .addProperty("IdleAnim", &GCDynamicProp::GetIdleAnim, &GCDynamicProp::SetIdleAnim)
        .addProperty("IdleAnimLoopMode", &GCDynamicProp::GetIdleAnimLoopMode, &GCDynamicProp::SetIdleAnimLoopMode)
        .addProperty("RandomizeCycle", &GCDynamicProp::GetRandomizeCycle, &GCDynamicProp::SetRandomizeCycle)
        .addProperty("StartDisabled", &GCDynamicProp::GetStartDisabled, &GCDynamicProp::SetStartDisabled)
        .addProperty("FiredStartEndOutput", &GCDynamicProp::GetFiredStartEndOutput, &GCDynamicProp::SetFiredStartEndOutput)
        .addProperty("ForceNpcExclude", &GCDynamicProp::GetForceNpcExclude, &GCDynamicProp::SetForceNpcExclude)
        .addProperty("CreateNonSolid", &GCDynamicProp::GetCreateNonSolid, &GCDynamicProp::SetCreateNonSolid)
        .addProperty("IsOverrideProp", &GCDynamicProp::GetIsOverrideProp, &GCDynamicProp::SetIsOverrideProp)
        .addProperty("InitialGlowState", &GCDynamicProp::GetInitialGlowState, &GCDynamicProp::SetInitialGlowState)
        .addProperty("GlowRange", &GCDynamicProp::GetGlowRange, &GCDynamicProp::SetGlowRange)
        .addProperty("GlowRangeMin", &GCDynamicProp::GetGlowRangeMin, &GCDynamicProp::SetGlowRangeMin)
        .addProperty("GlowColor", &GCDynamicProp::GetGlowColor, &GCDynamicProp::SetGlowColor)
        .addProperty("GlowTeam", &GCDynamicProp::GetGlowTeam, &GCDynamicProp::SetGlowTeam)
        .addProperty("Parent", &GCDynamicProp::GetParent, &GCDynamicProp::SetParent)
        .addFunction("ToPtr", &GCDynamicProp::ToPtr)
        .addFunction("IsValid", &GCDynamicProp::IsValid)
        .endClass();
}