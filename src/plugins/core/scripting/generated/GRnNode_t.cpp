#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnNode_t::GRnNode_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnNode_t::GRnNode_t(void *ptr) {
    m_ptr = ptr;
}
Vector GRnNode_t::GetMin() const {
    return GetSchemaValue<Vector>(m_ptr, "RnNode_t", "m_vMin");
}
void GRnNode_t::SetMin(Vector value) {
    SetSchemaValue(m_ptr, "RnNode_t", "m_vMin", true, value);
}
uint32_t GRnNode_t::GetChildren() const {
    return GetSchemaValue<uint32_t>(m_ptr, "RnNode_t", "m_nChildren");
}
void GRnNode_t::SetChildren(uint32_t value) {
    SetSchemaValue(m_ptr, "RnNode_t", "m_nChildren", true, value);
}
Vector GRnNode_t::GetMax() const {
    return GetSchemaValue<Vector>(m_ptr, "RnNode_t", "m_vMax");
}
void GRnNode_t::SetMax(Vector value) {
    SetSchemaValue(m_ptr, "RnNode_t", "m_vMax", true, value);
}
uint32_t GRnNode_t::GetTriangleOffset() const {
    return GetSchemaValue<uint32_t>(m_ptr, "RnNode_t", "m_nTriangleOffset");
}
void GRnNode_t::SetTriangleOffset(uint32_t value) {
    SetSchemaValue(m_ptr, "RnNode_t", "m_nTriangleOffset", true, value);
}
std::string GRnNode_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnNode_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRnNode_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnNode_t>("RnNode_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Min", &GRnNode_t::GetMin, &GRnNode_t::SetMin)
        .addProperty("Children", &GRnNode_t::GetChildren, &GRnNode_t::SetChildren)
        .addProperty("Max", &GRnNode_t::GetMax, &GRnNode_t::SetMax)
        .addProperty("TriangleOffset", &GRnNode_t::GetTriangleOffset, &GRnNode_t::SetTriangleOffset)
        .addFunction("ToPtr", &GRnNode_t::ToPtr)
        .addFunction("IsValid", &GRnNode_t::IsValid)
        .endClass();
}