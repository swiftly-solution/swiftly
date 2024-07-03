#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCRagdollPropAlias_physics_prop_ragdoll::GCRagdollPropAlias_physics_prop_ragdoll(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCRagdollPropAlias_physics_prop_ragdoll::GCRagdollPropAlias_physics_prop_ragdoll(void *ptr) {
    m_ptr = ptr;
}
std::string GCRagdollPropAlias_physics_prop_ragdoll::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCRagdollPropAlias_physics_prop_ragdoll::IsValid() {
    return (m_ptr != nullptr);
}
GCRagdollProp GCRagdollPropAlias_physics_prop_ragdoll::GetParent() const {
    GCRagdollProp value(m_ptr);
    return value;
}
void GCRagdollPropAlias_physics_prop_ragdoll::SetParent(GCRagdollProp value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCRagdollPropAlias_physics_prop_ragdoll(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollPropAlias_physics_prop_ragdoll>("CRagdollPropAlias_physics_prop_ragdoll")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCRagdollPropAlias_physics_prop_ragdoll::GetParent, &GCRagdollPropAlias_physics_prop_ragdoll::SetParent)
        .addFunction("ToPtr", &GCRagdollPropAlias_physics_prop_ragdoll::ToPtr)
        .addFunction("IsValid", &GCRagdollPropAlias_physics_prop_ragdoll::IsValid)
        .endClass();
}