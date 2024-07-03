#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFuseFunctionIndex_t::GFuseFunctionIndex_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFuseFunctionIndex_t::GFuseFunctionIndex_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GFuseFunctionIndex_t::GetValue() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FuseFunctionIndex_t", "m_Value");
}
void GFuseFunctionIndex_t::SetValue(uint16_t value) {
    SetSchemaValue(m_ptr, "FuseFunctionIndex_t", "m_Value", true, value);
}
std::string GFuseFunctionIndex_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFuseFunctionIndex_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFuseFunctionIndex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFuseFunctionIndex_t>("FuseFunctionIndex_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GFuseFunctionIndex_t::GetValue, &GFuseFunctionIndex_t::SetValue)
        .addFunction("ToPtr", &GFuseFunctionIndex_t::ToPtr)
        .addFunction("IsValid", &GFuseFunctionIndex_t::IsValid)
        .endClass();
}