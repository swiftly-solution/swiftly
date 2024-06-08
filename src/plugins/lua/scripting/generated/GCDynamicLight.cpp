#include "../../../core/scripting/generated/classes/GCDynamicLight.h"
#include "../core.h"

void SetupLuaClassGCDynamicLight(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDynamicLight>("CDynamicLight")
        .addProperty("ActualFlags", &GCDynamicLight::GetActualFlags, &GCDynamicLight::SetActualFlags)
        .addProperty("Flags", &GCDynamicLight::GetFlags, &GCDynamicLight::SetFlags)
        .addProperty("LightStyle", &GCDynamicLight::GetLightStyle, &GCDynamicLight::SetLightStyle)
        .addProperty("On", &GCDynamicLight::GetOn, &GCDynamicLight::SetOn)
        .addProperty("Radius", &GCDynamicLight::GetRadius, &GCDynamicLight::SetRadius)
        .addProperty("Exponent", &GCDynamicLight::GetExponent, &GCDynamicLight::SetExponent)
        .addProperty("InnerAngle", &GCDynamicLight::GetInnerAngle, &GCDynamicLight::SetInnerAngle)
        .addProperty("OuterAngle", &GCDynamicLight::GetOuterAngle, &GCDynamicLight::SetOuterAngle)
        .addProperty("SpotRadius", &GCDynamicLight::GetSpotRadius, &GCDynamicLight::SetSpotRadius)
        .endClass();
}