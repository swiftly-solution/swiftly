#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GModelConfigHandle_t::GModelConfigHandle_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GModelConfigHandle_t::GModelConfigHandle_t(void *ptr) {
    m_ptr = ptr;
}
uint32_t GModelConfigHandle_t::GetValue() const {
    return GetSchemaValue<uint32_t>(m_ptr, "ModelConfigHandle_t", "m_Value");
}
void GModelConfigHandle_t::SetValue(uint32_t value) {
    SetSchemaValue(m_ptr, "ModelConfigHandle_t", "m_Value", true, value);
}
std::string GModelConfigHandle_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GModelConfigHandle_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassModelConfigHandle_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GModelConfigHandle_t>("ModelConfigHandle_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GModelConfigHandle_t::GetValue, &GModelConfigHandle_t::SetValue)
        .addFunction("ToPtr", &GModelConfigHandle_t::ToPtr)
        .addFunction("IsValid", &GModelConfigHandle_t::IsValid)
        .endClass();
}