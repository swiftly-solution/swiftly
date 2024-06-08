#include "../../../core/scripting/generated/classes/GFeSimdSpringIntegrator_t.h"
#include "../core.h"

void SetupLuaClassGFeSimdSpringIntegrator_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSimdSpringIntegrator_t>("FeSimdSpringIntegrator_t")
        .addProperty("SpringRestLength", &GFeSimdSpringIntegrator_t::GetSpringRestLength, &GFeSimdSpringIntegrator_t::SetSpringRestLength)
        .addProperty("SpringConstant", &GFeSimdSpringIntegrator_t::GetSpringConstant, &GFeSimdSpringIntegrator_t::SetSpringConstant)
        .addProperty("SpringDamping", &GFeSimdSpringIntegrator_t::GetSpringDamping, &GFeSimdSpringIntegrator_t::SetSpringDamping)
        .addProperty("NodeWeight0", &GFeSimdSpringIntegrator_t::GetNodeWeight0, &GFeSimdSpringIntegrator_t::SetNodeWeight0)
        .endClass();
}