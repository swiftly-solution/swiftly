#include "../../../core/scripting/generated/classes/GFeQuad_t.h"
#include "../core.h"

void SetupLuaClassGFeQuad_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeQuad_t>("FeQuad_t")
        .addProperty("Node", &GFeQuad_t::GetNode, &GFeQuad_t::SetNode)
        .addProperty("Slack", &GFeQuad_t::GetSlack, &GFeQuad_t::SetSlack)
        .addProperty("Shape", &GFeQuad_t::GetShape, &GFeQuad_t::SetShape)
        .endClass();
}