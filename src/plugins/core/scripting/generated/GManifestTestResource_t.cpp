#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GManifestTestResource_t::GManifestTestResource_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GManifestTestResource_t::GManifestTestResource_t(void *ptr) {
    m_ptr = ptr;
}
std::string GManifestTestResource_t::GetName() const {
    return GetSchemaValue<CUtlString>(m_ptr, "ManifestTestResource_t", "m_name").Get();
}
void GManifestTestResource_t::SetName(std::string value) {
    SetSchemaValue(m_ptr, "ManifestTestResource_t", "m_name", true, CUtlString(value.c_str()));
}
std::string GManifestTestResource_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GManifestTestResource_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassManifestTestResource_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GManifestTestResource_t>("ManifestTestResource_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Name", &GManifestTestResource_t::GetName, &GManifestTestResource_t::SetName)
        .addFunction("ToPtr", &GManifestTestResource_t::ToPtr)
        .addFunction("IsValid", &GManifestTestResource_t::IsValid)
        .endClass();
}