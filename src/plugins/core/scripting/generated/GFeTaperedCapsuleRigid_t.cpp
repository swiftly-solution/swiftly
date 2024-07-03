#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeTaperedCapsuleRigid_t::GFeTaperedCapsuleRigid_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeTaperedCapsuleRigid_t::GFeTaperedCapsuleRigid_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<float> GFeTaperedCapsuleRigid_t::GetSphere() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "FeTaperedCapsuleRigid_t", "vSphere"); std::vector<float> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeTaperedCapsuleRigid_t::SetSphere(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "FeTaperedCapsuleRigid_t", "vSphere"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeTaperedCapsuleRigid_t", "vSphere", true, outValue);
}
uint16_t GFeTaperedCapsuleRigid_t::GetNode() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeTaperedCapsuleRigid_t", "nNode");
}
void GFeTaperedCapsuleRigid_t::SetNode(uint16_t value) {
    SetSchemaValue(m_ptr, "FeTaperedCapsuleRigid_t", "nNode", true, value);
}
uint16_t GFeTaperedCapsuleRigid_t::GetCollisionMask() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeTaperedCapsuleRigid_t", "nCollisionMask");
}
void GFeTaperedCapsuleRigid_t::SetCollisionMask(uint16_t value) {
    SetSchemaValue(m_ptr, "FeTaperedCapsuleRigid_t", "nCollisionMask", true, value);
}
uint16_t GFeTaperedCapsuleRigid_t::GetVertexMapIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeTaperedCapsuleRigid_t", "nVertexMapIndex");
}
void GFeTaperedCapsuleRigid_t::SetVertexMapIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "FeTaperedCapsuleRigid_t", "nVertexMapIndex", true, value);
}
uint16_t GFeTaperedCapsuleRigid_t::GetFlags() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeTaperedCapsuleRigid_t", "nFlags");
}
void GFeTaperedCapsuleRigid_t::SetFlags(uint16_t value) {
    SetSchemaValue(m_ptr, "FeTaperedCapsuleRigid_t", "nFlags", true, value);
}
std::string GFeTaperedCapsuleRigid_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeTaperedCapsuleRigid_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeTaperedCapsuleRigid_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeTaperedCapsuleRigid_t>("FeTaperedCapsuleRigid_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Sphere", &GFeTaperedCapsuleRigid_t::GetSphere, &GFeTaperedCapsuleRigid_t::SetSphere)
        .addProperty("Node", &GFeTaperedCapsuleRigid_t::GetNode, &GFeTaperedCapsuleRigid_t::SetNode)
        .addProperty("CollisionMask", &GFeTaperedCapsuleRigid_t::GetCollisionMask, &GFeTaperedCapsuleRigid_t::SetCollisionMask)
        .addProperty("VertexMapIndex", &GFeTaperedCapsuleRigid_t::GetVertexMapIndex, &GFeTaperedCapsuleRigid_t::SetVertexMapIndex)
        .addProperty("Flags", &GFeTaperedCapsuleRigid_t::GetFlags, &GFeTaperedCapsuleRigid_t::SetFlags)
        .addFunction("ToPtr", &GFeTaperedCapsuleRigid_t::ToPtr)
        .addFunction("IsValid", &GFeTaperedCapsuleRigid_t::IsValid)
        .endClass();
}