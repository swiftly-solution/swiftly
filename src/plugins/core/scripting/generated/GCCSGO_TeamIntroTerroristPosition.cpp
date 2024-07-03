#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGO_TeamIntroTerroristPosition::GCCSGO_TeamIntroTerroristPosition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGO_TeamIntroTerroristPosition::GCCSGO_TeamIntroTerroristPosition(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSGO_TeamIntroTerroristPosition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGO_TeamIntroTerroristPosition::IsValid() {
    return (m_ptr != nullptr);
}
GCCSGO_TeamIntroCharacterPosition GCCSGO_TeamIntroTerroristPosition::GetParent() const {
    GCCSGO_TeamIntroCharacterPosition value(m_ptr);
    return value;
}
void GCCSGO_TeamIntroTerroristPosition::SetParent(GCCSGO_TeamIntroCharacterPosition value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSGO_TeamIntroTerroristPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_TeamIntroTerroristPosition>("CCSGO_TeamIntroTerroristPosition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSGO_TeamIntroTerroristPosition::GetParent, &GCCSGO_TeamIntroTerroristPosition::SetParent)
        .addFunction("ToPtr", &GCCSGO_TeamIntroTerroristPosition::ToPtr)
        .addFunction("IsValid", &GCCSGO_TeamIntroTerroristPosition::IsValid)
        .endClass();
}