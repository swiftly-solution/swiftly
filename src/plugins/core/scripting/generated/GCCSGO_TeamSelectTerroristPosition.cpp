#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGO_TeamSelectTerroristPosition::GCCSGO_TeamSelectTerroristPosition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGO_TeamSelectTerroristPosition::GCCSGO_TeamSelectTerroristPosition(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSGO_TeamSelectTerroristPosition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGO_TeamSelectTerroristPosition::IsValid() {
    return (m_ptr != nullptr);
}
GCCSGO_TeamSelectCharacterPosition GCCSGO_TeamSelectTerroristPosition::GetParent() const {
    GCCSGO_TeamSelectCharacterPosition value(m_ptr);
    return value;
}
void GCCSGO_TeamSelectTerroristPosition::SetParent(GCCSGO_TeamSelectCharacterPosition value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSGO_TeamSelectTerroristPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_TeamSelectTerroristPosition>("CCSGO_TeamSelectTerroristPosition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSGO_TeamSelectTerroristPosition::GetParent, &GCCSGO_TeamSelectTerroristPosition::SetParent)
        .addFunction("ToPtr", &GCCSGO_TeamSelectTerroristPosition::ToPtr)
        .addFunction("IsValid", &GCCSGO_TeamSelectTerroristPosition::IsValid)
        .endClass();
}