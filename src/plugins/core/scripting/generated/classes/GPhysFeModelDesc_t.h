class GPhysFeModelDesc_t;

#ifndef _gcphysfemodeldesc_t_h
#define _gcphysfemodeldesc_t_h

#include "../../../scripting.h"


#include "GFeNodeBase_t.h"
#include "GFeSimdNodeBase_t.h"
#include "GFeQuad_t.h"
#include "GFeSimdQuad_t.h"
#include "GFeSimdTri_t.h"
#include "GFeSimdRodConstraint_t.h"
#include "GFeSimdRodConstraintAnim_t.h"
#include "GFeRodConstraint_t.h"
#include "GFeTwistConstraint_t.h"
#include "GFeAxialEdgeBend_t.h"
#include "GFeCtrlOffset_t.h"
#include "GFeCtrlOsOffset_t.h"
#include "GFeFollowNode_t.h"
#include "GFeCollisionPlane_t.h"
#include "GFeNodeIntegrator_t.h"
#include "GFeSpringIntegrator_t.h"
#include "GFeSimdSpringIntegrator_t.h"
#include "GFeWorldCollisionParams_t.h"
#include "GFeTaperedCapsuleStretch_t.h"
#include "GFeTaperedCapsuleRigid_t.h"
#include "GFeSphereRigid_t.h"
#include "GFeTreeChildren_t.h"
#include "GFeFitMatrix_t.h"
#include "GFeFitWeight_t.h"
#include "GFeNodeReverseOffset_t.h"
#include "GFeAnimStrayRadius_t.h"
#include "GFeSimdAnimStrayRadius_t.h"
#include "GFeKelagerBend2_t.h"
#include "GFeCtrlSoftOffset_t.h"
#include "GCFeIndexedJiggleBone.h"
#include "GFeTri_t.h"
#include "GFeBoxRigid_t.h"
#include "GFeRigidColliderIndices_t.h"
#include "GFeMorphLayerDepr_t.h"
#include "GFeVertexMapDesc_t.h"
#include "GFeEffectDesc_t.h"
#include "GFeNodeWindBase_t.h"

class GPhysFeModelDesc_t
{
private:
    void *m_ptr;

public:
    GPhysFeModelDesc_t() {}
    GPhysFeModelDesc_t(void *ptr) : m_ptr(ptr) {}

    std::vector<uint32> GetCtrlHash() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "PhysFeModelDesc_t", "m_CtrlHash"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCtrlHash(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "PhysFeModelDesc_t", "m_CtrlHash", true, value); }
    std::vector<CUtlString> GetCtrlName() const { CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "PhysFeModelDesc_t", "m_CtrlName"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCtrlName(std::vector<CUtlString> value) { SetSchemaValueCUtlVector<CUtlString>(m_ptr, "PhysFeModelDesc_t", "m_CtrlName", true, value); }
    uint32_t GetStaticNodeFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "PhysFeModelDesc_t", "m_nStaticNodeFlags"); }
    void SetStaticNodeFlags(uint32_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nStaticNodeFlags", true, value); }
    uint32_t GetDynamicNodeFlags() const { return GetSchemaValue<uint32_t>(m_ptr, "PhysFeModelDesc_t", "m_nDynamicNodeFlags"); }
    void SetDynamicNodeFlags(uint32_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nDynamicNodeFlags", true, value); }
    float GetLocalForce() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flLocalForce"); }
    void SetLocalForce(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flLocalForce", true, value); }
    float GetLocalRotation() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flLocalRotation"); }
    void SetLocalRotation(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flLocalRotation", true, value); }
    uint16_t GetNodeCount() const { return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nNodeCount"); }
    void SetNodeCount(uint16_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nNodeCount", true, value); }
    uint16_t GetStaticNodes() const { return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nStaticNodes"); }
    void SetStaticNodes(uint16_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nStaticNodes", true, value); }
    uint16_t GetRotLockStaticNodes() const { return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nRotLockStaticNodes"); }
    void SetRotLockStaticNodes(uint16_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nRotLockStaticNodes", true, value); }
    uint16_t GetFirstPositionDrivenNode() const { return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nFirstPositionDrivenNode"); }
    void SetFirstPositionDrivenNode(uint16_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nFirstPositionDrivenNode", true, value); }
    uint16_t GetSimdTriCount1() const { return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nSimdTriCount1"); }
    void SetSimdTriCount1(uint16_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nSimdTriCount1", true, value); }
    uint16_t GetSimdTriCount2() const { return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nSimdTriCount2"); }
    void SetSimdTriCount2(uint16_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nSimdTriCount2", true, value); }
    uint16_t GetSimdQuadCount1() const { return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nSimdQuadCount1"); }
    void SetSimdQuadCount1(uint16_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nSimdQuadCount1", true, value); }
    uint16_t GetSimdQuadCount2() const { return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nSimdQuadCount2"); }
    void SetSimdQuadCount2(uint16_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nSimdQuadCount2", true, value); }
    uint16_t GetQuadCount1() const { return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nQuadCount1"); }
    void SetQuadCount1(uint16_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nQuadCount1", true, value); }
    uint16_t GetQuadCount2() const { return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nQuadCount2"); }
    void SetQuadCount2(uint16_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nQuadCount2", true, value); }
    uint16_t GetTreeDepth() const { return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nTreeDepth"); }
    void SetTreeDepth(uint16_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nTreeDepth", true, value); }
    uint16_t GetNodeBaseJiggleboneDependsCount() const { return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nNodeBaseJiggleboneDependsCount"); }
    void SetNodeBaseJiggleboneDependsCount(uint16_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nNodeBaseJiggleboneDependsCount", true, value); }
    uint16_t GetRopeCount() const { return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nRopeCount"); }
    void SetRopeCount(uint16_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nRopeCount", true, value); }
    std::vector<uint16> GetRopes() const { CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "PhysFeModelDesc_t", "m_Ropes"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRopes(std::vector<uint16> value) { SetSchemaValueCUtlVector<uint16>(m_ptr, "PhysFeModelDesc_t", "m_Ropes", true, value); }
    std::vector<GFeNodeBase_t> GetNodeBases() const { CUtlVector<GFeNodeBase_t>* vec = GetSchemaValue<CUtlVector<GFeNodeBase_t>*>(m_ptr, "PhysFeModelDesc_t", "m_NodeBases"); std::vector<GFeNodeBase_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetNodeBases(std::vector<GFeNodeBase_t> value) { SetSchemaValueCUtlVector<GFeNodeBase_t>(m_ptr, "PhysFeModelDesc_t", "m_NodeBases", true, value); }
    std::vector<GFeSimdNodeBase_t> GetSimdNodeBases() const { CUtlVector<GFeSimdNodeBase_t>* vec = GetSchemaValue<CUtlVector<GFeSimdNodeBase_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SimdNodeBases"); std::vector<GFeSimdNodeBase_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSimdNodeBases(std::vector<GFeSimdNodeBase_t> value) { SetSchemaValueCUtlVector<GFeSimdNodeBase_t>(m_ptr, "PhysFeModelDesc_t", "m_SimdNodeBases", true, value); }
    std::vector<GFeQuad_t> GetQuads() const { CUtlVector<GFeQuad_t>* vec = GetSchemaValue<CUtlVector<GFeQuad_t>*>(m_ptr, "PhysFeModelDesc_t", "m_Quads"); std::vector<GFeQuad_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetQuads(std::vector<GFeQuad_t> value) { SetSchemaValueCUtlVector<GFeQuad_t>(m_ptr, "PhysFeModelDesc_t", "m_Quads", true, value); }
    std::vector<GFeSimdQuad_t> GetSimdQuads() const { CUtlVector<GFeSimdQuad_t>* vec = GetSchemaValue<CUtlVector<GFeSimdQuad_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SimdQuads"); std::vector<GFeSimdQuad_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSimdQuads(std::vector<GFeSimdQuad_t> value) { SetSchemaValueCUtlVector<GFeSimdQuad_t>(m_ptr, "PhysFeModelDesc_t", "m_SimdQuads", true, value); }
    std::vector<GFeSimdTri_t> GetSimdTris() const { CUtlVector<GFeSimdTri_t>* vec = GetSchemaValue<CUtlVector<GFeSimdTri_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SimdTris"); std::vector<GFeSimdTri_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSimdTris(std::vector<GFeSimdTri_t> value) { SetSchemaValueCUtlVector<GFeSimdTri_t>(m_ptr, "PhysFeModelDesc_t", "m_SimdTris", true, value); }
    std::vector<GFeSimdRodConstraint_t> GetSimdRods() const { CUtlVector<GFeSimdRodConstraint_t>* vec = GetSchemaValue<CUtlVector<GFeSimdRodConstraint_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SimdRods"); std::vector<GFeSimdRodConstraint_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSimdRods(std::vector<GFeSimdRodConstraint_t> value) { SetSchemaValueCUtlVector<GFeSimdRodConstraint_t>(m_ptr, "PhysFeModelDesc_t", "m_SimdRods", true, value); }
    std::vector<GFeSimdRodConstraintAnim_t> GetSimdRodsAnim() const { CUtlVector<GFeSimdRodConstraintAnim_t>* vec = GetSchemaValue<CUtlVector<GFeSimdRodConstraintAnim_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SimdRodsAnim"); std::vector<GFeSimdRodConstraintAnim_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSimdRodsAnim(std::vector<GFeSimdRodConstraintAnim_t> value) { SetSchemaValueCUtlVector<GFeSimdRodConstraintAnim_t>(m_ptr, "PhysFeModelDesc_t", "m_SimdRodsAnim", true, value); }
    std::vector<GFeRodConstraint_t> GetRods() const { CUtlVector<GFeRodConstraint_t>* vec = GetSchemaValue<CUtlVector<GFeRodConstraint_t>*>(m_ptr, "PhysFeModelDesc_t", "m_Rods"); std::vector<GFeRodConstraint_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRods(std::vector<GFeRodConstraint_t> value) { SetSchemaValueCUtlVector<GFeRodConstraint_t>(m_ptr, "PhysFeModelDesc_t", "m_Rods", true, value); }
    std::vector<GFeTwistConstraint_t> GetTwists() const { CUtlVector<GFeTwistConstraint_t>* vec = GetSchemaValue<CUtlVector<GFeTwistConstraint_t>*>(m_ptr, "PhysFeModelDesc_t", "m_Twists"); std::vector<GFeTwistConstraint_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTwists(std::vector<GFeTwistConstraint_t> value) { SetSchemaValueCUtlVector<GFeTwistConstraint_t>(m_ptr, "PhysFeModelDesc_t", "m_Twists", true, value); }
    std::vector<GFeAxialEdgeBend_t> GetAxialEdges() const { CUtlVector<GFeAxialEdgeBend_t>* vec = GetSchemaValue<CUtlVector<GFeAxialEdgeBend_t>*>(m_ptr, "PhysFeModelDesc_t", "m_AxialEdges"); std::vector<GFeAxialEdgeBend_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetAxialEdges(std::vector<GFeAxialEdgeBend_t> value) { SetSchemaValueCUtlVector<GFeAxialEdgeBend_t>(m_ptr, "PhysFeModelDesc_t", "m_AxialEdges", true, value); }
    std::vector<float32> GetNodeInvMasses() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "PhysFeModelDesc_t", "m_NodeInvMasses"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetNodeInvMasses(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "PhysFeModelDesc_t", "m_NodeInvMasses", true, value); }
    std::vector<GFeCtrlOffset_t> GetCtrlOffsets() const { CUtlVector<GFeCtrlOffset_t>* vec = GetSchemaValue<CUtlVector<GFeCtrlOffset_t>*>(m_ptr, "PhysFeModelDesc_t", "m_CtrlOffsets"); std::vector<GFeCtrlOffset_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCtrlOffsets(std::vector<GFeCtrlOffset_t> value) { SetSchemaValueCUtlVector<GFeCtrlOffset_t>(m_ptr, "PhysFeModelDesc_t", "m_CtrlOffsets", true, value); }
    std::vector<GFeCtrlOsOffset_t> GetCtrlOsOffsets() const { CUtlVector<GFeCtrlOsOffset_t>* vec = GetSchemaValue<CUtlVector<GFeCtrlOsOffset_t>*>(m_ptr, "PhysFeModelDesc_t", "m_CtrlOsOffsets"); std::vector<GFeCtrlOsOffset_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCtrlOsOffsets(std::vector<GFeCtrlOsOffset_t> value) { SetSchemaValueCUtlVector<GFeCtrlOsOffset_t>(m_ptr, "PhysFeModelDesc_t", "m_CtrlOsOffsets", true, value); }
    std::vector<GFeFollowNode_t> GetFollowNodes() const { CUtlVector<GFeFollowNode_t>* vec = GetSchemaValue<CUtlVector<GFeFollowNode_t>*>(m_ptr, "PhysFeModelDesc_t", "m_FollowNodes"); std::vector<GFeFollowNode_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFollowNodes(std::vector<GFeFollowNode_t> value) { SetSchemaValueCUtlVector<GFeFollowNode_t>(m_ptr, "PhysFeModelDesc_t", "m_FollowNodes", true, value); }
    std::vector<GFeCollisionPlane_t> GetCollisionPlanes() const { CUtlVector<GFeCollisionPlane_t>* vec = GetSchemaValue<CUtlVector<GFeCollisionPlane_t>*>(m_ptr, "PhysFeModelDesc_t", "m_CollisionPlanes"); std::vector<GFeCollisionPlane_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCollisionPlanes(std::vector<GFeCollisionPlane_t> value) { SetSchemaValueCUtlVector<GFeCollisionPlane_t>(m_ptr, "PhysFeModelDesc_t", "m_CollisionPlanes", true, value); }
    std::vector<GFeNodeIntegrator_t> GetNodeIntegrator() const { CUtlVector<GFeNodeIntegrator_t>* vec = GetSchemaValue<CUtlVector<GFeNodeIntegrator_t>*>(m_ptr, "PhysFeModelDesc_t", "m_NodeIntegrator"); std::vector<GFeNodeIntegrator_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetNodeIntegrator(std::vector<GFeNodeIntegrator_t> value) { SetSchemaValueCUtlVector<GFeNodeIntegrator_t>(m_ptr, "PhysFeModelDesc_t", "m_NodeIntegrator", true, value); }
    std::vector<GFeSpringIntegrator_t> GetSpringIntegrator() const { CUtlVector<GFeSpringIntegrator_t>* vec = GetSchemaValue<CUtlVector<GFeSpringIntegrator_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SpringIntegrator"); std::vector<GFeSpringIntegrator_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSpringIntegrator(std::vector<GFeSpringIntegrator_t> value) { SetSchemaValueCUtlVector<GFeSpringIntegrator_t>(m_ptr, "PhysFeModelDesc_t", "m_SpringIntegrator", true, value); }
    std::vector<GFeSimdSpringIntegrator_t> GetSimdSpringIntegrator() const { CUtlVector<GFeSimdSpringIntegrator_t>* vec = GetSchemaValue<CUtlVector<GFeSimdSpringIntegrator_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SimdSpringIntegrator"); std::vector<GFeSimdSpringIntegrator_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSimdSpringIntegrator(std::vector<GFeSimdSpringIntegrator_t> value) { SetSchemaValueCUtlVector<GFeSimdSpringIntegrator_t>(m_ptr, "PhysFeModelDesc_t", "m_SimdSpringIntegrator", true, value); }
    std::vector<GFeWorldCollisionParams_t> GetWorldCollisionParams() const { CUtlVector<GFeWorldCollisionParams_t>* vec = GetSchemaValue<CUtlVector<GFeWorldCollisionParams_t>*>(m_ptr, "PhysFeModelDesc_t", "m_WorldCollisionParams"); std::vector<GFeWorldCollisionParams_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetWorldCollisionParams(std::vector<GFeWorldCollisionParams_t> value) { SetSchemaValueCUtlVector<GFeWorldCollisionParams_t>(m_ptr, "PhysFeModelDesc_t", "m_WorldCollisionParams", true, value); }
    std::vector<float32> GetLegacyStretchForce() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "PhysFeModelDesc_t", "m_LegacyStretchForce"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLegacyStretchForce(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "PhysFeModelDesc_t", "m_LegacyStretchForce", true, value); }
    std::vector<float32> GetNodeCollisionRadii() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "PhysFeModelDesc_t", "m_NodeCollisionRadii"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetNodeCollisionRadii(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "PhysFeModelDesc_t", "m_NodeCollisionRadii", true, value); }
    std::vector<float32> GetDynNodeFriction() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "PhysFeModelDesc_t", "m_DynNodeFriction"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetDynNodeFriction(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "PhysFeModelDesc_t", "m_DynNodeFriction", true, value); }
    std::vector<float32> GetLocalRotation1() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "PhysFeModelDesc_t", "m_LocalRotation"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLocalRotation1(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "PhysFeModelDesc_t", "m_LocalRotation", true, value); }
    std::vector<float32> GetLocalForce1() const { CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "PhysFeModelDesc_t", "m_LocalForce"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLocalForce1(std::vector<float32> value) { SetSchemaValueCUtlVector<float32>(m_ptr, "PhysFeModelDesc_t", "m_LocalForce", true, value); }
    std::vector<GFeTaperedCapsuleStretch_t> GetTaperedCapsuleStretches() const { CUtlVector<GFeTaperedCapsuleStretch_t>* vec = GetSchemaValue<CUtlVector<GFeTaperedCapsuleStretch_t>*>(m_ptr, "PhysFeModelDesc_t", "m_TaperedCapsuleStretches"); std::vector<GFeTaperedCapsuleStretch_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTaperedCapsuleStretches(std::vector<GFeTaperedCapsuleStretch_t> value) { SetSchemaValueCUtlVector<GFeTaperedCapsuleStretch_t>(m_ptr, "PhysFeModelDesc_t", "m_TaperedCapsuleStretches", true, value); }
    std::vector<GFeTaperedCapsuleRigid_t> GetTaperedCapsuleRigids() const { CUtlVector<GFeTaperedCapsuleRigid_t>* vec = GetSchemaValue<CUtlVector<GFeTaperedCapsuleRigid_t>*>(m_ptr, "PhysFeModelDesc_t", "m_TaperedCapsuleRigids"); std::vector<GFeTaperedCapsuleRigid_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTaperedCapsuleRigids(std::vector<GFeTaperedCapsuleRigid_t> value) { SetSchemaValueCUtlVector<GFeTaperedCapsuleRigid_t>(m_ptr, "PhysFeModelDesc_t", "m_TaperedCapsuleRigids", true, value); }
    std::vector<GFeSphereRigid_t> GetSphereRigids() const { CUtlVector<GFeSphereRigid_t>* vec = GetSchemaValue<CUtlVector<GFeSphereRigid_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SphereRigids"); std::vector<GFeSphereRigid_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSphereRigids(std::vector<GFeSphereRigid_t> value) { SetSchemaValueCUtlVector<GFeSphereRigid_t>(m_ptr, "PhysFeModelDesc_t", "m_SphereRigids", true, value); }
    std::vector<uint16> GetWorldCollisionNodes() const { CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "PhysFeModelDesc_t", "m_WorldCollisionNodes"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetWorldCollisionNodes(std::vector<uint16> value) { SetSchemaValueCUtlVector<uint16>(m_ptr, "PhysFeModelDesc_t", "m_WorldCollisionNodes", true, value); }
    std::vector<uint16> GetTreeParents() const { CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "PhysFeModelDesc_t", "m_TreeParents"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTreeParents(std::vector<uint16> value) { SetSchemaValueCUtlVector<uint16>(m_ptr, "PhysFeModelDesc_t", "m_TreeParents", true, value); }
    std::vector<uint16> GetTreeCollisionMasks() const { CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "PhysFeModelDesc_t", "m_TreeCollisionMasks"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTreeCollisionMasks(std::vector<uint16> value) { SetSchemaValueCUtlVector<uint16>(m_ptr, "PhysFeModelDesc_t", "m_TreeCollisionMasks", true, value); }
    std::vector<GFeTreeChildren_t> GetTreeChildren() const { CUtlVector<GFeTreeChildren_t>* vec = GetSchemaValue<CUtlVector<GFeTreeChildren_t>*>(m_ptr, "PhysFeModelDesc_t", "m_TreeChildren"); std::vector<GFeTreeChildren_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTreeChildren(std::vector<GFeTreeChildren_t> value) { SetSchemaValueCUtlVector<GFeTreeChildren_t>(m_ptr, "PhysFeModelDesc_t", "m_TreeChildren", true, value); }
    std::vector<uint16> GetFreeNodes() const { CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "PhysFeModelDesc_t", "m_FreeNodes"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFreeNodes(std::vector<uint16> value) { SetSchemaValueCUtlVector<uint16>(m_ptr, "PhysFeModelDesc_t", "m_FreeNodes", true, value); }
    std::vector<GFeFitMatrix_t> GetFitMatrices() const { CUtlVector<GFeFitMatrix_t>* vec = GetSchemaValue<CUtlVector<GFeFitMatrix_t>*>(m_ptr, "PhysFeModelDesc_t", "m_FitMatrices"); std::vector<GFeFitMatrix_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFitMatrices(std::vector<GFeFitMatrix_t> value) { SetSchemaValueCUtlVector<GFeFitMatrix_t>(m_ptr, "PhysFeModelDesc_t", "m_FitMatrices", true, value); }
    std::vector<GFeFitWeight_t> GetFitWeights() const { CUtlVector<GFeFitWeight_t>* vec = GetSchemaValue<CUtlVector<GFeFitWeight_t>*>(m_ptr, "PhysFeModelDesc_t", "m_FitWeights"); std::vector<GFeFitWeight_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetFitWeights(std::vector<GFeFitWeight_t> value) { SetSchemaValueCUtlVector<GFeFitWeight_t>(m_ptr, "PhysFeModelDesc_t", "m_FitWeights", true, value); }
    std::vector<GFeNodeReverseOffset_t> GetReverseOffsets() const { CUtlVector<GFeNodeReverseOffset_t>* vec = GetSchemaValue<CUtlVector<GFeNodeReverseOffset_t>*>(m_ptr, "PhysFeModelDesc_t", "m_ReverseOffsets"); std::vector<GFeNodeReverseOffset_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetReverseOffsets(std::vector<GFeNodeReverseOffset_t> value) { SetSchemaValueCUtlVector<GFeNodeReverseOffset_t>(m_ptr, "PhysFeModelDesc_t", "m_ReverseOffsets", true, value); }
    std::vector<GFeAnimStrayRadius_t> GetAnimStrayRadii() const { CUtlVector<GFeAnimStrayRadius_t>* vec = GetSchemaValue<CUtlVector<GFeAnimStrayRadius_t>*>(m_ptr, "PhysFeModelDesc_t", "m_AnimStrayRadii"); std::vector<GFeAnimStrayRadius_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetAnimStrayRadii(std::vector<GFeAnimStrayRadius_t> value) { SetSchemaValueCUtlVector<GFeAnimStrayRadius_t>(m_ptr, "PhysFeModelDesc_t", "m_AnimStrayRadii", true, value); }
    std::vector<GFeSimdAnimStrayRadius_t> GetSimdAnimStrayRadii() const { CUtlVector<GFeSimdAnimStrayRadius_t>* vec = GetSchemaValue<CUtlVector<GFeSimdAnimStrayRadius_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SimdAnimStrayRadii"); std::vector<GFeSimdAnimStrayRadius_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSimdAnimStrayRadii(std::vector<GFeSimdAnimStrayRadius_t> value) { SetSchemaValueCUtlVector<GFeSimdAnimStrayRadius_t>(m_ptr, "PhysFeModelDesc_t", "m_SimdAnimStrayRadii", true, value); }
    std::vector<GFeKelagerBend2_t> GetKelagerBends() const { CUtlVector<GFeKelagerBend2_t>* vec = GetSchemaValue<CUtlVector<GFeKelagerBend2_t>*>(m_ptr, "PhysFeModelDesc_t", "m_KelagerBends"); std::vector<GFeKelagerBend2_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetKelagerBends(std::vector<GFeKelagerBend2_t> value) { SetSchemaValueCUtlVector<GFeKelagerBend2_t>(m_ptr, "PhysFeModelDesc_t", "m_KelagerBends", true, value); }
    std::vector<GFeCtrlSoftOffset_t> GetCtrlSoftOffsets() const { CUtlVector<GFeCtrlSoftOffset_t>* vec = GetSchemaValue<CUtlVector<GFeCtrlSoftOffset_t>*>(m_ptr, "PhysFeModelDesc_t", "m_CtrlSoftOffsets"); std::vector<GFeCtrlSoftOffset_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetCtrlSoftOffsets(std::vector<GFeCtrlSoftOffset_t> value) { SetSchemaValueCUtlVector<GFeCtrlSoftOffset_t>(m_ptr, "PhysFeModelDesc_t", "m_CtrlSoftOffsets", true, value); }
    std::vector<GCFeIndexedJiggleBone> GetJiggleBones() const { CUtlVector<GCFeIndexedJiggleBone>* vec = GetSchemaValue<CUtlVector<GCFeIndexedJiggleBone>*>(m_ptr, "PhysFeModelDesc_t", "m_JiggleBones"); std::vector<GCFeIndexedJiggleBone> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetJiggleBones(std::vector<GCFeIndexedJiggleBone> value) { SetSchemaValueCUtlVector<GCFeIndexedJiggleBone>(m_ptr, "PhysFeModelDesc_t", "m_JiggleBones", true, value); }
    std::vector<uint16> GetSourceElems() const { CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "PhysFeModelDesc_t", "m_SourceElems"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSourceElems(std::vector<uint16> value) { SetSchemaValueCUtlVector<uint16>(m_ptr, "PhysFeModelDesc_t", "m_SourceElems", true, value); }
    std::vector<uint32> GetGoalDampedSpringIntegrators() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "PhysFeModelDesc_t", "m_GoalDampedSpringIntegrators"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetGoalDampedSpringIntegrators(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "PhysFeModelDesc_t", "m_GoalDampedSpringIntegrators", true, value); }
    std::vector<GFeTri_t> GetTris() const { CUtlVector<GFeTri_t>* vec = GetSchemaValue<CUtlVector<GFeTri_t>*>(m_ptr, "PhysFeModelDesc_t", "m_Tris"); std::vector<GFeTri_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetTris(std::vector<GFeTri_t> value) { SetSchemaValueCUtlVector<GFeTri_t>(m_ptr, "PhysFeModelDesc_t", "m_Tris", true, value); }
    uint16_t GetTriCount1() const { return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nTriCount1"); }
    void SetTriCount1(uint16_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nTriCount1", true, value); }
    uint16_t GetTriCount2() const { return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nTriCount2"); }
    void SetTriCount2(uint16_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nTriCount2", true, value); }
    uint8_t GetReservedUint8() const { return GetSchemaValue<uint8_t>(m_ptr, "PhysFeModelDesc_t", "m_nReservedUint8"); }
    void SetReservedUint8(uint8_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nReservedUint8", true, value); }
    uint8_t GetExtraPressureIterations() const { return GetSchemaValue<uint8_t>(m_ptr, "PhysFeModelDesc_t", "m_nExtraPressureIterations"); }
    void SetExtraPressureIterations(uint8_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nExtraPressureIterations", true, value); }
    uint8_t GetExtraGoalIterations() const { return GetSchemaValue<uint8_t>(m_ptr, "PhysFeModelDesc_t", "m_nExtraGoalIterations"); }
    void SetExtraGoalIterations(uint8_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nExtraGoalIterations", true, value); }
    uint8_t GetExtraIterations() const { return GetSchemaValue<uint8_t>(m_ptr, "PhysFeModelDesc_t", "m_nExtraIterations"); }
    void SetExtraIterations(uint8_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nExtraIterations", true, value); }
    std::vector<GFeBoxRigid_t> GetBoxRigids() const { CUtlVector<GFeBoxRigid_t>* vec = GetSchemaValue<CUtlVector<GFeBoxRigid_t>*>(m_ptr, "PhysFeModelDesc_t", "m_BoxRigids"); std::vector<GFeBoxRigid_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetBoxRigids(std::vector<GFeBoxRigid_t> value) { SetSchemaValueCUtlVector<GFeBoxRigid_t>(m_ptr, "PhysFeModelDesc_t", "m_BoxRigids", true, value); }
    std::vector<uint8> GetDynNodeVertexSet() const { CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "PhysFeModelDesc_t", "m_DynNodeVertexSet"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetDynNodeVertexSet(std::vector<uint8> value) { SetSchemaValueCUtlVector<uint8>(m_ptr, "PhysFeModelDesc_t", "m_DynNodeVertexSet", true, value); }
    std::vector<uint32> GetVertexSetNames() const { CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "PhysFeModelDesc_t", "m_VertexSetNames"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetVertexSetNames(std::vector<uint32> value) { SetSchemaValueCUtlVector<uint32>(m_ptr, "PhysFeModelDesc_t", "m_VertexSetNames", true, value); }
    std::vector<GFeRigidColliderIndices_t> GetRigidColliderPriorities() const { CUtlVector<GFeRigidColliderIndices_t>* vec = GetSchemaValue<CUtlVector<GFeRigidColliderIndices_t>*>(m_ptr, "PhysFeModelDesc_t", "m_RigidColliderPriorities"); std::vector<GFeRigidColliderIndices_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetRigidColliderPriorities(std::vector<GFeRigidColliderIndices_t> value) { SetSchemaValueCUtlVector<GFeRigidColliderIndices_t>(m_ptr, "PhysFeModelDesc_t", "m_RigidColliderPriorities", true, value); }
    std::vector<GFeMorphLayerDepr_t> GetMorphLayers() const { CUtlVector<GFeMorphLayerDepr_t>* vec = GetSchemaValue<CUtlVector<GFeMorphLayerDepr_t>*>(m_ptr, "PhysFeModelDesc_t", "m_MorphLayers"); std::vector<GFeMorphLayerDepr_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMorphLayers(std::vector<GFeMorphLayerDepr_t> value) { SetSchemaValueCUtlVector<GFeMorphLayerDepr_t>(m_ptr, "PhysFeModelDesc_t", "m_MorphLayers", true, value); }
    std::vector<uint8> GetMorphSetData() const { CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "PhysFeModelDesc_t", "m_MorphSetData"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetMorphSetData(std::vector<uint8> value) { SetSchemaValueCUtlVector<uint8>(m_ptr, "PhysFeModelDesc_t", "m_MorphSetData", true, value); }
    std::vector<GFeVertexMapDesc_t> GetVertexMaps() const { CUtlVector<GFeVertexMapDesc_t>* vec = GetSchemaValue<CUtlVector<GFeVertexMapDesc_t>*>(m_ptr, "PhysFeModelDesc_t", "m_VertexMaps"); std::vector<GFeVertexMapDesc_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetVertexMaps(std::vector<GFeVertexMapDesc_t> value) { SetSchemaValueCUtlVector<GFeVertexMapDesc_t>(m_ptr, "PhysFeModelDesc_t", "m_VertexMaps", true, value); }
    std::vector<uint8> GetVertexMapValues() const { CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "PhysFeModelDesc_t", "m_VertexMapValues"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetVertexMapValues(std::vector<uint8> value) { SetSchemaValueCUtlVector<uint8>(m_ptr, "PhysFeModelDesc_t", "m_VertexMapValues", true, value); }
    std::vector<GFeEffectDesc_t> GetEffects() const { CUtlVector<GFeEffectDesc_t>* vec = GetSchemaValue<CUtlVector<GFeEffectDesc_t>*>(m_ptr, "PhysFeModelDesc_t", "m_Effects"); std::vector<GFeEffectDesc_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetEffects(std::vector<GFeEffectDesc_t> value) { SetSchemaValueCUtlVector<GFeEffectDesc_t>(m_ptr, "PhysFeModelDesc_t", "m_Effects", true, value); }
    std::vector<GFeCtrlOffset_t> GetLockToParent() const { CUtlVector<GFeCtrlOffset_t>* vec = GetSchemaValue<CUtlVector<GFeCtrlOffset_t>*>(m_ptr, "PhysFeModelDesc_t", "m_LockToParent"); std::vector<GFeCtrlOffset_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLockToParent(std::vector<GFeCtrlOffset_t> value) { SetSchemaValueCUtlVector<GFeCtrlOffset_t>(m_ptr, "PhysFeModelDesc_t", "m_LockToParent", true, value); }
    std::vector<uint16> GetLockToGoal() const { CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "PhysFeModelDesc_t", "m_LockToGoal"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetLockToGoal(std::vector<uint16> value) { SetSchemaValueCUtlVector<uint16>(m_ptr, "PhysFeModelDesc_t", "m_LockToGoal", true, value); }
    std::vector<int16> GetSkelParents() const { CUtlVector<int16>* vec = GetSchemaValue<CUtlVector<int16>*>(m_ptr, "PhysFeModelDesc_t", "m_SkelParents"); std::vector<int16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetSkelParents(std::vector<int16> value) { SetSchemaValueCUtlVector<int16>(m_ptr, "PhysFeModelDesc_t", "m_SkelParents", true, value); }
    std::vector<GFeNodeWindBase_t> GetDynNodeWindBases() const { CUtlVector<GFeNodeWindBase_t>* vec = GetSchemaValue<CUtlVector<GFeNodeWindBase_t>*>(m_ptr, "PhysFeModelDesc_t", "m_DynNodeWindBases"); std::vector<GFeNodeWindBase_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec; }
    void SetDynNodeWindBases(std::vector<GFeNodeWindBase_t> value) { SetSchemaValueCUtlVector<GFeNodeWindBase_t>(m_ptr, "PhysFeModelDesc_t", "m_DynNodeWindBases", true, value); }
    float GetInternalPressure() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flInternalPressure"); }
    void SetInternalPressure(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flInternalPressure", true, value); }
    float GetDefaultTimeDilation() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultTimeDilation"); }
    void SetDefaultTimeDilation(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultTimeDilation", true, value); }
    float GetWindage() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flWindage"); }
    void SetWindage(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flWindage", true, value); }
    float GetWindDrag() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flWindDrag"); }
    void SetWindDrag(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flWindDrag", true, value); }
    float GetDefaultSurfaceStretch() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultSurfaceStretch"); }
    void SetDefaultSurfaceStretch(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultSurfaceStretch", true, value); }
    float GetDefaultThreadStretch() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultThreadStretch"); }
    void SetDefaultThreadStretch(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultThreadStretch", true, value); }
    float GetDefaultGravityScale() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultGravityScale"); }
    void SetDefaultGravityScale(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultGravityScale", true, value); }
    float GetDefaultVelAirDrag() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultVelAirDrag"); }
    void SetDefaultVelAirDrag(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultVelAirDrag", true, value); }
    float GetDefaultExpAirDrag() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultExpAirDrag"); }
    void SetDefaultExpAirDrag(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultExpAirDrag", true, value); }
    float GetDefaultVelQuadAirDrag() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultVelQuadAirDrag"); }
    void SetDefaultVelQuadAirDrag(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultVelQuadAirDrag", true, value); }
    float GetDefaultExpQuadAirDrag() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultExpQuadAirDrag"); }
    void SetDefaultExpQuadAirDrag(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultExpQuadAirDrag", true, value); }
    float GetRodVelocitySmoothRate() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flRodVelocitySmoothRate"); }
    void SetRodVelocitySmoothRate(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flRodVelocitySmoothRate", true, value); }
    float GetQuadVelocitySmoothRate() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flQuadVelocitySmoothRate"); }
    void SetQuadVelocitySmoothRate(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flQuadVelocitySmoothRate", true, value); }
    float GetAddWorldCollisionRadius() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flAddWorldCollisionRadius"); }
    void SetAddWorldCollisionRadius(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flAddWorldCollisionRadius", true, value); }
    float GetDefaultVolumetricSolveAmount() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultVolumetricSolveAmount"); }
    void SetDefaultVolumetricSolveAmount(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultVolumetricSolveAmount", true, value); }
    float GetMotionSmoothCDT() const { return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flMotionSmoothCDT"); }
    void SetMotionSmoothCDT(float value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flMotionSmoothCDT", true, value); }
    uint16_t GetRodVelocitySmoothIterations() const { return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nRodVelocitySmoothIterations"); }
    void SetRodVelocitySmoothIterations(uint16_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nRodVelocitySmoothIterations", true, value); }
    uint16_t GetQuadVelocitySmoothIterations() const { return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nQuadVelocitySmoothIterations"); }
    void SetQuadVelocitySmoothIterations(uint16_t value) { SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nQuadVelocitySmoothIterations", true, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif