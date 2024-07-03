#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCAI_ExpresserWithFollowup::GCAI_ExpresserWithFollowup(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCAI_ExpresserWithFollowup::GCAI_ExpresserWithFollowup(void *ptr) {
    m_ptr = ptr;
}
GResponseFollowup GCAI_ExpresserWithFollowup::GetPostponedFollowup() const {
    GResponseFollowup value(*GetSchemaValuePtr<void*>(m_ptr, "CAI_ExpresserWithFollowup", "m_pPostponedFollowup"));
    return value;
}
void GCAI_ExpresserWithFollowup::SetPostponedFollowup(GResponseFollowup* value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'PostponedFollowup' is not possible.\n");
}
std::string GCAI_ExpresserWithFollowup::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCAI_ExpresserWithFollowup::IsValid() {
    return (m_ptr != nullptr);
}
GCAI_Expresser GCAI_ExpresserWithFollowup::GetParent() const {
    GCAI_Expresser value(m_ptr);
    return value;
}
void GCAI_ExpresserWithFollowup::SetParent(GCAI_Expresser value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCAI_ExpresserWithFollowup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAI_ExpresserWithFollowup>("CAI_ExpresserWithFollowup")
        .addConstructor<void (*)(std::string)>()
        .addProperty("PostponedFollowup", &GCAI_ExpresserWithFollowup::GetPostponedFollowup, &GCAI_ExpresserWithFollowup::SetPostponedFollowup)
        .addProperty("Parent", &GCAI_ExpresserWithFollowup::GetParent, &GCAI_ExpresserWithFollowup::SetParent)
        .addFunction("ToPtr", &GCAI_ExpresserWithFollowup::ToPtr)
        .addFunction("IsValid", &GCAI_ExpresserWithFollowup::IsValid)
        .endClass();
}