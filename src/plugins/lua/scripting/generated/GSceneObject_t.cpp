#include "../../../core/scripting/generated/classes/GSceneObject_t.h"
#include "../core.h"

void SetupLuaClassGSceneObject_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSceneObject_t>("SceneObject_t")
        .addProperty("ObjectID", &GSceneObject_t::GetObjectID, &GSceneObject_t::SetObjectID)
        .addProperty("Transform", &GSceneObject_t::GetTransform, &GSceneObject_t::SetTransform)
        .addProperty("FadeStartDistance", &GSceneObject_t::GetFadeStartDistance, &GSceneObject_t::SetFadeStartDistance)
        .addProperty("FadeEndDistance", &GSceneObject_t::GetFadeEndDistance, &GSceneObject_t::SetFadeEndDistance)
        .addProperty("TintColor", &GSceneObject_t::GetTintColor, &GSceneObject_t::SetTintColor)
        .addProperty("Skin", &GSceneObject_t::GetSkin, &GSceneObject_t::SetSkin)
        .addProperty("ObjectTypeFlags", &GSceneObject_t::GetObjectTypeFlags, &GSceneObject_t::SetObjectTypeFlags)
        .addProperty("LightingOrigin", &GSceneObject_t::GetLightingOrigin, &GSceneObject_t::SetLightingOrigin)
        .addProperty("OverlayRenderOrder", &GSceneObject_t::GetOverlayRenderOrder, &GSceneObject_t::SetOverlayRenderOrder)
        .addProperty("LODOverride", &GSceneObject_t::GetLODOverride, &GSceneObject_t::SetLODOverride)
        .addProperty("CubeMapPrecomputedHandshake", &GSceneObject_t::GetCubeMapPrecomputedHandshake, &GSceneObject_t::SetCubeMapPrecomputedHandshake)
        .addProperty("LightProbeVolumePrecomputedHandshake", &GSceneObject_t::GetLightProbeVolumePrecomputedHandshake, &GSceneObject_t::SetLightProbeVolumePrecomputedHandshake)
        .endClass();
}