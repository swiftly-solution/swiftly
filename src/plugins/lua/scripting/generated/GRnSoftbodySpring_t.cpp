#include "../../../core/scripting/generated/classes/GRnSoftbodySpring_t.h"
#include "../core.h"

void SetupLuaClassGRnSoftbodySpring_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnSoftbodySpring_t>("RnSoftbodySpring_t")
        .addProperty("Particle", &GRnSoftbodySpring_t::GetParticle, &GRnSoftbodySpring_t::SetParticle)
        .addProperty("Length", &GRnSoftbodySpring_t::GetLength, &GRnSoftbodySpring_t::SetLength)
        .endClass();
}