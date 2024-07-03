#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeEdgeDesc_t::GFeEdgeDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeEdgeDesc_t::GFeEdgeDesc_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint16_t> GFeEdgeDesc_t::GetEdge() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeEdgeDesc_t", "nEdge"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeEdgeDesc_t::SetEdge(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeEdgeDesc_t", "nEdge"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeEdgeDesc_t", "nEdge", true, outValue);
}
std::vector<uint16_t> GFeEdgeDesc_t::GetVirtElem() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeEdgeDesc_t", "nVirtElem"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeEdgeDesc_t::SetVirtElem(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeEdgeDesc_t", "nVirtElem"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeEdgeDesc_t", "nVirtElem", true, outValue);
}
std::string GFeEdgeDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeEdgeDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeEdgeDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeEdgeDesc_t>("FeEdgeDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Edge", &GFeEdgeDesc_t::GetEdge, &GFeEdgeDesc_t::SetEdge)
        .addProperty("VirtElem", &GFeEdgeDesc_t::GetVirtElem, &GFeEdgeDesc_t::SetVirtElem)
        .addFunction("ToPtr", &GFeEdgeDesc_t::ToPtr)
        .addFunction("IsValid", &GFeEdgeDesc_t::IsValid)
        .endClass();
}