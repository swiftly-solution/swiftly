#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeBoxRigid_t::GFeBoxRigid_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeBoxRigid_t::GFeBoxRigid_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GFeBoxRigid_t::GetNode() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeBoxRigid_t", "nNode");
}
void GFeBoxRigid_t::SetNode(uint16_t value) {
    SetSchemaValue(m_ptr, "FeBoxRigid_t", "nNode", true, value);
}
uint16_t GFeBoxRigid_t::GetCollisionMask() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeBoxRigid_t", "nCollisionMask");
}
void GFeBoxRigid_t::SetCollisionMask(uint16_t value) {
    SetSchemaValue(m_ptr, "FeBoxRigid_t", "nCollisionMask", true, value);
}
Vector GFeBoxRigid_t::GetSize() const {
    return GetSchemaValue<Vector>(m_ptr, "FeBoxRigid_t", "vSize");
}
void GFeBoxRigid_t::SetSize(Vector value) {
    SetSchemaValue(m_ptr, "FeBoxRigid_t", "vSize", true, value);
}
uint16_t GFeBoxRigid_t::GetVertexMapIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeBoxRigid_t", "nVertexMapIndex");
}
void GFeBoxRigid_t::SetVertexMapIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "FeBoxRigid_t", "nVertexMapIndex", true, value);
}
uint16_t GFeBoxRigid_t::GetFlags() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeBoxRigid_t", "nFlags");
}
void GFeBoxRigid_t::SetFlags(uint16_t value) {
    SetSchemaValue(m_ptr, "FeBoxRigid_t", "nFlags", true, value);
}
std::string GFeBoxRigid_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeBoxRigid_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeBoxRigid_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeBoxRigid_t>("FeBoxRigid_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Node", &GFeBoxRigid_t::GetNode, &GFeBoxRigid_t::SetNode)
        .addProperty("CollisionMask", &GFeBoxRigid_t::GetCollisionMask, &GFeBoxRigid_t::SetCollisionMask)
        .addProperty("Size", &GFeBoxRigid_t::GetSize, &GFeBoxRigid_t::SetSize)
        .addProperty("VertexMapIndex", &GFeBoxRigid_t::GetVertexMapIndex, &GFeBoxRigid_t::SetVertexMapIndex)
        .addProperty("Flags", &GFeBoxRigid_t::GetFlags, &GFeBoxRigid_t::SetFlags)
        .addFunction("ToPtr", &GFeBoxRigid_t::ToPtr)
        .addFunction("IsValid", &GFeBoxRigid_t::IsValid)
        .endClass();
}