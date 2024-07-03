#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFishPool::GCFishPool(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFishPool::GCFishPool(void *ptr) {
    m_ptr = ptr;
}
int32_t GCFishPool::GetFishCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "CFishPool", "m_fishCount");
}
void GCFishPool::SetFishCount(int32_t value) {
    SetSchemaValue(m_ptr, "CFishPool", "m_fishCount", false, value);
}
float GCFishPool::GetMaxRange() const {
    return GetSchemaValue<float>(m_ptr, "CFishPool", "m_maxRange");
}
void GCFishPool::SetMaxRange(float value) {
    SetSchemaValue(m_ptr, "CFishPool", "m_maxRange", false, value);
}
float GCFishPool::GetSwimDepth() const {
    return GetSchemaValue<float>(m_ptr, "CFishPool", "m_swimDepth");
}
void GCFishPool::SetSwimDepth(float value) {
    SetSchemaValue(m_ptr, "CFishPool", "m_swimDepth", false, value);
}
float GCFishPool::GetWaterLevel() const {
    return GetSchemaValue<float>(m_ptr, "CFishPool", "m_waterLevel");
}
void GCFishPool::SetWaterLevel(float value) {
    SetSchemaValue(m_ptr, "CFishPool", "m_waterLevel", false, value);
}
bool GCFishPool::GetIsDormant() const {
    return GetSchemaValue<bool>(m_ptr, "CFishPool", "m_isDormant");
}
void GCFishPool::SetIsDormant(bool value) {
    SetSchemaValue(m_ptr, "CFishPool", "m_isDormant", false, value);
}
GCountdownTimer GCFishPool::GetVisTimer() const {
    GCountdownTimer value(GetSchemaPtr(m_ptr, "CFishPool", "m_visTimer"));
    return value;
}
void GCFishPool::SetVisTimer(GCountdownTimer value) {
    SetSchemaValue(m_ptr, "CFishPool", "m_visTimer", false, value);
}
std::string GCFishPool::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFishPool::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCFishPool::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCFishPool::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFishPool(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFishPool>("CFishPool")
        .addConstructor<void (*)(std::string)>()
        .addProperty("FishCount", &GCFishPool::GetFishCount, &GCFishPool::SetFishCount)
        .addProperty("MaxRange", &GCFishPool::GetMaxRange, &GCFishPool::SetMaxRange)
        .addProperty("SwimDepth", &GCFishPool::GetSwimDepth, &GCFishPool::SetSwimDepth)
        .addProperty("WaterLevel", &GCFishPool::GetWaterLevel, &GCFishPool::SetWaterLevel)
        .addProperty("IsDormant", &GCFishPool::GetIsDormant, &GCFishPool::SetIsDormant)
        .addProperty("VisTimer", &GCFishPool::GetVisTimer, &GCFishPool::SetVisTimer)
        .addProperty("Parent", &GCFishPool::GetParent, &GCFishPool::SetParent)
        .addFunction("ToPtr", &GCFishPool::ToPtr)
        .addFunction("IsValid", &GCFishPool::IsValid)
        .endClass();
}