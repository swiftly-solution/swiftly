#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeSourceEdge_t::GFeSourceEdge_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeSourceEdge_t::GFeSourceEdge_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint16_t> GFeSourceEdge_t::GetNode() const {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSourceEdge_t", "nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 2; i++) { ret.push_back(outValue[i]); } return ret;
}
void GFeSourceEdge_t::SetNode(std::vector<uint16_t> value) {
    uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "FeSourceEdge_t", "nNode"); for(int i = 0; i < 2; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "FeSourceEdge_t", "nNode", true, outValue);
}
std::string GFeSourceEdge_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeSourceEdge_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeSourceEdge_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSourceEdge_t>("FeSourceEdge_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Node", &GFeSourceEdge_t::GetNode, &GFeSourceEdge_t::SetNode)
        .addFunction("ToPtr", &GFeSourceEdge_t::ToPtr)
        .addFunction("IsValid", &GFeSourceEdge_t::IsValid)
        .endClass();
}