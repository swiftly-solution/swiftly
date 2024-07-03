#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNetworkOriginCellCoordQuantizedVector::GCNetworkOriginCellCoordQuantizedVector(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNetworkOriginCellCoordQuantizedVector::GCNetworkOriginCellCoordQuantizedVector(void *ptr) {
    m_ptr = ptr;
}
uint16_t GCNetworkOriginCellCoordQuantizedVector::GetCellX() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_cellX");
}
void GCNetworkOriginCellCoordQuantizedVector::SetCellX(uint16_t value) {
    SetSchemaValue(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_cellX", false, value);
}
uint16_t GCNetworkOriginCellCoordQuantizedVector::GetCellY() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_cellY");
}
void GCNetworkOriginCellCoordQuantizedVector::SetCellY(uint16_t value) {
    SetSchemaValue(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_cellY", false, value);
}
uint16_t GCNetworkOriginCellCoordQuantizedVector::GetCellZ() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_cellZ");
}
void GCNetworkOriginCellCoordQuantizedVector::SetCellZ(uint16_t value) {
    SetSchemaValue(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_cellZ", false, value);
}
uint16_t GCNetworkOriginCellCoordQuantizedVector::GetOutsideWorld() const {
    return GetSchemaValue<uint16_t>(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_nOutsideWorld");
}
void GCNetworkOriginCellCoordQuantizedVector::SetOutsideWorld(uint16_t value) {
    SetSchemaValue(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_nOutsideWorld", false, value);
}
float GCNetworkOriginCellCoordQuantizedVector::GetX() const {
    return GetSchemaValue<float>(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_vecX");
}
void GCNetworkOriginCellCoordQuantizedVector::SetX(float value) {
    SetSchemaValue(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_vecX", false, value);
}
float GCNetworkOriginCellCoordQuantizedVector::GetY() const {
    return GetSchemaValue<float>(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_vecY");
}
void GCNetworkOriginCellCoordQuantizedVector::SetY(float value) {
    SetSchemaValue(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_vecY", false, value);
}
float GCNetworkOriginCellCoordQuantizedVector::GetZ() const {
    return GetSchemaValue<float>(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_vecZ");
}
void GCNetworkOriginCellCoordQuantizedVector::SetZ(float value) {
    SetSchemaValue(m_ptr, "CNetworkOriginCellCoordQuantizedVector", "m_vecZ", false, value);
}
std::string GCNetworkOriginCellCoordQuantizedVector::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNetworkOriginCellCoordQuantizedVector::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNetworkOriginCellCoordQuantizedVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNetworkOriginCellCoordQuantizedVector>("CNetworkOriginCellCoordQuantizedVector")
        .addConstructor<void (*)(std::string)>()
        .addProperty("CellX", &GCNetworkOriginCellCoordQuantizedVector::GetCellX, &GCNetworkOriginCellCoordQuantizedVector::SetCellX)
        .addProperty("CellY", &GCNetworkOriginCellCoordQuantizedVector::GetCellY, &GCNetworkOriginCellCoordQuantizedVector::SetCellY)
        .addProperty("CellZ", &GCNetworkOriginCellCoordQuantizedVector::GetCellZ, &GCNetworkOriginCellCoordQuantizedVector::SetCellZ)
        .addProperty("OutsideWorld", &GCNetworkOriginCellCoordQuantizedVector::GetOutsideWorld, &GCNetworkOriginCellCoordQuantizedVector::SetOutsideWorld)
        .addProperty("X", &GCNetworkOriginCellCoordQuantizedVector::GetX, &GCNetworkOriginCellCoordQuantizedVector::SetX)
        .addProperty("Y", &GCNetworkOriginCellCoordQuantizedVector::GetY, &GCNetworkOriginCellCoordQuantizedVector::SetY)
        .addProperty("Z", &GCNetworkOriginCellCoordQuantizedVector::GetZ, &GCNetworkOriginCellCoordQuantizedVector::SetZ)
        .addFunction("ToPtr", &GCNetworkOriginCellCoordQuantizedVector::ToPtr)
        .addFunction("IsValid", &GCNetworkOriginCellCoordQuantizedVector::IsValid)
        .endClass();
}