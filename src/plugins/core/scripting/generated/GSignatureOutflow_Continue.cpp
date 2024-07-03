#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GSignatureOutflow_Continue::GSignatureOutflow_Continue(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GSignatureOutflow_Continue::GSignatureOutflow_Continue(void *ptr) {
    m_ptr = ptr;
}
std::string GSignatureOutflow_Continue::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GSignatureOutflow_Continue::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassSignatureOutflow_Continue(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSignatureOutflow_Continue>("SignatureOutflow_Continue")
        .addConstructor<void (*)(std::string)>()
        .addFunction("ToPtr", &GSignatureOutflow_Continue::ToPtr)
        .addFunction("IsValid", &GSignatureOutflow_Continue::IsValid)
        .endClass();
}