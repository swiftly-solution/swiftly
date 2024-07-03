#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCSoundOpvarSetOBBEntity::GCSoundOpvarSetOBBEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCSoundOpvarSetOBBEntity::GCSoundOpvarSetOBBEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCSoundOpvarSetOBBEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCSoundOpvarSetOBBEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCSoundOpvarSetAABBEntity GCSoundOpvarSetOBBEntity::GetParent() const {
    GCSoundOpvarSetAABBEntity value(m_ptr);
    return value;
}
void GCSoundOpvarSetOBBEntity::SetParent(GCSoundOpvarSetAABBEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCSoundOpvarSetOBBEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundOpvarSetOBBEntity>("CSoundOpvarSetOBBEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCSoundOpvarSetOBBEntity::GetParent, &GCSoundOpvarSetOBBEntity::SetParent)
        .addFunction("ToPtr", &GCSoundOpvarSetOBBEntity::ToPtr)
        .addFunction("IsValid", &GCSoundOpvarSetOBBEntity::IsValid)
        .endClass();
}