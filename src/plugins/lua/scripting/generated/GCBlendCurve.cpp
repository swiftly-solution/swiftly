#include "../../../core/scripting/generated/classes/GCBlendCurve.h"
#include "../core.h"

void SetupLuaClassGCBlendCurve(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBlendCurve>("CBlendCurve")
        .addProperty("ControlPoint1", &GCBlendCurve::GetControlPoint1, &GCBlendCurve::SetControlPoint1)
        .addProperty("ControlPoint2", &GCBlendCurve::GetControlPoint2, &GCBlendCurve::SetControlPoint2)
        .endClass();
}