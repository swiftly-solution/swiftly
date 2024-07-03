#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCBaseAnimGraph::GCBaseAnimGraph(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCBaseAnimGraph::GCBaseAnimGraph(void *ptr) {
    m_ptr = ptr;
}
bool GCBaseAnimGraph::GetInitiallyPopulateInterpHistory() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseAnimGraph", "m_bInitiallyPopulateInterpHistory");
}
void GCBaseAnimGraph::SetInitiallyPopulateInterpHistory(bool value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraph", "m_bInitiallyPopulateInterpHistory", false, value);
}
GIChoreoServices GCBaseAnimGraph::GetChoreoServices() const {
    GIChoreoServices value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseAnimGraph", "m_pChoreoServices"));
    return value;
}
void GCBaseAnimGraph::SetChoreoServices(GIChoreoServices* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ChoreoServices' is not possible.\n");
}
bool GCBaseAnimGraph::GetAnimGraphUpdateEnabled() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseAnimGraph", "m_bAnimGraphUpdateEnabled");
}
void GCBaseAnimGraph::SetAnimGraphUpdateEnabled(bool value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraph", "m_bAnimGraphUpdateEnabled", false, value);
}
float GCBaseAnimGraph::GetMaxSlopeDistance() const {
    return GetSchemaValue<float>(m_ptr, "CBaseAnimGraph", "m_flMaxSlopeDistance");
}
void GCBaseAnimGraph::SetMaxSlopeDistance(float value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraph", "m_flMaxSlopeDistance", false, value);
}
Vector GCBaseAnimGraph::GetLastSlopeCheckPos() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseAnimGraph", "m_vLastSlopeCheckPos");
}
void GCBaseAnimGraph::SetLastSlopeCheckPos(Vector value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraph", "m_vLastSlopeCheckPos", false, value);
}
bool GCBaseAnimGraph::GetAnimationUpdateScheduled() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseAnimGraph", "m_bAnimationUpdateScheduled");
}
void GCBaseAnimGraph::SetAnimationUpdateScheduled(bool value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraph", "m_bAnimationUpdateScheduled", false, value);
}
Vector GCBaseAnimGraph::GetForce() const {
    return GetSchemaValue<Vector>(m_ptr, "CBaseAnimGraph", "m_vecForce");
}
void GCBaseAnimGraph::SetForce(Vector value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraph", "m_vecForce", false, value);
}
int32_t GCBaseAnimGraph::GetForceBone() const {
    return GetSchemaValue<int32_t>(m_ptr, "CBaseAnimGraph", "m_nForceBone");
}
void GCBaseAnimGraph::SetForceBone(int32_t value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraph", "m_nForceBone", false, value);
}
GPhysicsRagdollPose_t GCBaseAnimGraph::GetRagdollPose() const {
    GPhysicsRagdollPose_t value(*GetSchemaValuePtr<void*>(m_ptr, "CBaseAnimGraph", "m_pRagdollPose"));
    return value;
}
void GCBaseAnimGraph::SetRagdollPose(GPhysicsRagdollPose_t* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'RagdollPose' is not possible.\n");
}
bool GCBaseAnimGraph::GetRagdollClientSide() const {
    return GetSchemaValue<bool>(m_ptr, "CBaseAnimGraph", "m_bRagdollClientSide");
}
void GCBaseAnimGraph::SetRagdollClientSide(bool value) {
    SetSchemaValue(m_ptr, "CBaseAnimGraph", "m_bRagdollClientSide", false, value);
}
std::string GCBaseAnimGraph::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCBaseAnimGraph::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCBaseAnimGraph::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCBaseAnimGraph::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCBaseAnimGraph(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseAnimGraph>("CBaseAnimGraph")
        .addConstructor<void (*)(std::string)>()
        .addProperty("InitiallyPopulateInterpHistory", &GCBaseAnimGraph::GetInitiallyPopulateInterpHistory, &GCBaseAnimGraph::SetInitiallyPopulateInterpHistory)
        .addProperty("ChoreoServices", &GCBaseAnimGraph::GetChoreoServices, &GCBaseAnimGraph::SetChoreoServices)
        .addProperty("AnimGraphUpdateEnabled", &GCBaseAnimGraph::GetAnimGraphUpdateEnabled, &GCBaseAnimGraph::SetAnimGraphUpdateEnabled)
        .addProperty("MaxSlopeDistance", &GCBaseAnimGraph::GetMaxSlopeDistance, &GCBaseAnimGraph::SetMaxSlopeDistance)
        .addProperty("LastSlopeCheckPos", &GCBaseAnimGraph::GetLastSlopeCheckPos, &GCBaseAnimGraph::SetLastSlopeCheckPos)
        .addProperty("AnimationUpdateScheduled", &GCBaseAnimGraph::GetAnimationUpdateScheduled, &GCBaseAnimGraph::SetAnimationUpdateScheduled)
        .addProperty("Force", &GCBaseAnimGraph::GetForce, &GCBaseAnimGraph::SetForce)
        .addProperty("ForceBone", &GCBaseAnimGraph::GetForceBone, &GCBaseAnimGraph::SetForceBone)
        .addProperty("RagdollPose", &GCBaseAnimGraph::GetRagdollPose, &GCBaseAnimGraph::SetRagdollPose)
        .addProperty("RagdollClientSide", &GCBaseAnimGraph::GetRagdollClientSide, &GCBaseAnimGraph::SetRagdollClientSide)
        .addProperty("Parent", &GCBaseAnimGraph::GetParent, &GCBaseAnimGraph::SetParent)
        .addFunction("ToPtr", &GCBaseAnimGraph::ToPtr)
        .addFunction("IsValid", &GCBaseAnimGraph::IsValid)
        .endClass();
}