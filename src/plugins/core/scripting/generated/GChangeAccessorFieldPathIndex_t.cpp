#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GChangeAccessorFieldPathIndex_t::GChangeAccessorFieldPathIndex_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GChangeAccessorFieldPathIndex_t::GChangeAccessorFieldPathIndex_t(void *ptr) {
    m_ptr = ptr;
}
int16_t GChangeAccessorFieldPathIndex_t::GetValue() const {
    return GetSchemaValue<int16_t>(m_ptr, "ChangeAccessorFieldPathIndex_t", "m_Value");
}
void GChangeAccessorFieldPathIndex_t::SetValue(int16_t value) {
    SetSchemaValue(m_ptr, "ChangeAccessorFieldPathIndex_t", "m_Value", true, value);
}
std::string GChangeAccessorFieldPathIndex_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GChangeAccessorFieldPathIndex_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassChangeAccessorFieldPathIndex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GChangeAccessorFieldPathIndex_t>("ChangeAccessorFieldPathIndex_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GChangeAccessorFieldPathIndex_t::GetValue, &GChangeAccessorFieldPathIndex_t::SetValue)
        .addFunction("ToPtr", &GChangeAccessorFieldPathIndex_t::ToPtr)
        .addFunction("IsValid", &GChangeAccessorFieldPathIndex_t::IsValid)
        .endClass();
}