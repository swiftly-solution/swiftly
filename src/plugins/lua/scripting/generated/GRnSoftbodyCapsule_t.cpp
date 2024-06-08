#include "../../../core/scripting/generated/classes/GRnSoftbodyCapsule_t.h"
#include "../core.h"

void SetupLuaClassGRnSoftbodyCapsule_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnSoftbodyCapsule_t>("RnSoftbodyCapsule_t")
        .addProperty("Center", &GRnSoftbodyCapsule_t::GetCenter, &GRnSoftbodyCapsule_t::SetCenter)
        .addProperty("Radius", &GRnSoftbodyCapsule_t::GetRadius, &GRnSoftbodyCapsule_t::SetRadius)
        .addProperty("Particle", &GRnSoftbodyCapsule_t::GetParticle, &GRnSoftbodyCapsule_t::SetParticle)
        .endClass();
}