#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointEntity::GCPointEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointEntity::GCPointEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCPointEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseEntity GCPointEntity::GetParent() const {
    GCBaseEntity value(m_ptr);
    return value;
}
void GCPointEntity::SetParent(GCBaseEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointEntity>("CPointEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPointEntity::GetParent, &GCPointEntity::SetParent)
        .addFunction("ToPtr", &GCPointEntity::ToPtr)
        .addFunction("IsValid", &GCPointEntity::IsValid)
        .endClass();
}