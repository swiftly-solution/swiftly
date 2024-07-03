#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEntityKeyValueData_t::GEntityKeyValueData_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEntityKeyValueData_t::GEntityKeyValueData_t(void *ptr) {
    m_ptr = ptr;
}
std::vector<GEntityIOConnectionData_t> GEntityKeyValueData_t::GetConnections() const {
    CUtlVector<GEntityIOConnectionData_t>* vec = GetSchemaValue<CUtlVector<GEntityIOConnectionData_t>*>(m_ptr, "EntityKeyValueData_t", "m_connections"); std::vector<GEntityIOConnectionData_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GEntityKeyValueData_t::SetConnections(std::vector<GEntityIOConnectionData_t> value) {
    SetSchemaValueCUtlVector<GEntityIOConnectionData_t>(m_ptr, "EntityKeyValueData_t", "m_connections", true, value);
}
std::string GEntityKeyValueData_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEntityKeyValueData_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEntityKeyValueData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEntityKeyValueData_t>("EntityKeyValueData_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Connections", &GEntityKeyValueData_t::GetConnections, &GEntityKeyValueData_t::SetConnections)
        .addFunction("ToPtr", &GEntityKeyValueData_t::ToPtr)
        .addFunction("IsValid", &GEntityKeyValueData_t::IsValid)
        .endClass();
}