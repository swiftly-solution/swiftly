#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCParticleSystemDefinition::GCParticleSystemDefinition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCParticleSystemDefinition::GCParticleSystemDefinition(void *ptr) {
    m_ptr = ptr;
}
int32_t GCParticleSystemDefinition::GetBehaviorVersion() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nBehaviorVersion");
}
void GCParticleSystemDefinition::SetBehaviorVersion(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nBehaviorVersion", false, value);
}
std::vector<GCParticleFunctionPreEmission*> GCParticleSystemDefinition::GetPreEmissionOperators() const {
    CUtlVector<GCParticleFunctionPreEmission*>* vec = GetSchemaValue<CUtlVector<GCParticleFunctionPreEmission*>*>(m_ptr, "CParticleSystemDefinition", "m_PreEmissionOperators"); std::vector<GCParticleFunctionPreEmission*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCParticleSystemDefinition::SetPreEmissionOperators(std::vector<GCParticleFunctionPreEmission*> value) {
    SetSchemaValueCUtlVector<GCParticleFunctionPreEmission*>(m_ptr, "CParticleSystemDefinition", "m_PreEmissionOperators", false, value);
}
std::vector<GCParticleFunctionEmitter*> GCParticleSystemDefinition::GetEmitters() const {
    CUtlVector<GCParticleFunctionEmitter*>* vec = GetSchemaValue<CUtlVector<GCParticleFunctionEmitter*>*>(m_ptr, "CParticleSystemDefinition", "m_Emitters"); std::vector<GCParticleFunctionEmitter*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCParticleSystemDefinition::SetEmitters(std::vector<GCParticleFunctionEmitter*> value) {
    SetSchemaValueCUtlVector<GCParticleFunctionEmitter*>(m_ptr, "CParticleSystemDefinition", "m_Emitters", false, value);
}
std::vector<GCParticleFunctionInitializer*> GCParticleSystemDefinition::GetInitializers() const {
    CUtlVector<GCParticleFunctionInitializer*>* vec = GetSchemaValue<CUtlVector<GCParticleFunctionInitializer*>*>(m_ptr, "CParticleSystemDefinition", "m_Initializers"); std::vector<GCParticleFunctionInitializer*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCParticleSystemDefinition::SetInitializers(std::vector<GCParticleFunctionInitializer*> value) {
    SetSchemaValueCUtlVector<GCParticleFunctionInitializer*>(m_ptr, "CParticleSystemDefinition", "m_Initializers", false, value);
}
std::vector<GCParticleFunctionOperator*> GCParticleSystemDefinition::GetOperators() const {
    CUtlVector<GCParticleFunctionOperator*>* vec = GetSchemaValue<CUtlVector<GCParticleFunctionOperator*>*>(m_ptr, "CParticleSystemDefinition", "m_Operators"); std::vector<GCParticleFunctionOperator*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCParticleSystemDefinition::SetOperators(std::vector<GCParticleFunctionOperator*> value) {
    SetSchemaValueCUtlVector<GCParticleFunctionOperator*>(m_ptr, "CParticleSystemDefinition", "m_Operators", false, value);
}
std::vector<GCParticleFunctionForce*> GCParticleSystemDefinition::GetForceGenerators() const {
    CUtlVector<GCParticleFunctionForce*>* vec = GetSchemaValue<CUtlVector<GCParticleFunctionForce*>*>(m_ptr, "CParticleSystemDefinition", "m_ForceGenerators"); std::vector<GCParticleFunctionForce*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCParticleSystemDefinition::SetForceGenerators(std::vector<GCParticleFunctionForce*> value) {
    SetSchemaValueCUtlVector<GCParticleFunctionForce*>(m_ptr, "CParticleSystemDefinition", "m_ForceGenerators", false, value);
}
std::vector<GCParticleFunctionConstraint*> GCParticleSystemDefinition::GetConstraints() const {
    CUtlVector<GCParticleFunctionConstraint*>* vec = GetSchemaValue<CUtlVector<GCParticleFunctionConstraint*>*>(m_ptr, "CParticleSystemDefinition", "m_Constraints"); std::vector<GCParticleFunctionConstraint*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCParticleSystemDefinition::SetConstraints(std::vector<GCParticleFunctionConstraint*> value) {
    SetSchemaValueCUtlVector<GCParticleFunctionConstraint*>(m_ptr, "CParticleSystemDefinition", "m_Constraints", false, value);
}
std::vector<GCParticleFunctionRenderer*> GCParticleSystemDefinition::GetRenderers() const {
    CUtlVector<GCParticleFunctionRenderer*>* vec = GetSchemaValue<CUtlVector<GCParticleFunctionRenderer*>*>(m_ptr, "CParticleSystemDefinition", "m_Renderers"); std::vector<GCParticleFunctionRenderer*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCParticleSystemDefinition::SetRenderers(std::vector<GCParticleFunctionRenderer*> value) {
    SetSchemaValueCUtlVector<GCParticleFunctionRenderer*>(m_ptr, "CParticleSystemDefinition", "m_Renderers", false, value);
}
std::vector<GParticleChildrenInfo_t> GCParticleSystemDefinition::GetChildren() const {
    CUtlVector<GParticleChildrenInfo_t>* vec = GetSchemaValue<CUtlVector<GParticleChildrenInfo_t>*>(m_ptr, "CParticleSystemDefinition", "m_Children"); std::vector<GParticleChildrenInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCParticleSystemDefinition::SetChildren(std::vector<GParticleChildrenInfo_t> value) {
    SetSchemaValueCUtlVector<GParticleChildrenInfo_t>(m_ptr, "CParticleSystemDefinition", "m_Children", false, value);
}
int32_t GCParticleSystemDefinition::GetFirstMultipleOverride_BackwardCompat() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nFirstMultipleOverride_BackwardCompat");
}
void GCParticleSystemDefinition::SetFirstMultipleOverride_BackwardCompat(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nFirstMultipleOverride_BackwardCompat", false, value);
}
int32_t GCParticleSystemDefinition::GetInitialParticles() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nInitialParticles");
}
void GCParticleSystemDefinition::SetInitialParticles(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nInitialParticles", false, value);
}
int32_t GCParticleSystemDefinition::GetMaxParticles() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nMaxParticles");
}
void GCParticleSystemDefinition::SetMaxParticles(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nMaxParticles", false, value);
}
int32_t GCParticleSystemDefinition::GetGroupID() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nGroupID");
}
void GCParticleSystemDefinition::SetGroupID(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nGroupID", false, value);
}
Vector GCParticleSystemDefinition::GetBoundingBoxMin() const {
    return GetSchemaValue<Vector>(m_ptr, "CParticleSystemDefinition", "m_BoundingBoxMin");
}
void GCParticleSystemDefinition::SetBoundingBoxMin(Vector value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_BoundingBoxMin", false, value);
}
Vector GCParticleSystemDefinition::GetBoundingBoxMax() const {
    return GetSchemaValue<Vector>(m_ptr, "CParticleSystemDefinition", "m_BoundingBoxMax");
}
void GCParticleSystemDefinition::SetBoundingBoxMax(Vector value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_BoundingBoxMax", false, value);
}
float GCParticleSystemDefinition::GetDepthSortBias() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flDepthSortBias");
}
void GCParticleSystemDefinition::SetDepthSortBias(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flDepthSortBias", false, value);
}
int32_t GCParticleSystemDefinition::GetSortOverridePositionCP() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nSortOverridePositionCP");
}
void GCParticleSystemDefinition::SetSortOverridePositionCP(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nSortOverridePositionCP", false, value);
}
bool GCParticleSystemDefinition::GetInfiniteBounds() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleSystemDefinition", "m_bInfiniteBounds");
}
void GCParticleSystemDefinition::SetInfiniteBounds(bool value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_bInfiniteBounds", false, value);
}
bool GCParticleSystemDefinition::GetEnableNamedValues() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleSystemDefinition", "m_bEnableNamedValues");
}
void GCParticleSystemDefinition::SetEnableNamedValues(bool value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_bEnableNamedValues", false, value);
}
std::string GCParticleSystemDefinition::GetNamedValueDomain() const {
    return GetSchemaValue<CUtlString>(m_ptr, "CParticleSystemDefinition", "m_NamedValueDomain").Get();
}
void GCParticleSystemDefinition::SetNamedValueDomain(std::string value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_NamedValueDomain", false, CUtlString(value.c_str()));
}
std::vector<GParticleNamedValueSource_t*> GCParticleSystemDefinition::GetNamedValueLocals() const {
    CUtlVector<GParticleNamedValueSource_t*>* vec = GetSchemaValue<CUtlVector<GParticleNamedValueSource_t*>*>(m_ptr, "CParticleSystemDefinition", "m_NamedValueLocals"); std::vector<GParticleNamedValueSource_t*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCParticleSystemDefinition::SetNamedValueLocals(std::vector<GParticleNamedValueSource_t*> value) {
    SetSchemaValueCUtlVector<GParticleNamedValueSource_t*>(m_ptr, "CParticleSystemDefinition", "m_NamedValueLocals", false, value);
}
Color GCParticleSystemDefinition::GetConstantColor() const {
    return GetSchemaValue<Color>(m_ptr, "CParticleSystemDefinition", "m_ConstantColor");
}
void GCParticleSystemDefinition::SetConstantColor(Color value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_ConstantColor", false, value);
}
Vector GCParticleSystemDefinition::GetConstantNormal() const {
    return GetSchemaValue<Vector>(m_ptr, "CParticleSystemDefinition", "m_ConstantNormal");
}
void GCParticleSystemDefinition::SetConstantNormal(Vector value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_ConstantNormal", false, value);
}
float GCParticleSystemDefinition::GetConstantRadius() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flConstantRadius");
}
void GCParticleSystemDefinition::SetConstantRadius(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flConstantRadius", false, value);
}
float GCParticleSystemDefinition::GetConstantRotation() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flConstantRotation");
}
void GCParticleSystemDefinition::SetConstantRotation(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flConstantRotation", false, value);
}
float GCParticleSystemDefinition::GetConstantRotationSpeed() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flConstantRotationSpeed");
}
void GCParticleSystemDefinition::SetConstantRotationSpeed(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flConstantRotationSpeed", false, value);
}
float GCParticleSystemDefinition::GetConstantLifespan() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flConstantLifespan");
}
void GCParticleSystemDefinition::SetConstantLifespan(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flConstantLifespan", false, value);
}
int32_t GCParticleSystemDefinition::GetConstantSequenceNumber() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nConstantSequenceNumber");
}
void GCParticleSystemDefinition::SetConstantSequenceNumber(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nConstantSequenceNumber", false, value);
}
int32_t GCParticleSystemDefinition::GetConstantSequenceNumber1() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nConstantSequenceNumber1");
}
void GCParticleSystemDefinition::SetConstantSequenceNumber1(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nConstantSequenceNumber1", false, value);
}
int32_t GCParticleSystemDefinition::GetSnapshotControlPoint() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nSnapshotControlPoint");
}
void GCParticleSystemDefinition::SetSnapshotControlPoint(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nSnapshotControlPoint", false, value);
}
float GCParticleSystemDefinition::GetCullRadius() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flCullRadius");
}
void GCParticleSystemDefinition::SetCullRadius(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flCullRadius", false, value);
}
float GCParticleSystemDefinition::GetCullFillCost() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flCullFillCost");
}
void GCParticleSystemDefinition::SetCullFillCost(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flCullFillCost", false, value);
}
int32_t GCParticleSystemDefinition::GetCullControlPoint() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nCullControlPoint");
}
void GCParticleSystemDefinition::SetCullControlPoint(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nCullControlPoint", false, value);
}
int32_t GCParticleSystemDefinition::GetFallbackMaxCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nFallbackMaxCount");
}
void GCParticleSystemDefinition::SetFallbackMaxCount(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nFallbackMaxCount", false, value);
}
float GCParticleSystemDefinition::GetPreSimulationTime() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flPreSimulationTime");
}
void GCParticleSystemDefinition::SetPreSimulationTime(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flPreSimulationTime", false, value);
}
float GCParticleSystemDefinition::GetStopSimulationAfterTime() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flStopSimulationAfterTime");
}
void GCParticleSystemDefinition::SetStopSimulationAfterTime(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flStopSimulationAfterTime", false, value);
}
float GCParticleSystemDefinition::GetMaximumTimeStep() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flMaximumTimeStep");
}
void GCParticleSystemDefinition::SetMaximumTimeStep(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flMaximumTimeStep", false, value);
}
float GCParticleSystemDefinition::GetMaximumSimTime() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flMaximumSimTime");
}
void GCParticleSystemDefinition::SetMaximumSimTime(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flMaximumSimTime", false, value);
}
float GCParticleSystemDefinition::GetMinimumSimTime() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flMinimumSimTime");
}
void GCParticleSystemDefinition::SetMinimumSimTime(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flMinimumSimTime", false, value);
}
float GCParticleSystemDefinition::GetMinimumTimeStep() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flMinimumTimeStep");
}
void GCParticleSystemDefinition::SetMinimumTimeStep(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flMinimumTimeStep", false, value);
}
int32_t GCParticleSystemDefinition::GetMinimumFrames() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nMinimumFrames");
}
void GCParticleSystemDefinition::SetMinimumFrames(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nMinimumFrames", false, value);
}
int32_t GCParticleSystemDefinition::GetMinCPULevel() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nMinCPULevel");
}
void GCParticleSystemDefinition::SetMinCPULevel(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nMinCPULevel", false, value);
}
int32_t GCParticleSystemDefinition::GetMinGPULevel() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nMinGPULevel");
}
void GCParticleSystemDefinition::SetMinGPULevel(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nMinGPULevel", false, value);
}
float GCParticleSystemDefinition::GetNoDrawTimeToGoToSleep() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flNoDrawTimeToGoToSleep");
}
void GCParticleSystemDefinition::SetNoDrawTimeToGoToSleep(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flNoDrawTimeToGoToSleep", false, value);
}
float GCParticleSystemDefinition::GetMaxDrawDistance() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flMaxDrawDistance");
}
void GCParticleSystemDefinition::SetMaxDrawDistance(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flMaxDrawDistance", false, value);
}
float GCParticleSystemDefinition::GetStartFadeDistance() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flStartFadeDistance");
}
void GCParticleSystemDefinition::SetStartFadeDistance(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flStartFadeDistance", false, value);
}
float GCParticleSystemDefinition::GetMaxCreationDistance() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flMaxCreationDistance");
}
void GCParticleSystemDefinition::SetMaxCreationDistance(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flMaxCreationDistance", false, value);
}
int32_t GCParticleSystemDefinition::GetAggregationMinAvailableParticles() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nAggregationMinAvailableParticles");
}
void GCParticleSystemDefinition::SetAggregationMinAvailableParticles(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nAggregationMinAvailableParticles", false, value);
}
float GCParticleSystemDefinition::GetAggregateRadius() const {
    return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flAggregateRadius");
}
void GCParticleSystemDefinition::SetAggregateRadius(float value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flAggregateRadius", false, value);
}
bool GCParticleSystemDefinition::GetShouldBatch() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleSystemDefinition", "m_bShouldBatch");
}
void GCParticleSystemDefinition::SetShouldBatch(bool value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_bShouldBatch", false, value);
}
bool GCParticleSystemDefinition::GetShouldHitboxesFallbackToRenderBounds() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleSystemDefinition", "m_bShouldHitboxesFallbackToRenderBounds");
}
void GCParticleSystemDefinition::SetShouldHitboxesFallbackToRenderBounds(bool value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_bShouldHitboxesFallbackToRenderBounds", false, value);
}
bool GCParticleSystemDefinition::GetShouldHitboxesFallbackToSnapshot() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleSystemDefinition", "m_bShouldHitboxesFallbackToSnapshot");
}
void GCParticleSystemDefinition::SetShouldHitboxesFallbackToSnapshot(bool value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_bShouldHitboxesFallbackToSnapshot", false, value);
}
bool GCParticleSystemDefinition::GetShouldHitboxesFallbackToCollisionHulls() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleSystemDefinition", "m_bShouldHitboxesFallbackToCollisionHulls");
}
void GCParticleSystemDefinition::SetShouldHitboxesFallbackToCollisionHulls(bool value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_bShouldHitboxesFallbackToCollisionHulls", false, value);
}
uint64_t GCParticleSystemDefinition::GetViewModelEffect() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CParticleSystemDefinition", "m_nViewModelEffect");
}
void GCParticleSystemDefinition::SetViewModelEffect(uint64_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nViewModelEffect", false, value);
}
bool GCParticleSystemDefinition::GetScreenSpaceEffect() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleSystemDefinition", "m_bScreenSpaceEffect");
}
void GCParticleSystemDefinition::SetScreenSpaceEffect(bool value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_bScreenSpaceEffect", false, value);
}
std::string GCParticleSystemDefinition::GetTargetLayerID() const {
    return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CParticleSystemDefinition", "m_pszTargetLayerID").String();
}
void GCParticleSystemDefinition::SetTargetLayerID(std::string value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_pszTargetLayerID", false, CUtlSymbolLarge(value.c_str()));
}
int32_t GCParticleSystemDefinition::GetSkipRenderControlPoint() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nSkipRenderControlPoint");
}
void GCParticleSystemDefinition::SetSkipRenderControlPoint(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nSkipRenderControlPoint", false, value);
}
int32_t GCParticleSystemDefinition::GetAllowRenderControlPoint() const {
    return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nAllowRenderControlPoint");
}
void GCParticleSystemDefinition::SetAllowRenderControlPoint(int32_t value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nAllowRenderControlPoint", false, value);
}
bool GCParticleSystemDefinition::GetShouldSort() const {
    return GetSchemaValue<bool>(m_ptr, "CParticleSystemDefinition", "m_bShouldSort");
}
void GCParticleSystemDefinition::SetShouldSort(bool value) {
    SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_bShouldSort", false, value);
}
std::vector<GParticleControlPointConfiguration_t> GCParticleSystemDefinition::GetControlPointConfigurations() const {
    CUtlVector<GParticleControlPointConfiguration_t>* vec = GetSchemaValue<CUtlVector<GParticleControlPointConfiguration_t>*>(m_ptr, "CParticleSystemDefinition", "m_controlPointConfigurations"); std::vector<GParticleControlPointConfiguration_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCParticleSystemDefinition::SetControlPointConfigurations(std::vector<GParticleControlPointConfiguration_t> value) {
    SetSchemaValueCUtlVector<GParticleControlPointConfiguration_t>(m_ptr, "CParticleSystemDefinition", "m_controlPointConfigurations", false, value);
}
std::string GCParticleSystemDefinition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCParticleSystemDefinition::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCParticleSystemDefinition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleSystemDefinition>("CParticleSystemDefinition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BehaviorVersion", &GCParticleSystemDefinition::GetBehaviorVersion, &GCParticleSystemDefinition::SetBehaviorVersion)
        .addProperty("PreEmissionOperators", &GCParticleSystemDefinition::GetPreEmissionOperators, &GCParticleSystemDefinition::SetPreEmissionOperators)
        .addProperty("Emitters", &GCParticleSystemDefinition::GetEmitters, &GCParticleSystemDefinition::SetEmitters)
        .addProperty("Initializers", &GCParticleSystemDefinition::GetInitializers, &GCParticleSystemDefinition::SetInitializers)
        .addProperty("Operators", &GCParticleSystemDefinition::GetOperators, &GCParticleSystemDefinition::SetOperators)
        .addProperty("ForceGenerators", &GCParticleSystemDefinition::GetForceGenerators, &GCParticleSystemDefinition::SetForceGenerators)
        .addProperty("Constraints", &GCParticleSystemDefinition::GetConstraints, &GCParticleSystemDefinition::SetConstraints)
        .addProperty("Renderers", &GCParticleSystemDefinition::GetRenderers, &GCParticleSystemDefinition::SetRenderers)
        .addProperty("Children", &GCParticleSystemDefinition::GetChildren, &GCParticleSystemDefinition::SetChildren)
        .addProperty("FirstMultipleOverride_BackwardCompat", &GCParticleSystemDefinition::GetFirstMultipleOverride_BackwardCompat, &GCParticleSystemDefinition::SetFirstMultipleOverride_BackwardCompat)
        .addProperty("InitialParticles", &GCParticleSystemDefinition::GetInitialParticles, &GCParticleSystemDefinition::SetInitialParticles)
        .addProperty("MaxParticles", &GCParticleSystemDefinition::GetMaxParticles, &GCParticleSystemDefinition::SetMaxParticles)
        .addProperty("GroupID", &GCParticleSystemDefinition::GetGroupID, &GCParticleSystemDefinition::SetGroupID)
        .addProperty("BoundingBoxMin", &GCParticleSystemDefinition::GetBoundingBoxMin, &GCParticleSystemDefinition::SetBoundingBoxMin)
        .addProperty("BoundingBoxMax", &GCParticleSystemDefinition::GetBoundingBoxMax, &GCParticleSystemDefinition::SetBoundingBoxMax)
        .addProperty("DepthSortBias", &GCParticleSystemDefinition::GetDepthSortBias, &GCParticleSystemDefinition::SetDepthSortBias)
        .addProperty("SortOverridePositionCP", &GCParticleSystemDefinition::GetSortOverridePositionCP, &GCParticleSystemDefinition::SetSortOverridePositionCP)
        .addProperty("InfiniteBounds", &GCParticleSystemDefinition::GetInfiniteBounds, &GCParticleSystemDefinition::SetInfiniteBounds)
        .addProperty("EnableNamedValues", &GCParticleSystemDefinition::GetEnableNamedValues, &GCParticleSystemDefinition::SetEnableNamedValues)
        .addProperty("NamedValueDomain", &GCParticleSystemDefinition::GetNamedValueDomain, &GCParticleSystemDefinition::SetNamedValueDomain)
        .addProperty("NamedValueLocals", &GCParticleSystemDefinition::GetNamedValueLocals, &GCParticleSystemDefinition::SetNamedValueLocals)
        .addProperty("ConstantColor", &GCParticleSystemDefinition::GetConstantColor, &GCParticleSystemDefinition::SetConstantColor)
        .addProperty("ConstantNormal", &GCParticleSystemDefinition::GetConstantNormal, &GCParticleSystemDefinition::SetConstantNormal)
        .addProperty("ConstantRadius", &GCParticleSystemDefinition::GetConstantRadius, &GCParticleSystemDefinition::SetConstantRadius)
        .addProperty("ConstantRotation", &GCParticleSystemDefinition::GetConstantRotation, &GCParticleSystemDefinition::SetConstantRotation)
        .addProperty("ConstantRotationSpeed", &GCParticleSystemDefinition::GetConstantRotationSpeed, &GCParticleSystemDefinition::SetConstantRotationSpeed)
        .addProperty("ConstantLifespan", &GCParticleSystemDefinition::GetConstantLifespan, &GCParticleSystemDefinition::SetConstantLifespan)
        .addProperty("ConstantSequenceNumber", &GCParticleSystemDefinition::GetConstantSequenceNumber, &GCParticleSystemDefinition::SetConstantSequenceNumber)
        .addProperty("ConstantSequenceNumber1", &GCParticleSystemDefinition::GetConstantSequenceNumber1, &GCParticleSystemDefinition::SetConstantSequenceNumber1)
        .addProperty("SnapshotControlPoint", &GCParticleSystemDefinition::GetSnapshotControlPoint, &GCParticleSystemDefinition::SetSnapshotControlPoint)
        .addProperty("CullRadius", &GCParticleSystemDefinition::GetCullRadius, &GCParticleSystemDefinition::SetCullRadius)
        .addProperty("CullFillCost", &GCParticleSystemDefinition::GetCullFillCost, &GCParticleSystemDefinition::SetCullFillCost)
        .addProperty("CullControlPoint", &GCParticleSystemDefinition::GetCullControlPoint, &GCParticleSystemDefinition::SetCullControlPoint)
        .addProperty("FallbackMaxCount", &GCParticleSystemDefinition::GetFallbackMaxCount, &GCParticleSystemDefinition::SetFallbackMaxCount)
        .addProperty("PreSimulationTime", &GCParticleSystemDefinition::GetPreSimulationTime, &GCParticleSystemDefinition::SetPreSimulationTime)
        .addProperty("StopSimulationAfterTime", &GCParticleSystemDefinition::GetStopSimulationAfterTime, &GCParticleSystemDefinition::SetStopSimulationAfterTime)
        .addProperty("MaximumTimeStep", &GCParticleSystemDefinition::GetMaximumTimeStep, &GCParticleSystemDefinition::SetMaximumTimeStep)
        .addProperty("MaximumSimTime", &GCParticleSystemDefinition::GetMaximumSimTime, &GCParticleSystemDefinition::SetMaximumSimTime)
        .addProperty("MinimumSimTime", &GCParticleSystemDefinition::GetMinimumSimTime, &GCParticleSystemDefinition::SetMinimumSimTime)
        .addProperty("MinimumTimeStep", &GCParticleSystemDefinition::GetMinimumTimeStep, &GCParticleSystemDefinition::SetMinimumTimeStep)
        .addProperty("MinimumFrames", &GCParticleSystemDefinition::GetMinimumFrames, &GCParticleSystemDefinition::SetMinimumFrames)
        .addProperty("MinCPULevel", &GCParticleSystemDefinition::GetMinCPULevel, &GCParticleSystemDefinition::SetMinCPULevel)
        .addProperty("MinGPULevel", &GCParticleSystemDefinition::GetMinGPULevel, &GCParticleSystemDefinition::SetMinGPULevel)
        .addProperty("NoDrawTimeToGoToSleep", &GCParticleSystemDefinition::GetNoDrawTimeToGoToSleep, &GCParticleSystemDefinition::SetNoDrawTimeToGoToSleep)
        .addProperty("MaxDrawDistance", &GCParticleSystemDefinition::GetMaxDrawDistance, &GCParticleSystemDefinition::SetMaxDrawDistance)
        .addProperty("StartFadeDistance", &GCParticleSystemDefinition::GetStartFadeDistance, &GCParticleSystemDefinition::SetStartFadeDistance)
        .addProperty("MaxCreationDistance", &GCParticleSystemDefinition::GetMaxCreationDistance, &GCParticleSystemDefinition::SetMaxCreationDistance)
        .addProperty("AggregationMinAvailableParticles", &GCParticleSystemDefinition::GetAggregationMinAvailableParticles, &GCParticleSystemDefinition::SetAggregationMinAvailableParticles)
        .addProperty("AggregateRadius", &GCParticleSystemDefinition::GetAggregateRadius, &GCParticleSystemDefinition::SetAggregateRadius)
        .addProperty("ShouldBatch", &GCParticleSystemDefinition::GetShouldBatch, &GCParticleSystemDefinition::SetShouldBatch)
        .addProperty("ShouldHitboxesFallbackToRenderBounds", &GCParticleSystemDefinition::GetShouldHitboxesFallbackToRenderBounds, &GCParticleSystemDefinition::SetShouldHitboxesFallbackToRenderBounds)
        .addProperty("ShouldHitboxesFallbackToSnapshot", &GCParticleSystemDefinition::GetShouldHitboxesFallbackToSnapshot, &GCParticleSystemDefinition::SetShouldHitboxesFallbackToSnapshot)
        .addProperty("ShouldHitboxesFallbackToCollisionHulls", &GCParticleSystemDefinition::GetShouldHitboxesFallbackToCollisionHulls, &GCParticleSystemDefinition::SetShouldHitboxesFallbackToCollisionHulls)
        .addProperty("ViewModelEffect", &GCParticleSystemDefinition::GetViewModelEffect, &GCParticleSystemDefinition::SetViewModelEffect)
        .addProperty("ScreenSpaceEffect", &GCParticleSystemDefinition::GetScreenSpaceEffect, &GCParticleSystemDefinition::SetScreenSpaceEffect)
        .addProperty("TargetLayerID", &GCParticleSystemDefinition::GetTargetLayerID, &GCParticleSystemDefinition::SetTargetLayerID)
        .addProperty("SkipRenderControlPoint", &GCParticleSystemDefinition::GetSkipRenderControlPoint, &GCParticleSystemDefinition::SetSkipRenderControlPoint)
        .addProperty("AllowRenderControlPoint", &GCParticleSystemDefinition::GetAllowRenderControlPoint, &GCParticleSystemDefinition::SetAllowRenderControlPoint)
        .addProperty("ShouldSort", &GCParticleSystemDefinition::GetShouldSort, &GCParticleSystemDefinition::SetShouldSort)
        .addProperty("ControlPointConfigurations", &GCParticleSystemDefinition::GetControlPointConfigurations, &GCParticleSystemDefinition::SetControlPointConfigurations)
        .addFunction("ToPtr", &GCParticleSystemDefinition::ToPtr)
        .addFunction("IsValid", &GCParticleSystemDefinition::IsValid)
        .endClass();
}