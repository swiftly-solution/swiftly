#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGO_WingmanIntroCounterTerroristPosition::GCCSGO_WingmanIntroCounterTerroristPosition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGO_WingmanIntroCounterTerroristPosition::GCCSGO_WingmanIntroCounterTerroristPosition(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSGO_WingmanIntroCounterTerroristPosition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGO_WingmanIntroCounterTerroristPosition::IsValid() {
    return (m_ptr != nullptr);
}
GCCSGO_WingmanIntroCharacterPosition GCCSGO_WingmanIntroCounterTerroristPosition::GetParent() const {
    GCCSGO_WingmanIntroCharacterPosition value(m_ptr);
    return value;
}
void GCCSGO_WingmanIntroCounterTerroristPosition::SetParent(GCCSGO_WingmanIntroCharacterPosition value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSGO_WingmanIntroCounterTerroristPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_WingmanIntroCounterTerroristPosition>("CCSGO_WingmanIntroCounterTerroristPosition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSGO_WingmanIntroCounterTerroristPosition::GetParent, &GCCSGO_WingmanIntroCounterTerroristPosition::SetParent)
        .addFunction("ToPtr", &GCCSGO_WingmanIntroCounterTerroristPosition::ToPtr)
        .addFunction("IsValid", &GCCSGO_WingmanIntroCounterTerroristPosition::IsValid)
        .endClass();
}