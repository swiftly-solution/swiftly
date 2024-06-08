#include "../../../core/scripting/generated/classes/GFeNodeIntegrator_t.h"
#include "../core.h"

void SetupLuaClassGFeNodeIntegrator_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeNodeIntegrator_t>("FeNodeIntegrator_t")
        .addProperty("PointDamping", &GFeNodeIntegrator_t::GetPointDamping, &GFeNodeIntegrator_t::SetPointDamping)
        .addProperty("AnimationForceAttraction", &GFeNodeIntegrator_t::GetAnimationForceAttraction, &GFeNodeIntegrator_t::SetAnimationForceAttraction)
        .addProperty("AnimationVertexAttraction", &GFeNodeIntegrator_t::GetAnimationVertexAttraction, &GFeNodeIntegrator_t::SetAnimationVertexAttraction)
        .addProperty("Gravity", &GFeNodeIntegrator_t::GetGravity, &GFeNodeIntegrator_t::SetGravity)
        .endClass();
}