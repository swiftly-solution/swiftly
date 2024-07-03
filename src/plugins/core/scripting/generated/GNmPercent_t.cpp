#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GNmPercent_t::GNmPercent_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GNmPercent_t::GNmPercent_t(void *ptr) {
    m_ptr = ptr;
}
float GNmPercent_t::GetValue() const {
    return GetSchemaValue<float>(m_ptr, "NmPercent_t", "m_flValue");
}
void GNmPercent_t::SetValue(float value) {
    SetSchemaValue(m_ptr, "NmPercent_t", "m_flValue", true, value);
}
std::string GNmPercent_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GNmPercent_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassNmPercent_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GNmPercent_t>("NmPercent_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GNmPercent_t::GetValue, &GNmPercent_t::SetValue)
        .addFunction("ToPtr", &GNmPercent_t::ToPtr)
        .addFunction("IsValid", &GNmPercent_t::IsValid)
        .endClass();
}