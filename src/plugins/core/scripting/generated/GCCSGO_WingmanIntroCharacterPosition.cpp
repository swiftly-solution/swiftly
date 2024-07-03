#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGO_WingmanIntroCharacterPosition::GCCSGO_WingmanIntroCharacterPosition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGO_WingmanIntroCharacterPosition::GCCSGO_WingmanIntroCharacterPosition(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSGO_WingmanIntroCharacterPosition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGO_WingmanIntroCharacterPosition::IsValid() {
    return (m_ptr != nullptr);
}
GCCSGO_TeamIntroCharacterPosition GCCSGO_WingmanIntroCharacterPosition::GetParent() const {
    GCCSGO_TeamIntroCharacterPosition value(m_ptr);
    return value;
}
void GCCSGO_WingmanIntroCharacterPosition::SetParent(GCCSGO_TeamIntroCharacterPosition value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSGO_WingmanIntroCharacterPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_WingmanIntroCharacterPosition>("CCSGO_WingmanIntroCharacterPosition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSGO_WingmanIntroCharacterPosition::GetParent, &GCCSGO_WingmanIntroCharacterPosition::SetParent)
        .addFunction("ToPtr", &GCCSGO_WingmanIntroCharacterPosition::ToPtr)
        .addFunction("IsValid", &GCCSGO_WingmanIntroCharacterPosition::IsValid)
        .endClass();
}