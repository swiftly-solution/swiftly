#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GWorld_t::GWorld_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GWorld_t::GWorld_t(void *ptr) {
    m_ptr = ptr;
}
GWorldBuilderParams_t GWorld_t::GetBuilderParams() const {
    GWorldBuilderParams_t value(GetSchemaPtr(m_ptr, "World_t", "m_builderParams"));
    return value;
}
void GWorld_t::SetBuilderParams(GWorldBuilderParams_t value) {
    SetSchemaValue(m_ptr, "World_t", "m_builderParams", true, value);
}
std::vector<GNodeData_t> GWorld_t::GetWorldNodes() const {
    CUtlVector<GNodeData_t>* vec = GetSchemaValue<CUtlVector<GNodeData_t>*>(m_ptr, "World_t", "m_worldNodes"); std::vector<GNodeData_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GWorld_t::SetWorldNodes(std::vector<GNodeData_t> value) {
    SetSchemaValueCUtlVector<GNodeData_t>(m_ptr, "World_t", "m_worldNodes", true, value);
}
GBakedLightingInfo_t GWorld_t::GetWorldLightingInfo() const {
    GBakedLightingInfo_t value(GetSchemaPtr(m_ptr, "World_t", "m_worldLightingInfo"));
    return value;
}
void GWorld_t::SetWorldLightingInfo(GBakedLightingInfo_t value) {
    SetSchemaValue(m_ptr, "World_t", "m_worldLightingInfo", true, value);
}
std::string GWorld_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GWorld_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassWorld_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GWorld_t>("World_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("BuilderParams", &GWorld_t::GetBuilderParams, &GWorld_t::SetBuilderParams)
        .addProperty("WorldNodes", &GWorld_t::GetWorldNodes, &GWorld_t::SetWorldNodes)
        .addProperty("WorldLightingInfo", &GWorld_t::GetWorldLightingInfo, &GWorld_t::SetWorldLightingInfo)
        .addFunction("ToPtr", &GWorld_t::ToPtr)
        .addFunction("IsValid", &GWorld_t::IsValid)
        .endClass();
}