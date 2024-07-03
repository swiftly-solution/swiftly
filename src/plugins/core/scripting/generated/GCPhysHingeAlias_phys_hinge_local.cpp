#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPhysHingeAlias_phys_hinge_local::GCPhysHingeAlias_phys_hinge_local(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPhysHingeAlias_phys_hinge_local::GCPhysHingeAlias_phys_hinge_local(void *ptr) {
    m_ptr = ptr;
}
std::string GCPhysHingeAlias_phys_hinge_local::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPhysHingeAlias_phys_hinge_local::IsValid() {
    return (m_ptr != nullptr);
}
GCPhysHinge GCPhysHingeAlias_phys_hinge_local::GetParent() const {
    GCPhysHinge value(m_ptr);
    return value;
}
void GCPhysHingeAlias_phys_hinge_local::SetParent(GCPhysHinge value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPhysHingeAlias_phys_hinge_local(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysHingeAlias_phys_hinge_local>("CPhysHingeAlias_phys_hinge_local")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPhysHingeAlias_phys_hinge_local::GetParent, &GCPhysHingeAlias_phys_hinge_local::SetParent)
        .addFunction("ToPtr", &GCPhysHingeAlias_phys_hinge_local::ToPtr)
        .addFunction("IsValid", &GCPhysHingeAlias_phys_hinge_local::IsValid)
        .endClass();
}