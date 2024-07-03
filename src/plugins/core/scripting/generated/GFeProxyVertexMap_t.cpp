#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeProxyVertexMap_t::GFeProxyVertexMap_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeProxyVertexMap_t::GFeProxyVertexMap_t(void *ptr) {
    m_ptr = ptr;
}
std::string GFeProxyVertexMap_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "FeProxyVertexMap_t", "m_Name").Get();
}
void GFeProxyVertexMap_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "FeProxyVertexMap_t", "m_Name", true, CUtlString(value.c_str()));
}
float GFeProxyVertexMap_t::GetWeight() const {
    return GetSchemaValue<float>(m_ptr, "FeProxyVertexMap_t", "m_flWeight");
}
void GFeProxyVertexMap_t::SetWeight(float value) {
    SetSchemaValue(m_ptr, "FeProxyVertexMap_t", "m_flWeight", true, value);
}
std::string GFeProxyVertexMap_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeProxyVertexMap_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeProxyVertexMap_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeProxyVertexMap_t>("FeProxyVertexMap_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GFeProxyVertexMap_t::GetName, &GFeProxyVertexMap_t::SetName)
        .addProperty("Weight", &GFeProxyVertexMap_t::GetWeight, &GFeProxyVertexMap_t::SetWeight)
        .addFunction("ToPtr", &GFeProxyVertexMap_t::ToPtr)
        .addFunction("IsValid", &GFeProxyVertexMap_t::IsValid)
        .endClass();
}