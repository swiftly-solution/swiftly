#include "../../../core/scripting/generated/classes/GCBaseAnimGraphController.h"
#include "../core.h"

void SetupLuaClassGCBaseAnimGraphController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseAnimGraphController>("CBaseAnimGraphController")
        .addProperty("AnimGraphNetworkedVars", &GCBaseAnimGraphController::GetAnimGraphNetworkedVars, &GCBaseAnimGraphController::SetAnimGraphNetworkedVars)
        .addProperty("SequenceFinished", &GCBaseAnimGraphController::GetSequenceFinished, &GCBaseAnimGraphController::SetSequenceFinished)
        .addProperty("SoundSyncTime", &GCBaseAnimGraphController::GetSoundSyncTime, &GCBaseAnimGraphController::SetSoundSyncTime)
        .addProperty("ActiveIKChainMask", &GCBaseAnimGraphController::GetActiveIKChainMask, &GCBaseAnimGraphController::SetActiveIKChainMask)
        .addProperty("SeqFixedCycle", &GCBaseAnimGraphController::GetSeqFixedCycle, &GCBaseAnimGraphController::SetSeqFixedCycle)
        .addProperty("AnimLoopMode", &GCBaseAnimGraphController::GetAnimLoopMode, &GCBaseAnimGraphController::SetAnimLoopMode)
        .addProperty("PlaybackRate", &GCBaseAnimGraphController::GetPlaybackRate, &GCBaseAnimGraphController::SetPlaybackRate)
        .addProperty("NotifyState", &GCBaseAnimGraphController::GetNotifyState, &GCBaseAnimGraphController::SetNotifyState)
        .addProperty("NetworkedAnimationInputsChanged", &GCBaseAnimGraphController::GetNetworkedAnimationInputsChanged, &GCBaseAnimGraphController::SetNetworkedAnimationInputsChanged)
        .addProperty("NetworkedSequenceChanged", &GCBaseAnimGraphController::GetNetworkedSequenceChanged, &GCBaseAnimGraphController::SetNetworkedSequenceChanged)
        .addProperty("LastUpdateSkipped", &GCBaseAnimGraphController::GetLastUpdateSkipped, &GCBaseAnimGraphController::SetLastUpdateSkipped)
        .endClass();
}