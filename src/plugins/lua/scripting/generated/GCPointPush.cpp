#include "../../../core/scripting/generated/classes/GCPointPush.h"
#include "../core.h"

void SetupLuaClassGCPointPush(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointPush>("CPointPush")
        .addProperty("Enabled", &GCPointPush::GetEnabled, &GCPointPush::SetEnabled)
        .addProperty("Magnitude", &GCPointPush::GetMagnitude, &GCPointPush::SetMagnitude)
        .addProperty("Radius", &GCPointPush::GetRadius, &GCPointPush::SetRadius)
        .addProperty("InnerRadius", &GCPointPush::GetInnerRadius, &GCPointPush::SetInnerRadius)
        .addProperty("ConeOfInfluence", &GCPointPush::GetConeOfInfluence, &GCPointPush::SetConeOfInfluence)
        .addProperty("FilterName", &GCPointPush::GetFilterName, &GCPointPush::SetFilterName)
        .addProperty("Filter", &GCPointPush::GetFilter, &GCPointPush::SetFilter)
        .endClass();
}