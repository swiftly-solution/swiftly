#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCNetworkOriginQuantizedVector::GCNetworkOriginQuantizedVector(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCNetworkOriginQuantizedVector::GCNetworkOriginQuantizedVector(void *ptr) {
    m_ptr = ptr;
}
float GCNetworkOriginQuantizedVector::GetX() const {
    return GetSchemaValue<float>(m_ptr, "CNetworkOriginQuantizedVector", "m_vecX");
}
void GCNetworkOriginQuantizedVector::SetX(float value) {
    SetSchemaValue(m_ptr, "CNetworkOriginQuantizedVector", "m_vecX", false, value);
}
float GCNetworkOriginQuantizedVector::GetY() const {
    return GetSchemaValue<float>(m_ptr, "CNetworkOriginQuantizedVector", "m_vecY");
}
void GCNetworkOriginQuantizedVector::SetY(float value) {
    SetSchemaValue(m_ptr, "CNetworkOriginQuantizedVector", "m_vecY", false, value);
}
float GCNetworkOriginQuantizedVector::GetZ() const {
    return GetSchemaValue<float>(m_ptr, "CNetworkOriginQuantizedVector", "m_vecZ");
}
void GCNetworkOriginQuantizedVector::SetZ(float value) {
    SetSchemaValue(m_ptr, "CNetworkOriginQuantizedVector", "m_vecZ", false, value);
}
std::string GCNetworkOriginQuantizedVector::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCNetworkOriginQuantizedVector::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCNetworkOriginQuantizedVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNetworkOriginQuantizedVector>("CNetworkOriginQuantizedVector")
        .addConstructor<void (*)(std::string)>()
        .addProperty("X", &GCNetworkOriginQuantizedVector::GetX, &GCNetworkOriginQuantizedVector::SetX)
        .addProperty("Y", &GCNetworkOriginQuantizedVector::GetY, &GCNetworkOriginQuantizedVector::SetY)
        .addProperty("Z", &GCNetworkOriginQuantizedVector::GetZ, &GCNetworkOriginQuantizedVector::SetZ)
        .addFunction("ToPtr", &GCNetworkOriginQuantizedVector::ToPtr)
        .addFunction("IsValid", &GCNetworkOriginQuantizedVector::IsValid)
        .endClass();
}