#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCLightSpotEntity::GCLightSpotEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCLightSpotEntity::GCLightSpotEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCLightSpotEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCLightSpotEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCLightEntity GCLightSpotEntity::GetParent() const {
    GCLightEntity value(m_ptr);
    return value;
}
void GCLightSpotEntity::SetParent(GCLightEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCLightSpotEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLightSpotEntity>("CLightSpotEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCLightSpotEntity::GetParent, &GCLightSpotEntity::SetParent)
        .addFunction("ToPtr", &GCLightSpotEntity::ToPtr)
        .addFunction("IsValid", &GCLightSpotEntity::IsValid)
        .endClass();
}