#include "../../../core/scripting/generated/classes/GCGunTarget.h"
#include "../core.h"

void SetupLuaClassGCGunTarget(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGunTarget>("CGunTarget")
        .addProperty("On", &GCGunTarget::GetOn, &GCGunTarget::SetOn)
        .addProperty("TargetEnt", &GCGunTarget::GetTargetEnt, &GCGunTarget::SetTargetEnt)
        .addProperty("OnDeath", &GCGunTarget::GetOnDeath, &GCGunTarget::SetOnDeath)
        .endClass();
}