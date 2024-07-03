#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCShatterGlassShard::GCShatterGlassShard(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCShatterGlassShard::GCShatterGlassShard(void *ptr) {
    m_ptr = ptr;
}
uint32_t GCShatterGlassShard::GetShardHandle() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CShatterGlassShard", "m_hShardHandle");
}
void GCShatterGlassShard::SetShardHandle(uint32_t value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_hShardHandle", false, value);
}
std::vector<Vector2D> GCShatterGlassShard::GetPanelVertices() const {
    CUtlVector<Vector2D>* vec = GetSchemaValue<CUtlVector<Vector2D>*>(m_ptr, "CShatterGlassShard", "m_vecPanelVertices"); std::vector<Vector2D> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCShatterGlassShard::SetPanelVertices(std::vector<Vector2D> value) {
    SetSchemaValueCUtlVector<Vector2D>(m_ptr, "CShatterGlassShard", "m_vecPanelVertices", false, value);
}
Vector2D GCShatterGlassShard::GetLocalPanelSpaceOrigin() const {
    return GetSchemaValue<Vector2D>(m_ptr, "CShatterGlassShard", "m_vLocalPanelSpaceOrigin");
}
void GCShatterGlassShard::SetLocalPanelSpaceOrigin(Vector2D value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_vLocalPanelSpaceOrigin", false, value);
}
GCShatterGlassShardPhysics GCShatterGlassShard::GetPhysicsEntity() const {
    GCShatterGlassShardPhysics value(*GetSchemaValuePtr<void*>(m_ptr, "CShatterGlassShard", "m_hPhysicsEntity"));
    return value;
}
void GCShatterGlassShard::SetPhysicsEntity(GCShatterGlassShardPhysics* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PhysicsEntity' is not possible.\n");
}
GCFuncShatterglass GCShatterGlassShard::GetParentPanel() const {
    GCFuncShatterglass value(*GetSchemaValuePtr<void*>(m_ptr, "CShatterGlassShard", "m_hParentPanel"));
    return value;
}
void GCShatterGlassShard::SetParentPanel(GCFuncShatterglass* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'ParentPanel' is not possible.\n");
}
uint32_t GCShatterGlassShard::GetParentShard() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CShatterGlassShard", "m_hParentShard");
}
void GCShatterGlassShard::SetParentShard(uint32_t value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_hParentShard", false, value);
}
uint64_t GCShatterGlassShard::GetShatterStressType() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CShatterGlassShard", "m_ShatterStressType");
}
void GCShatterGlassShard::SetShatterStressType(uint64_t value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_ShatterStressType", false, value);
}
Vector GCShatterGlassShard::GetStressVelocity() const {
    return GetSchemaValue<Vector>(m_ptr, "CShatterGlassShard", "m_vecStressVelocity");
}
void GCShatterGlassShard::SetStressVelocity(Vector value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_vecStressVelocity", false, value);
}
bool GCShatterGlassShard::GetCreatedModel() const {
    return GetSchemaValue<bool>(m_ptr, "CShatterGlassShard", "m_bCreatedModel");
}
void GCShatterGlassShard::SetCreatedModel(bool value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_bCreatedModel", false, value);
}
float GCShatterGlassShard::GetLongestEdge() const {
    return GetSchemaValue<float>(m_ptr, "CShatterGlassShard", "m_flLongestEdge");
}
void GCShatterGlassShard::SetLongestEdge(float value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_flLongestEdge", false, value);
}
float GCShatterGlassShard::GetShortestEdge() const {
    return GetSchemaValue<float>(m_ptr, "CShatterGlassShard", "m_flShortestEdge");
}
void GCShatterGlassShard::SetShortestEdge(float value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_flShortestEdge", false, value);
}
float GCShatterGlassShard::GetLongestAcross() const {
    return GetSchemaValue<float>(m_ptr, "CShatterGlassShard", "m_flLongestAcross");
}
void GCShatterGlassShard::SetLongestAcross(float value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_flLongestAcross", false, value);
}
float GCShatterGlassShard::GetShortestAcross() const {
    return GetSchemaValue<float>(m_ptr, "CShatterGlassShard", "m_flShortestAcross");
}
void GCShatterGlassShard::SetShortestAcross(float value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_flShortestAcross", false, value);
}
float GCShatterGlassShard::GetSumOfAllEdges() const {
    return GetSchemaValue<float>(m_ptr, "CShatterGlassShard", "m_flSumOfAllEdges");
}
void GCShatterGlassShard::SetSumOfAllEdges(float value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_flSumOfAllEdges", false, value);
}
float GCShatterGlassShard::GetArea() const {
    return GetSchemaValue<float>(m_ptr, "CShatterGlassShard", "m_flArea");
}
void GCShatterGlassShard::SetArea(float value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_flArea", false, value);
}
uint64_t GCShatterGlassShard::GetOnFrameEdge() const {
    return GetSchemaValue<uint64_t>(m_ptr, "CShatterGlassShard", "m_nOnFrameEdge");
}
void GCShatterGlassShard::SetOnFrameEdge(uint64_t value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_nOnFrameEdge", false, value);
}
int32_t GCShatterGlassShard::GetParentPanelsNthShard() const {
    return GetSchemaValue<int32_t>(m_ptr, "CShatterGlassShard", "m_nParentPanelsNthShard");
}
void GCShatterGlassShard::SetParentPanelsNthShard(int32_t value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_nParentPanelsNthShard", false, value);
}
int32_t GCShatterGlassShard::GetSubShardGeneration() const {
    return GetSchemaValue<int32_t>(m_ptr, "CShatterGlassShard", "m_nSubShardGeneration");
}
void GCShatterGlassShard::SetSubShardGeneration(int32_t value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_nSubShardGeneration", false, value);
}
Vector2D GCShatterGlassShard::GetAverageVertPosition() const {
    return GetSchemaValue<Vector2D>(m_ptr, "CShatterGlassShard", "m_vecAverageVertPosition");
}
void GCShatterGlassShard::SetAverageVertPosition(Vector2D value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_vecAverageVertPosition", false, value);
}
bool GCShatterGlassShard::GetAverageVertPositionIsValid() const {
    return GetSchemaValue<bool>(m_ptr, "CShatterGlassShard", "m_bAverageVertPositionIsValid");
}
void GCShatterGlassShard::SetAverageVertPositionIsValid(bool value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_bAverageVertPositionIsValid", false, value);
}
Vector2D GCShatterGlassShard::GetPanelSpaceStressPositionA() const {
    return GetSchemaValue<Vector2D>(m_ptr, "CShatterGlassShard", "m_vecPanelSpaceStressPositionA");
}
void GCShatterGlassShard::SetPanelSpaceStressPositionA(Vector2D value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_vecPanelSpaceStressPositionA", false, value);
}
Vector2D GCShatterGlassShard::GetPanelSpaceStressPositionB() const {
    return GetSchemaValue<Vector2D>(m_ptr, "CShatterGlassShard", "m_vecPanelSpaceStressPositionB");
}
void GCShatterGlassShard::SetPanelSpaceStressPositionB(Vector2D value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_vecPanelSpaceStressPositionB", false, value);
}
bool GCShatterGlassShard::GetStressPositionAIsValid() const {
    return GetSchemaValue<bool>(m_ptr, "CShatterGlassShard", "m_bStressPositionAIsValid");
}
void GCShatterGlassShard::SetStressPositionAIsValid(bool value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_bStressPositionAIsValid", false, value);
}
bool GCShatterGlassShard::GetStressPositionBIsValid() const {
    return GetSchemaValue<bool>(m_ptr, "CShatterGlassShard", "m_bStressPositionBIsValid");
}
void GCShatterGlassShard::SetStressPositionBIsValid(bool value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_bStressPositionBIsValid", false, value);
}
bool GCShatterGlassShard::GetFlaggedForRemoval() const {
    return GetSchemaValue<bool>(m_ptr, "CShatterGlassShard", "m_bFlaggedForRemoval");
}
void GCShatterGlassShard::SetFlaggedForRemoval(bool value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_bFlaggedForRemoval", false, value);
}
float GCShatterGlassShard::GetPhysicsEntitySpawnedAtTime() const {
    return GetSchemaValue<float>(m_ptr, "CShatterGlassShard", "m_flPhysicsEntitySpawnedAtTime");
}
void GCShatterGlassShard::SetPhysicsEntitySpawnedAtTime(float value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_flPhysicsEntitySpawnedAtTime", false, value);
}
bool GCShatterGlassShard::GetShatterRateLimited() const {
    return GetSchemaValue<bool>(m_ptr, "CShatterGlassShard", "m_bShatterRateLimited");
}
void GCShatterGlassShard::SetShatterRateLimited(bool value) {
    SetSchemaValue(m_ptr, "CShatterGlassShard", "m_bShatterRateLimited", false, value);
}
GCBaseEntity GCShatterGlassShard::GetEntityHittingMe() const {
    GCBaseEntity value(*GetSchemaValuePtr<void*>(m_ptr, "CShatterGlassShard", "m_hEntityHittingMe"));
    return value;
}
void GCShatterGlassShard::SetEntityHittingMe(GCBaseEntity* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'EntityHittingMe' is not possible.\n");
}
std::vector<uint32> GCShatterGlassShard::GetNeighbors() const {
    CUtlVector<uint32>* vec = GetSchemaValue<CUtlVector<uint32>*>(m_ptr, "CShatterGlassShard", "m_vecNeighbors"); std::vector<uint32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCShatterGlassShard::SetNeighbors(std::vector<uint32> value) {
    SetSchemaValueCUtlVector<uint32>(m_ptr, "CShatterGlassShard", "m_vecNeighbors", false, value);
}
std::string GCShatterGlassShard::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCShatterGlassShard::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCShatterGlassShard(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCShatterGlassShard>("CShatterGlassShard")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ShardHandle", &GCShatterGlassShard::GetShardHandle, &GCShatterGlassShard::SetShardHandle)
        .addProperty("PanelVertices", &GCShatterGlassShard::GetPanelVertices, &GCShatterGlassShard::SetPanelVertices)
        .addProperty("LocalPanelSpaceOrigin", &GCShatterGlassShard::GetLocalPanelSpaceOrigin, &GCShatterGlassShard::SetLocalPanelSpaceOrigin)
        .addProperty("PhysicsEntity", &GCShatterGlassShard::GetPhysicsEntity, &GCShatterGlassShard::SetPhysicsEntity)
        .addProperty("ParentPanel", &GCShatterGlassShard::GetParentPanel, &GCShatterGlassShard::SetParentPanel)
        .addProperty("ParentShard", &GCShatterGlassShard::GetParentShard, &GCShatterGlassShard::SetParentShard)
        .addProperty("ShatterStressType", &GCShatterGlassShard::GetShatterStressType, &GCShatterGlassShard::SetShatterStressType)
        .addProperty("StressVelocity", &GCShatterGlassShard::GetStressVelocity, &GCShatterGlassShard::SetStressVelocity)
        .addProperty("CreatedModel", &GCShatterGlassShard::GetCreatedModel, &GCShatterGlassShard::SetCreatedModel)
        .addProperty("LongestEdge", &GCShatterGlassShard::GetLongestEdge, &GCShatterGlassShard::SetLongestEdge)
        .addProperty("ShortestEdge", &GCShatterGlassShard::GetShortestEdge, &GCShatterGlassShard::SetShortestEdge)
        .addProperty("LongestAcross", &GCShatterGlassShard::GetLongestAcross, &GCShatterGlassShard::SetLongestAcross)
        .addProperty("ShortestAcross", &GCShatterGlassShard::GetShortestAcross, &GCShatterGlassShard::SetShortestAcross)
        .addProperty("SumOfAllEdges", &GCShatterGlassShard::GetSumOfAllEdges, &GCShatterGlassShard::SetSumOfAllEdges)
        .addProperty("Area", &GCShatterGlassShard::GetArea, &GCShatterGlassShard::SetArea)
        .addProperty("OnFrameEdge", &GCShatterGlassShard::GetOnFrameEdge, &GCShatterGlassShard::SetOnFrameEdge)
        .addProperty("ParentPanelsNthShard", &GCShatterGlassShard::GetParentPanelsNthShard, &GCShatterGlassShard::SetParentPanelsNthShard)
        .addProperty("SubShardGeneration", &GCShatterGlassShard::GetSubShardGeneration, &GCShatterGlassShard::SetSubShardGeneration)
        .addProperty("AverageVertPosition", &GCShatterGlassShard::GetAverageVertPosition, &GCShatterGlassShard::SetAverageVertPosition)
        .addProperty("AverageVertPositionIsValid", &GCShatterGlassShard::GetAverageVertPositionIsValid, &GCShatterGlassShard::SetAverageVertPositionIsValid)
        .addProperty("PanelSpaceStressPositionA", &GCShatterGlassShard::GetPanelSpaceStressPositionA, &GCShatterGlassShard::SetPanelSpaceStressPositionA)
        .addProperty("PanelSpaceStressPositionB", &GCShatterGlassShard::GetPanelSpaceStressPositionB, &GCShatterGlassShard::SetPanelSpaceStressPositionB)
        .addProperty("StressPositionAIsValid", &GCShatterGlassShard::GetStressPositionAIsValid, &GCShatterGlassShard::SetStressPositionAIsValid)
        .addProperty("StressPositionBIsValid", &GCShatterGlassShard::GetStressPositionBIsValid, &GCShatterGlassShard::SetStressPositionBIsValid)
        .addProperty("FlaggedForRemoval", &GCShatterGlassShard::GetFlaggedForRemoval, &GCShatterGlassShard::SetFlaggedForRemoval)
        .addProperty("PhysicsEntitySpawnedAtTime", &GCShatterGlassShard::GetPhysicsEntitySpawnedAtTime, &GCShatterGlassShard::SetPhysicsEntitySpawnedAtTime)
        .addProperty("ShatterRateLimited", &GCShatterGlassShard::GetShatterRateLimited, &GCShatterGlassShard::SetShatterRateLimited)
        .addProperty("EntityHittingMe", &GCShatterGlassShard::GetEntityHittingMe, &GCShatterGlassShard::SetEntityHittingMe)
        .addProperty("Neighbors", &GCShatterGlassShard::GetNeighbors, &GCShatterGlassShard::SetNeighbors)
        .addFunction("ToPtr", &GCShatterGlassShard::ToPtr)
        .addFunction("IsValid", &GCShatterGlassShard::IsValid)
        .endClass();
}