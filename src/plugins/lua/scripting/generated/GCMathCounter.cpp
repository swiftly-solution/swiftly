#include "../../../core/scripting/generated/classes/GCMathCounter.h"
#include "../core.h"

void SetupLuaClassGCMathCounter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMathCounter>("CMathCounter")
        .addProperty("Min", &GCMathCounter::GetMin, &GCMathCounter::SetMin)
        .addProperty("Max", &GCMathCounter::GetMax, &GCMathCounter::SetMax)
        .addProperty("HitMin", &GCMathCounter::GetHitMin, &GCMathCounter::SetHitMin)
        .addProperty("HitMax", &GCMathCounter::GetHitMax, &GCMathCounter::SetHitMax)
        .addProperty("Disabled", &GCMathCounter::GetDisabled, &GCMathCounter::SetDisabled)
        .addProperty("OnHitMin", &GCMathCounter::GetOnHitMin, &GCMathCounter::SetOnHitMin)
        .addProperty("OnHitMax", &GCMathCounter::GetOnHitMax, &GCMathCounter::SetOnHitMax)
        .addProperty("OnChangedFromMin", &GCMathCounter::GetOnChangedFromMin, &GCMathCounter::SetOnChangedFromMin)
        .addProperty("OnChangedFromMax", &GCMathCounter::GetOnChangedFromMax, &GCMathCounter::SetOnChangedFromMax)
        .endClass();
}