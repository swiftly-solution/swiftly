#include "../../../core/scripting/generated/classes/GPointCameraSettings_t.h"
#include "../core.h"

void SetupLuaClassGPointCameraSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GPointCameraSettings_t>("PointCameraSettings_t")
        .addProperty("NearBlurryDistance", &GPointCameraSettings_t::GetNearBlurryDistance, &GPointCameraSettings_t::SetNearBlurryDistance)
        .addProperty("NearCrispDistance", &GPointCameraSettings_t::GetNearCrispDistance, &GPointCameraSettings_t::SetNearCrispDistance)
        .addProperty("FarCrispDistance", &GPointCameraSettings_t::GetFarCrispDistance, &GPointCameraSettings_t::SetFarCrispDistance)
        .addProperty("FarBlurryDistance", &GPointCameraSettings_t::GetFarBlurryDistance, &GPointCameraSettings_t::SetFarBlurryDistance)
        .endClass();
}