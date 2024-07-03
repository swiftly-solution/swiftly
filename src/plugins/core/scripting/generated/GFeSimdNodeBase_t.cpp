#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeSimdNodeBase_t::GFeSimdNodeBase_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeSimdNodeBase_t::GFeSimdNodeBase_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint16_t> GFeSimdNodeBase_t::GetNode() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeSimdNodeBase_t::SetNode(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNode"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSimdNodeBase_t", "nNode", true, outValue);
}
std::vector<uint16_t> GFeSimdNodeBase_t::GetNodeX0() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNodeX0"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeSimdNodeBase_t::SetNodeX0(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNodeX0"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSimdNodeBase_t", "nNodeX0", true, outValue);
}
std::vector<uint16_t> GFeSimdNodeBase_t::GetNodeX1() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNodeX1"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeSimdNodeBase_t::SetNodeX1(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNodeX1"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSimdNodeBase_t", "nNodeX1", true, outValue);
}
std::vector<uint16_t> GFeSimdNodeBase_t::GetNodeY0() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNodeY0"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeSimdNodeBase_t::SetNodeY0(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNodeY0"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSimdNodeBase_t", "nNodeY0", true, outValue);
}
std::vector<uint16_t> GFeSimdNodeBase_t::GetNodeY1() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNodeY1"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeSimdNodeBase_t::SetNodeY1(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nNodeY1"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSimdNodeBase_t", "nNodeY1", true, outValue);
}
std::vector<uint16_t> GFeSimdNodeBase_t::GetDummy() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nDummy"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeSimdNodeBase_t::SetDummy(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSimdNodeBase_t", "nDummy"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSimdNodeBase_t", "nDummy", true, outValue);
}
GFourQuaternions GFeSimdNodeBase_t::GetAdjust() const {
    GFourQuaternions value(GetSchemaPtr(m_ptr, "FeSimdNodeBase_t", "qAdjust"));
    return value;
}
void GFeSimdNodeBase_t::SetAdjust(GFourQuaternions value) {
    SetSchemaValue(m_ptr, "FeSimdNodeBase_t", "qAdjust", true, value);
}
std::string GFeSimdNodeBase_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeSimdNodeBase_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeSimdNodeBase_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSimdNodeBase_t>("FeSimdNodeBase_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Node", &GFeSimdNodeBase_t::GetNode, &GFeSimdNodeBase_t::SetNode)
        .addProperty("NodeX0", &GFeSimdNodeBase_t::GetNodeX0, &GFeSimdNodeBase_t::SetNodeX0)
        .addProperty("NodeX1", &GFeSimdNodeBase_t::GetNodeX1, &GFeSimdNodeBase_t::SetNodeX1)
        .addProperty("NodeY0", &GFeSimdNodeBase_t::GetNodeY0, &GFeSimdNodeBase_t::SetNodeY0)
        .addProperty("NodeY1", &GFeSimdNodeBase_t::GetNodeY1, &GFeSimdNodeBase_t::SetNodeY1)
        .addProperty("Dummy", &GFeSimdNodeBase_t::GetDummy, &GFeSimdNodeBase_t::SetDummy)
        .addProperty("Adjust", &GFeSimdNodeBase_t::GetAdjust, &GFeSimdNodeBase_t::SetAdjust)
        .addFunction("ToPtr", &GFeSimdNodeBase_t::ToPtr)
        .addFunction("IsValid", &GFeSimdNodeBase_t::IsValid)
        .endClass();
}