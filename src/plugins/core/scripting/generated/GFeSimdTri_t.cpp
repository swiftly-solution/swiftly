#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeSimdTri_t::GFeSimdTri_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeSimdTri_t::GFeSimdTri_t(void *ptr) {
    m_ptr = ptr;
}
float GFeSimdTri_t::GetW1() const {
    return GetSchemaValue<float>(m_ptr, "FeSimdTri_t", "w1");
}
void GFeSimdTri_t::SetW1(float value) {
    SetSchemaValue(m_ptr, "FeSimdTri_t", "w1", true, value);
}
float GFeSimdTri_t::GetW2() const {
    return GetSchemaValue<float>(m_ptr, "FeSimdTri_t", "w2");
}
void GFeSimdTri_t::SetW2(float value) {
    SetSchemaValue(m_ptr, "FeSimdTri_t", "w2", true, value);
}
float GFeSimdTri_t::Get1x() const {
    return GetSchemaValue<float>(m_ptr, "FeSimdTri_t", "v1x");
}
void GFeSimdTri_t::Set1x(float value) {
    SetSchemaValue(m_ptr, "FeSimdTri_t", "v1x", true, value);
}
std::string GFeSimdTri_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeSimdTri_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeSimdTri_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSimdTri_t>("FeSimdTri_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("W1", &GFeSimdTri_t::GetW1, &GFeSimdTri_t::SetW1)
        .addProperty("W2", &GFeSimdTri_t::GetW2, &GFeSimdTri_t::SetW2)
        .addProperty("1x", &GFeSimdTri_t::Get1x, &GFeSimdTri_t::Set1x)
        .addFunction("ToPtr", &GFeSimdTri_t::ToPtr)
        .addFunction("IsValid", &GFeSimdTri_t::IsValid)
        .endClass();
}