#include "../../../core/scripting/generated/classes/GRnSoftbodyParticle_t.h"
#include "../core.h"

void SetupLuaClassGRnSoftbodyParticle_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnSoftbodyParticle_t>("RnSoftbodyParticle_t")
        .addProperty("MassInv", &GRnSoftbodyParticle_t::GetMassInv, &GRnSoftbodyParticle_t::SetMassInv)
        .endClass();
}