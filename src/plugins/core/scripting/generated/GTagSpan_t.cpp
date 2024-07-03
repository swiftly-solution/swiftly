#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GTagSpan_t::GTagSpan_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GTagSpan_t::GTagSpan_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GTagSpan_t::GetTagIndex() const {
    return GetSchemaValue<int32_t>(m_ptr, "TagSpan_t", "m_tagIndex");
}
void GTagSpan_t::SetTagIndex(int32_t value) {
    SetSchemaValue(m_ptr, "TagSpan_t", "m_tagIndex", true, value);
}
float GTagSpan_t::GetStartCycle() const {
    return GetSchemaValue<float>(m_ptr, "TagSpan_t", "m_startCycle");
}
void GTagSpan_t::SetStartCycle(float value) {
    SetSchemaValue(m_ptr, "TagSpan_t", "m_startCycle", true, value);
}
float GTagSpan_t::GetEndCycle() const {
    return GetSchemaValue<float>(m_ptr, "TagSpan_t", "m_endCycle");
}
void GTagSpan_t::SetEndCycle(float value) {
    SetSchemaValue(m_ptr, "TagSpan_t", "m_endCycle", true, value);
}
std::string GTagSpan_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GTagSpan_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassTagSpan_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GTagSpan_t>("TagSpan_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TagIndex", &GTagSpan_t::GetTagIndex, &GTagSpan_t::SetTagIndex)
        .addProperty("StartCycle", &GTagSpan_t::GetStartCycle, &GTagSpan_t::SetStartCycle)
        .addProperty("EndCycle", &GTagSpan_t::GetEndCycle, &GTagSpan_t::SetEndCycle)
        .addFunction("ToPtr", &GTagSpan_t::ToPtr)
        .addFunction("IsValid", &GTagSpan_t::IsValid)
        .endClass();
}