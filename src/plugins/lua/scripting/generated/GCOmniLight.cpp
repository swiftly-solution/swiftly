#include "../../../core/scripting/generated/classes/GCOmniLight.h"
#include "../core.h"

void SetupLuaClassGCOmniLight(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCOmniLight>("COmniLight")
        .addProperty("InnerAngle", &GCOmniLight::GetInnerAngle, &GCOmniLight::SetInnerAngle)
        .addProperty("OuterAngle", &GCOmniLight::GetOuterAngle, &GCOmniLight::SetOuterAngle)
        .addProperty("ShowLight", &GCOmniLight::GetShowLight, &GCOmniLight::SetShowLight)
        .endClass();
}