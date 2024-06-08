#include "../../../core/scripting/generated/classes/GCSpotlightEnd.h"
#include "../core.h"

void SetupLuaClassGCSpotlightEnd(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSpotlightEnd>("CSpotlightEnd")
        .addProperty("LightScale", &GCSpotlightEnd::GetLightScale, &GCSpotlightEnd::SetLightScale)
        .addProperty("Radius", &GCSpotlightEnd::GetRadius, &GCSpotlightEnd::SetRadius)
        .addProperty("SpotlightDir", &GCSpotlightEnd::GetSpotlightDir, &GCSpotlightEnd::SetSpotlightDir)
        .addProperty("SpotlightOrg", &GCSpotlightEnd::GetSpotlightOrg, &GCSpotlightEnd::SetSpotlightOrg)
        .endClass();
}