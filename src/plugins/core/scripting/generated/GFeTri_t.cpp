#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeTri_t::GFeTri_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeTri_t::GFeTri_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint16_t> GFeTri_t::GetNode() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeTri_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeTri_t::SetNode(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeTri_t", "nNode"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeTri_t", "nNode", true, outValue);
}
float GFeTri_t::GetW1() const {
    return GetSchemaValue<float>(m_ptr, "FeTri_t", "w1");
}
void GFeTri_t::SetW1(float value) {
    SetSchemaValue(m_ptr, "FeTri_t", "w1", true, value);
}
float GFeTri_t::GetW2() const {
    return GetSchemaValue<float>(m_ptr, "FeTri_t", "w2");
}
void GFeTri_t::SetW2(float value) {
    SetSchemaValue(m_ptr, "FeTri_t", "w2", true, value);
}
float GFeTri_t::Get1x() const {
    return GetSchemaValue<float>(m_ptr, "FeTri_t", "v1x");
}
void GFeTri_t::Set1x(float value) {
    SetSchemaValue(m_ptr, "FeTri_t", "v1x", true, value);
}
Vector2D GFeTri_t::Get2() const {
    return GetSchemaValue<Vector2D>(m_ptr, "FeTri_t", "v2");
}
void GFeTri_t::Set2(Vector2D value) {
    SetSchemaValue(m_ptr, "FeTri_t", "v2", true, value);
}
std::string GFeTri_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeTri_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeTri_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeTri_t>("FeTri_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Node", &GFeTri_t::GetNode, &GFeTri_t::SetNode)
        .addProperty("W1", &GFeTri_t::GetW1, &GFeTri_t::SetW1)
        .addProperty("W2", &GFeTri_t::GetW2, &GFeTri_t::SetW2)
        .addProperty("1x", &GFeTri_t::Get1x, &GFeTri_t::Set1x)
        .addProperty("2", &GFeTri_t::Get2, &GFeTri_t::Set2)
        .addFunction("ToPtr", &GFeTri_t::ToPtr)
        .addFunction("IsValid", &GFeTri_t::IsValid)
        .endClass();
}