#include "../../../core/scripting/generated/classes/GFeSpringIntegrator_t.h"
#include "../core.h"

void SetupLuaClassGFeSpringIntegrator_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSpringIntegrator_t>("FeSpringIntegrator_t")
        .addProperty("Node", &GFeSpringIntegrator_t::GetNode, &GFeSpringIntegrator_t::SetNode)
        .addProperty("SpringRestLength", &GFeSpringIntegrator_t::GetSpringRestLength, &GFeSpringIntegrator_t::SetSpringRestLength)
        .addProperty("SpringConstant", &GFeSpringIntegrator_t::GetSpringConstant, &GFeSpringIntegrator_t::SetSpringConstant)
        .addProperty("SpringDamping", &GFeSpringIntegrator_t::GetSpringDamping, &GFeSpringIntegrator_t::SetSpringDamping)
        .addProperty("NodeWeight0", &GFeSpringIntegrator_t::GetNodeWeight0, &GFeSpringIntegrator_t::SetNodeWeight0)
        .endClass();
}