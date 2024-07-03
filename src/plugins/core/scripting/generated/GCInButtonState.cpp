#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInButtonState::GCInButtonState(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInButtonState::GCInButtonState(void *ptr) {
    m_ptr = ptr;
}
std::vector<uint64_t> GCInButtonState::GetButtonStates() const {
    uint64_t* outValue = GetSchemaValue<uint64_t*>(m_ptr, "CInButtonState", "m_pButtonStates"); std::vector<uint64_t> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret;
}
void GCInButtonState::SetButtonStates(std::vector<uint64_t> value) {
    uint64_t* outValue = GetSchemaValue<uint64_t*>(m_ptr, "CInButtonState", "m_pButtonStates"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "CInButtonState", "m_pButtonStates", false, outValue);
}
std::string GCInButtonState::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInButtonState::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassCInButtonState(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInButtonState>("CInButtonState")
        .addConstructor<void (*)(std::string)>()
        .addProperty("ButtonStates", &GCInButtonState::GetButtonStates, &GCInButtonState::SetButtonStates)
        .addFunction("ToPtr", &GCInButtonState::ToPtr)
        .addFunction("IsValid", &GCInButtonState::IsValid)
        .endClass();
}