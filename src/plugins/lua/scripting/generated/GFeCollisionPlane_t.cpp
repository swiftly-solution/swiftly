#include "../../../core/scripting/generated/classes/GFeCollisionPlane_t.h"
#include "../core.h"

void SetupLuaClassGFeCollisionPlane_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFeCollisionPlane_t>("FeCollisionPlane_t")
        .addProperty("CtrlParent", &GFeCollisionPlane_t::GetCtrlParent, &GFeCollisionPlane_t::SetCtrlParent)
        .addProperty("ChildNode", &GFeCollisionPlane_t::GetChildNode, &GFeCollisionPlane_t::SetChildNode)
        .addProperty("Plane", &GFeCollisionPlane_t::GetPlane, &GFeCollisionPlane_t::SetPlane)
        .addProperty("Strength", &GFeCollisionPlane_t::GetStrength, &GFeCollisionPlane_t::SetStrength)
        .endClass();
}