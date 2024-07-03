#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPhysFeModelDesc_t::GPhysFeModelDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPhysFeModelDesc_t::GPhysFeModelDesc_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint32> GPhysFeModelDesc_t::GetCtrlHash() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "PhysFeModelDesc_t", "m_CtrlHash"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetCtrlHash(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "PhysFeModelDesc_t", "m_CtrlHash", true, value);
}
std::vector<CUtlString> GPhysFeModelDesc_t::GetCtrlName() const {
    CUtlVector<CUtlString>* vec = GetSchemaValue<CUtlVector<CUtlString>*>(m_ptr, "PhysFeModelDesc_t", "m_CtrlName"); std::vector<CUtlString> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetCtrlName(std::vector<CUtlString> value) {
    SetSchemaValueCUtlVector<CUtlString>(m_ptr, "PhysFeModelDesc_t", "m_CtrlName", true, value);
}
uint32_t GPhysFeModelDesc_t::GetStaticNodeFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "PhysFeModelDesc_t", "m_nStaticNodeFlags");
}
void GPhysFeModelDesc_t::SetStaticNodeFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nStaticNodeFlags", true, value);
}
uint32_t GPhysFeModelDesc_t::GetDynamicNodeFlags() const {
    return GetSchemaValue<uint32_t>(m_ptr, "PhysFeModelDesc_t", "m_nDynamicNodeFlags");
}
void GPhysFeModelDesc_t::SetDynamicNodeFlags(uint32_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nDynamicNodeFlags", true, value);
}
float GPhysFeModelDesc_t::GetLocalForce() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flLocalForce");
}
void GPhysFeModelDesc_t::SetLocalForce(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flLocalForce", true, value);
}
float GPhysFeModelDesc_t::GetLocalRotation() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flLocalRotation");
}
void GPhysFeModelDesc_t::SetLocalRotation(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flLocalRotation", true, value);
}
uint16_t GPhysFeModelDesc_t::GetNodeCount() const {
    return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nNodeCount");
}
void GPhysFeModelDesc_t::SetNodeCount(uint16_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nNodeCount", true, value);
}
uint16_t GPhysFeModelDesc_t::GetStaticNodes() const {
    return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nStaticNodes");
}
void GPhysFeModelDesc_t::SetStaticNodes(uint16_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nStaticNodes", true, value);
}
uint16_t GPhysFeModelDesc_t::GetRotLockStaticNodes() const {
    return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nRotLockStaticNodes");
}
void GPhysFeModelDesc_t::SetRotLockStaticNodes(uint16_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nRotLockStaticNodes", true, value);
}
uint16_t GPhysFeModelDesc_t::GetFirstPositionDrivenNode() const {
    return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nFirstPositionDrivenNode");
}
void GPhysFeModelDesc_t::SetFirstPositionDrivenNode(uint16_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nFirstPositionDrivenNode", true, value);
}
uint16_t GPhysFeModelDesc_t::GetSimdTriCount1() const {
    return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nSimdTriCount1");
}
void GPhysFeModelDesc_t::SetSimdTriCount1(uint16_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nSimdTriCount1", true, value);
}
uint16_t GPhysFeModelDesc_t::GetSimdTriCount2() const {
    return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nSimdTriCount2");
}
void GPhysFeModelDesc_t::SetSimdTriCount2(uint16_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nSimdTriCount2", true, value);
}
uint16_t GPhysFeModelDesc_t::GetSimdQuadCount1() const {
    return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nSimdQuadCount1");
}
void GPhysFeModelDesc_t::SetSimdQuadCount1(uint16_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nSimdQuadCount1", true, value);
}
uint16_t GPhysFeModelDesc_t::GetSimdQuadCount2() const {
    return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nSimdQuadCount2");
}
void GPhysFeModelDesc_t::SetSimdQuadCount2(uint16_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nSimdQuadCount2", true, value);
}
uint16_t GPhysFeModelDesc_t::GetQuadCount1() const {
    return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nQuadCount1");
}
void GPhysFeModelDesc_t::SetQuadCount1(uint16_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nQuadCount1", true, value);
}
uint16_t GPhysFeModelDesc_t::GetQuadCount2() const {
    return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nQuadCount2");
}
void GPhysFeModelDesc_t::SetQuadCount2(uint16_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nQuadCount2", true, value);
}
uint16_t GPhysFeModelDesc_t::GetTreeDepth() const {
    return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nTreeDepth");
}
void GPhysFeModelDesc_t::SetTreeDepth(uint16_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nTreeDepth", true, value);
}
uint16_t GPhysFeModelDesc_t::GetNodeBaseJiggleboneDependsCount() const {
    return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nNodeBaseJiggleboneDependsCount");
}
void GPhysFeModelDesc_t::SetNodeBaseJiggleboneDependsCount(uint16_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nNodeBaseJiggleboneDependsCount", true, value);
}
uint16_t GPhysFeModelDesc_t::GetRopeCount() const {
    return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nRopeCount");
}
void GPhysFeModelDesc_t::SetRopeCount(uint16_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nRopeCount", true, value);
}
std::vector<uint16> GPhysFeModelDesc_t::GetRopes() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "PhysFeModelDesc_t", "m_Ropes"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetRopes(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "PhysFeModelDesc_t", "m_Ropes", true, value);
}
std::vector<GFeNodeBase_t> GPhysFeModelDesc_t::GetNodeBases() const {
    CUtlVector<GFeNodeBase_t>* vec = GetSchemaValue<CUtlVector<GFeNodeBase_t>*>(m_ptr, "PhysFeModelDesc_t", "m_NodeBases"); std::vector<GFeNodeBase_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetNodeBases(std::vector<GFeNodeBase_t> value) {
    SetSchemaValueCUtlVector<GFeNodeBase_t>(m_ptr, "PhysFeModelDesc_t", "m_NodeBases", true, value);
}
std::vector<GFeSimdNodeBase_t> GPhysFeModelDesc_t::GetSimdNodeBases() const {
    CUtlVector<GFeSimdNodeBase_t>* vec = GetSchemaValue<CUtlVector<GFeSimdNodeBase_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SimdNodeBases"); std::vector<GFeSimdNodeBase_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetSimdNodeBases(std::vector<GFeSimdNodeBase_t> value) {
    SetSchemaValueCUtlVector<GFeSimdNodeBase_t>(m_ptr, "PhysFeModelDesc_t", "m_SimdNodeBases", true, value);
}
std::vector<GFeQuad_t> GPhysFeModelDesc_t::GetQuads() const {
    CUtlVector<GFeQuad_t>* vec = GetSchemaValue<CUtlVector<GFeQuad_t>*>(m_ptr, "PhysFeModelDesc_t", "m_Quads"); std::vector<GFeQuad_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetQuads(std::vector<GFeQuad_t> value) {
    SetSchemaValueCUtlVector<GFeQuad_t>(m_ptr, "PhysFeModelDesc_t", "m_Quads", true, value);
}
std::vector<GFeSimdQuad_t> GPhysFeModelDesc_t::GetSimdQuads() const {
    CUtlVector<GFeSimdQuad_t>* vec = GetSchemaValue<CUtlVector<GFeSimdQuad_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SimdQuads"); std::vector<GFeSimdQuad_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetSimdQuads(std::vector<GFeSimdQuad_t> value) {
    SetSchemaValueCUtlVector<GFeSimdQuad_t>(m_ptr, "PhysFeModelDesc_t", "m_SimdQuads", true, value);
}
std::vector<GFeSimdTri_t> GPhysFeModelDesc_t::GetSimdTris() const {
    CUtlVector<GFeSimdTri_t>* vec = GetSchemaValue<CUtlVector<GFeSimdTri_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SimdTris"); std::vector<GFeSimdTri_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetSimdTris(std::vector<GFeSimdTri_t> value) {
    SetSchemaValueCUtlVector<GFeSimdTri_t>(m_ptr, "PhysFeModelDesc_t", "m_SimdTris", true, value);
}
std::vector<GFeSimdRodConstraint_t> GPhysFeModelDesc_t::GetSimdRods() const {
    CUtlVector<GFeSimdRodConstraint_t>* vec = GetSchemaValue<CUtlVector<GFeSimdRodConstraint_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SimdRods"); std::vector<GFeSimdRodConstraint_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetSimdRods(std::vector<GFeSimdRodConstraint_t> value) {
    SetSchemaValueCUtlVector<GFeSimdRodConstraint_t>(m_ptr, "PhysFeModelDesc_t", "m_SimdRods", true, value);
}
std::vector<GFeSimdRodConstraintAnim_t> GPhysFeModelDesc_t::GetSimdRodsAnim() const {
    CUtlVector<GFeSimdRodConstraintAnim_t>* vec = GetSchemaValue<CUtlVector<GFeSimdRodConstraintAnim_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SimdRodsAnim"); std::vector<GFeSimdRodConstraintAnim_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetSimdRodsAnim(std::vector<GFeSimdRodConstraintAnim_t> value) {
    SetSchemaValueCUtlVector<GFeSimdRodConstraintAnim_t>(m_ptr, "PhysFeModelDesc_t", "m_SimdRodsAnim", true, value);
}
std::vector<GFeRodConstraint_t> GPhysFeModelDesc_t::GetRods() const {
    CUtlVector<GFeRodConstraint_t>* vec = GetSchemaValue<CUtlVector<GFeRodConstraint_t>*>(m_ptr, "PhysFeModelDesc_t", "m_Rods"); std::vector<GFeRodConstraint_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetRods(std::vector<GFeRodConstraint_t> value) {
    SetSchemaValueCUtlVector<GFeRodConstraint_t>(m_ptr, "PhysFeModelDesc_t", "m_Rods", true, value);
}
std::vector<GFeTwistConstraint_t> GPhysFeModelDesc_t::GetTwists() const {
    CUtlVector<GFeTwistConstraint_t>* vec = GetSchemaValue<CUtlVector<GFeTwistConstraint_t>*>(m_ptr, "PhysFeModelDesc_t", "m_Twists"); std::vector<GFeTwistConstraint_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetTwists(std::vector<GFeTwistConstraint_t> value) {
    SetSchemaValueCUtlVector<GFeTwistConstraint_t>(m_ptr, "PhysFeModelDesc_t", "m_Twists", true, value);
}
std::vector<GFeAxialEdgeBend_t> GPhysFeModelDesc_t::GetAxialEdges() const {
    CUtlVector<GFeAxialEdgeBend_t>* vec = GetSchemaValue<CUtlVector<GFeAxialEdgeBend_t>*>(m_ptr, "PhysFeModelDesc_t", "m_AxialEdges"); std::vector<GFeAxialEdgeBend_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetAxialEdges(std::vector<GFeAxialEdgeBend_t> value) {
    SetSchemaValueCUtlVector<GFeAxialEdgeBend_t>(m_ptr, "PhysFeModelDesc_t", "m_AxialEdges", true, value);
}
std::vector<float32> GPhysFeModelDesc_t::GetNodeInvMasses() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "PhysFeModelDesc_t", "m_NodeInvMasses"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetNodeInvMasses(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "PhysFeModelDesc_t", "m_NodeInvMasses", true, value);
}
std::vector<GFeCtrlOffset_t> GPhysFeModelDesc_t::GetCtrlOffsets() const {
    CUtlVector<GFeCtrlOffset_t>* vec = GetSchemaValue<CUtlVector<GFeCtrlOffset_t>*>(m_ptr, "PhysFeModelDesc_t", "m_CtrlOffsets"); std::vector<GFeCtrlOffset_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetCtrlOffsets(std::vector<GFeCtrlOffset_t> value) {
    SetSchemaValueCUtlVector<GFeCtrlOffset_t>(m_ptr, "PhysFeModelDesc_t", "m_CtrlOffsets", true, value);
}
std::vector<GFeCtrlOsOffset_t> GPhysFeModelDesc_t::GetCtrlOsOffsets() const {
    CUtlVector<GFeCtrlOsOffset_t>* vec = GetSchemaValue<CUtlVector<GFeCtrlOsOffset_t>*>(m_ptr, "PhysFeModelDesc_t", "m_CtrlOsOffsets"); std::vector<GFeCtrlOsOffset_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetCtrlOsOffsets(std::vector<GFeCtrlOsOffset_t> value) {
    SetSchemaValueCUtlVector<GFeCtrlOsOffset_t>(m_ptr, "PhysFeModelDesc_t", "m_CtrlOsOffsets", true, value);
}
std::vector<GFeFollowNode_t> GPhysFeModelDesc_t::GetFollowNodes() const {
    CUtlVector<GFeFollowNode_t>* vec = GetSchemaValue<CUtlVector<GFeFollowNode_t>*>(m_ptr, "PhysFeModelDesc_t", "m_FollowNodes"); std::vector<GFeFollowNode_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetFollowNodes(std::vector<GFeFollowNode_t> value) {
    SetSchemaValueCUtlVector<GFeFollowNode_t>(m_ptr, "PhysFeModelDesc_t", "m_FollowNodes", true, value);
}
std::vector<GFeCollisionPlane_t> GPhysFeModelDesc_t::GetCollisionPlanes() const {
    CUtlVector<GFeCollisionPlane_t>* vec = GetSchemaValue<CUtlVector<GFeCollisionPlane_t>*>(m_ptr, "PhysFeModelDesc_t", "m_CollisionPlanes"); std::vector<GFeCollisionPlane_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetCollisionPlanes(std::vector<GFeCollisionPlane_t> value) {
    SetSchemaValueCUtlVector<GFeCollisionPlane_t>(m_ptr, "PhysFeModelDesc_t", "m_CollisionPlanes", true, value);
}
std::vector<GFeNodeIntegrator_t> GPhysFeModelDesc_t::GetNodeIntegrator() const {
    CUtlVector<GFeNodeIntegrator_t>* vec = GetSchemaValue<CUtlVector<GFeNodeIntegrator_t>*>(m_ptr, "PhysFeModelDesc_t", "m_NodeIntegrator"); std::vector<GFeNodeIntegrator_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetNodeIntegrator(std::vector<GFeNodeIntegrator_t> value) {
    SetSchemaValueCUtlVector<GFeNodeIntegrator_t>(m_ptr, "PhysFeModelDesc_t", "m_NodeIntegrator", true, value);
}
std::vector<GFeSpringIntegrator_t> GPhysFeModelDesc_t::GetSpringIntegrator() const {
    CUtlVector<GFeSpringIntegrator_t>* vec = GetSchemaValue<CUtlVector<GFeSpringIntegrator_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SpringIntegrator"); std::vector<GFeSpringIntegrator_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetSpringIntegrator(std::vector<GFeSpringIntegrator_t> value) {
    SetSchemaValueCUtlVector<GFeSpringIntegrator_t>(m_ptr, "PhysFeModelDesc_t", "m_SpringIntegrator", true, value);
}
std::vector<GFeSimdSpringIntegrator_t> GPhysFeModelDesc_t::GetSimdSpringIntegrator() const {
    CUtlVector<GFeSimdSpringIntegrator_t>* vec = GetSchemaValue<CUtlVector<GFeSimdSpringIntegrator_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SimdSpringIntegrator"); std::vector<GFeSimdSpringIntegrator_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetSimdSpringIntegrator(std::vector<GFeSimdSpringIntegrator_t> value) {
    SetSchemaValueCUtlVector<GFeSimdSpringIntegrator_t>(m_ptr, "PhysFeModelDesc_t", "m_SimdSpringIntegrator", true, value);
}
std::vector<GFeWorldCollisionParams_t> GPhysFeModelDesc_t::GetWorldCollisionParams() const {
    CUtlVector<GFeWorldCollisionParams_t>* vec = GetSchemaValue<CUtlVector<GFeWorldCollisionParams_t>*>(m_ptr, "PhysFeModelDesc_t", "m_WorldCollisionParams"); std::vector<GFeWorldCollisionParams_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetWorldCollisionParams(std::vector<GFeWorldCollisionParams_t> value) {
    SetSchemaValueCUtlVector<GFeWorldCollisionParams_t>(m_ptr, "PhysFeModelDesc_t", "m_WorldCollisionParams", true, value);
}
std::vector<float32> GPhysFeModelDesc_t::GetLegacyStretchForce() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "PhysFeModelDesc_t", "m_LegacyStretchForce"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetLegacyStretchForce(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "PhysFeModelDesc_t", "m_LegacyStretchForce", true, value);
}
std::vector<float32> GPhysFeModelDesc_t::GetNodeCollisionRadii() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "PhysFeModelDesc_t", "m_NodeCollisionRadii"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetNodeCollisionRadii(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "PhysFeModelDesc_t", "m_NodeCollisionRadii", true, value);
}
std::vector<float32> GPhysFeModelDesc_t::GetDynNodeFriction() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "PhysFeModelDesc_t", "m_DynNodeFriction"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetDynNodeFriction(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "PhysFeModelDesc_t", "m_DynNodeFriction", true, value);
}
std::vector<float32> GPhysFeModelDesc_t::GetLocalRotation1() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "PhysFeModelDesc_t", "m_LocalRotation"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetLocalRotation1(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "PhysFeModelDesc_t", "m_LocalRotation", true, value);
}
std::vector<float32> GPhysFeModelDesc_t::GetLocalForce1() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "PhysFeModelDesc_t", "m_LocalForce"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetLocalForce1(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "PhysFeModelDesc_t", "m_LocalForce", true, value);
}
std::vector<GFeTaperedCapsuleStretch_t> GPhysFeModelDesc_t::GetTaperedCapsuleStretches() const {
    CUtlVector<GFeTaperedCapsuleStretch_t>* vec = GetSchemaValue<CUtlVector<GFeTaperedCapsuleStretch_t>*>(m_ptr, "PhysFeModelDesc_t", "m_TaperedCapsuleStretches"); std::vector<GFeTaperedCapsuleStretch_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetTaperedCapsuleStretches(std::vector<GFeTaperedCapsuleStretch_t> value) {
    SetSchemaValueCUtlVector<GFeTaperedCapsuleStretch_t>(m_ptr, "PhysFeModelDesc_t", "m_TaperedCapsuleStretches", true, value);
}
std::vector<GFeTaperedCapsuleRigid_t> GPhysFeModelDesc_t::GetTaperedCapsuleRigids() const {
    CUtlVector<GFeTaperedCapsuleRigid_t>* vec = GetSchemaValue<CUtlVector<GFeTaperedCapsuleRigid_t>*>(m_ptr, "PhysFeModelDesc_t", "m_TaperedCapsuleRigids"); std::vector<GFeTaperedCapsuleRigid_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetTaperedCapsuleRigids(std::vector<GFeTaperedCapsuleRigid_t> value) {
    SetSchemaValueCUtlVector<GFeTaperedCapsuleRigid_t>(m_ptr, "PhysFeModelDesc_t", "m_TaperedCapsuleRigids", true, value);
}
std::vector<GFeSphereRigid_t> GPhysFeModelDesc_t::GetSphereRigids() const {
    CUtlVector<GFeSphereRigid_t>* vec = GetSchemaValue<CUtlVector<GFeSphereRigid_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SphereRigids"); std::vector<GFeSphereRigid_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetSphereRigids(std::vector<GFeSphereRigid_t> value) {
    SetSchemaValueCUtlVector<GFeSphereRigid_t>(m_ptr, "PhysFeModelDesc_t", "m_SphereRigids", true, value);
}
std::vector<uint16> GPhysFeModelDesc_t::GetWorldCollisionNodes() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "PhysFeModelDesc_t", "m_WorldCollisionNodes"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetWorldCollisionNodes(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "PhysFeModelDesc_t", "m_WorldCollisionNodes", true, value);
}
std::vector<uint16> GPhysFeModelDesc_t::GetTreeParents() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "PhysFeModelDesc_t", "m_TreeParents"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetTreeParents(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "PhysFeModelDesc_t", "m_TreeParents", true, value);
}
std::vector<uint16> GPhysFeModelDesc_t::GetTreeCollisionMasks() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "PhysFeModelDesc_t", "m_TreeCollisionMasks"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetTreeCollisionMasks(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "PhysFeModelDesc_t", "m_TreeCollisionMasks", true, value);
}
std::vector<GFeTreeChildren_t> GPhysFeModelDesc_t::GetTreeChildren() const {
    CUtlVector<GFeTreeChildren_t>* vec = GetSchemaValue<CUtlVector<GFeTreeChildren_t>*>(m_ptr, "PhysFeModelDesc_t", "m_TreeChildren"); std::vector<GFeTreeChildren_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetTreeChildren(std::vector<GFeTreeChildren_t> value) {
    SetSchemaValueCUtlVector<GFeTreeChildren_t>(m_ptr, "PhysFeModelDesc_t", "m_TreeChildren", true, value);
}
std::vector<uint16> GPhysFeModelDesc_t::GetFreeNodes() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "PhysFeModelDesc_t", "m_FreeNodes"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetFreeNodes(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "PhysFeModelDesc_t", "m_FreeNodes", true, value);
}
std::vector<GFeFitMatrix_t> GPhysFeModelDesc_t::GetFitMatrices() const {
    CUtlVector<GFeFitMatrix_t>* vec = GetSchemaValue<CUtlVector<GFeFitMatrix_t>*>(m_ptr, "PhysFeModelDesc_t", "m_FitMatrices"); std::vector<GFeFitMatrix_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetFitMatrices(std::vector<GFeFitMatrix_t> value) {
    SetSchemaValueCUtlVector<GFeFitMatrix_t>(m_ptr, "PhysFeModelDesc_t", "m_FitMatrices", true, value);
}
std::vector<GFeFitWeight_t> GPhysFeModelDesc_t::GetFitWeights() const {
    CUtlVector<GFeFitWeight_t>* vec = GetSchemaValue<CUtlVector<GFeFitWeight_t>*>(m_ptr, "PhysFeModelDesc_t", "m_FitWeights"); std::vector<GFeFitWeight_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetFitWeights(std::vector<GFeFitWeight_t> value) {
    SetSchemaValueCUtlVector<GFeFitWeight_t>(m_ptr, "PhysFeModelDesc_t", "m_FitWeights", true, value);
}
std::vector<GFeNodeReverseOffset_t> GPhysFeModelDesc_t::GetReverseOffsets() const {
    CUtlVector<GFeNodeReverseOffset_t>* vec = GetSchemaValue<CUtlVector<GFeNodeReverseOffset_t>*>(m_ptr, "PhysFeModelDesc_t", "m_ReverseOffsets"); std::vector<GFeNodeReverseOffset_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetReverseOffsets(std::vector<GFeNodeReverseOffset_t> value) {
    SetSchemaValueCUtlVector<GFeNodeReverseOffset_t>(m_ptr, "PhysFeModelDesc_t", "m_ReverseOffsets", true, value);
}
std::vector<GFeAnimStrayRadius_t> GPhysFeModelDesc_t::GetAnimStrayRadii() const {
    CUtlVector<GFeAnimStrayRadius_t>* vec = GetSchemaValue<CUtlVector<GFeAnimStrayRadius_t>*>(m_ptr, "PhysFeModelDesc_t", "m_AnimStrayRadii"); std::vector<GFeAnimStrayRadius_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetAnimStrayRadii(std::vector<GFeAnimStrayRadius_t> value) {
    SetSchemaValueCUtlVector<GFeAnimStrayRadius_t>(m_ptr, "PhysFeModelDesc_t", "m_AnimStrayRadii", true, value);
}
std::vector<GFeSimdAnimStrayRadius_t> GPhysFeModelDesc_t::GetSimdAnimStrayRadii() const {
    CUtlVector<GFeSimdAnimStrayRadius_t>* vec = GetSchemaValue<CUtlVector<GFeSimdAnimStrayRadius_t>*>(m_ptr, "PhysFeModelDesc_t", "m_SimdAnimStrayRadii"); std::vector<GFeSimdAnimStrayRadius_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetSimdAnimStrayRadii(std::vector<GFeSimdAnimStrayRadius_t> value) {
    SetSchemaValueCUtlVector<GFeSimdAnimStrayRadius_t>(m_ptr, "PhysFeModelDesc_t", "m_SimdAnimStrayRadii", true, value);
}
std::vector<GFeKelagerBend2_t> GPhysFeModelDesc_t::GetKelagerBends() const {
    CUtlVector<GFeKelagerBend2_t>* vec = GetSchemaValue<CUtlVector<GFeKelagerBend2_t>*>(m_ptr, "PhysFeModelDesc_t", "m_KelagerBends"); std::vector<GFeKelagerBend2_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetKelagerBends(std::vector<GFeKelagerBend2_t> value) {
    SetSchemaValueCUtlVector<GFeKelagerBend2_t>(m_ptr, "PhysFeModelDesc_t", "m_KelagerBends", true, value);
}
std::vector<GFeCtrlSoftOffset_t> GPhysFeModelDesc_t::GetCtrlSoftOffsets() const {
    CUtlVector<GFeCtrlSoftOffset_t>* vec = GetSchemaValue<CUtlVector<GFeCtrlSoftOffset_t>*>(m_ptr, "PhysFeModelDesc_t", "m_CtrlSoftOffsets"); std::vector<GFeCtrlSoftOffset_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetCtrlSoftOffsets(std::vector<GFeCtrlSoftOffset_t> value) {
    SetSchemaValueCUtlVector<GFeCtrlSoftOffset_t>(m_ptr, "PhysFeModelDesc_t", "m_CtrlSoftOffsets", true, value);
}
std::vector<GCFeIndexedJiggleBone> GPhysFeModelDesc_t::GetJiggleBones() const {
    CUtlVector<GCFeIndexedJiggleBone>* vec = GetSchemaValue<CUtlVector<GCFeIndexedJiggleBone>*>(m_ptr, "PhysFeModelDesc_t", "m_JiggleBones"); std::vector<GCFeIndexedJiggleBone> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetJiggleBones(std::vector<GCFeIndexedJiggleBone> value) {
    SetSchemaValueCUtlVector<GCFeIndexedJiggleBone>(m_ptr, "PhysFeModelDesc_t", "m_JiggleBones", true, value);
}
std::vector<uint16> GPhysFeModelDesc_t::GetSourceElems() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "PhysFeModelDesc_t", "m_SourceElems"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetSourceElems(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "PhysFeModelDesc_t", "m_SourceElems", true, value);
}
std::vector<uint32> GPhysFeModelDesc_t::GetGoalDampedSpringIntegrators() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "PhysFeModelDesc_t", "m_GoalDampedSpringIntegrators"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetGoalDampedSpringIntegrators(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "PhysFeModelDesc_t", "m_GoalDampedSpringIntegrators", true, value);
}
std::vector<GFeTri_t> GPhysFeModelDesc_t::GetTris() const {
    CUtlVector<GFeTri_t>* vec = GetSchemaValue<CUtlVector<GFeTri_t>*>(m_ptr, "PhysFeModelDesc_t", "m_Tris"); std::vector<GFeTri_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetTris(std::vector<GFeTri_t> value) {
    SetSchemaValueCUtlVector<GFeTri_t>(m_ptr, "PhysFeModelDesc_t", "m_Tris", true, value);
}
uint16_t GPhysFeModelDesc_t::GetTriCount1() const {
    return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nTriCount1");
}
void GPhysFeModelDesc_t::SetTriCount1(uint16_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nTriCount1", true, value);
}
uint16_t GPhysFeModelDesc_t::GetTriCount2() const {
    return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nTriCount2");
}
void GPhysFeModelDesc_t::SetTriCount2(uint16_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nTriCount2", true, value);
}
uint8_t GPhysFeModelDesc_t::GetReservedUint8() const {
    return GetSchemaValue<uint8_t>(m_ptr, "PhysFeModelDesc_t", "m_nReservedUint8");
}
void GPhysFeModelDesc_t::SetReservedUint8(uint8_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nReservedUint8", true, value);
}
uint8_t GPhysFeModelDesc_t::GetExtraPressureIterations() const {
    return GetSchemaValue<uint8_t>(m_ptr, "PhysFeModelDesc_t", "m_nExtraPressureIterations");
}
void GPhysFeModelDesc_t::SetExtraPressureIterations(uint8_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nExtraPressureIterations", true, value);
}
uint8_t GPhysFeModelDesc_t::GetExtraGoalIterations() const {
    return GetSchemaValue<uint8_t>(m_ptr, "PhysFeModelDesc_t", "m_nExtraGoalIterations");
}
void GPhysFeModelDesc_t::SetExtraGoalIterations(uint8_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nExtraGoalIterations", true, value);
}
uint8_t GPhysFeModelDesc_t::GetExtraIterations() const {
    return GetSchemaValue<uint8_t>(m_ptr, "PhysFeModelDesc_t", "m_nExtraIterations");
}
void GPhysFeModelDesc_t::SetExtraIterations(uint8_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nExtraIterations", true, value);
}
std::vector<GFeBoxRigid_t> GPhysFeModelDesc_t::GetBoxRigids() const {
    CUtlVector<GFeBoxRigid_t>* vec = GetSchemaValue<CUtlVector<GFeBoxRigid_t>*>(m_ptr, "PhysFeModelDesc_t", "m_BoxRigids"); std::vector<GFeBoxRigid_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetBoxRigids(std::vector<GFeBoxRigid_t> value) {
    SetSchemaValueCUtlVector<GFeBoxRigid_t>(m_ptr, "PhysFeModelDesc_t", "m_BoxRigids", true, value);
}
std::vector<uint8> GPhysFeModelDesc_t::GetDynNodeVertexSet() const {
    CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "PhysFeModelDesc_t", "m_DynNodeVertexSet"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetDynNodeVertexSet(std::vector<uint8> value) {
    SetSchemaValueCUtlVector<uint8>(m_ptr, "PhysFeModelDesc_t", "m_DynNodeVertexSet", true, value);
}
std::vector<uint32> GPhysFeModelDesc_t::GetVertexSetNames() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "PhysFeModelDesc_t", "m_VertexSetNames"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetVertexSetNames(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "PhysFeModelDesc_t", "m_VertexSetNames", true, value);
}
std::vector<GFeRigidColliderIndices_t> GPhysFeModelDesc_t::GetRigidColliderPriorities() const {
    CUtlVector<GFeRigidColliderIndices_t>* vec = GetSchemaValue<CUtlVector<GFeRigidColliderIndices_t>*>(m_ptr, "PhysFeModelDesc_t", "m_RigidColliderPriorities"); std::vector<GFeRigidColliderIndices_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetRigidColliderPriorities(std::vector<GFeRigidColliderIndices_t> value) {
    SetSchemaValueCUtlVector<GFeRigidColliderIndices_t>(m_ptr, "PhysFeModelDesc_t", "m_RigidColliderPriorities", true, value);
}
std::vector<GFeMorphLayerDepr_t> GPhysFeModelDesc_t::GetMorphLayers() const {
    CUtlVector<GFeMorphLayerDepr_t>* vec = GetSchemaValue<CUtlVector<GFeMorphLayerDepr_t>*>(m_ptr, "PhysFeModelDesc_t", "m_MorphLayers"); std::vector<GFeMorphLayerDepr_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetMorphLayers(std::vector<GFeMorphLayerDepr_t> value) {
    SetSchemaValueCUtlVector<GFeMorphLayerDepr_t>(m_ptr, "PhysFeModelDesc_t", "m_MorphLayers", true, value);
}
std::vector<uint8> GPhysFeModelDesc_t::GetMorphSetData() const {
    CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "PhysFeModelDesc_t", "m_MorphSetData"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetMorphSetData(std::vector<uint8> value) {
    SetSchemaValueCUtlVector<uint8>(m_ptr, "PhysFeModelDesc_t", "m_MorphSetData", true, value);
}
std::vector<GFeVertexMapDesc_t> GPhysFeModelDesc_t::GetVertexMaps() const {
    CUtlVector<GFeVertexMapDesc_t>* vec = GetSchemaValue<CUtlVector<GFeVertexMapDesc_t>*>(m_ptr, "PhysFeModelDesc_t", "m_VertexMaps"); std::vector<GFeVertexMapDesc_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetVertexMaps(std::vector<GFeVertexMapDesc_t> value) {
    SetSchemaValueCUtlVector<GFeVertexMapDesc_t>(m_ptr, "PhysFeModelDesc_t", "m_VertexMaps", true, value);
}
std::vector<uint8> GPhysFeModelDesc_t::GetVertexMapValues() const {
    CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "PhysFeModelDesc_t", "m_VertexMapValues"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetVertexMapValues(std::vector<uint8> value) {
    SetSchemaValueCUtlVector<uint8>(m_ptr, "PhysFeModelDesc_t", "m_VertexMapValues", true, value);
}
std::vector<GFeEffectDesc_t> GPhysFeModelDesc_t::GetEffects() const {
    CUtlVector<GFeEffectDesc_t>* vec = GetSchemaValue<CUtlVector<GFeEffectDesc_t>*>(m_ptr, "PhysFeModelDesc_t", "m_Effects"); std::vector<GFeEffectDesc_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetEffects(std::vector<GFeEffectDesc_t> value) {
    SetSchemaValueCUtlVector<GFeEffectDesc_t>(m_ptr, "PhysFeModelDesc_t", "m_Effects", true, value);
}
std::vector<GFeCtrlOffset_t> GPhysFeModelDesc_t::GetLockToParent() const {
    CUtlVector<GFeCtrlOffset_t>* vec = GetSchemaValue<CUtlVector<GFeCtrlOffset_t>*>(m_ptr, "PhysFeModelDesc_t", "m_LockToParent"); std::vector<GFeCtrlOffset_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetLockToParent(std::vector<GFeCtrlOffset_t> value) {
    SetSchemaValueCUtlVector<GFeCtrlOffset_t>(m_ptr, "PhysFeModelDesc_t", "m_LockToParent", true, value);
}
std::vector<uint16> GPhysFeModelDesc_t::GetLockToGoal() const {
    CUtlVector<uint16>* vec = GetSchemaValue<CUtlVector<uint16>*>(m_ptr, "PhysFeModelDesc_t", "m_LockToGoal"); std::vector<uint16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetLockToGoal(std::vector<uint16> value) {
    SetSchemaValueCUtlVector<uint16>(m_ptr, "PhysFeModelDesc_t", "m_LockToGoal", true, value);
}
std::vector<int16> GPhysFeModelDesc_t::GetSkelParents() const {
    CUtlVector<int16>* vec = GetSchemaValue<CUtlVector<int16>*>(m_ptr, "PhysFeModelDesc_t", "m_SkelParents"); std::vector<int16> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetSkelParents(std::vector<int16> value) {
    SetSchemaValueCUtlVector<int16>(m_ptr, "PhysFeModelDesc_t", "m_SkelParents", true, value);
}
std::vector<GFeNodeWindBase_t> GPhysFeModelDesc_t::GetDynNodeWindBases() const {
    CUtlVector<GFeNodeWindBase_t>* vec = GetSchemaValue<CUtlVector<GFeNodeWindBase_t>*>(m_ptr, "PhysFeModelDesc_t", "m_DynNodeWindBases"); std::vector<GFeNodeWindBase_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GPhysFeModelDesc_t::SetDynNodeWindBases(std::vector<GFeNodeWindBase_t> value) {
    SetSchemaValueCUtlVector<GFeNodeWindBase_t>(m_ptr, "PhysFeModelDesc_t", "m_DynNodeWindBases", true, value);
}
float GPhysFeModelDesc_t::GetInternalPressure() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flInternalPressure");
}
void GPhysFeModelDesc_t::SetInternalPressure(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flInternalPressure", true, value);
}
float GPhysFeModelDesc_t::GetDefaultTimeDilation() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultTimeDilation");
}
void GPhysFeModelDesc_t::SetDefaultTimeDilation(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultTimeDilation", true, value);
}
float GPhysFeModelDesc_t::GetWindage() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flWindage");
}
void GPhysFeModelDesc_t::SetWindage(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flWindage", true, value);
}
float GPhysFeModelDesc_t::GetWindDrag() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flWindDrag");
}
void GPhysFeModelDesc_t::SetWindDrag(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flWindDrag", true, value);
}
float GPhysFeModelDesc_t::GetDefaultSurfaceStretch() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultSurfaceStretch");
}
void GPhysFeModelDesc_t::SetDefaultSurfaceStretch(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultSurfaceStretch", true, value);
}
float GPhysFeModelDesc_t::GetDefaultThreadStretch() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultThreadStretch");
}
void GPhysFeModelDesc_t::SetDefaultThreadStretch(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultThreadStretch", true, value);
}
float GPhysFeModelDesc_t::GetDefaultGravityScale() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultGravityScale");
}
void GPhysFeModelDesc_t::SetDefaultGravityScale(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultGravityScale", true, value);
}
float GPhysFeModelDesc_t::GetDefaultVelAirDrag() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultVelAirDrag");
}
void GPhysFeModelDesc_t::SetDefaultVelAirDrag(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultVelAirDrag", true, value);
}
float GPhysFeModelDesc_t::GetDefaultExpAirDrag() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultExpAirDrag");
}
void GPhysFeModelDesc_t::SetDefaultExpAirDrag(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultExpAirDrag", true, value);
}
float GPhysFeModelDesc_t::GetDefaultVelQuadAirDrag() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultVelQuadAirDrag");
}
void GPhysFeModelDesc_t::SetDefaultVelQuadAirDrag(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultVelQuadAirDrag", true, value);
}
float GPhysFeModelDesc_t::GetDefaultExpQuadAirDrag() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultExpQuadAirDrag");
}
void GPhysFeModelDesc_t::SetDefaultExpQuadAirDrag(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultExpQuadAirDrag", true, value);
}
float GPhysFeModelDesc_t::GetRodVelocitySmoothRate() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flRodVelocitySmoothRate");
}
void GPhysFeModelDesc_t::SetRodVelocitySmoothRate(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flRodVelocitySmoothRate", true, value);
}
float GPhysFeModelDesc_t::GetQuadVelocitySmoothRate() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flQuadVelocitySmoothRate");
}
void GPhysFeModelDesc_t::SetQuadVelocitySmoothRate(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flQuadVelocitySmoothRate", true, value);
}
float GPhysFeModelDesc_t::GetAddWorldCollisionRadius() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flAddWorldCollisionRadius");
}
void GPhysFeModelDesc_t::SetAddWorldCollisionRadius(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flAddWorldCollisionRadius", true, value);
}
float GPhysFeModelDesc_t::GetDefaultVolumetricSolveAmount() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flDefaultVolumetricSolveAmount");
}
void GPhysFeModelDesc_t::SetDefaultVolumetricSolveAmount(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flDefaultVolumetricSolveAmount", true, value);
}
float GPhysFeModelDesc_t::GetMotionSmoothCDT() const {
    return GetSchemaValue<float>(m_ptr, "PhysFeModelDesc_t", "m_flMotionSmoothCDT");
}
void GPhysFeModelDesc_t::SetMotionSmoothCDT(float value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_flMotionSmoothCDT", true, value);
}
uint16_t GPhysFeModelDesc_t::GetRodVelocitySmoothIterations() const {
    return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nRodVelocitySmoothIterations");
}
void GPhysFeModelDesc_t::SetRodVelocitySmoothIterations(uint16_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nRodVelocitySmoothIterations", true, value);
}
uint16_t GPhysFeModelDesc_t::GetQuadVelocitySmoothIterations() const {
    return GetSchemaValue<uint16_t>(m_ptr, "PhysFeModelDesc_t", "m_nQuadVelocitySmoothIterations");
}
void GPhysFeModelDesc_t::SetQuadVelocitySmoothIterations(uint16_t value) {
    SetSchemaValue(m_ptr, "PhysFeModelDesc_t", "m_nQuadVelocitySmoothIterations", true, value);
}
std::string GPhysFeModelDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPhysFeModelDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassPhysFeModelDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPhysFeModelDesc_t>("PhysFeModelDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CtrlHash", &GPhysFeModelDesc_t::GetCtrlHash, &GPhysFeModelDesc_t::SetCtrlHash)
        .addProperty("CtrlName", &GPhysFeModelDesc_t::GetCtrlName, &GPhysFeModelDesc_t::SetCtrlName)
        .addProperty("StaticNodeFlags", &GPhysFeModelDesc_t::GetStaticNodeFlags, &GPhysFeModelDesc_t::SetStaticNodeFlags)
        .addProperty("DynamicNodeFlags", &GPhysFeModelDesc_t::GetDynamicNodeFlags, &GPhysFeModelDesc_t::SetDynamicNodeFlags)
        .addProperty("LocalForce", &GPhysFeModelDesc_t::GetLocalForce, &GPhysFeModelDesc_t::SetLocalForce)
        .addProperty("LocalRotation", &GPhysFeModelDesc_t::GetLocalRotation, &GPhysFeModelDesc_t::SetLocalRotation)
        .addProperty("NodeCount", &GPhysFeModelDesc_t::GetNodeCount, &GPhysFeModelDesc_t::SetNodeCount)
        .addProperty("StaticNodes", &GPhysFeModelDesc_t::GetStaticNodes, &GPhysFeModelDesc_t::SetStaticNodes)
        .addProperty("RotLockStaticNodes", &GPhysFeModelDesc_t::GetRotLockStaticNodes, &GPhysFeModelDesc_t::SetRotLockStaticNodes)
        .addProperty("FirstPositionDrivenNode", &GPhysFeModelDesc_t::GetFirstPositionDrivenNode, &GPhysFeModelDesc_t::SetFirstPositionDrivenNode)
        .addProperty("SimdTriCount1", &GPhysFeModelDesc_t::GetSimdTriCount1, &GPhysFeModelDesc_t::SetSimdTriCount1)
        .addProperty("SimdTriCount2", &GPhysFeModelDesc_t::GetSimdTriCount2, &GPhysFeModelDesc_t::SetSimdTriCount2)
        .addProperty("SimdQuadCount1", &GPhysFeModelDesc_t::GetSimdQuadCount1, &GPhysFeModelDesc_t::SetSimdQuadCount1)
        .addProperty("SimdQuadCount2", &GPhysFeModelDesc_t::GetSimdQuadCount2, &GPhysFeModelDesc_t::SetSimdQuadCount2)
        .addProperty("QuadCount1", &GPhysFeModelDesc_t::GetQuadCount1, &GPhysFeModelDesc_t::SetQuadCount1)
        .addProperty("QuadCount2", &GPhysFeModelDesc_t::GetQuadCount2, &GPhysFeModelDesc_t::SetQuadCount2)
        .addProperty("TreeDepth", &GPhysFeModelDesc_t::GetTreeDepth, &GPhysFeModelDesc_t::SetTreeDepth)
        .addProperty("NodeBaseJiggleboneDependsCount", &GPhysFeModelDesc_t::GetNodeBaseJiggleboneDependsCount, &GPhysFeModelDesc_t::SetNodeBaseJiggleboneDependsCount)
        .addProperty("RopeCount", &GPhysFeModelDesc_t::GetRopeCount, &GPhysFeModelDesc_t::SetRopeCount)
        .addProperty("Ropes", &GPhysFeModelDesc_t::GetRopes, &GPhysFeModelDesc_t::SetRopes)
        .addProperty("NodeBases", &GPhysFeModelDesc_t::GetNodeBases, &GPhysFeModelDesc_t::SetNodeBases)
        .addProperty("SimdNodeBases", &GPhysFeModelDesc_t::GetSimdNodeBases, &GPhysFeModelDesc_t::SetSimdNodeBases)
        .addProperty("Quads", &GPhysFeModelDesc_t::GetQuads, &GPhysFeModelDesc_t::SetQuads)
        .addProperty("SimdQuads", &GPhysFeModelDesc_t::GetSimdQuads, &GPhysFeModelDesc_t::SetSimdQuads)
        .addProperty("SimdTris", &GPhysFeModelDesc_t::GetSimdTris, &GPhysFeModelDesc_t::SetSimdTris)
        .addProperty("SimdRods", &GPhysFeModelDesc_t::GetSimdRods, &GPhysFeModelDesc_t::SetSimdRods)
        .addProperty("SimdRodsAnim", &GPhysFeModelDesc_t::GetSimdRodsAnim, &GPhysFeModelDesc_t::SetSimdRodsAnim)
        .addProperty("Rods", &GPhysFeModelDesc_t::GetRods, &GPhysFeModelDesc_t::SetRods)
        .addProperty("Twists", &GPhysFeModelDesc_t::GetTwists, &GPhysFeModelDesc_t::SetTwists)
        .addProperty("AxialEdges", &GPhysFeModelDesc_t::GetAxialEdges, &GPhysFeModelDesc_t::SetAxialEdges)
        .addProperty("NodeInvMasses", &GPhysFeModelDesc_t::GetNodeInvMasses, &GPhysFeModelDesc_t::SetNodeInvMasses)
        .addProperty("CtrlOffsets", &GPhysFeModelDesc_t::GetCtrlOffsets, &GPhysFeModelDesc_t::SetCtrlOffsets)
        .addProperty("CtrlOsOffsets", &GPhysFeModelDesc_t::GetCtrlOsOffsets, &GPhysFeModelDesc_t::SetCtrlOsOffsets)
        .addProperty("FollowNodes", &GPhysFeModelDesc_t::GetFollowNodes, &GPhysFeModelDesc_t::SetFollowNodes)
        .addProperty("CollisionPlanes", &GPhysFeModelDesc_t::GetCollisionPlanes, &GPhysFeModelDesc_t::SetCollisionPlanes)
        .addProperty("NodeIntegrator", &GPhysFeModelDesc_t::GetNodeIntegrator, &GPhysFeModelDesc_t::SetNodeIntegrator)
        .addProperty("SpringIntegrator", &GPhysFeModelDesc_t::GetSpringIntegrator, &GPhysFeModelDesc_t::SetSpringIntegrator)
        .addProperty("SimdSpringIntegrator", &GPhysFeModelDesc_t::GetSimdSpringIntegrator, &GPhysFeModelDesc_t::SetSimdSpringIntegrator)
        .addProperty("WorldCollisionParams", &GPhysFeModelDesc_t::GetWorldCollisionParams, &GPhysFeModelDesc_t::SetWorldCollisionParams)
        .addProperty("LegacyStretchForce", &GPhysFeModelDesc_t::GetLegacyStretchForce, &GPhysFeModelDesc_t::SetLegacyStretchForce)
        .addProperty("NodeCollisionRadii", &GPhysFeModelDesc_t::GetNodeCollisionRadii, &GPhysFeModelDesc_t::SetNodeCollisionRadii)
        .addProperty("DynNodeFriction", &GPhysFeModelDesc_t::GetDynNodeFriction, &GPhysFeModelDesc_t::SetDynNodeFriction)
        .addProperty("LocalRotation1", &GPhysFeModelDesc_t::GetLocalRotation1, &GPhysFeModelDesc_t::SetLocalRotation1)
        .addProperty("LocalForce1", &GPhysFeModelDesc_t::GetLocalForce1, &GPhysFeModelDesc_t::SetLocalForce1)
        .addProperty("TaperedCapsuleStretches", &GPhysFeModelDesc_t::GetTaperedCapsuleStretches, &GPhysFeModelDesc_t::SetTaperedCapsuleStretches)
        .addProperty("TaperedCapsuleRigids", &GPhysFeModelDesc_t::GetTaperedCapsuleRigids, &GPhysFeModelDesc_t::SetTaperedCapsuleRigids)
        .addProperty("SphereRigids", &GPhysFeModelDesc_t::GetSphereRigids, &GPhysFeModelDesc_t::SetSphereRigids)
        .addProperty("WorldCollisionNodes", &GPhysFeModelDesc_t::GetWorldCollisionNodes, &GPhysFeModelDesc_t::SetWorldCollisionNodes)
        .addProperty("TreeParents", &GPhysFeModelDesc_t::GetTreeParents, &GPhysFeModelDesc_t::SetTreeParents)
        .addProperty("TreeCollisionMasks", &GPhysFeModelDesc_t::GetTreeCollisionMasks, &GPhysFeModelDesc_t::SetTreeCollisionMasks)
        .addProperty("TreeChildren", &GPhysFeModelDesc_t::GetTreeChildren, &GPhysFeModelDesc_t::SetTreeChildren)
        .addProperty("FreeNodes", &GPhysFeModelDesc_t::GetFreeNodes, &GPhysFeModelDesc_t::SetFreeNodes)
        .addProperty("FitMatrices", &GPhysFeModelDesc_t::GetFitMatrices, &GPhysFeModelDesc_t::SetFitMatrices)
        .addProperty("FitWeights", &GPhysFeModelDesc_t::GetFitWeights, &GPhysFeModelDesc_t::SetFitWeights)
        .addProperty("ReverseOffsets", &GPhysFeModelDesc_t::GetReverseOffsets, &GPhysFeModelDesc_t::SetReverseOffsets)
        .addProperty("AnimStrayRadii", &GPhysFeModelDesc_t::GetAnimStrayRadii, &GPhysFeModelDesc_t::SetAnimStrayRadii)
        .addProperty("SimdAnimStrayRadii", &GPhysFeModelDesc_t::GetSimdAnimStrayRadii, &GPhysFeModelDesc_t::SetSimdAnimStrayRadii)
        .addProperty("KelagerBends", &GPhysFeModelDesc_t::GetKelagerBends, &GPhysFeModelDesc_t::SetKelagerBends)
        .addProperty("CtrlSoftOffsets", &GPhysFeModelDesc_t::GetCtrlSoftOffsets, &GPhysFeModelDesc_t::SetCtrlSoftOffsets)
        .addProperty("JiggleBones", &GPhysFeModelDesc_t::GetJiggleBones, &GPhysFeModelDesc_t::SetJiggleBones)
        .addProperty("SourceElems", &GPhysFeModelDesc_t::GetSourceElems, &GPhysFeModelDesc_t::SetSourceElems)
        .addProperty("GoalDampedSpringIntegrators", &GPhysFeModelDesc_t::GetGoalDampedSpringIntegrators, &GPhysFeModelDesc_t::SetGoalDampedSpringIntegrators)
        .addProperty("Tris", &GPhysFeModelDesc_t::GetTris, &GPhysFeModelDesc_t::SetTris)
        .addProperty("TriCount1", &GPhysFeModelDesc_t::GetTriCount1, &GPhysFeModelDesc_t::SetTriCount1)
        .addProperty("TriCount2", &GPhysFeModelDesc_t::GetTriCount2, &GPhysFeModelDesc_t::SetTriCount2)
        .addProperty("ReservedUint8", &GPhysFeModelDesc_t::GetReservedUint8, &GPhysFeModelDesc_t::SetReservedUint8)
        .addProperty("ExtraPressureIterations", &GPhysFeModelDesc_t::GetExtraPressureIterations, &GPhysFeModelDesc_t::SetExtraPressureIterations)
        .addProperty("ExtraGoalIterations", &GPhysFeModelDesc_t::GetExtraGoalIterations, &GPhysFeModelDesc_t::SetExtraGoalIterations)
        .addProperty("ExtraIterations", &GPhysFeModelDesc_t::GetExtraIterations, &GPhysFeModelDesc_t::SetExtraIterations)
        .addProperty("BoxRigids", &GPhysFeModelDesc_t::GetBoxRigids, &GPhysFeModelDesc_t::SetBoxRigids)
        .addProperty("DynNodeVertexSet", &GPhysFeModelDesc_t::GetDynNodeVertexSet, &GPhysFeModelDesc_t::SetDynNodeVertexSet)
        .addProperty("VertexSetNames", &GPhysFeModelDesc_t::GetVertexSetNames, &GPhysFeModelDesc_t::SetVertexSetNames)
        .addProperty("RigidColliderPriorities", &GPhysFeModelDesc_t::GetRigidColliderPriorities, &GPhysFeModelDesc_t::SetRigidColliderPriorities)
        .addProperty("MorphLayers", &GPhysFeModelDesc_t::GetMorphLayers, &GPhysFeModelDesc_t::SetMorphLayers)
        .addProperty("MorphSetData", &GPhysFeModelDesc_t::GetMorphSetData, &GPhysFeModelDesc_t::SetMorphSetData)
        .addProperty("VertexMaps", &GPhysFeModelDesc_t::GetVertexMaps, &GPhysFeModelDesc_t::SetVertexMaps)
        .addProperty("VertexMapValues", &GPhysFeModelDesc_t::GetVertexMapValues, &GPhysFeModelDesc_t::SetVertexMapValues)
        .addProperty("Effects", &GPhysFeModelDesc_t::GetEffects, &GPhysFeModelDesc_t::SetEffects)
        .addProperty("LockToParent", &GPhysFeModelDesc_t::GetLockToParent, &GPhysFeModelDesc_t::SetLockToParent)
        .addProperty("LockToGoal", &GPhysFeModelDesc_t::GetLockToGoal, &GPhysFeModelDesc_t::SetLockToGoal)
        .addProperty("SkelParents", &GPhysFeModelDesc_t::GetSkelParents, &GPhysFeModelDesc_t::SetSkelParents)
        .addProperty("DynNodeWindBases", &GPhysFeModelDesc_t::GetDynNodeWindBases, &GPhysFeModelDesc_t::SetDynNodeWindBases)
        .addProperty("InternalPressure", &GPhysFeModelDesc_t::GetInternalPressure, &GPhysFeModelDesc_t::SetInternalPressure)
        .addProperty("DefaultTimeDilation", &GPhysFeModelDesc_t::GetDefaultTimeDilation, &GPhysFeModelDesc_t::SetDefaultTimeDilation)
        .addProperty("Windage", &GPhysFeModelDesc_t::GetWindage, &GPhysFeModelDesc_t::SetWindage)
        .addProperty("WindDrag", &GPhysFeModelDesc_t::GetWindDrag, &GPhysFeModelDesc_t::SetWindDrag)
        .addProperty("DefaultSurfaceStretch", &GPhysFeModelDesc_t::GetDefaultSurfaceStretch, &GPhysFeModelDesc_t::SetDefaultSurfaceStretch)
        .addProperty("DefaultThreadStretch", &GPhysFeModelDesc_t::GetDefaultThreadStretch, &GPhysFeModelDesc_t::SetDefaultThreadStretch)
        .addProperty("DefaultGravityScale", &GPhysFeModelDesc_t::GetDefaultGravityScale, &GPhysFeModelDesc_t::SetDefaultGravityScale)
        .addProperty("DefaultVelAirDrag", &GPhysFeModelDesc_t::GetDefaultVelAirDrag, &GPhysFeModelDesc_t::SetDefaultVelAirDrag)
        .addProperty("DefaultExpAirDrag", &GPhysFeModelDesc_t::GetDefaultExpAirDrag, &GPhysFeModelDesc_t::SetDefaultExpAirDrag)
        .addProperty("DefaultVelQuadAirDrag", &GPhysFeModelDesc_t::GetDefaultVelQuadAirDrag, &GPhysFeModelDesc_t::SetDefaultVelQuadAirDrag)
        .addProperty("DefaultExpQuadAirDrag", &GPhysFeModelDesc_t::GetDefaultExpQuadAirDrag, &GPhysFeModelDesc_t::SetDefaultExpQuadAirDrag)
        .addProperty("RodVelocitySmoothRate", &GPhysFeModelDesc_t::GetRodVelocitySmoothRate, &GPhysFeModelDesc_t::SetRodVelocitySmoothRate)
        .addProperty("QuadVelocitySmoothRate", &GPhysFeModelDesc_t::GetQuadVelocitySmoothRate, &GPhysFeModelDesc_t::SetQuadVelocitySmoothRate)
        .addProperty("AddWorldCollisionRadius", &GPhysFeModelDesc_t::GetAddWorldCollisionRadius, &GPhysFeModelDesc_t::SetAddWorldCollisionRadius)
        .addProperty("DefaultVolumetricSolveAmount", &GPhysFeModelDesc_t::GetDefaultVolumetricSolveAmount, &GPhysFeModelDesc_t::SetDefaultVolumetricSolveAmount)
        .addProperty("MotionSmoothCDT", &GPhysFeModelDesc_t::GetMotionSmoothCDT, &GPhysFeModelDesc_t::SetMotionSmoothCDT)
        .addProperty("RodVelocitySmoothIterations", &GPhysFeModelDesc_t::GetRodVelocitySmoothIterations, &GPhysFeModelDesc_t::SetRodVelocitySmoothIterations)
        .addProperty("QuadVelocitySmoothIterations", &GPhysFeModelDesc_t::GetQuadVelocitySmoothIterations, &GPhysFeModelDesc_t::SetQuadVelocitySmoothIterations)
        .addFunction("ToPtr", &GPhysFeModelDesc_t::ToPtr)
        .addFunction("IsValid", &GPhysFeModelDesc_t::IsValid)
        .endClass();
}