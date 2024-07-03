#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFourQuaternions::GFourQuaternions(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFourQuaternions::GFourQuaternions(void *ptr) {
    m_ptr = ptr;
}
float GFourQuaternions::GetX() const {
    return GetSchemaValue<float>(m_ptr, "FourQuaternions", "x");
}
void GFourQuaternions::SetX(float value) {
    SetSchemaValue(m_ptr, "FourQuaternions", "x", false, value);
}
float GFourQuaternions::GetY() const {
    return GetSchemaValue<float>(m_ptr, "FourQuaternions", "y");
}
void GFourQuaternions::SetY(float value) {
    SetSchemaValue(m_ptr, "FourQuaternions", "y", false, value);
}
float GFourQuaternions::GetZ() const {
    return GetSchemaValue<float>(m_ptr, "FourQuaternions", "z");
}
void GFourQuaternions::SetZ(float value) {
    SetSchemaValue(m_ptr, "FourQuaternions", "z", false, value);
}
float GFourQuaternions::GetW() const {
    return GetSchemaValue<float>(m_ptr, "FourQuaternions", "w");
}
void GFourQuaternions::SetW(float value) {
    SetSchemaValue(m_ptr, "FourQuaternions", "w", false, value);
}
std::string GFourQuaternions::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFourQuaternions::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFourQuaternions(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFourQuaternions>("FourQuaternions")
        .addConstructor<void (*)(std::string)>()
        .addProperty("X", &GFourQuaternions::GetX, &GFourQuaternions::SetX)
        .addProperty("Y", &GFourQuaternions::GetY, &GFourQuaternions::SetY)
        .addProperty("Z", &GFourQuaternions::GetZ, &GFourQuaternions::SetZ)
        .addProperty("W", &GFourQuaternions::GetW, &GFourQuaternions::SetW)
        .addFunction("ToPtr", &GFourQuaternions::ToPtr)
        .addFunction("IsValid", &GFourQuaternions::IsValid)
        .endClass();
}