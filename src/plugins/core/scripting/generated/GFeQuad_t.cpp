#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeQuad_t::GFeQuad_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeQuad_t::GFeQuad_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint16_t> GFeQuad_t::GetNode() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeQuad_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeQuad_t::SetNode(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeQuad_t", "nNode"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeQuad_t", "nNode", true, outValue);
}
float GFeQuad_t::GetSlack() const {
    return GetSchemaValue<float>(m_ptr, "FeQuad_t", "flSlack");
}
void GFeQuad_t::SetSlack(float value) {
    SetSchemaValue(m_ptr, "FeQuad_t", "flSlack", true, value);
}
std::vector<Vector4D> GFeQuad_t::GetShape() const {
    Vector4D* outValue = GetSchemaValue<Vector4D*>(m_ptr, "FeQuad_t", "vShape"); std::vector<Vector4D> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeQuad_t::SetShape(std::vector<Vector4D> value) {
    Vector4D* outValue = GetSchemaValue<Vector4D*>(m_ptr, "FeQuad_t", "vShape"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeQuad_t", "vShape", true, outValue);
}
std::string GFeQuad_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeQuad_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeQuad_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeQuad_t>("FeQuad_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Node", &GFeQuad_t::GetNode, &GFeQuad_t::SetNode)
        .addProperty("Slack", &GFeQuad_t::GetSlack, &GFeQuad_t::SetSlack)
        .addProperty("Shape", &GFeQuad_t::GetShape, &GFeQuad_t::SetShape)
        .addFunction("ToPtr", &GFeQuad_t::ToPtr)
        .addFunction("IsValid", &GFeQuad_t::IsValid)
        .endClass();
}