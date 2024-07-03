#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNetworkVelocityVector::GCNetworkVelocityVector(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNetworkVelocityVector::GCNetworkVelocityVector(void *ptr) {
    m_ptr = ptr;
}
float GCNetworkVelocityVector::GetX() const {
    return GetSchemaValue<float>(m_ptr, "CNetworkVelocityVector", "m_vecX");
}
void GCNetworkVelocityVector::SetX(float value) {
    SetSchemaValue(m_ptr, "CNetworkVelocityVector", "m_vecX", false, value);
}
float GCNetworkVelocityVector::GetY() const {
    return GetSchemaValue<float>(m_ptr, "CNetworkVelocityVector", "m_vecY");
}
void GCNetworkVelocityVector::SetY(float value) {
    SetSchemaValue(m_ptr, "CNetworkVelocityVector", "m_vecY", false, value);
}
float GCNetworkVelocityVector::GetZ() const {
    return GetSchemaValue<float>(m_ptr, "CNetworkVelocityVector", "m_vecZ");
}
void GCNetworkVelocityVector::SetZ(float value) {
    SetSchemaValue(m_ptr, "CNetworkVelocityVector", "m_vecZ", false, value);
}
std::string GCNetworkVelocityVector::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNetworkVelocityVector::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNetworkVelocityVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNetworkVelocityVector>("CNetworkVelocityVector")
        .addConstructor<void (*)(std::string)>()
        .addProperty("X", &GCNetworkVelocityVector::GetX, &GCNetworkVelocityVector::SetX)
        .addProperty("Y", &GCNetworkVelocityVector::GetY, &GCNetworkVelocityVector::SetY)
        .addProperty("Z", &GCNetworkVelocityVector::GetZ, &GCNetworkVelocityVector::SetZ)
        .addFunction("ToPtr", &GCNetworkVelocityVector::ToPtr)
        .addFunction("IsValid", &GCNetworkVelocityVector::IsValid)
        .endClass();
}