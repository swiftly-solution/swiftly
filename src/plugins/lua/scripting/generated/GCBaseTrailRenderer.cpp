#include "../../../core/scripting/generated/classes/GCBaseTrailRenderer.h"
#include "../core.h"

void SetupLuaClassGCBaseTrailRenderer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseTrailRenderer>("CBaseTrailRenderer")
        .addProperty("OrientationType", &GCBaseTrailRenderer::GetOrientationType, &GCBaseTrailRenderer::SetOrientationType)
        .addProperty("OrientationControlPoint", &GCBaseTrailRenderer::GetOrientationControlPoint, &GCBaseTrailRenderer::SetOrientationControlPoint)
        .addProperty("MinSize", &GCBaseTrailRenderer::GetMinSize, &GCBaseTrailRenderer::SetMinSize)
        .addProperty("MaxSize", &GCBaseTrailRenderer::GetMaxSize, &GCBaseTrailRenderer::SetMaxSize)
        .addProperty("StartFadeSize", &GCBaseTrailRenderer::GetStartFadeSize, &GCBaseTrailRenderer::SetStartFadeSize)
        .addProperty("EndFadeSize", &GCBaseTrailRenderer::GetEndFadeSize, &GCBaseTrailRenderer::SetEndFadeSize)
        .addProperty("ClampV", &GCBaseTrailRenderer::GetClampV, &GCBaseTrailRenderer::SetClampV)
        .endClass();
}