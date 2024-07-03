#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCEnvFunnel::GCEnvFunnel(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCEnvFunnel::GCEnvFunnel(void *ptr) {
    m_ptr = ptr;
}
std::string GCEnvFunnel::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCEnvFunnel::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCEnvFunnel::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCEnvFunnel::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCEnvFunnel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvFunnel>("CEnvFunnel")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCEnvFunnel::GetParent, &GCEnvFunnel::SetParent)
        .addFunction("ToPtr", &GCEnvFunnel::ToPtr)
        .addFunction("IsValid", &GCEnvFunnel::IsValid)
        .endClass();
}