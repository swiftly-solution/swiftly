#include "../../../core/scripting/generated/classes/GCGameSceneNode.h"
#include "../core.h"

void SetupLuaClassGCGameSceneNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameSceneNode>("CGameSceneNode")
        .addProperty("Owner", &GCGameSceneNode::GetOwner, &GCGameSceneNode::SetOwner)
        .addProperty("Parent", &GCGameSceneNode::GetParent, &GCGameSceneNode::SetParent)
        .addProperty("Child", &GCGameSceneNode::GetChild, &GCGameSceneNode::SetChild)
        .addProperty("NextSibling", &GCGameSceneNode::GetNextSibling, &GCGameSceneNode::SetNextSibling)
        .addProperty("Origin", &GCGameSceneNode::GetOrigin, &GCGameSceneNode::SetOrigin)
        .addProperty("Rotation", &GCGameSceneNode::GetRotation, &GCGameSceneNode::SetRotation)
        .addProperty("Scale", &GCGameSceneNode::GetScale, &GCGameSceneNode::SetScale)
        .addProperty("AbsOrigin", &GCGameSceneNode::GetAbsOrigin, &GCGameSceneNode::SetAbsOrigin)
        .addProperty("AbsRotation", &GCGameSceneNode::GetAbsRotation, &GCGameSceneNode::SetAbsRotation)
        .addProperty("AbsScale", &GCGameSceneNode::GetAbsScale, &GCGameSceneNode::SetAbsScale)
        .addProperty("ParentAttachmentOrBone", &GCGameSceneNode::GetParentAttachmentOrBone, &GCGameSceneNode::SetParentAttachmentOrBone)
        .addProperty("DebugAbsOriginChanges", &GCGameSceneNode::GetDebugAbsOriginChanges, &GCGameSceneNode::SetDebugAbsOriginChanges)
        .addProperty("Dormant", &GCGameSceneNode::GetDormant, &GCGameSceneNode::SetDormant)
        .addProperty("ForceParentToBeNetworked", &GCGameSceneNode::GetForceParentToBeNetworked, &GCGameSceneNode::SetForceParentToBeNetworked)
        .addProperty("HierarchicalDepth", &GCGameSceneNode::GetHierarchicalDepth, &GCGameSceneNode::SetHierarchicalDepth)
        .addProperty("HierarchyType", &GCGameSceneNode::GetHierarchyType, &GCGameSceneNode::SetHierarchyType)
        .addProperty("DoNotSetAnimTimeInInvalidatePhysicsCount", &GCGameSceneNode::GetDoNotSetAnimTimeInInvalidatePhysicsCount, &GCGameSceneNode::SetDoNotSetAnimTimeInInvalidatePhysicsCount)
        .addProperty("Name", &GCGameSceneNode::GetName, &GCGameSceneNode::SetName)
        .addProperty("HierarchyAttachName", &GCGameSceneNode::GetHierarchyAttachName, &GCGameSceneNode::SetHierarchyAttachName)
        .addProperty("ZOffset", &GCGameSceneNode::GetZOffset, &GCGameSceneNode::SetZOffset)
        .addProperty("ClientLocalScale", &GCGameSceneNode::GetClientLocalScale, &GCGameSceneNode::SetClientLocalScale)
        .addProperty("RenderOrigin", &GCGameSceneNode::GetRenderOrigin, &GCGameSceneNode::SetRenderOrigin)
        .endClass();
}