#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCGameSceneNode::GCGameSceneNode(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCGameSceneNode::GCGameSceneNode(void *ptr) {
    m_ptr = ptr;
}
GCEntityInstance GCGameSceneNode::GetOwner() const {
    GCEntityInstance value(*GetSchemaValuePtr<void*>(m_ptr, "CGameSceneNode", "m_pOwner"));
    return value;
}
void GCGameSceneNode::SetOwner(GCEntityInstance* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Owner' is not possible.\n");
}
GCGameSceneNode GCGameSceneNode::GetParent() const {
    GCGameSceneNode value(*GetSchemaValuePtr<void*>(m_ptr, "CGameSceneNode", "m_pParent"));
    return value;
}
void GCGameSceneNode::SetParent(GCGameSceneNode* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
GCGameSceneNode GCGameSceneNode::GetChild() const {
    GCGameSceneNode value(*GetSchemaValuePtr<void*>(m_ptr, "CGameSceneNode", "m_pChild"));
    return value;
}
void GCGameSceneNode::SetChild(GCGameSceneNode* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Child' is not possible.\n");
}
GCGameSceneNode GCGameSceneNode::GetNextSibling() const {
    GCGameSceneNode value(*GetSchemaValuePtr<void*>(m_ptr, "CGameSceneNode", "m_pNextSibling"));
    return value;
}
void GCGameSceneNode::SetNextSibling(GCGameSceneNode* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'NextSibling' is not possible.\n");
}
GCNetworkOriginCellCoordQuantizedVector GCGameSceneNode::GetOrigin() const {
    GCNetworkOriginCellCoordQuantizedVector value(GetSchemaPtr(m_ptr, "CGameSceneNode", "m_vecOrigin"));
    return value;
}
void GCGameSceneNode::SetOrigin(GCNetworkOriginCellCoordQuantizedVector value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_vecOrigin", false, value);
}
QAngle GCGameSceneNode::GetRotation() const {
    return GetSchemaValue<QAngle>(m_ptr, "CGameSceneNode", "m_angRotation");
}
void GCGameSceneNode::SetRotation(QAngle value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_angRotation", false, value);
}
float GCGameSceneNode::GetScale() const {
    return GetSchemaValue<float>(m_ptr, "CGameSceneNode", "m_flScale");
}
void GCGameSceneNode::SetScale(float value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_flScale", false, value);
}
Vector GCGameSceneNode::GetAbsOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CGameSceneNode", "m_vecAbsOrigin");
}
void GCGameSceneNode::SetAbsOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_vecAbsOrigin", false, value);
}
QAngle GCGameSceneNode::GetAbsRotation() const {
    return GetSchemaValue<QAngle>(m_ptr, "CGameSceneNode", "m_angAbsRotation");
}
void GCGameSceneNode::SetAbsRotation(QAngle value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_angAbsRotation", false, value);
}
float GCGameSceneNode::GetAbsScale() const {
    return GetSchemaValue<float>(m_ptr, "CGameSceneNode", "m_flAbsScale");
}
void GCGameSceneNode::SetAbsScale(float value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_flAbsScale", false, value);
}
int16_t GCGameSceneNode::GetParentAttachmentOrBone() const {
    return GetSchemaValue<int16_t>(m_ptr, "CGameSceneNode", "m_nParentAttachmentOrBone");
}
void GCGameSceneNode::SetParentAttachmentOrBone(int16_t value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_nParentAttachmentOrBone", false, value);
}
bool GCGameSceneNode::GetDebugAbsOriginChanges() const {
    return GetSchemaValue<bool>(m_ptr, "CGameSceneNode", "m_bDebugAbsOriginChanges");
}
void GCGameSceneNode::SetDebugAbsOriginChanges(bool value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_bDebugAbsOriginChanges", false, value);
}
bool GCGameSceneNode::GetDormant() const {
    return GetSchemaValue<bool>(m_ptr, "CGameSceneNode", "m_bDormant");
}
void GCGameSceneNode::SetDormant(bool value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_bDormant", false, value);
}
bool GCGameSceneNode::GetForceParentToBeNetworked() const {
    return GetSchemaValue<bool>(m_ptr, "CGameSceneNode", "m_bForceParentToBeNetworked");
}
void GCGameSceneNode::SetForceParentToBeNetworked(bool value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_bForceParentToBeNetworked", false, value);
}
uint8_t GCGameSceneNode::GetHierarchicalDepth() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CGameSceneNode", "m_nHierarchicalDepth");
}
void GCGameSceneNode::SetHierarchicalDepth(uint8_t value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_nHierarchicalDepth", false, value);
}
uint8_t GCGameSceneNode::GetHierarchyType() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CGameSceneNode", "m_nHierarchyType");
}
void GCGameSceneNode::SetHierarchyType(uint8_t value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_nHierarchyType", false, value);
}
uint8_t GCGameSceneNode::GetDoNotSetAnimTimeInInvalidatePhysicsCount() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CGameSceneNode", "m_nDoNotSetAnimTimeInInvalidatePhysicsCount");
}
void GCGameSceneNode::SetDoNotSetAnimTimeInInvalidatePhysicsCount(uint8_t value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_nDoNotSetAnimTimeInInvalidatePhysicsCount", false, value);
}
CUtlStringToken GCGameSceneNode::GetName() const {
    return GetSchemaValue<CUtlStringToken>(m_ptr, "CGameSceneNode", "m_name");
}
void GCGameSceneNode::SetName(CUtlStringToken value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_name", false, value);
}
CUtlStringToken GCGameSceneNode::GetHierarchyAttachName() const {
    return GetSchemaValue<CUtlStringToken>(m_ptr, "CGameSceneNode", "m_hierarchyAttachName");
}
void GCGameSceneNode::SetHierarchyAttachName(CUtlStringToken value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_hierarchyAttachName", false, value);
}
float GCGameSceneNode::GetZOffset() const {
    return GetSchemaValue<float>(m_ptr, "CGameSceneNode", "m_flZOffset");
}
void GCGameSceneNode::SetZOffset(float value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_flZOffset", false, value);
}
float GCGameSceneNode::GetClientLocalScale() const {
    return GetSchemaValue<float>(m_ptr, "CGameSceneNode", "m_flClientLocalScale");
}
void GCGameSceneNode::SetClientLocalScale(float value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_flClientLocalScale", false, value);
}
Vector GCGameSceneNode::GetRenderOrigin() const {
    return GetSchemaValue<Vector>(m_ptr, "CGameSceneNode", "m_vRenderOrigin");
}
void GCGameSceneNode::SetRenderOrigin(Vector value) {
    SetSchemaValue(m_ptr, "CGameSceneNode", "m_vRenderOrigin", false, value);
}
std::string GCGameSceneNode::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCGameSceneNode::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCGameSceneNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameSceneNode>("CGameSceneNode")
        .addConstructor<void (*)(std::string)>()
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
        .addFunction("ToPtr", &GCGameSceneNode::ToPtr)
        .addFunction("IsValid", &GCGameSceneNode::IsValid)
        .endClass();
}