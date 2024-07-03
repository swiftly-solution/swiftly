#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSignatureOutflow_Resume::GSignatureOutflow_Resume(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSignatureOutflow_Resume::GSignatureOutflow_Resume(void *ptr) {
    m_ptr = ptr;
}
std::string GSignatureOutflow_Resume::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSignatureOutflow_Resume::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSignatureOutflow_Resume(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSignatureOutflow_Resume>("SignatureOutflow_Resume")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GSignatureOutflow_Resume::ToPtr)
        .addFunction("IsValid", &GSignatureOutflow_Resume::IsValid)
        .endClass();
}