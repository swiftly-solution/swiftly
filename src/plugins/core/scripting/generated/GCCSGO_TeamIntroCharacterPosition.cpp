#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGO_TeamIntroCharacterPosition::GCCSGO_TeamIntroCharacterPosition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGO_TeamIntroCharacterPosition::GCCSGO_TeamIntroCharacterPosition(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSGO_TeamIntroCharacterPosition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGO_TeamIntroCharacterPosition::IsValid() {
    return (m_ptr != nullptr);
}
GCCSGO_TeamPreviewCharacterPosition GCCSGO_TeamIntroCharacterPosition::GetParent() const {
    GCCSGO_TeamPreviewCharacterPosition value(m_ptr);
    return value;
}
void GCCSGO_TeamIntroCharacterPosition::SetParent(GCCSGO_TeamPreviewCharacterPosition value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSGO_TeamIntroCharacterPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_TeamIntroCharacterPosition>("CCSGO_TeamIntroCharacterPosition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSGO_TeamIntroCharacterPosition::GetParent, &GCCSGO_TeamIntroCharacterPosition::SetParent)
        .addFunction("ToPtr", &GCCSGO_TeamIntroCharacterPosition::ToPtr)
        .addFunction("IsValid", &GCCSGO_TeamIntroCharacterPosition::IsValid)
        .endClass();
}