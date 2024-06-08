#include "../../../core/scripting/generated/classes/GCParticleFunctionRenderer.h"
#include "../core.h"

void SetupLuaClassGCParticleFunctionRenderer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCParticleFunctionRenderer>("CParticleFunctionRenderer")
        .addProperty("VisibilityInputs", &GCParticleFunctionRenderer::GetVisibilityInputs, &GCParticleFunctionRenderer::SetVisibilityInputs)
        .addProperty("CannotBeRefracted", &GCParticleFunctionRenderer::GetCannotBeRefracted, &GCParticleFunctionRenderer::SetCannotBeRefracted)
        .addProperty("SkipRenderingOnMobile", &GCParticleFunctionRenderer::GetSkipRenderingOnMobile, &GCParticleFunctionRenderer::SetSkipRenderingOnMobile)
        .endClass();
}