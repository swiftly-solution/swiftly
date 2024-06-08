#include "../../../core/scripting/generated/classes/GCInfoOffscreenPanoramaTexture.h"
#include "../core.h"

void SetupLuaClassGCInfoOffscreenPanoramaTexture(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoOffscreenPanoramaTexture>("CInfoOffscreenPanoramaTexture")
        .addProperty("Disabled", &GCInfoOffscreenPanoramaTexture::GetDisabled, &GCInfoOffscreenPanoramaTexture::SetDisabled)
        .addProperty("ResolutionX", &GCInfoOffscreenPanoramaTexture::GetResolutionX, &GCInfoOffscreenPanoramaTexture::SetResolutionX)
        .addProperty("ResolutionY", &GCInfoOffscreenPanoramaTexture::GetResolutionY, &GCInfoOffscreenPanoramaTexture::SetResolutionY)
        .addProperty("LayoutFileName", &GCInfoOffscreenPanoramaTexture::GetLayoutFileName, &GCInfoOffscreenPanoramaTexture::SetLayoutFileName)
        .addProperty("RenderAttrName", &GCInfoOffscreenPanoramaTexture::GetRenderAttrName, &GCInfoOffscreenPanoramaTexture::SetRenderAttrName)
        .addProperty("TargetEntities", &GCInfoOffscreenPanoramaTexture::GetTargetEntities, &GCInfoOffscreenPanoramaTexture::SetTargetEntities)
        .addProperty("TargetChangeCount", &GCInfoOffscreenPanoramaTexture::GetTargetChangeCount, &GCInfoOffscreenPanoramaTexture::SetTargetChangeCount)
        .addProperty("CSSClasses", &GCInfoOffscreenPanoramaTexture::GetCSSClasses, &GCInfoOffscreenPanoramaTexture::SetCSSClasses)
        .addProperty("TargetsName", &GCInfoOffscreenPanoramaTexture::GetTargetsName, &GCInfoOffscreenPanoramaTexture::SetTargetsName)
        .endClass();
}