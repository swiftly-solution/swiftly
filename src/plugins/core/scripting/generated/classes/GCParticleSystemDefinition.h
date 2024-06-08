class GCParticleSystemDefinition;

#ifndef _gccparticlesystemdefinition_h
#define _gccparticlesystemdefinition_h

#include "../../../scripting.h"

#include "../types/GInheritableBoolType_t.h"
#include "GCParticleFunction.h"
#include "GCParticleFunctionPreEmission.h"
#include "GCParticleFunctionEmitter.h"
#include "GCParticleFunctionInitializer.h"
#include "GCParticleFunctionOperator.h"
#include "GCParticleFunctionForce.h"
#include "GCParticleFunctionConstraint.h"
#include "GCParticleFunctionRenderer.h"
#include "GParticleChildrenInfo_t.h"
#include "GParticleNamedValueSource_t.h"
#include "GParticleControlPointConfiguration_t.h"

class GCParticleSystemDefinition
{
private:
    void *m_ptr;

public:
    GCParticleSystemDefinition() {}
    GCParticleSystemDefinition(void *ptr) : m_ptr(ptr) {}

    int32_t GetBehaviorVersion() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nBehaviorVersion"); }
    void SetBehaviorVersion(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nBehaviorVersion", false, value); }
    std::vector<GCParticleFunctionPreEmission*> GetPreEmissionOperators() const { CUtlVector<GCParticleFunctionPreEmission*>* vec = GetSchemaValue<CUtlVector<GCParticleFunctionPreEmission*>*>(m_ptr, "CParticleSystemDefinition", "m_PreEmissionOperators"); std::vector<GCParticleFunctionPreEmission*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetPreEmissionOperators(std::vector<GCParticleFunctionPreEmission*> value) { SetSchemaValueCUtlVector<GCParticleFunctionPreEmission*>(m_ptr, "CParticleSystemDefinition", "m_PreEmissionOperators", false, value); }
    std::vector<GCParticleFunctionEmitter*> GetEmitters() const { CUtlVector<GCParticleFunctionEmitter*>* vec = GetSchemaValue<CUtlVector<GCParticleFunctionEmitter*>*>(m_ptr, "CParticleSystemDefinition", "m_Emitters"); std::vector<GCParticleFunctionEmitter*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetEmitters(std::vector<GCParticleFunctionEmitter*> value) { SetSchemaValueCUtlVector<GCParticleFunctionEmitter*>(m_ptr, "CParticleSystemDefinition", "m_Emitters", false, value); }
    std::vector<GCParticleFunctionInitializer*> GetInitializers() const { CUtlVector<GCParticleFunctionInitializer*>* vec = GetSchemaValue<CUtlVector<GCParticleFunctionInitializer*>*>(m_ptr, "CParticleSystemDefinition", "m_Initializers"); std::vector<GCParticleFunctionInitializer*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetInitializers(std::vector<GCParticleFunctionInitializer*> value) { SetSchemaValueCUtlVector<GCParticleFunctionInitializer*>(m_ptr, "CParticleSystemDefinition", "m_Initializers", false, value); }
    std::vector<GCParticleFunctionOperator*> GetOperators() const { CUtlVector<GCParticleFunctionOperator*>* vec = GetSchemaValue<CUtlVector<GCParticleFunctionOperator*>*>(m_ptr, "CParticleSystemDefinition", "m_Operators"); std::vector<GCParticleFunctionOperator*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetOperators(std::vector<GCParticleFunctionOperator*> value) { SetSchemaValueCUtlVector<GCParticleFunctionOperator*>(m_ptr, "CParticleSystemDefinition", "m_Operators", false, value); }
    std::vector<GCParticleFunctionForce*> GetForceGenerators() const { CUtlVector<GCParticleFunctionForce*>* vec = GetSchemaValue<CUtlVector<GCParticleFunctionForce*>*>(m_ptr, "CParticleSystemDefinition", "m_ForceGenerators"); std::vector<GCParticleFunctionForce*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetForceGenerators(std::vector<GCParticleFunctionForce*> value) { SetSchemaValueCUtlVector<GCParticleFunctionForce*>(m_ptr, "CParticleSystemDefinition", "m_ForceGenerators", false, value); }
    std::vector<GCParticleFunctionConstraint*> GetConstraints() const { CUtlVector<GCParticleFunctionConstraint*>* vec = GetSchemaValue<CUtlVector<GCParticleFunctionConstraint*>*>(m_ptr, "CParticleSystemDefinition", "m_Constraints"); std::vector<GCParticleFunctionConstraint*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetConstraints(std::vector<GCParticleFunctionConstraint*> value) { SetSchemaValueCUtlVector<GCParticleFunctionConstraint*>(m_ptr, "CParticleSystemDefinition", "m_Constraints", false, value); }
    std::vector<GCParticleFunctionRenderer*> GetRenderers() const { CUtlVector<GCParticleFunctionRenderer*>* vec = GetSchemaValue<CUtlVector<GCParticleFunctionRenderer*>*>(m_ptr, "CParticleSystemDefinition", "m_Renderers"); std::vector<GCParticleFunctionRenderer*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRenderers(std::vector<GCParticleFunctionRenderer*> value) { SetSchemaValueCUtlVector<GCParticleFunctionRenderer*>(m_ptr, "CParticleSystemDefinition", "m_Renderers", false, value); }
    std::vector<GParticleChildrenInfo_t> GetChildren() const { CUtlVector<GParticleChildrenInfo_t>* vec = GetSchemaValue<CUtlVector<GParticleChildrenInfo_t>*>(m_ptr, "CParticleSystemDefinition", "m_Children"); std::vector<GParticleChildrenInfo_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetChildren(std::vector<GParticleChildrenInfo_t> value) { SetSchemaValueCUtlVector<GParticleChildrenInfo_t>(m_ptr, "CParticleSystemDefinition", "m_Children", false, value); }
    int32_t GetFirstMultipleOverride_BackwardCompat() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nFirstMultipleOverride_BackwardCompat"); }
    void SetFirstMultipleOverride_BackwardCompat(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nFirstMultipleOverride_BackwardCompat", false, value); }
    int32_t GetInitialParticles() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nInitialParticles"); }
    void SetInitialParticles(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nInitialParticles", false, value); }
    int32_t GetMaxParticles() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nMaxParticles"); }
    void SetMaxParticles(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nMaxParticles", false, value); }
    int32_t GetGroupID() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nGroupID"); }
    void SetGroupID(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nGroupID", false, value); }
    Vector GetBoundingBoxMin() const { return GetSchemaValue<Vector>(m_ptr, "CParticleSystemDefinition", "m_BoundingBoxMin"); }
    void SetBoundingBoxMin(Vector value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_BoundingBoxMin", false, value); }
    Vector GetBoundingBoxMax() const { return GetSchemaValue<Vector>(m_ptr, "CParticleSystemDefinition", "m_BoundingBoxMax"); }
    void SetBoundingBoxMax(Vector value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_BoundingBoxMax", false, value); }
    float GetDepthSortBias() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flDepthSortBias"); }
    void SetDepthSortBias(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flDepthSortBias", false, value); }
    int32_t GetSortOverridePositionCP() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nSortOverridePositionCP"); }
    void SetSortOverridePositionCP(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nSortOverridePositionCP", false, value); }
    bool GetInfiniteBounds() const { return GetSchemaValue<bool>(m_ptr, "CParticleSystemDefinition", "m_bInfiniteBounds"); }
    void SetInfiniteBounds(bool value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_bInfiniteBounds", false, value); }
    bool GetEnableNamedValues() const { return GetSchemaValue<bool>(m_ptr, "CParticleSystemDefinition", "m_bEnableNamedValues"); }
    void SetEnableNamedValues(bool value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_bEnableNamedValues", false, value); }
    CUtlString GetNamedValueDomain() const { return GetSchemaValue<CUtlString>(m_ptr, "CParticleSystemDefinition", "m_NamedValueDomain"); }
    void SetNamedValueDomain(CUtlString value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_NamedValueDomain", false, value); }
    std::vector<GParticleNamedValueSource_t*> GetNamedValueLocals() const { CUtlVector<GParticleNamedValueSource_t*>* vec = GetSchemaValue<CUtlVector<GParticleNamedValueSource_t*>*>(m_ptr, "CParticleSystemDefinition", "m_NamedValueLocals"); std::vector<GParticleNamedValueSource_t*> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetNamedValueLocals(std::vector<GParticleNamedValueSource_t*> value) { SetSchemaValueCUtlVector<GParticleNamedValueSource_t*>(m_ptr, "CParticleSystemDefinition", "m_NamedValueLocals", false, value); }
    Color GetConstantColor() const { return GetSchemaValue<Color>(m_ptr, "CParticleSystemDefinition", "m_ConstantColor"); }
    void SetConstantColor(Color value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_ConstantColor", false, value); }
    Vector GetConstantNormal() const { return GetSchemaValue<Vector>(m_ptr, "CParticleSystemDefinition", "m_ConstantNormal"); }
    void SetConstantNormal(Vector value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_ConstantNormal", false, value); }
    float GetConstantRadius() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flConstantRadius"); }
    void SetConstantRadius(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flConstantRadius", false, value); }
    float GetConstantRotation() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flConstantRotation"); }
    void SetConstantRotation(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flConstantRotation", false, value); }
    float GetConstantRotationSpeed() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flConstantRotationSpeed"); }
    void SetConstantRotationSpeed(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flConstantRotationSpeed", false, value); }
    float GetConstantLifespan() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flConstantLifespan"); }
    void SetConstantLifespan(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flConstantLifespan", false, value); }
    int32_t GetConstantSequenceNumber() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nConstantSequenceNumber"); }
    void SetConstantSequenceNumber(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nConstantSequenceNumber", false, value); }
    int32_t GetConstantSequenceNumber1() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nConstantSequenceNumber1"); }
    void SetConstantSequenceNumber1(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nConstantSequenceNumber1", false, value); }
    int32_t GetSnapshotControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nSnapshotControlPoint"); }
    void SetSnapshotControlPoint(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nSnapshotControlPoint", false, value); }
    float GetCullRadius() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flCullRadius"); }
    void SetCullRadius(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flCullRadius", false, value); }
    float GetCullFillCost() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flCullFillCost"); }
    void SetCullFillCost(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flCullFillCost", false, value); }
    int32_t GetCullControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nCullControlPoint"); }
    void SetCullControlPoint(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nCullControlPoint", false, value); }
    int32_t GetFallbackMaxCount() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nFallbackMaxCount"); }
    void SetFallbackMaxCount(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nFallbackMaxCount", false, value); }
    float GetPreSimulationTime() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flPreSimulationTime"); }
    void SetPreSimulationTime(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flPreSimulationTime", false, value); }
    float GetStopSimulationAfterTime() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flStopSimulationAfterTime"); }
    void SetStopSimulationAfterTime(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flStopSimulationAfterTime", false, value); }
    float GetMaximumTimeStep() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flMaximumTimeStep"); }
    void SetMaximumTimeStep(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flMaximumTimeStep", false, value); }
    float GetMaximumSimTime() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flMaximumSimTime"); }
    void SetMaximumSimTime(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flMaximumSimTime", false, value); }
    float GetMinimumSimTime() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flMinimumSimTime"); }
    void SetMinimumSimTime(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flMinimumSimTime", false, value); }
    float GetMinimumTimeStep() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flMinimumTimeStep"); }
    void SetMinimumTimeStep(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flMinimumTimeStep", false, value); }
    int32_t GetMinimumFrames() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nMinimumFrames"); }
    void SetMinimumFrames(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nMinimumFrames", false, value); }
    int32_t GetMinCPULevel() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nMinCPULevel"); }
    void SetMinCPULevel(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nMinCPULevel", false, value); }
    int32_t GetMinGPULevel() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nMinGPULevel"); }
    void SetMinGPULevel(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nMinGPULevel", false, value); }
    float GetNoDrawTimeToGoToSleep() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flNoDrawTimeToGoToSleep"); }
    void SetNoDrawTimeToGoToSleep(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flNoDrawTimeToGoToSleep", false, value); }
    float GetMaxDrawDistance() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flMaxDrawDistance"); }
    void SetMaxDrawDistance(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flMaxDrawDistance", false, value); }
    float GetStartFadeDistance() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flStartFadeDistance"); }
    void SetStartFadeDistance(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flStartFadeDistance", false, value); }
    float GetMaxCreationDistance() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flMaxCreationDistance"); }
    void SetMaxCreationDistance(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flMaxCreationDistance", false, value); }
    int32_t GetAggregationMinAvailableParticles() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nAggregationMinAvailableParticles"); }
    void SetAggregationMinAvailableParticles(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nAggregationMinAvailableParticles", false, value); }
    float GetAggregateRadius() const { return GetSchemaValue<float>(m_ptr, "CParticleSystemDefinition", "m_flAggregateRadius"); }
    void SetAggregateRadius(float value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_flAggregateRadius", false, value); }
    bool GetShouldBatch() const { return GetSchemaValue<bool>(m_ptr, "CParticleSystemDefinition", "m_bShouldBatch"); }
    void SetShouldBatch(bool value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_bShouldBatch", false, value); }
    bool GetShouldHitboxesFallbackToRenderBounds() const { return GetSchemaValue<bool>(m_ptr, "CParticleSystemDefinition", "m_bShouldHitboxesFallbackToRenderBounds"); }
    void SetShouldHitboxesFallbackToRenderBounds(bool value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_bShouldHitboxesFallbackToRenderBounds", false, value); }
    bool GetShouldHitboxesFallbackToSnapshot() const { return GetSchemaValue<bool>(m_ptr, "CParticleSystemDefinition", "m_bShouldHitboxesFallbackToSnapshot"); }
    void SetShouldHitboxesFallbackToSnapshot(bool value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_bShouldHitboxesFallbackToSnapshot", false, value); }
    bool GetShouldHitboxesFallbackToCollisionHulls() const { return GetSchemaValue<bool>(m_ptr, "CParticleSystemDefinition", "m_bShouldHitboxesFallbackToCollisionHulls"); }
    void SetShouldHitboxesFallbackToCollisionHulls(bool value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_bShouldHitboxesFallbackToCollisionHulls", false, value); }
    InheritableBoolType_t GetViewModelEffect() const { return GetSchemaValue<InheritableBoolType_t>(m_ptr, "CParticleSystemDefinition", "m_nViewModelEffect"); }
    void SetViewModelEffect(InheritableBoolType_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nViewModelEffect", false, value); }
    bool GetScreenSpaceEffect() const { return GetSchemaValue<bool>(m_ptr, "CParticleSystemDefinition", "m_bScreenSpaceEffect"); }
    void SetScreenSpaceEffect(bool value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_bScreenSpaceEffect", false, value); }
    CUtlSymbolLarge GetTargetLayerID() const { return GetSchemaValue<CUtlSymbolLarge>(m_ptr, "CParticleSystemDefinition", "m_pszTargetLayerID"); }
    void SetTargetLayerID(CUtlSymbolLarge value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_pszTargetLayerID", false, value); }
    int32_t GetSkipRenderControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nSkipRenderControlPoint"); }
    void SetSkipRenderControlPoint(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nSkipRenderControlPoint", false, value); }
    int32_t GetAllowRenderControlPoint() const { return GetSchemaValue<int32_t>(m_ptr, "CParticleSystemDefinition", "m_nAllowRenderControlPoint"); }
    void SetAllowRenderControlPoint(int32_t value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_nAllowRenderControlPoint", false, value); }
    bool GetShouldSort() const { return GetSchemaValue<bool>(m_ptr, "CParticleSystemDefinition", "m_bShouldSort"); }
    void SetShouldSort(bool value) { SetSchemaValue(m_ptr, "CParticleSystemDefinition", "m_bShouldSort", false, value); }
    std::vector<GParticleControlPointConfiguration_t> GetControlPointConfigurations() const { CUtlVector<GParticleControlPointConfiguration_t>* vec = GetSchemaValue<CUtlVector<GParticleControlPointConfiguration_t>*>(m_ptr, "CParticleSystemDefinition", "m_controlPointConfigurations"); std::vector<GParticleControlPointConfiguration_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetControlPointConfigurations(std::vector<GParticleControlPointConfiguration_t> value) { SetSchemaValueCUtlVector<GParticleControlPointConfiguration_t>(m_ptr, "CParticleSystemDefinition", "m_controlPointConfigurations", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif