#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGO_TeamIntroCounterTerroristPosition::GCCSGO_TeamIntroCounterTerroristPosition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGO_TeamIntroCounterTerroristPosition::GCCSGO_TeamIntroCounterTerroristPosition(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSGO_TeamIntroCounterTerroristPosition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGO_TeamIntroCounterTerroristPosition::IsValid() {
    return (m_ptr != nullptr);
}
GCCSGO_TeamIntroCharacterPosition GCCSGO_TeamIntroCounterTerroristPosition::GetParent() const {
    GCCSGO_TeamIntroCharacterPosition value(m_ptr);
    return value;
}
void GCCSGO_TeamIntroCounterTerroristPosition::SetParent(GCCSGO_TeamIntroCharacterPosition value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSGO_TeamIntroCounterTerroristPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_TeamIntroCounterTerroristPosition>("CCSGO_TeamIntroCounterTerroristPosition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSGO_TeamIntroCounterTerroristPosition::GetParent, &GCCSGO_TeamIntroCounterTerroristPosition::SetParent)
        .addFunction("ToPtr", &GCCSGO_TeamIntroCounterTerroristPosition::ToPtr)
        .addFunction("IsValid", &GCCSGO_TeamIntroCounterTerroristPosition::IsValid)
        .endClass();
}