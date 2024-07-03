#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNetworkViewOffsetVector::GCNetworkViewOffsetVector(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNetworkViewOffsetVector::GCNetworkViewOffsetVector(void *ptr) {
    m_ptr = ptr;
}
float GCNetworkViewOffsetVector::GetX() const {
    return GetSchemaValue<float>(m_ptr, "CNetworkViewOffsetVector", "m_vecX");
}
void GCNetworkViewOffsetVector::SetX(float value) {
    SetSchemaValue(m_ptr, "CNetworkViewOffsetVector", "m_vecX", false, value);
}
float GCNetworkViewOffsetVector::GetY() const {
    return GetSchemaValue<float>(m_ptr, "CNetworkViewOffsetVector", "m_vecY");
}
void GCNetworkViewOffsetVector::SetY(float value) {
    SetSchemaValue(m_ptr, "CNetworkViewOffsetVector", "m_vecY", false, value);
}
float GCNetworkViewOffsetVector::GetZ() const {
    return GetSchemaValue<float>(m_ptr, "CNetworkViewOffsetVector", "m_vecZ");
}
void GCNetworkViewOffsetVector::SetZ(float value) {
    SetSchemaValue(m_ptr, "CNetworkViewOffsetVector", "m_vecZ", false, value);
}
std::string GCNetworkViewOffsetVector::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNetworkViewOffsetVector::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNetworkViewOffsetVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNetworkViewOffsetVector>("CNetworkViewOffsetVector")
        .addConstructor<void (*)(std::string)>()
        .addProperty("X", &GCNetworkViewOffsetVector::GetX, &GCNetworkViewOffsetVector::SetX)
        .addProperty("Y", &GCNetworkViewOffsetVector::GetY, &GCNetworkViewOffsetVector::SetY)
        .addProperty("Z", &GCNetworkViewOffsetVector::GetZ, &GCNetworkViewOffsetVector::SetZ)
        .addFunction("ToPtr", &GCNetworkViewOffsetVector::ToPtr)
        .addFunction("IsValid", &GCNetworkViewOffsetVector::IsValid)
        .endClass();
}