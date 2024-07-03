#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeFitWeight_t::GFeFitWeight_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeFitWeight_t::GFeFitWeight_t(void *ptr) {
    m_ptr = ptr;
}
float GFeFitWeight_t::GetWeight() const {
    return GetSchemaValue<float>(m_ptr, "FeFitWeight_t", "flWeight");
}
void GFeFitWeight_t::SetWeight(float value) {
    SetSchemaValue(m_ptr, "FeFitWeight_t", "flWeight", true, value);
}
uint16_t GFeFitWeight_t::GetNode() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeFitWeight_t", "nNode");
}
void GFeFitWeight_t::SetNode(uint16_t value) {
    SetSchemaValue(m_ptr, "FeFitWeight_t", "nNode", true, value);
}
uint16_t GFeFitWeight_t::GetDummy() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeFitWeight_t", "nDummy");
}
void GFeFitWeight_t::SetDummy(uint16_t value) {
    SetSchemaValue(m_ptr, "FeFitWeight_t", "nDummy", true, value);
}
std::string GFeFitWeight_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeFitWeight_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeFitWeight_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeFitWeight_t>("FeFitWeight_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Weight", &GFeFitWeight_t::GetWeight, &GFeFitWeight_t::SetWeight)
        .addProperty("Node", &GFeFitWeight_t::GetNode, &GFeFitWeight_t::SetNode)
        .addProperty("Dummy", &GFeFitWeight_t::GetDummy, &GFeFitWeight_t::SetDummy)
        .addFunction("ToPtr", &GFeFitWeight_t::ToPtr)
        .addFunction("IsValid", &GFeFitWeight_t::IsValid)
        .endClass();
}