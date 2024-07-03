#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GEventPostDataUpdate_t::GEventPostDataUpdate_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GEventPostDataUpdate_t::GEventPostDataUpdate_t(void *ptr) {
    m_ptr = ptr;
}
int32_t GEventPostDataUpdate_t::GetCount() const {
    return GetSchemaValue<int32_t>(m_ptr, "EventPostDataUpdate_t", "m_nCount");
}
void GEventPostDataUpdate_t::SetCount(int32_t value) {
    SetSchemaValue(m_ptr, "EventPostDataUpdate_t", "m_nCount", true, value);
}
std::string GEventPostDataUpdate_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GEventPostDataUpdate_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassEventPostDataUpdate_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GEventPostDataUpdate_t>("EventPostDataUpdate_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Count", &GEventPostDataUpdate_t::GetCount, &GEventPostDataUpdate_t::SetCount)
        .addFunction("ToPtr", &GEventPostDataUpdate_t::ToPtr)
        .addFunction("IsValid", &GEventPostDataUpdate_t::IsValid)
        .endClass();
}