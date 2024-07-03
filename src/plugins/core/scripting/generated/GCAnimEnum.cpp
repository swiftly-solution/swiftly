#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAnimEnum::GCAnimEnum(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAnimEnum::GCAnimEnum(void *ptr) {
    m_ptr = ptr;
}
uint8_t GCAnimEnum::GetValue() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CAnimEnum", "m_value");
}
void GCAnimEnum::SetValue(uint8_t value) {
    SetSchemaValue(m_ptr, "CAnimEnum", "m_value", false, value);
}
std::string GCAnimEnum::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAnimEnum::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCAnimEnum(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimEnum>("CAnimEnum")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Value", &GCAnimEnum::GetValue, &GCAnimEnum::SetValue)
        .addFunction("ToPtr", &GCAnimEnum::ToPtr)
        .addFunction("IsValid", &GCAnimEnum::IsValid)
        .endClass();
}