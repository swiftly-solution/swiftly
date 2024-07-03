#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeSphereRigid_t::GFeSphereRigid_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeSphereRigid_t::GFeSphereRigid_t(void *ptr) {
    m_ptr = ptr;
}
float GFeSphereRigid_t::GetSphere() const {
    return GetSchemaValue<float>(m_ptr, "FeSphereRigid_t", "vSphere");
}
void GFeSphereRigid_t::SetSphere(float value) {
    SetSchemaValue(m_ptr, "FeSphereRigid_t", "vSphere", true, value);
}
uint16_t GFeSphereRigid_t::GetNode() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeSphereRigid_t", "nNode");
}
void GFeSphereRigid_t::SetNode(uint16_t value) {
    SetSchemaValue(m_ptr, "FeSphereRigid_t", "nNode", true, value);
}
uint16_t GFeSphereRigid_t::GetCollisionMask() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeSphereRigid_t", "nCollisionMask");
}
void GFeSphereRigid_t::SetCollisionMask(uint16_t value) {
    SetSchemaValue(m_ptr, "FeSphereRigid_t", "nCollisionMask", true, value);
}
uint16_t GFeSphereRigid_t::GetVertexMapIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeSphereRigid_t", "nVertexMapIndex");
}
void GFeSphereRigid_t::SetVertexMapIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "FeSphereRigid_t", "nVertexMapIndex", true, value);
}
uint16_t GFeSphereRigid_t::GetFlags() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeSphereRigid_t", "nFlags");
}
void GFeSphereRigid_t::SetFlags(uint16_t value) {
    SetSchemaValue(m_ptr, "FeSphereRigid_t", "nFlags", true, value);
}
std::string GFeSphereRigid_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeSphereRigid_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeSphereRigid_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSphereRigid_t>("FeSphereRigid_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Sphere", &GFeSphereRigid_t::GetSphere, &GFeSphereRigid_t::SetSphere)
        .addProperty("Node", &GFeSphereRigid_t::GetNode, &GFeSphereRigid_t::SetNode)
        .addProperty("CollisionMask", &GFeSphereRigid_t::GetCollisionMask, &GFeSphereRigid_t::SetCollisionMask)
        .addProperty("VertexMapIndex", &GFeSphereRigid_t::GetVertexMapIndex, &GFeSphereRigid_t::SetVertexMapIndex)
        .addProperty("Flags", &GFeSphereRigid_t::GetFlags, &GFeSphereRigid_t::SetFlags)
        .addFunction("ToPtr", &GFeSphereRigid_t::ToPtr)
        .addFunction("IsValid", &GFeSphereRigid_t::IsValid)
        .endClass();
}