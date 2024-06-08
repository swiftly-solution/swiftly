#include "../../../core/scripting/generated/classes/GViewAngleServerChange_t.h"
#include "../core.h"

void SetupLuaClassGViewAngleServerChange_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GViewAngleServerChange_t>("ViewAngleServerChange_t")
        .addProperty("Type", &GViewAngleServerChange_t::GetType, &GViewAngleServerChange_t::SetType)
        .addProperty("Angle", &GViewAngleServerChange_t::GetAngle, &GViewAngleServerChange_t::SetAngle)
        .addProperty("Index", &GViewAngleServerChange_t::GetIndex, &GViewAngleServerChange_t::SetIndex)
        .endClass();
}