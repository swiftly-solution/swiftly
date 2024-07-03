#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFourVectors2D::GFourVectors2D(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFourVectors2D::GFourVectors2D(void *ptr) {
    m_ptr = ptr;
}
float GFourVectors2D::GetX() const {
    return GetSchemaValue<float>(m_ptr, "FourVectors2D", "x");
}
void GFourVectors2D::SetX(float value) {
    SetSchemaValue(m_ptr, "FourVectors2D", "x", false, value);
}
float GFourVectors2D::GetY() const {
    return GetSchemaValue<float>(m_ptr, "FourVectors2D", "y");
}
void GFourVectors2D::SetY(float value) {
    SetSchemaValue(m_ptr, "FourVectors2D", "y", false, value);
}
std::string GFourVectors2D::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFourVectors2D::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFourVectors2D(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFourVectors2D>("FourVectors2D")
        .addConstructor<void (*)(std::string)>()
        .addProperty("X", &GFourVectors2D::GetX, &GFourVectors2D::SetX)
        .addProperty("Y", &GFourVectors2D::GetY, &GFourVectors2D::SetY)
        .addFunction("ToPtr", &GFourVectors2D::ToPtr)
        .addFunction("IsValid", &GFourVectors2D::IsValid)
        .endClass();
}