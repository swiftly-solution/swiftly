#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFeFitMatrix_t::GFeFitMatrix_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFeFitMatrix_t::GFeFitMatrix_t(void *ptr) {
    m_ptr = ptr;
}
Vector GFeFitMatrix_t::GetCenter() const {
    return GetSchemaValue<Vector>(m_ptr, "FeFitMatrix_t", "vCenter");
}
void GFeFitMatrix_t::SetCenter(Vector value) {
    SetSchemaValue(m_ptr, "FeFitMatrix_t", "vCenter", true, value);
}
uint16_t GFeFitMatrix_t::GetEnd() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeFitMatrix_t", "nEnd");
}
void GFeFitMatrix_t::SetEnd(uint16_t value) {
    SetSchemaValue(m_ptr, "FeFitMatrix_t", "nEnd", true, value);
}
uint16_t GFeFitMatrix_t::GetNode() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeFitMatrix_t", "nNode");
}
void GFeFitMatrix_t::SetNode(uint16_t value) {
    SetSchemaValue(m_ptr, "FeFitMatrix_t", "nNode", true, value);
}
uint16_t GFeFitMatrix_t::GetBeginDynamic() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FeFitMatrix_t", "nBeginDynamic");
}
void GFeFitMatrix_t::SetBeginDynamic(uint16_t value) {
    SetSchemaValue(m_ptr, "FeFitMatrix_t", "nBeginDynamic", true, value);
}
std::string GFeFitMatrix_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFeFitMatrix_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFeFitMatrix_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeFitMatrix_t>("FeFitMatrix_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Center", &GFeFitMatrix_t::GetCenter, &GFeFitMatrix_t::SetCenter)
        .addProperty("End", &GFeFitMatrix_t::GetEnd, &GFeFitMatrix_t::SetEnd)
        .addProperty("Node", &GFeFitMatrix_t::GetNode, &GFeFitMatrix_t::SetNode)
        .addProperty("BeginDynamic", &GFeFitMatrix_t::GetBeginDynamic, &GFeFitMatrix_t::SetBeginDynamic)
        .addFunction("ToPtr", &GFeFitMatrix_t::ToPtr)
        .addFunction("IsValid", &GFeFitMatrix_t::IsValid)
        .endClass();
}