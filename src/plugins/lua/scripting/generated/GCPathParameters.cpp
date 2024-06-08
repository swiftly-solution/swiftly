#include "../../../core/scripting/generated/classes/GCPathParameters.h"
#include "../core.h"

void SetupLuaClassGCPathParameters(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathParameters>("CPathParameters")
        .addProperty("StartControlPointNumber", &GCPathParameters::GetStartControlPointNumber, &GCPathParameters::SetStartControlPointNumber)
        .addProperty("EndControlPointNumber", &GCPathParameters::GetEndControlPointNumber, &GCPathParameters::SetEndControlPointNumber)
        .addProperty("BulgeControl", &GCPathParameters::GetBulgeControl, &GCPathParameters::SetBulgeControl)
        .addProperty("Bulge", &GCPathParameters::GetBulge, &GCPathParameters::SetBulge)
        .addProperty("MidPoint", &GCPathParameters::GetMidPoint, &GCPathParameters::SetMidPoint)
        .addProperty("StartPointOffset", &GCPathParameters::GetStartPointOffset, &GCPathParameters::SetStartPointOffset)
        .addProperty("MidPointOffset", &GCPathParameters::GetMidPointOffset, &GCPathParameters::SetMidPointOffset)
        .addProperty("EndOffset", &GCPathParameters::GetEndOffset, &GCPathParameters::SetEndOffset)
        .endClass();
}