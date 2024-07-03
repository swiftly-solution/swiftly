#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSmokeGrenadeProjectile::GCSmokeGrenadeProjectile(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSmokeGrenadeProjectile::GCSmokeGrenadeProjectile(void *ptr) {
    m_ptr = ptr;
}
int32_t GCSmokeGrenadeProjectile::GetSmokeEffectTickBegin() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSmokeGrenadeProjectile", "m_nSmokeEffectTickBegin");
}
void GCSmokeGrenadeProjectile::SetSmokeEffectTickBegin(int32_t value) {
    SetSchemaValue(m_ptr, "CSmokeGrenadeProjectile", "m_nSmokeEffectTickBegin", false, value);
}
bool GCSmokeGrenadeProjectile::GetDidSmokeEffect() const {
    return GetSchemaValue<bool>(m_ptr, "CSmokeGrenadeProjectile", "m_bDidSmokeEffect");
}
void GCSmokeGrenadeProjectile::SetDidSmokeEffect(bool value) {
    SetSchemaValue(m_ptr, "CSmokeGrenadeProjectile", "m_bDidSmokeEffect", false, value);
}
int32_t GCSmokeGrenadeProjectile::GetRandomSeed() const {
    return GetSchemaValue<int32_t>(m_ptr, "CSmokeGrenadeProjectile", "m_nRandomSeed");
}
void GCSmokeGrenadeProjectile::SetRandomSeed(int32_t value) {
    SetSchemaValue(m_ptr, "CSmokeGrenadeProjectile", "m_nRandomSeed", false, value);
}
Vector GCSmokeGrenadeProjectile::GetSmokeColor() const {
    return GetSchemaValue<Vector>(m_ptr, "CSmokeGrenadeProjectile", "m_vSmokeColor");
}
void GCSmokeGrenadeProjectile::SetSmokeColor(Vector value) {
    SetSchemaValue(m_ptr, "CSmokeGrenadeProjectile", "m_vSmokeColor", false, value);
}
Vector GCSmokeGrenadeProjectile::GetSmokeDetonationPos() const {
    return GetSchemaValue<Vector>(m_ptr, "CSmokeGrenadeProjectile", "m_vSmokeDetonationPos");
}
void GCSmokeGrenadeProjectile::SetSmokeDetonationPos(Vector value) {
    SetSchemaValue(m_ptr, "CSmokeGrenadeProjectile", "m_vSmokeDetonationPos", false, value);
}
std::vector<uint8> GCSmokeGrenadeProjectile::GetVoxelFrameData() const {
    CUtlVector<uint8>* vec = GetSchemaValue<CUtlVector<uint8>*>(m_ptr, "CSmokeGrenadeProjectile", "m_VoxelFrameData"); std::vector<uint8> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCSmokeGrenadeProjectile::SetVoxelFrameData(std::vector<uint8> value) {
    SetSchemaValueCUtlVector<uint8>(m_ptr, "CSmokeGrenadeProjectile", "m_VoxelFrameData", false, value);
}
float GCSmokeGrenadeProjectile::GetLastBounce() const {
    return GetSchemaValue<float>(m_ptr, "CSmokeGrenadeProjectile", "m_flLastBounce");
}
void GCSmokeGrenadeProjectile::SetLastBounce(float value) {
    SetSchemaValue(m_ptr, "CSmokeGrenadeProjectile", "m_flLastBounce", false, value);
}
float GCSmokeGrenadeProjectile::GetFllastSimulationTime() const {
    return GetSchemaValue<float>(m_ptr, "CSmokeGrenadeProjectile", "m_fllastSimulationTime");
}
void GCSmokeGrenadeProjectile::SetFllastSimulationTime(float value) {
    SetSchemaValue(m_ptr, "CSmokeGrenadeProjectile", "m_fllastSimulationTime", false, value);
}
std::string GCSmokeGrenadeProjectile::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSmokeGrenadeProjectile::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseCSGrenadeProjectile GCSmokeGrenadeProjectile::GetParent() const {
    GCBaseCSGrenadeProjectile value(m_ptr);
    return value;
}
void GCSmokeGrenadeProjectile::SetParent(GCBaseCSGrenadeProjectile value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSmokeGrenadeProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSmokeGrenadeProjectile>("CSmokeGrenadeProjectile")
        .addConstructor<void (*)(std::string)>()
        .addProperty("SmokeEffectTickBegin", &GCSmokeGrenadeProjectile::GetSmokeEffectTickBegin, &GCSmokeGrenadeProjectile::SetSmokeEffectTickBegin)
        .addProperty("DidSmokeEffect", &GCSmokeGrenadeProjectile::GetDidSmokeEffect, &GCSmokeGrenadeProjectile::SetDidSmokeEffect)
        .addProperty("RandomSeed", &GCSmokeGrenadeProjectile::GetRandomSeed, &GCSmokeGrenadeProjectile::SetRandomSeed)
        .addProperty("SmokeColor", &GCSmokeGrenadeProjectile::GetSmokeColor, &GCSmokeGrenadeProjectile::SetSmokeColor)
        .addProperty("SmokeDetonationPos", &GCSmokeGrenadeProjectile::GetSmokeDetonationPos, &GCSmokeGrenadeProjectile::SetSmokeDetonationPos)
        .addProperty("VoxelFrameData", &GCSmokeGrenadeProjectile::GetVoxelFrameData, &GCSmokeGrenadeProjectile::SetVoxelFrameData)
        .addProperty("LastBounce", &GCSmokeGrenadeProjectile::GetLastBounce, &GCSmokeGrenadeProjectile::SetLastBounce)
        .addProperty("FllastSimulationTime", &GCSmokeGrenadeProjectile::GetFllastSimulationTime, &GCSmokeGrenadeProjectile::SetFllastSimulationTime)
        .addProperty("Parent", &GCSmokeGrenadeProjectile::GetParent, &GCSmokeGrenadeProjectile::SetParent)
        .addFunction("ToPtr", &GCSmokeGrenadeProjectile::ToPtr)
        .addFunction("IsValid", &GCSmokeGrenadeProjectile::IsValid)
        .endClass();
}