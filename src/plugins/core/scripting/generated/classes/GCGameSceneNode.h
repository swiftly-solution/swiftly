class GCGameSceneNode;

#ifndef _gccgamescenenode_h
#define _gccgamescenenode_h

#include "../../../scripting.h"


#include "GCEntityInstance.h"
#include "GCGameSceneNode.h"
#include "GCNetworkOriginCellCoordQuantizedVector.h"

class GCGameSceneNode
{
private:
    void *m_ptr;

public:
    GCGameSceneNode() {}
    GCGameSceneNode(void *ptr) : m_ptr(ptr) {}

    GCEntityInstance* GetOwner() const { return GetSchemaValue<GCEntityInstance*>(m_ptr, "CGameSceneNode", "m_pOwner"); }
    void SetOwner(GCEntityInstance* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Owner' is not possible.\n"); }
    GCGameSceneNode* GetParent() const { return GetSchemaValue<GCGameSceneNode*>(m_ptr, "CGameSceneNode", "m_pParent"); }
    void SetParent(GCGameSceneNode* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n"); }
    GCGameSceneNode* GetChild() const { return GetSchemaValue<GCGameSceneNode*>(m_ptr, "CGameSceneNode", "m_pChild"); }
    void SetChild(GCGameSceneNode* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'Child' is not possible.\n"); }
    GCGameSceneNode* GetNextSibling() const { return GetSchemaValue<GCGameSceneNode*>(m_ptr, "CGameSceneNode", "m_pNextSibling"); }
    void SetNextSibling(GCGameSceneNode* value) { PLUGIN_PRINT("Schema SDK", "Setting a value for 'NextSibling' is not possible.\n"); }
    GCNetworkOriginCellCoordQuantizedVector GetOrigin() const { return GetSchemaValue<GCNetworkOriginCellCoordQuantizedVector>(m_ptr, "CGameSceneNode", "m_vecOrigin"); }
    void SetOrigin(GCNetworkOriginCellCoordQuantizedVector value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_vecOrigin", false, value); }
    QAngle GetRotation() const { return GetSchemaValue<QAngle>(m_ptr, "CGameSceneNode", "m_angRotation"); }
    void SetRotation(QAngle value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_angRotation", false, value); }
    float GetScale() const { return GetSchemaValue<float>(m_ptr, "CGameSceneNode", "m_flScale"); }
    void SetScale(float value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_flScale", false, value); }
    Vector GetAbsOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CGameSceneNode", "m_vecAbsOrigin"); }
    void SetAbsOrigin(Vector value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_vecAbsOrigin", false, value); }
    QAngle GetAbsRotation() const { return GetSchemaValue<QAngle>(m_ptr, "CGameSceneNode", "m_angAbsRotation"); }
    void SetAbsRotation(QAngle value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_angAbsRotation", false, value); }
    float GetAbsScale() const { return GetSchemaValue<float>(m_ptr, "CGameSceneNode", "m_flAbsScale"); }
    void SetAbsScale(float value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_flAbsScale", false, value); }
    int16_t GetParentAttachmentOrBone() const { return GetSchemaValue<int16_t>(m_ptr, "CGameSceneNode", "m_nParentAttachmentOrBone"); }
    void SetParentAttachmentOrBone(int16_t value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_nParentAttachmentOrBone", false, value); }
    bool GetDebugAbsOriginChanges() const { return GetSchemaValue<bool>(m_ptr, "CGameSceneNode", "m_bDebugAbsOriginChanges"); }
    void SetDebugAbsOriginChanges(bool value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_bDebugAbsOriginChanges", false, value); }
    bool GetDormant() const { return GetSchemaValue<bool>(m_ptr, "CGameSceneNode", "m_bDormant"); }
    void SetDormant(bool value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_bDormant", false, value); }
    bool GetForceParentToBeNetworked() const { return GetSchemaValue<bool>(m_ptr, "CGameSceneNode", "m_bForceParentToBeNetworked"); }
    void SetForceParentToBeNetworked(bool value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_bForceParentToBeNetworked", false, value); }
    uint8_t GetHierarchicalDepth() const { return GetSchemaValue<uint8_t>(m_ptr, "CGameSceneNode", "m_nHierarchicalDepth"); }
    void SetHierarchicalDepth(uint8_t value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_nHierarchicalDepth", false, value); }
    uint8_t GetHierarchyType() const { return GetSchemaValue<uint8_t>(m_ptr, "CGameSceneNode", "m_nHierarchyType"); }
    void SetHierarchyType(uint8_t value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_nHierarchyType", false, value); }
    uint8_t GetDoNotSetAnimTimeInInvalidatePhysicsCount() const { return GetSchemaValue<uint8_t>(m_ptr, "CGameSceneNode", "m_nDoNotSetAnimTimeInInvalidatePhysicsCount"); }
    void SetDoNotSetAnimTimeInInvalidatePhysicsCount(uint8_t value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_nDoNotSetAnimTimeInInvalidatePhysicsCount", false, value); }
    CUtlStringToken GetName() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "CGameSceneNode", "m_name"); }
    void SetName(CUtlStringToken value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_name", false, value); }
    CUtlStringToken GetHierarchyAttachName() const { return GetSchemaValue<CUtlStringToken>(m_ptr, "CGameSceneNode", "m_hierarchyAttachName"); }
    void SetHierarchyAttachName(CUtlStringToken value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_hierarchyAttachName", false, value); }
    float GetZOffset() const { return GetSchemaValue<float>(m_ptr, "CGameSceneNode", "m_flZOffset"); }
    void SetZOffset(float value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_flZOffset", false, value); }
    float GetClientLocalScale() const { return GetSchemaValue<float>(m_ptr, "CGameSceneNode", "m_flClientLocalScale"); }
    void SetClientLocalScale(float value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_flClientLocalScale", false, value); }
    Vector GetRenderOrigin() const { return GetSchemaValue<Vector>(m_ptr, "CGameSceneNode", "m_vRenderOrigin"); }
    void SetRenderOrigin(Vector value) { SetSchemaValue(m_ptr, "CGameSceneNode", "m_vRenderOrigin", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif