#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCMotionMatchingUpdateNode::GCMotionMatchingUpdateNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCMotionMatchingUpdateNode::GCMotionMatchingUpdateNode(void *ptr) {
    m_ptr = ptr;
}
GCMotionDataSet GCMotionMatchingUpdateNode::GetDataSet() const {
    GCMotionDataSet value(GetSchemaPtr(m_ptr, "CMotionMatchingUpdateNode", "m_dataSet"));
    return value;
}
void GCMotionMatchingUpdateNode::SetDataSet(GCMotionDataSet value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_dataSet", false, value);
}
std::vector<float32> GCMotionMatchingUpdateNode::GetWeights() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "CMotionMatchingUpdateNode", "m_weights"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCMotionMatchingUpdateNode::SetWeights(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "CMotionMatchingUpdateNode", "m_weights", false, value);
}
bool GCMotionMatchingUpdateNode::GetSearchEveryTick() const {
    return GetSchemaValue<bool>(m_ptr, "CMotionMatchingUpdateNode", "m_bSearchEveryTick");
}
void GCMotionMatchingUpdateNode::SetSearchEveryTick(bool value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_bSearchEveryTick", false, value);
}
float GCMotionMatchingUpdateNode::GetSearchInterval() const {
    return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flSearchInterval");
}
void GCMotionMatchingUpdateNode::SetSearchInterval(float value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flSearchInterval", false, value);
}
bool GCMotionMatchingUpdateNode::GetSearchWhenClipEnds() const {
    return GetSchemaValue<bool>(m_ptr, "CMotionMatchingUpdateNode", "m_bSearchWhenClipEnds");
}
void GCMotionMatchingUpdateNode::SetSearchWhenClipEnds(bool value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_bSearchWhenClipEnds", false, value);
}
bool GCMotionMatchingUpdateNode::GetSearchWhenGoalChanges() const {
    return GetSchemaValue<bool>(m_ptr, "CMotionMatchingUpdateNode", "m_bSearchWhenGoalChanges");
}
void GCMotionMatchingUpdateNode::SetSearchWhenGoalChanges(bool value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_bSearchWhenGoalChanges", false, value);
}
GCBlendCurve GCMotionMatchingUpdateNode::GetBlendCurve() const {
    GCBlendCurve value(GetSchemaPtr(m_ptr, "CMotionMatchingUpdateNode", "m_blendCurve"));
    return value;
}
void GCMotionMatchingUpdateNode::SetBlendCurve(GCBlendCurve value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_blendCurve", false, value);
}
float GCMotionMatchingUpdateNode::GetSampleRate() const {
    return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flSampleRate");
}
void GCMotionMatchingUpdateNode::SetSampleRate(float value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flSampleRate", false, value);
}
float GCMotionMatchingUpdateNode::GetBlendTime() const {
    return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flBlendTime");
}
void GCMotionMatchingUpdateNode::SetBlendTime(float value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flBlendTime", false, value);
}
bool GCMotionMatchingUpdateNode::GetLockClipWhenWaning() const {
    return GetSchemaValue<bool>(m_ptr, "CMotionMatchingUpdateNode", "m_bLockClipWhenWaning");
}
void GCMotionMatchingUpdateNode::SetLockClipWhenWaning(bool value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_bLockClipWhenWaning", false, value);
}
float GCMotionMatchingUpdateNode::GetSelectionThreshold() const {
    return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flSelectionThreshold");
}
void GCMotionMatchingUpdateNode::SetSelectionThreshold(float value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flSelectionThreshold", false, value);
}
float GCMotionMatchingUpdateNode::GetReselectionTimeWindow() const {
    return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flReselectionTimeWindow");
}
void GCMotionMatchingUpdateNode::SetReselectionTimeWindow(float value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flReselectionTimeWindow", false, value);
}
bool GCMotionMatchingUpdateNode::GetEnableRotationCorrection() const {
    return GetSchemaValue<bool>(m_ptr, "CMotionMatchingUpdateNode", "m_bEnableRotationCorrection");
}
void GCMotionMatchingUpdateNode::SetEnableRotationCorrection(bool value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_bEnableRotationCorrection", false, value);
}
bool GCMotionMatchingUpdateNode::GetGoalAssist() const {
    return GetSchemaValue<bool>(m_ptr, "CMotionMatchingUpdateNode", "m_bGoalAssist");
}
void GCMotionMatchingUpdateNode::SetGoalAssist(bool value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_bGoalAssist", false, value);
}
float GCMotionMatchingUpdateNode::GetGoalAssistDistance() const {
    return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flGoalAssistDistance");
}
void GCMotionMatchingUpdateNode::SetGoalAssistDistance(float value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flGoalAssistDistance", false, value);
}
float GCMotionMatchingUpdateNode::GetGoalAssistTolerance() const {
    return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flGoalAssistTolerance");
}
void GCMotionMatchingUpdateNode::SetGoalAssistTolerance(float value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flGoalAssistTolerance", false, value);
}
GCAnimInputDamping GCMotionMatchingUpdateNode::GetDistanceScale_Damping() const {
    GCAnimInputDamping value(GetSchemaPtr(m_ptr, "CMotionMatchingUpdateNode", "m_distanceScale_Damping"));
    return value;
}
void GCMotionMatchingUpdateNode::SetDistanceScale_Damping(GCAnimInputDamping value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_distanceScale_Damping", false, value);
}
float GCMotionMatchingUpdateNode::GetDistanceScale_OuterRadius() const {
    return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flDistanceScale_OuterRadius");
}
void GCMotionMatchingUpdateNode::SetDistanceScale_OuterRadius(float value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flDistanceScale_OuterRadius", false, value);
}
float GCMotionMatchingUpdateNode::GetDistanceScale_InnerRadius() const {
    return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flDistanceScale_InnerRadius");
}
void GCMotionMatchingUpdateNode::SetDistanceScale_InnerRadius(float value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flDistanceScale_InnerRadius", false, value);
}
float GCMotionMatchingUpdateNode::GetDistanceScale_MaxScale() const {
    return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flDistanceScale_MaxScale");
}
void GCMotionMatchingUpdateNode::SetDistanceScale_MaxScale(float value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flDistanceScale_MaxScale", false, value);
}
float GCMotionMatchingUpdateNode::GetDistanceScale_MinScale() const {
    return GetSchemaValue<float>(m_ptr, "CMotionMatchingUpdateNode", "m_flDistanceScale_MinScale");
}
void GCMotionMatchingUpdateNode::SetDistanceScale_MinScale(float value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_flDistanceScale_MinScale", false, value);
}
bool GCMotionMatchingUpdateNode::GetEnableDistanceScaling() const {
    return GetSchemaValue<bool>(m_ptr, "CMotionMatchingUpdateNode", "m_bEnableDistanceScaling");
}
void GCMotionMatchingUpdateNode::SetEnableDistanceScaling(bool value) {
    SetSchemaValue(m_ptr, "CMotionMatchingUpdateNode", "m_bEnableDistanceScaling", false, value);
}
std::string GCMotionMatchingUpdateNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCMotionMatchingUpdateNode::IsValid() {
    return (m_ptr != nullptr);
}
GCLeafUpdateNode GCMotionMatchingUpdateNode::GetParent() const {
    GCLeafUpdateNode value(m_ptr);
    return value;
}
void GCMotionMatchingUpdateNode::SetParent(GCLeafUpdateNode value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCMotionMatchingUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMotionMatchingUpdateNode>("CMotionMatchingUpdateNode")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DataSet", &GCMotionMatchingUpdateNode::GetDataSet, &GCMotionMatchingUpdateNode::SetDataSet)
        .addProperty("Weights", &GCMotionMatchingUpdateNode::GetWeights, &GCMotionMatchingUpdateNode::SetWeights)
        .addProperty("SearchEveryTick", &GCMotionMatchingUpdateNode::GetSearchEveryTick, &GCMotionMatchingUpdateNode::SetSearchEveryTick)
        .addProperty("SearchInterval", &GCMotionMatchingUpdateNode::GetSearchInterval, &GCMotionMatchingUpdateNode::SetSearchInterval)
        .addProperty("SearchWhenClipEnds", &GCMotionMatchingUpdateNode::GetSearchWhenClipEnds, &GCMotionMatchingUpdateNode::SetSearchWhenClipEnds)
        .addProperty("SearchWhenGoalChanges", &GCMotionMatchingUpdateNode::GetSearchWhenGoalChanges, &GCMotionMatchingUpdateNode::SetSearchWhenGoalChanges)
        .addProperty("BlendCurve", &GCMotionMatchingUpdateNode::GetBlendCurve, &GCMotionMatchingUpdateNode::SetBlendCurve)
        .addProperty("SampleRate", &GCMotionMatchingUpdateNode::GetSampleRate, &GCMotionMatchingUpdateNode::SetSampleRate)
        .addProperty("BlendTime", &GCMotionMatchingUpdateNode::GetBlendTime, &GCMotionMatchingUpdateNode::SetBlendTime)
        .addProperty("LockClipWhenWaning", &GCMotionMatchingUpdateNode::GetLockClipWhenWaning, &GCMotionMatchingUpdateNode::SetLockClipWhenWaning)
        .addProperty("SelectionThreshold", &GCMotionMatchingUpdateNode::GetSelectionThreshold, &GCMotionMatchingUpdateNode::SetSelectionThreshold)
        .addProperty("ReselectionTimeWindow", &GCMotionMatchingUpdateNode::GetReselectionTimeWindow, &GCMotionMatchingUpdateNode::SetReselectionTimeWindow)
        .addProperty("EnableRotationCorrection", &GCMotionMatchingUpdateNode::GetEnableRotationCorrection, &GCMotionMatchingUpdateNode::SetEnableRotationCorrection)
        .addProperty("GoalAssist", &GCMotionMatchingUpdateNode::GetGoalAssist, &GCMotionMatchingUpdateNode::SetGoalAssist)
        .addProperty("GoalAssistDistance", &GCMotionMatchingUpdateNode::GetGoalAssistDistance, &GCMotionMatchingUpdateNode::SetGoalAssistDistance)
        .addProperty("GoalAssistTolerance", &GCMotionMatchingUpdateNode::GetGoalAssistTolerance, &GCMotionMatchingUpdateNode::SetGoalAssistTolerance)
        .addProperty("DistanceScale_Damping", &GCMotionMatchingUpdateNode::GetDistanceScale_Damping, &GCMotionMatchingUpdateNode::SetDistanceScale_Damping)
        .addProperty("DistanceScale_OuterRadius", &GCMotionMatchingUpdateNode::GetDistanceScale_OuterRadius, &GCMotionMatchingUpdateNode::SetDistanceScale_OuterRadius)
        .addProperty("DistanceScale_InnerRadius", &GCMotionMatchingUpdateNode::GetDistanceScale_InnerRadius, &GCMotionMatchingUpdateNode::SetDistanceScale_InnerRadius)
        .addProperty("DistanceScale_MaxScale", &GCMotionMatchingUpdateNode::GetDistanceScale_MaxScale, &GCMotionMatchingUpdateNode::SetDistanceScale_MaxScale)
        .addProperty("DistanceScale_MinScale", &GCMotionMatchingUpdateNode::GetDistanceScale_MinScale, &GCMotionMatchingUpdateNode::SetDistanceScale_MinScale)
        .addProperty("EnableDistanceScaling", &GCMotionMatchingUpdateNode::GetEnableDistanceScaling, &GCMotionMatchingUpdateNode::SetEnableDistanceScaling)
        .addProperty("Parent", &GCMotionMatchingUpdateNode::GetParent, &GCMotionMatchingUpdateNode::SetParent)
        .addFunction("ToPtr", &GCMotionMatchingUpdateNode::ToPtr)
        .addFunction("IsValid", &GCMotionMatchingUpdateNode::IsValid)
        .endClass();
}