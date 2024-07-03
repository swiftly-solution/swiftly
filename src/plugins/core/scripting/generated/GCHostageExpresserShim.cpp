#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCHostageExpresserShim::GCHostageExpresserShim(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCHostageExpresserShim::GCHostageExpresserShim(void *ptr) {
    m_ptr = ptr;
}
GCAI_Expresser GCHostageExpresserShim::GetExpresser() const {
    GCAI_Expresser value(*GetSchemaValuePtr<void*>(m_ptr, "CHostageExpresserShim", "m_pExpresser"));
    return value;
}
void GCHostageExpresserShim::SetExpresser(GCAI_Expresser* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Expresser' is not possible.\n");
}
std::string GCHostageExpresserShim::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCHostageExpresserShim::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseCombatCharacter GCHostageExpresserShim::GetParent() const {
    GCBaseCombatCharacter value(m_ptr);
    return value;
}
void GCHostageExpresserShim::SetParent(GCBaseCombatCharacter value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCHostageExpresserShim(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHostageExpresserShim>("CHostageExpresserShim")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Expresser", &GCHostageExpresserShim::GetExpresser, &GCHostageExpresserShim::SetExpresser)
        .addProperty("Parent", &GCHostageExpresserShim::GetParent, &GCHostageExpresserShim::SetParent)
        .addFunction("ToPtr", &GCHostageExpresserShim::ToPtr)
        .addFunction("IsValid", &GCHostageExpresserShim::IsValid)
        .endClass();
}