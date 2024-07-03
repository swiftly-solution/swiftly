#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GRnSphereDesc_t::GRnSphereDesc_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GRnSphereDesc_t::GRnSphereDesc_t(void *ptr) {
    m_ptr = ptr;
}
std::string GRnSphereDesc_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GRnSphereDesc_t::IsValid() {
    return (m_ptr != nullptr);
}
GRnShapeDesc_t GRnSphereDesc_t::GetParent() const {
    GRnShapeDesc_t value(m_ptr);
    return value;
}
void GRnSphereDesc_t::SetParent(GRnShapeDesc_t value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassRnSphereDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnSphereDesc_t>("RnSphereDesc_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GRnSphereDesc_t::GetParent, &GRnSphereDesc_t::SetParent)
        .addFunction("ToPtr", &GRnSphereDesc_t::ToPtr)
        .addFunction("IsValid", &GRnSphereDesc_t::IsValid)
        .endClass();
}