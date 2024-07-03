#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCInfoParticleTarget::GCInfoParticleTarget(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCInfoParticleTarget::GCInfoParticleTarget(void *ptr) {
    m_ptr = ptr;
}
std::string GCInfoParticleTarget::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCInfoParticleTarget::IsValid() {
    return (m_ptr != nullptr);
}
GCPointEntity GCInfoParticleTarget::GetParent() const {
    GCPointEntity value(m_ptr);
    return value;
}
void GCInfoParticleTarget::SetParent(GCPointEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCInfoParticleTarget(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoParticleTarget>("CInfoParticleTarget")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCInfoParticleTarget::GetParent, &GCInfoParticleTarget::SetParent)
        .addFunction("ToPtr", &GCInfoParticleTarget::ToPtr)
        .addFunction("IsValid", &GCInfoParticleTarget::IsValid)
        .endClass();
}