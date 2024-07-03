#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GTestResource_t::GTestResource_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GTestResource_t::GTestResource_t(void *ptr) {
    m_ptr = ptr;
}
std::string GTestResource_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "TestResource_t", "m_name").Get();
}
void GTestResource_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "TestResource_t", "m_name", true, CUtlString(value.c_str()));
}
std::string GTestResource_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GTestResource_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassTestResource_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GTestResource_t>("TestResource_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GTestResource_t::GetName, &GTestResource_t::SetName)
        .addFunction("ToPtr", &GTestResource_t::ToPtr)
        .addFunction("IsValid", &GTestResource_t::IsValid)
        .endClass();
}