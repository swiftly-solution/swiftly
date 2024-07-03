#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCModelPointEntity::GCModelPointEntity(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCModelPointEntity::GCModelPointEntity(void *ptr) {
    m_ptr = ptr;
}
std::string GCModelPointEntity::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCModelPointEntity::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseModelEntity GCModelPointEntity::GetParent() const {
    GCBaseModelEntity value(m_ptr);
    return value;
}
void GCModelPointEntity::SetParent(GCBaseModelEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCModelPointEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelPointEntity>("CModelPointEntity")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCModelPointEntity::GetParent, &GCModelPointEntity::SetParent)
        .addFunction("ToPtr", &GCModelPointEntity::ToPtr)
        .addFunction("IsValid", &GCModelPointEntity::IsValid)
        .endClass();
}