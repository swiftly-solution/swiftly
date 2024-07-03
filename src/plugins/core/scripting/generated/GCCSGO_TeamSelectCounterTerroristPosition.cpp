#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGO_TeamSelectCounterTerroristPosition::GCCSGO_TeamSelectCounterTerroristPosition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGO_TeamSelectCounterTerroristPosition::GCCSGO_TeamSelectCounterTerroristPosition(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSGO_TeamSelectCounterTerroristPosition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGO_TeamSelectCounterTerroristPosition::IsValid() {
    return (m_ptr != nullptr);
}
GCCSGO_TeamSelectCharacterPosition GCCSGO_TeamSelectCounterTerroristPosition::GetParent() const {
    GCCSGO_TeamSelectCharacterPosition value(m_ptr);
    return value;
}
void GCCSGO_TeamSelectCounterTerroristPosition::SetParent(GCCSGO_TeamSelectCharacterPosition value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSGO_TeamSelectCounterTerroristPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_TeamSelectCounterTerroristPosition>("CCSGO_TeamSelectCounterTerroristPosition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSGO_TeamSelectCounterTerroristPosition::GetParent, &GCCSGO_TeamSelectCounterTerroristPosition::SetParent)
        .addFunction("ToPtr", &GCCSGO_TeamSelectCounterTerroristPosition::ToPtr)
        .addFunction("IsValid", &GCCSGO_TeamSelectCounterTerroristPosition::IsValid)
        .endClass();
}