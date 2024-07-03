#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnHalfEdge_t::GRnHalfEdge_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnHalfEdge_t::GRnHalfEdge_t(void *ptr) {
    m_ptr = ptr;
}
uint8_t GRnHalfEdge_t::GetNext() const {
    return GetSchemaValue<uint8_t>(m_ptr, "RnHalfEdge_t", "m_nNext");
}
void GRnHalfEdge_t::SetNext(uint8_t value) {
    SetSchemaValue(m_ptr, "RnHalfEdge_t", "m_nNext", true, value);
}
uint8_t GRnHalfEdge_t::GetTwin() const {
    return GetSchemaValue<uint8_t>(m_ptr, "RnHalfEdge_t", "m_nTwin");
}
void GRnHalfEdge_t::SetTwin(uint8_t value) {
    SetSchemaValue(m_ptr, "RnHalfEdge_t", "m_nTwin", true, value);
}
uint8_t GRnHalfEdge_t::GetOrigin() const {
    return GetSchemaValue<uint8_t>(m_ptr, "RnHalfEdge_t", "m_nOrigin");
}
void GRnHalfEdge_t::SetOrigin(uint8_t value) {
    SetSchemaValue(m_ptr, "RnHalfEdge_t", "m_nOrigin", true, value);
}
uint8_t GRnHalfEdge_t::GetFace() const {
    return GetSchemaValue<uint8_t>(m_ptr, "RnHalfEdge_t", "m_nFace");
}
void GRnHalfEdge_t::SetFace(uint8_t value) {
    SetSchemaValue(m_ptr, "RnHalfEdge_t", "m_nFace", true, value);
}
std::string GRnHalfEdge_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnHalfEdge_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRnHalfEdge_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnHalfEdge_t>("RnHalfEdge_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Next", &GRnHalfEdge_t::GetNext, &GRnHalfEdge_t::SetNext)
        .addProperty("Twin", &GRnHalfEdge_t::GetTwin, &GRnHalfEdge_t::SetTwin)
        .addProperty("Origin", &GRnHalfEdge_t::GetOrigin, &GRnHalfEdge_t::SetOrigin)
        .addProperty("Face", &GRnHalfEdge_t::GetFace, &GRnHalfEdge_t::SetFace)
        .addFunction("ToPtr", &GRnHalfEdge_t::ToPtr)
        .addFunction("IsValid", &GRnHalfEdge_t::IsValid)
        .endClass();
}