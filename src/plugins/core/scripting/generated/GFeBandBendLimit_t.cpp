#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeBandBendLimit_t::GFeBandBendLimit_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeBandBendLimit_t::GFeBandBendLimit_t(void *ptr) {
    m_ptr = ptr;
}
float GFeBandBendLimit_t::GetDistMin() const {
    return GetSchemaValue<float>(m_ptr, "FeBandBendLimit_t", "flDistMin");
}
void GFeBandBendLimit_t::SetDistMin(float value) {
    SetSchemaValue(m_ptr, "FeBandBendLimit_t", "flDistMin", true, value);
}
float GFeBandBendLimit_t::GetDistMax() const {
    return GetSchemaValue<float>(m_ptr, "FeBandBendLimit_t", "flDistMax");
}
void GFeBandBendLimit_t::SetDistMax(float value) {
    SetSchemaValue(m_ptr, "FeBandBendLimit_t", "flDistMax", true, value);
}
std::vector<uint16_t> GFeBandBendLimit_t::GetNode() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeBandBendLimit_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 6; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeBandBendLimit_t::SetNode(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeBandBendLimit_t", "nNode"); for(int i = 0; i < 6; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeBandBendLimit_t", "nNode", true, outValue);
}
std::string GFeBandBendLimit_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeBandBendLimit_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeBandBendLimit_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeBandBendLimit_t>("FeBandBendLimit_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("DistMin", &GFeBandBendLimit_t::GetDistMin, &GFeBandBendLimit_t::SetDistMin)
        .addProperty("DistMax", &GFeBandBendLimit_t::GetDistMax, &GFeBandBendLimit_t::SetDistMax)
        .addProperty("Node", &GFeBandBendLimit_t::GetNode, &GFeBandBendLimit_t::SetNode)
        .addFunction("ToPtr", &GFeBandBendLimit_t::ToPtr)
        .addFunction("IsValid", &GFeBandBendLimit_t::IsValid)
        .endClass();
}