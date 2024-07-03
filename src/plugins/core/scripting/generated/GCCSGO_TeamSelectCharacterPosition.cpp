#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCCSGO_TeamSelectCharacterPosition::GCCSGO_TeamSelectCharacterPosition(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCCSGO_TeamSelectCharacterPosition::GCCSGO_TeamSelectCharacterPosition(void *ptr) {
    m_ptr = ptr;
}
std::string GCCSGO_TeamSelectCharacterPosition::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCCSGO_TeamSelectCharacterPosition::IsValid() {
    return (m_ptr != nullptr);
}
GCCSGO_TeamPreviewCharacterPosition GCCSGO_TeamSelectCharacterPosition::GetParent() const {
    GCCSGO_TeamPreviewCharacterPosition value(m_ptr);
    return value;
}
void GCCSGO_TeamSelectCharacterPosition::SetParent(GCCSGO_TeamPreviewCharacterPosition value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCCSGO_TeamSelectCharacterPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSGO_TeamSelectCharacterPosition>("CCSGO_TeamSelectCharacterPosition")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCCSGO_TeamSelectCharacterPosition::GetParent, &GCCSGO_TeamSelectCharacterPosition::SetParent)
        .addFunction("ToPtr", &GCCSGO_TeamSelectCharacterPosition::ToPtr)
        .addFunction("IsValid", &GCCSGO_TeamSelectCharacterPosition::IsValid)
        .endClass();
}