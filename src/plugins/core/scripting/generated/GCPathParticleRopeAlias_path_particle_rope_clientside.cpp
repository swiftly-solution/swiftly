#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPathParticleRopeAlias_path_particle_rope_clientside::GCPathParticleRopeAlias_path_particle_rope_clientside(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPathParticleRopeAlias_path_particle_rope_clientside::GCPathParticleRopeAlias_path_particle_rope_clientside(void *ptr) {
    m_ptr = ptr;
}
std::string GCPathParticleRopeAlias_path_particle_rope_clientside::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPathParticleRopeAlias_path_particle_rope_clientside::IsValid() {
    return (m_ptr != nullptr);
}
GCPathParticleRope GCPathParticleRopeAlias_path_particle_rope_clientside::GetParent() const {
    GCPathParticleRope value(m_ptr);
    return value;
}
void GCPathParticleRopeAlias_path_particle_rope_clientside::SetParent(GCPathParticleRope value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPathParticleRopeAlias_path_particle_rope_clientside(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathParticleRopeAlias_path_particle_rope_clientside>("CPathParticleRopeAlias_path_particle_rope_clientside")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Parent", &GCPathParticleRopeAlias_path_particle_rope_clientside::GetParent, &GCPathParticleRopeAlias_path_particle_rope_clientside::SetParent)
        .addFunction("ToPtr", &GCPathParticleRopeAlias_path_particle_rope_clientside::ToPtr)
        .addFunction("IsValid", &GCPathParticleRopeAlias_path_particle_rope_clientside::IsValid)
        .endClass();
}