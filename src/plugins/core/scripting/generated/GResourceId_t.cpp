#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GResourceId_t::GResourceId_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GResourceId_t::GResourceId_t(void *ptr) {
    m_ptr = ptr;
}
uint64_t GResourceId_t::GetValue() const {
    return GetSchemaValue<uint64_t>(m_ptr, "ResourceId_t", "m_Value");
}
void GResourceId_t::SetValue(uint64_t value) {
    SetSchemaValue(m_ptr, "ResourceId_t", "m_Value", true, value);
}
std::string GResourceId_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GResourceId_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassResourceId_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GResourceId_t>("ResourceId_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GResourceId_t::GetValue, &GResourceId_t::SetValue)
        .addFunction("ToPtr", &GResourceId_t::ToPtr)
        .addFunction("IsValid", &GResourceId_t::IsValid)
        .endClass();
}