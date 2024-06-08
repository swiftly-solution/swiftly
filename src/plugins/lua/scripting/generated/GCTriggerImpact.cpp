#include "../../../core/scripting/generated/classes/GCTriggerImpact.h"
#include "../core.h"

void SetupLuaClassGCTriggerImpact(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerImpact>("CTriggerImpact")
        .addProperty("Magnitude", &GCTriggerImpact::GetMagnitude, &GCTriggerImpact::SetMagnitude)
        .addProperty("Noise", &GCTriggerImpact::GetNoise, &GCTriggerImpact::SetNoise)
        .addProperty("Viewkick", &GCTriggerImpact::GetViewkick, &GCTriggerImpact::SetViewkick)
        .endClass();
}