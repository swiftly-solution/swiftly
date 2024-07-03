#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GFuseVariableIndex_t::GFuseVariableIndex_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GFuseVariableIndex_t::GFuseVariableIndex_t(void *ptr) {
    m_ptr = ptr;
}
uint16_t GFuseVariableIndex_t::GetValue() const {
    return GetSchemaValue<uint16_t>(m_ptr, "FuseVariableIndex_t", "m_Value");
}
void GFuseVariableIndex_t::SetValue(uint16_t value) {
    SetSchemaValue(m_ptr, "FuseVariableIndex_t", "m_Value", true, value);
}
std::string GFuseVariableIndex_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GFuseVariableIndex_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassFuseVariableIndex_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFuseVariableIndex_t>("FuseVariableIndex_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GFuseVariableIndex_t::GetValue, &GFuseVariableIndex_t::SetValue)
        .addFunction("ToPtr", &GFuseVariableIndex_t::ToPtr)
        .addFunction("IsValid", &GFuseVariableIndex_t::IsValid)
        .endClass();
}