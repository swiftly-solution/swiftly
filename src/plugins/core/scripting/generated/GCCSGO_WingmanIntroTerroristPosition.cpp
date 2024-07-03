#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGO_WingmanIntroTerroristPosition::GCCSGO_WingmanIntroTerroristPosition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGO_WingmanIntroTerroristPosition::GCCSGO_WingmanIntroTerroristPosition(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSGO_WingmanIntroTerroristPosition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGO_WingmanIntroTerroristPosition::IsValid() {
    return (m_ptr != nullptr);
}
GCCSGO_WingmanIntroCharacterPosition GCCSGO_WingmanIntroTerroristPosition::GetParent() const {
    GCCSGO_WingmanIntroCharacterPosition value(m_ptr);
    return value;
}
void GCCSGO_WingmanIntroTerroristPosition::SetParent(GCCSGO_WingmanIntroCharacterPosition value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSGO_WingmanIntroTerroristPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_WingmanIntroTerroristPosition>("CCSGO_WingmanIntroTerroristPosition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSGO_WingmanIntroTerroristPosition::GetParent, &GCCSGO_WingmanIntroTerroristPosition::SetParent)
        .addFunction("ToPtr", &GCCSGO_WingmanIntroTerroristPosition::ToPtr)
        .addFunction("IsValid", &GCCSGO_WingmanIntroTerroristPosition::IsValid)
        .endClass();
}