#include "../../../core/scripting/generated/classes/GCSplineConstraint.h"
#include "../core.h"

void SetupLuaClassGCSplineConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSplineConstraint>("CSplineConstraint")
        .addProperty("AnchorOffsetRestore", &GCSplineConstraint::GetAnchorOffsetRestore, &GCSplineConstraint::SetAnchorOffsetRestore)
        .endClass();
}