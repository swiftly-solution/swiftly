#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSensorGrenade::GCSensorGrenade(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSensorGrenade::GCSensorGrenade(void *ptr) {
    m_ptr = ptr;
}
std::string GCSensorGrenade::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSensorGrenade::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseCSGrenade GCSensorGrenade::GetParent() const {
    GCBaseCSGrenade value(m_ptr);
    return value;
}
void GCSensorGrenade::SetParent(GCBaseCSGrenade value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSensorGrenade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSensorGrenade>("CSensorGrenade")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCSensorGrenade::GetParent, &GCSensorGrenade::SetParent)
        .addFunction("ToPtr", &GCSensorGrenade::ToPtr)
        .addFunction("IsValid", &GCSensorGrenade::IsValid)
        .endClass();
}