#include "../../../core/scripting/generated/classes/GResponseFollowup.h"
#include "../core.h"

void SetupLuaClassGResponseFollowup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GResponseFollowup>("ResponseFollowup")
        .addProperty("Followup_concept", &GResponseFollowup::GetFollowup_concept, &GResponseFollowup::SetFollowup_concept)
        .addProperty("Followup_contexts", &GResponseFollowup::GetFollowup_contexts, &GResponseFollowup::SetFollowup_contexts)
        .addProperty("Followup_delay", &GResponseFollowup::GetFollowup_delay, &GResponseFollowup::SetFollowup_delay)
        .addProperty("Followup_target", &GResponseFollowup::GetFollowup_target, &GResponseFollowup::SetFollowup_target)
        .addProperty("Followup_entityiotarget", &GResponseFollowup::GetFollowup_entityiotarget, &GResponseFollowup::SetFollowup_entityiotarget)
        .addProperty("Followup_entityioinput", &GResponseFollowup::GetFollowup_entityioinput, &GResponseFollowup::SetFollowup_entityioinput)
        .addProperty("Followup_entityiodelay", &GResponseFollowup::GetFollowup_entityiodelay, &GResponseFollowup::SetFollowup_entityiodelay)
        .addProperty("Fired", &GResponseFollowup::GetFired, &GResponseFollowup::SetFired)
        .endClass();
}