#include "../../../core/scripting/generated/classes/GCBaseModelEntity.h"
#include "../core.h"

void SetupLuaClassGCBaseModelEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseModelEntity>("CBaseModelEntity")
        .addProperty("CRenderComponent", &GCBaseModelEntity::GetCRenderComponent, &GCBaseModelEntity::SetCRenderComponent)
        .addProperty("CHitboxComponent", &GCBaseModelEntity::GetCHitboxComponent, &GCBaseModelEntity::SetCHitboxComponent)
        .addProperty("OnIgnite", &GCBaseModelEntity::GetOnIgnite, &GCBaseModelEntity::SetOnIgnite)
        .addProperty("RenderMode", &GCBaseModelEntity::GetRenderMode, &GCBaseModelEntity::SetRenderMode)
        .addProperty("RenderFX", &GCBaseModelEntity::GetRenderFX, &GCBaseModelEntity::SetRenderFX)
        .addProperty("AllowFadeInView", &GCBaseModelEntity::GetAllowFadeInView, &GCBaseModelEntity::SetAllowFadeInView)
        .addProperty("Render", &GCBaseModelEntity::GetRender, &GCBaseModelEntity::SetRender)
        .addProperty("RenderAttributes", &GCBaseModelEntity::GetRenderAttributes, &GCBaseModelEntity::SetRenderAttributes)
        .addProperty("RenderToCubemaps", &GCBaseModelEntity::GetRenderToCubemaps, &GCBaseModelEntity::SetRenderToCubemaps)
        .addProperty("Collision", &GCBaseModelEntity::GetCollision, &GCBaseModelEntity::SetCollision)
        .addProperty("Glow", &GCBaseModelEntity::GetGlow, &GCBaseModelEntity::SetGlow)
        .addProperty("GlowBackfaceMult", &GCBaseModelEntity::GetGlowBackfaceMult, &GCBaseModelEntity::SetGlowBackfaceMult)
        .addProperty("FadeMinDist", &GCBaseModelEntity::GetFadeMinDist, &GCBaseModelEntity::SetFadeMinDist)
        .addProperty("FadeMaxDist", &GCBaseModelEntity::GetFadeMaxDist, &GCBaseModelEntity::SetFadeMaxDist)
        .addProperty("FadeScale", &GCBaseModelEntity::GetFadeScale, &GCBaseModelEntity::SetFadeScale)
        .addProperty("ShadowStrength", &GCBaseModelEntity::GetShadowStrength, &GCBaseModelEntity::SetShadowStrength)
        .addProperty("ObjectCulling", &GCBaseModelEntity::GetObjectCulling, &GCBaseModelEntity::SetObjectCulling)
        .addProperty("AddDecal", &GCBaseModelEntity::GetAddDecal, &GCBaseModelEntity::SetAddDecal)
        .addProperty("DecalPosition", &GCBaseModelEntity::GetDecalPosition, &GCBaseModelEntity::SetDecalPosition)
        .addProperty("DecalForwardAxis", &GCBaseModelEntity::GetDecalForwardAxis, &GCBaseModelEntity::SetDecalForwardAxis)
        .addProperty("DecalHealBloodRate", &GCBaseModelEntity::GetDecalHealBloodRate, &GCBaseModelEntity::SetDecalHealBloodRate)
        .addProperty("DecalHealHeightRate", &GCBaseModelEntity::GetDecalHealHeightRate, &GCBaseModelEntity::SetDecalHealHeightRate)
        .addProperty("ConfigEntitiesToPropagateMaterialDecalsTo", &GCBaseModelEntity::GetConfigEntitiesToPropagateMaterialDecalsTo, &GCBaseModelEntity::SetConfigEntitiesToPropagateMaterialDecalsTo)
        .addProperty("ViewOffset", &GCBaseModelEntity::GetViewOffset, &GCBaseModelEntity::SetViewOffset)
        .endClass();
}