#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GAmmoIndex_t::GAmmoIndex_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GAmmoIndex_t::GAmmoIndex_t(void *ptr) {
    m_ptr = ptr;
}
int8_t GAmmoIndex_t::GetValue() const {
    return GetSchemaValue<int8_t>(m_ptr, "AmmoIndex_t", "m_Value");
}
void GAmmoIndex_t::SetValue(int8_t value) {
    SetSchemaValue(m_ptr, "AmmoIndex_t", "m_Value", true, value);
}
std::string GAmmoIndex_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GAmmoIndex_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassAmmoIndex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GAmmoIndex_t>("AmmoIndex_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GAmmoIndex_t::GetValue, &GAmmoIndex_t::SetValue)
        .addFunction("ToPtr", &GAmmoIndex_t::ToPtr)
        .addFunction("IsValid", &GAmmoIndex_t::IsValid)
        .endClass();
}