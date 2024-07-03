#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GOldFeEdge_t::GOldFeEdge_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GOldFeEdge_t::GOldFeEdge_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<float> GOldFeEdge_t::GetK() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "OldFeEdge_t", "m_flK"); std::vector<float> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GOldFeEdge_t::SetK(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "OldFeEdge_t", "m_flK"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "OldFeEdge_t", "m_flK", true, outValue);
}
float GOldFeEdge_t::GetInvA() const {
    return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "invA");
}
void GOldFeEdge_t::SetInvA(float value) {
    SetSchemaValue(m_ptr, "OldFeEdge_t", "invA", true, value);
}
float GOldFeEdge_t::GetT() const {
    return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "t");
}
void GOldFeEdge_t::SetT(float value) {
    SetSchemaValue(m_ptr, "OldFeEdge_t", "t", true, value);
}
float GOldFeEdge_t::GetThetaRelaxed() const {
    return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "flThetaRelaxed");
}
void GOldFeEdge_t::SetThetaRelaxed(float value) {
    SetSchemaValue(m_ptr, "OldFeEdge_t", "flThetaRelaxed", true, value);
}
float GOldFeEdge_t::GetThetaFactor() const {
    return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "flThetaFactor");
}
void GOldFeEdge_t::SetThetaFactor(float value) {
    SetSchemaValue(m_ptr, "OldFeEdge_t", "flThetaFactor", true, value);
}
float GOldFeEdge_t::GetC01() const {
    return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "c01");
}
void GOldFeEdge_t::SetC01(float value) {
    SetSchemaValue(m_ptr, "OldFeEdge_t", "c01", true, value);
}
float GOldFeEdge_t::GetC02() const {
    return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "c02");
}
void GOldFeEdge_t::SetC02(float value) {
    SetSchemaValue(m_ptr, "OldFeEdge_t", "c02", true, value);
}
float GOldFeEdge_t::GetC03() const {
    return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "c03");
}
void GOldFeEdge_t::SetC03(float value) {
    SetSchemaValue(m_ptr, "OldFeEdge_t", "c03", true, value);
}
float GOldFeEdge_t::GetC04() const {
    return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "c04");
}
void GOldFeEdge_t::SetC04(float value) {
    SetSchemaValue(m_ptr, "OldFeEdge_t", "c04", true, value);
}
float GOldFeEdge_t::GetAxialModelDist() const {
    return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "flAxialModelDist");
}
void GOldFeEdge_t::SetAxialModelDist(float value) {
    SetSchemaValue(m_ptr, "OldFeEdge_t", "flAxialModelDist", true, value);
}
std::vector<float> GOldFeEdge_t::GetAxialModelWeights() const {
    float* outValue = GetSchemaValue<float*>(m_ptr, "OldFeEdge_t", "flAxialModelWeights"); std::vector<float> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GOldFeEdge_t::SetAxialModelWeights(std::vector<float> value) {
    float* outValue = GetSchemaValue<float*>(m_ptr, "OldFeEdge_t", "flAxialModelWeights"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "OldFeEdge_t", "flAxialModelWeights", true, outValue);
}
std::vector<uint16_t> GOldFeEdge_t::GetNode() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "OldFeEdge_t", "m_nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret;
}
void GOldFeEdge_t::SetNode(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "OldFeEdge_t", "m_nNode"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "OldFeEdge_t", "m_nNode", true, outValue);
}
std::string GOldFeEdge_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GOldFeEdge_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassOldFeEdge_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GOldFeEdge_t>("OldFeEdge_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("K", &GOldFeEdge_t::GetK, &GOldFeEdge_t::SetK)
        .addProperty("InvA", &GOldFeEdge_t::GetInvA, &GOldFeEdge_t::SetInvA)
        .addProperty("T", &GOldFeEdge_t::GetT, &GOldFeEdge_t::SetT)
        .addProperty("ThetaRelaxed", &GOldFeEdge_t::GetThetaRelaxed, &GOldFeEdge_t::SetThetaRelaxed)
        .addProperty("ThetaFactor", &GOldFeEdge_t::GetThetaFactor, &GOldFeEdge_t::SetThetaFactor)
        .addProperty("C01", &GOldFeEdge_t::GetC01, &GOldFeEdge_t::SetC01)
        .addProperty("C02", &GOldFeEdge_t::GetC02, &GOldFeEdge_t::SetC02)
        .addProperty("C03", &GOldFeEdge_t::GetC03, &GOldFeEdge_t::SetC03)
        .addProperty("C04", &GOldFeEdge_t::GetC04, &GOldFeEdge_t::SetC04)
        .addProperty("AxialModelDist", &GOldFeEdge_t::GetAxialModelDist, &GOldFeEdge_t::SetAxialModelDist)
        .addProperty("AxialModelWeights", &GOldFeEdge_t::GetAxialModelWeights, &GOldFeEdge_t::SetAxialModelWeights)
        .addProperty("Node", &GOldFeEdge_t::GetNode, &GOldFeEdge_t::SetNode)
        .addFunction("ToPtr", &GOldFeEdge_t::ToPtr)
        .addFunction("IsValid", &GOldFeEdge_t::IsValid)
        .endClass();
}