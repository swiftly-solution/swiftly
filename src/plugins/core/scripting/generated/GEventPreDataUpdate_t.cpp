#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventPreDataUpdate_t::GEventPreDataUpdate_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventPreDataUpdate_t::GEventPreDataUpdate_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GEventPreDataUpdate_t::GetCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "EventPreDataUpdate_t", "m_nCount");
}
void GEventPreDataUpdate_t::SetCount(int32_t value) {
    SetSchemaValue(m_ptr, "EventPreDataUpdate_t", "m_nCount", true, value);
}
std::string GEventPreDataUpdate_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventPreDataUpdate_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventPreDataUpdate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventPreDataUpdate_t>("EventPreDataUpdate_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Count", &GEventPreDataUpdate_t::GetCount, &GEventPreDataUpdate_t::SetCount)
        .addFunction("ToPtr", &GEventPreDataUpdate_t::ToPtr)
        .addFunction("IsValid", &GEventPreDataUpdate_t::IsValid)
        .endClass();
}