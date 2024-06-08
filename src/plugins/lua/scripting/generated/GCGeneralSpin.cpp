#include "../../../core/scripting/generated/classes/GCGeneralSpin.h"
#include "../core.h"

void SetupLuaClassGCGeneralSpin(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGeneralSpin>("CGeneralSpin")
        .addProperty("SpinRateDegrees", &GCGeneralSpin::GetSpinRateDegrees, &GCGeneralSpin::SetSpinRateDegrees)
        .addProperty("SpinRateMinDegrees", &GCGeneralSpin::GetSpinRateMinDegrees, &GCGeneralSpin::SetSpinRateMinDegrees)
        .addProperty("SpinRateStopTime", &GCGeneralSpin::GetSpinRateStopTime, &GCGeneralSpin::SetSpinRateStopTime)
        .endClass();
}