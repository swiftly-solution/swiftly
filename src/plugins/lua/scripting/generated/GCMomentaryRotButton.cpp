#include "../../../core/scripting/generated/classes/GCMomentaryRotButton.h"
#include "../core.h"

void SetupLuaClassGCMomentaryRotButton(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMomentaryRotButton>("CMomentaryRotButton")
        .addProperty("OnUnpressed", &GCMomentaryRotButton::GetOnUnpressed, &GCMomentaryRotButton::SetOnUnpressed)
        .addProperty("OnFullyOpen", &GCMomentaryRotButton::GetOnFullyOpen, &GCMomentaryRotButton::SetOnFullyOpen)
        .addProperty("OnFullyClosed", &GCMomentaryRotButton::GetOnFullyClosed, &GCMomentaryRotButton::SetOnFullyClosed)
        .addProperty("OnReachedPosition", &GCMomentaryRotButton::GetOnReachedPosition, &GCMomentaryRotButton::SetOnReachedPosition)
        .addProperty("LastUsed", &GCMomentaryRotButton::GetLastUsed, &GCMomentaryRotButton::SetLastUsed)
        .addProperty("Start", &GCMomentaryRotButton::GetStart, &GCMomentaryRotButton::SetStart)
        .addProperty("End", &GCMomentaryRotButton::GetEnd, &GCMomentaryRotButton::SetEnd)
        .addProperty("IdealYaw", &GCMomentaryRotButton::GetIdealYaw, &GCMomentaryRotButton::SetIdealYaw)
        .addProperty("Noise", &GCMomentaryRotButton::GetNoise, &GCMomentaryRotButton::SetNoise)
        .addProperty("UpdateTarget", &GCMomentaryRotButton::GetUpdateTarget, &GCMomentaryRotButton::SetUpdateTarget)
        .addProperty("Direction", &GCMomentaryRotButton::GetDirection, &GCMomentaryRotButton::SetDirection)
        .addProperty("ReturnSpeed", &GCMomentaryRotButton::GetReturnSpeed, &GCMomentaryRotButton::SetReturnSpeed)
        .addProperty("StartPosition", &GCMomentaryRotButton::GetStartPosition, &GCMomentaryRotButton::SetStartPosition)
        .endClass();
}