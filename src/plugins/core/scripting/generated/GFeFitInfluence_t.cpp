#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeFitInfluence_t::GFeFitInfluence_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeFitInfluence_t::GFeFitInfluence_t(void *ptr) {
    m_ptr = ptr;
}
uint32_t GFeFitInfluence_t::GetVertexNode() const {
    return GetSchemaValue<uint32_t>(m_ptr, "FeFitInfluence_t", "nVertexNode");
}
void GFeFitInfluence_t::SetVertexNode(uint32_t value) {
    SetSchemaValue(m_ptr, "FeFitInfluence_t", "nVertexNode", true, value);
}
float GFeFitInfluence_t::GetWeight() const {
    return GetSchemaValue<float>(m_ptr, "FeFitInfluence_t", "flWeight");
}
void GFeFitInfluence_t::SetWeight(float value) {
    SetSchemaValue(m_ptr, "FeFitInfluence_t", "flWeight", true, value);
}
uint32_t GFeFitInfluence_t::GetMatrixNode() const {
    return GetSchemaValue<uint32_t>(m_ptr, "FeFitInfluence_t", "nMatrixNode");
}
void GFeFitInfluence_t::SetMatrixNode(uint32_t value) {
    SetSchemaValue(m_ptr, "FeFitInfluence_t", "nMatrixNode", true, value);
}
std::string GFeFitInfluence_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeFitInfluence_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeFitInfluence_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeFitInfluence_t>("FeFitInfluence_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("VertexNode", &GFeFitInfluence_t::GetVertexNode, &GFeFitInfluence_t::SetVertexNode)
        .addProperty("Weight", &GFeFitInfluence_t::GetWeight, &GFeFitInfluence_t::SetWeight)
        .addProperty("MatrixNode", &GFeFitInfluence_t::GetMatrixNode, &GFeFitInfluence_t::SetMatrixNode)
        .addFunction("ToPtr", &GFeFitInfluence_t::ToPtr)
        .addFunction("IsValid", &GFeFitInfluence_t::IsValid)
        .endClass();
}