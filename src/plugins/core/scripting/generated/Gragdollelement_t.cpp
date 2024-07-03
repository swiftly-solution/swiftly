#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

Gragdollelement_t::Gragdollelement_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
Gragdollelement_t::Gragdollelement_t(void *ptr) {
    m_ptr = ptr;
}
Vector Gragdollelement_t::GetOriginParentSpace() const {
    return GetSchemaValue<Vector>(m_ptr, "ragdollelement_t", "originParentSpace");
}
void Gragdollelement_t::SetOriginParentSpace(Vector value) {
    SetSchemaValue(m_ptr, "ragdollelement_t", "originParentSpace", true, value);
}
int32_t Gragdollelement_t::GetParentIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "ragdollelement_t", "parentIndex");
}
void Gragdollelement_t::SetParentIndex(int32_t value) {
    SetSchemaValue(m_ptr, "ragdollelement_t", "parentIndex", true, value);
}
float Gragdollelement_t::GetRadius() const {
    return GetSchemaValue<float>(m_ptr, "ragdollelement_t", "m_flRadius");
}
void Gragdollelement_t::SetRadius(float value) {
    SetSchemaValue(m_ptr, "ragdollelement_t", "m_flRadius", true, value);
}
std::string Gragdollelement_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool Gragdollelement_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassragdollelement_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gragdollelement_t>("ragdollelement_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("OriginParentSpace", &Gragdollelement_t::GetOriginParentSpace, &Gragdollelement_t::SetOriginParentSpace)
        .addProperty("ParentIndex", &Gragdollelement_t::GetParentIndex, &Gragdollelement_t::SetParentIndex)
        .addProperty("Radius", &Gragdollelement_t::GetRadius, &Gragdollelement_t::SetRadius)
        .addFunction("ToPtr", &Gragdollelement_t::ToPtr)
        .addFunction("IsValid", &Gragdollelement_t::IsValid)
        .endClass();
}