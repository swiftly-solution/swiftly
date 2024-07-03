#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnBlendVertex_t::GRnBlendVertex_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnBlendVertex_t::GRnBlendVertex_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GRnBlendVertex_t::GetWeight0() const {
    return GetSchemaValue<uint16_t>(m_ptr, "RnBlendVertex_t", "m_nWeight0");
}
void GRnBlendVertex_t::SetWeight0(uint16_t value) {
    SetSchemaValue(m_ptr, "RnBlendVertex_t", "m_nWeight0", true, value);
}
uint16_t GRnBlendVertex_t::GetIndex0() const {
    return GetSchemaValue<uint16_t>(m_ptr, "RnBlendVertex_t", "m_nIndex0");
}
void GRnBlendVertex_t::SetIndex0(uint16_t value) {
    SetSchemaValue(m_ptr, "RnBlendVertex_t", "m_nIndex0", true, value);
}
uint16_t GRnBlendVertex_t::GetWeight1() const {
    return GetSchemaValue<uint16_t>(m_ptr, "RnBlendVertex_t", "m_nWeight1");
}
void GRnBlendVertex_t::SetWeight1(uint16_t value) {
    SetSchemaValue(m_ptr, "RnBlendVertex_t", "m_nWeight1", true, value);
}
uint16_t GRnBlendVertex_t::GetIndex1() const {
    return GetSchemaValue<uint16_t>(m_ptr, "RnBlendVertex_t", "m_nIndex1");
}
void GRnBlendVertex_t::SetIndex1(uint16_t value) {
    SetSchemaValue(m_ptr, "RnBlendVertex_t", "m_nIndex1", true, value);
}
uint16_t GRnBlendVertex_t::GetWeight2() const {
    return GetSchemaValue<uint16_t>(m_ptr, "RnBlendVertex_t", "m_nWeight2");
}
void GRnBlendVertex_t::SetWeight2(uint16_t value) {
    SetSchemaValue(m_ptr, "RnBlendVertex_t", "m_nWeight2", true, value);
}
uint16_t GRnBlendVertex_t::GetIndex2() const {
    return GetSchemaValue<uint16_t>(m_ptr, "RnBlendVertex_t", "m_nIndex2");
}
void GRnBlendVertex_t::SetIndex2(uint16_t value) {
    SetSchemaValue(m_ptr, "RnBlendVertex_t", "m_nIndex2", true, value);
}
uint16_t GRnBlendVertex_t::GetFlags() const {
    return GetSchemaValue<uint16_t>(m_ptr, "RnBlendVertex_t", "m_nFlags");
}
void GRnBlendVertex_t::SetFlags(uint16_t value) {
    SetSchemaValue(m_ptr, "RnBlendVertex_t", "m_nFlags", true, value);
}
uint16_t GRnBlendVertex_t::GetTargetIndex() const {
    return GetSchemaValue<uint16_t>(m_ptr, "RnBlendVertex_t", "m_nTargetIndex");
}
void GRnBlendVertex_t::SetTargetIndex(uint16_t value) {
    SetSchemaValue(m_ptr, "RnBlendVertex_t", "m_nTargetIndex", true, value);
}
std::string GRnBlendVertex_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnBlendVertex_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassRnBlendVertex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnBlendVertex_t>("RnBlendVertex_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Weight0", &GRnBlendVertex_t::GetWeight0, &GRnBlendVertex_t::SetWeight0)
        .addProperty("Index0", &GRnBlendVertex_t::GetIndex0, &GRnBlendVertex_t::SetIndex0)
        .addProperty("Weight1", &GRnBlendVertex_t::GetWeight1, &GRnBlendVertex_t::SetWeight1)
        .addProperty("Index1", &GRnBlendVertex_t::GetIndex1, &GRnBlendVertex_t::SetIndex1)
        .addProperty("Weight2", &GRnBlendVertex_t::GetWeight2, &GRnBlendVertex_t::SetWeight2)
        .addProperty("Index2", &GRnBlendVertex_t::GetIndex2, &GRnBlendVertex_t::SetIndex2)
        .addProperty("Flags", &GRnBlendVertex_t::GetFlags, &GRnBlendVertex_t::SetFlags)
        .addProperty("TargetIndex", &GRnBlendVertex_t::GetTargetIndex, &GRnBlendVertex_t::SetTargetIndex)
        .addFunction("ToPtr", &GRnBlendVertex_t::ToPtr)
        .addFunction("IsValid", &GRnBlendVertex_t::IsValid)
        .endClass();
}