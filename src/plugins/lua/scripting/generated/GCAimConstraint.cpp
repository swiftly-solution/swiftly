#include "../../../core/scripting/generated/classes/GCAimConstraint.h"
#include "../core.h"

void SetupLuaClassGCAimConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAimConstraint>("CAimConstraint")
        .addProperty("AimOffset", &GCAimConstraint::GetAimOffset, &GCAimConstraint::SetAimOffset)
        .addProperty("UpType", &GCAimConstraint::GetUpType, &GCAimConstraint::SetUpType)
        .endClass();
}