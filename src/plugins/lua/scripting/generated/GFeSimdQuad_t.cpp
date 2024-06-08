#include "../../../core/scripting/generated/classes/GFeSimdQuad_t.h"
#include "../core.h"

void SetupLuaClassGFeSimdQuad_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeSimdQuad_t>("FeSimdQuad_t")
        .addProperty("4Slack", &GFeSimdQuad_t::Get4Slack, &GFeSimdQuad_t::Set4Slack)
        .addProperty("4Weights", &GFeSimdQuad_t::Get4Weights, &GFeSimdQuad_t::Set4Weights)
        .endClass();
}