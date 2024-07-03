#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Gshard_model_desc_t::Gshard_model_desc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Gshard_model_desc_t::Gshard_model_desc_t(void *ptr) {
    m_ptr = ptr;
}
int32_t Gshard_model_desc_t::GetModelID() const {
    return GetSchemaValue<int32_t>(m_ptr, "shard_model_desc_t", "m_nModelID");
}
void Gshard_model_desc_t::SetModelID(int32_t value) {
    SetSchemaValue(m_ptr, "shard_model_desc_t", "m_nModelID", true, value);
}
uint64_t Gshard_model_desc_t::GetSolid() const {
    return GetSchemaValue<uint64_t>(m_ptr, "shard_model_desc_t", "m_solid");
}
void Gshard_model_desc_t::SetSolid(uint64_t value) {
    SetSchemaValue(m_ptr, "shard_model_desc_t", "m_solid", true, value);
}
uint64_t Gshard_model_desc_t::GetShatterPanelMode() const {
    return GetSchemaValue<uint64_t>(m_ptr, "shard_model_desc_t", "m_ShatterPanelMode");
}
void Gshard_model_desc_t::SetShatterPanelMode(uint64_t value) {
    SetSchemaValue(m_ptr, "shard_model_desc_t", "m_ShatterPanelMode", true, value);
}
Vector2D Gshard_model_desc_t::GetPanelSize() const {
    return GetSchemaValue<Vector2D>(m_ptr, "shard_model_desc_t", "m_vecPanelSize");
}
void Gshard_model_desc_t::SetPanelSize(Vector2D value) {
    SetSchemaValue(m_ptr, "shard_model_desc_t", "m_vecPanelSize", true, value);
}
Vector2D Gshard_model_desc_t::GetStressPositionA() const {
    return GetSchemaValue<Vector2D>(m_ptr, "shard_model_desc_t", "m_vecStressPositionA");
}
void Gshard_model_desc_t::SetStressPositionA(Vector2D value) {
    SetSchemaValue(m_ptr, "shard_model_desc_t", "m_vecStressPositionA", true, value);
}
Vector2D Gshard_model_desc_t::GetStressPositionB() const {
    return GetSchemaValue<Vector2D>(m_ptr, "shard_model_desc_t", "m_vecStressPositionB");
}
void Gshard_model_desc_t::SetStressPositionB(Vector2D value) {
    SetSchemaValue(m_ptr, "shard_model_desc_t", "m_vecStressPositionB", true, value);
}
std::vector<Vector2D> Gshard_model_desc_t::GetPanelVertices() const {
    CUtlVector<Vector2D>* vec = GetSchemaValue<CUtlVector<Vector2D>*>(m_ptr, "shard_model_desc_t", "m_vecPanelVertices"); std::vector<Vector2D> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void Gshard_model_desc_t::SetPanelVertices(std::vector<Vector2D> value) {
    SetSchemaValueCUtlVector<Vector2D>(m_ptr, "shard_model_desc_t", "m_vecPanelVertices", true, value);
}
float Gshard_model_desc_t::GetGlassHalfThickness() const {
    return GetSchemaValue<float>(m_ptr, "shard_model_desc_t", "m_flGlassHalfThickness");
}
void Gshard_model_desc_t::SetGlassHalfThickness(float value) {
    SetSchemaValue(m_ptr, "shard_model_desc_t", "m_flGlassHalfThickness", true, value);
}
bool Gshard_model_desc_t::GetHasParent() const {
    return GetSchemaValue<bool>(m_ptr, "shard_model_desc_t", "m_bHasParent");
}
void Gshard_model_desc_t::SetHasParent(bool value) {
    SetSchemaValue(m_ptr, "shard_model_desc_t", "m_bHasParent", true, value);
}
bool Gshard_model_desc_t::GetParentFrozen() const {
    return GetSchemaValue<bool>(m_ptr, "shard_model_desc_t", "m_bParentFrozen");
}
void Gshard_model_desc_t::SetParentFrozen(bool value) {
    SetSchemaValue(m_ptr, "shard_model_desc_t", "m_bParentFrozen", true, value);
}
CUtlStringToken Gshard_model_desc_t::GetSurfacePropStringToken() const {
    return GetSchemaValue<CUtlStringToken>(m_ptr, "shard_model_desc_t", "m_SurfacePropStringToken");
}
void Gshard_model_desc_t::SetSurfacePropStringToken(CUtlStringToken value) {
    SetSchemaValue(m_ptr, "shard_model_desc_t", "m_SurfacePropStringToken", true, value);
}
std::string Gshard_model_desc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Gshard_model_desc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassshard_model_desc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gshard_model_desc_t>("shard_model_desc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ModelID", &Gshard_model_desc_t::GetModelID, &Gshard_model_desc_t::SetModelID)
        .addProperty("Solid", &Gshard_model_desc_t::GetSolid, &Gshard_model_desc_t::SetSolid)
        .addProperty("ShatterPanelMode", &Gshard_model_desc_t::GetShatterPanelMode, &Gshard_model_desc_t::SetShatterPanelMode)
        .addProperty("PanelSize", &Gshard_model_desc_t::GetPanelSize, &Gshard_model_desc_t::SetPanelSize)
        .addProperty("StressPositionA", &Gshard_model_desc_t::GetStressPositionA, &Gshard_model_desc_t::SetStressPositionA)
        .addProperty("StressPositionB", &Gshard_model_desc_t::GetStressPositionB, &Gshard_model_desc_t::SetStressPositionB)
        .addProperty("PanelVertices", &Gshard_model_desc_t::GetPanelVertices, &Gshard_model_desc_t::SetPanelVertices)
        .addProperty("GlassHalfThickness", &Gshard_model_desc_t::GetGlassHalfThickness, &Gshard_model_desc_t::SetGlassHalfThickness)
        .addProperty("HasParent", &Gshard_model_desc_t::GetHasParent, &Gshard_model_desc_t::SetHasParent)
        .addProperty("ParentFrozen", &Gshard_model_desc_t::GetParentFrozen, &Gshard_model_desc_t::SetParentFrozen)
        .addProperty("SurfacePropStringToken", &Gshard_model_desc_t::GetSurfacePropStringToken, &Gshard_model_desc_t::SetSurfacePropStringToken)
        .addFunction("ToPtr", &Gshard_model_desc_t::ToPtr)
        .addFunction("IsValid", &Gshard_model_desc_t::IsValid)
        .endClass();
}