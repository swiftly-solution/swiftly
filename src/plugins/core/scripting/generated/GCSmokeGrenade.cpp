#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSmokeGrenade::GCSmokeGrenade(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSmokeGrenade::GCSmokeGrenade(void *ptr) {
    m_ptr = ptr;
}
std::string GCSmokeGrenade::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSmokeGrenade::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseCSGrenade GCSmokeGrenade::GetParent() const {
    GCBaseCSGrenade value(m_ptr);
    return value;
}
void GCSmokeGrenade::SetParent(GCBaseCSGrenade value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSmokeGrenade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSmokeGrenade>("CSmokeGrenade")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCSmokeGrenade::GetParent, &GCSmokeGrenade::SetParent)
        .addFunction("ToPtr", &GCSmokeGrenade::ToPtr)
        .addFunction("IsValid", &GCSmokeGrenade::IsValid)
        .endClass();
}