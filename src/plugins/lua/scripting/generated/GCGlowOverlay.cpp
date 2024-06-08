#include "../../../core/scripting/generated/classes/GCGlowOverlay.h"
#include "../core.h"

void SetupLuaClassGCGlowOverlay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGlowOverlay>("CGlowOverlay")
        .addProperty("Pos", &GCGlowOverlay::GetPos, &GCGlowOverlay::SetPos)
        .addProperty("Directional", &GCGlowOverlay::GetDirectional, &GCGlowOverlay::SetDirectional)
        .addProperty("Direction", &GCGlowOverlay::GetDirection, &GCGlowOverlay::SetDirection)
        .addProperty("InSky", &GCGlowOverlay::GetInSky, &GCGlowOverlay::SetInSky)
        .addProperty("SkyObstructionScale", &GCGlowOverlay::GetSkyObstructionScale, &GCGlowOverlay::SetSkyObstructionScale)
        .addProperty("Sprites", &GCGlowOverlay::GetSprites, &GCGlowOverlay::SetSprites)
        .addProperty("Sprites1", &GCGlowOverlay::GetSprites1, &GCGlowOverlay::SetSprites1)
        .addProperty("ProxyRadius", &GCGlowOverlay::GetProxyRadius, &GCGlowOverlay::SetProxyRadius)
        .addProperty("HDRColorScale", &GCGlowOverlay::GetHDRColorScale, &GCGlowOverlay::SetHDRColorScale)
        .addProperty("GlowObstructionScale", &GCGlowOverlay::GetGlowObstructionScale, &GCGlowOverlay::SetGlowObstructionScale)
        .addProperty("CacheGlowObstruction", &GCGlowOverlay::GetCacheGlowObstruction, &GCGlowOverlay::SetCacheGlowObstruction)
        .addProperty("CacheSkyObstruction", &GCGlowOverlay::GetCacheSkyObstruction, &GCGlowOverlay::SetCacheSkyObstruction)
        .addProperty("Activated", &GCGlowOverlay::GetActivated, &GCGlowOverlay::SetActivated)
        .addProperty("ListIndex", &GCGlowOverlay::GetListIndex, &GCGlowOverlay::SetListIndex)
        .addProperty("QueryHandle", &GCGlowOverlay::GetQueryHandle, &GCGlowOverlay::SetQueryHandle)
        .endClass();
}