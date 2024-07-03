#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeTaperedCapsuleStretch_t::GFeTaperedCapsuleStretch_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeTaperedCapsuleStretch_t::GFeTaperedCapsuleStretch_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint16_t> GFeTaperedCapsuleStretch_t::GetNode() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeTaperedCapsuleStretch_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeTaperedCapsuleStretch_t::SetNode(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeTaperedCapsuleStretch_t", "nNode"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeTaperedCapsuleStretch_t", "nNode", true, outValue);
}
uint16_t GFeTaperedCapsuleStretch_t::GetCollisionMask() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeTaperedCapsuleStretch_t", "nCollisionMask");
}
void GFeTaperedCapsuleStretch_t::SetCollisionMask(uint16_t value) {
    SetSchemaValue(m_ptr, "FeTaperedCapsuleStretch_t", "nCollisionMask", true, value);
}
uint16_t GFeTaperedCapsuleStretch_t::GetDummy() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeTaperedCapsuleStretch_t", "nDummy");
}
void GFeTaperedCapsuleStretch_t::SetDummy(uint16_t value) {
    SetSchemaValue(m_ptr, "FeTaperedCapsuleStretch_t", "nDummy", true, value);
}
std::vector<float> GFeTaperedCapsuleStretch_t::GetRadius() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "FeTaperedCapsuleStretch_t", "flRadius"); std::vector<float> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeTaperedCapsuleStretch_t::SetRadius(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "FeTaperedCapsuleStretch_t", "flRadius"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeTaperedCapsuleStretch_t", "flRadius", true, outValue);
}
std::string GFeTaperedCapsuleStretch_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeTaperedCapsuleStretch_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeTaperedCapsuleStretch_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeTaperedCapsuleStretch_t>("FeTaperedCapsuleStretch_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Node", &GFeTaperedCapsuleStretch_t::GetNode, &GFeTaperedCapsuleStretch_t::SetNode)
        .addProperty("CollisionMask", &GFeTaperedCapsuleStretch_t::GetCollisionMask, &GFeTaperedCapsuleStretch_t::SetCollisionMask)
        .addProperty("Dummy", &GFeTaperedCapsuleStretch_t::GetDummy, &GFeTaperedCapsuleStretch_t::SetDummy)
        .addProperty("Radius", &GFeTaperedCapsuleStretch_t::GetRadius, &GFeTaperedCapsuleStretch_t::SetRadius)
        .addFunction("ToPtr", &GFeTaperedCapsuleStretch_t::ToPtr)
        .addFunction("IsValid", &GFeTaperedCapsuleStretch_t::IsValid)
        .endClass();
}