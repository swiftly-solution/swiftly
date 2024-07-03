#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GConceptHistory_t::GConceptHistory_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GConceptHistory_t::GConceptHistory_t(void *ptr) {
    m_ptr = ptr;
}
float GConceptHistory_t::GetTimeSpoken() const {
    return GetSchemaValue<float>(m_ptr, "ConceptHistory_t", "timeSpoken");
}
void GConceptHistory_t::SetTimeSpoken(float value) {
    SetSchemaValue(m_ptr, "ConceptHistory_t", "timeSpoken", true, value);
}
std::string GConceptHistory_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GConceptHistory_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassConceptHistory_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GConceptHistory_t>("ConceptHistory_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TimeSpoken", &GConceptHistory_t::GetTimeSpoken, &GConceptHistory_t::SetTimeSpoken)
        .addFunction("ToPtr", &GConceptHistory_t::ToPtr)
        .addFunction("IsValid", &GConceptHistory_t::IsValid)
        .endClass();
}