#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GPermEntityLumpData_t::GPermEntityLumpData_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GPermEntityLumpData_t::GPermEntityLumpData_t(void *ptr) {
    m_ptr = ptr;
}
std::string GPermEntityLumpData_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "PermEntityLumpData_t", "m_name").Get();
}
void GPermEntityLumpData_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "PermEntityLumpData_t", "m_name", true, CUtlString(value.c_str()));
}
std::string GPermEntityLumpData_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GPermEntityLumpData_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassPermEntityLumpData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPermEntityLumpData_t>("PermEntityLumpData_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GPermEntityLumpData_t::GetName, &GPermEntityLumpData_t::SetName)
        .addFunction("ToPtr", &GPermEntityLumpData_t::ToPtr)
        .addFunction("IsValid", &GPermEntityLumpData_t::IsValid)
        .endClass();
}