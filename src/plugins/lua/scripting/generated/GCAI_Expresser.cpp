#include "../../../core/scripting/generated/classes/GCAI_Expresser.h"
#include "../core.h"

void SetupLuaClassGCAI_Expresser(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAI_Expresser>("CAI_Expresser")
        .addProperty("VoicePitch", &GCAI_Expresser::GetVoicePitch, &GCAI_Expresser::SetVoicePitch)
        .addProperty("AllowSpeakingInterrupts", &GCAI_Expresser::GetAllowSpeakingInterrupts, &GCAI_Expresser::SetAllowSpeakingInterrupts)
        .addProperty("ConsiderSceneInvolvementAsSpeech", &GCAI_Expresser::GetConsiderSceneInvolvementAsSpeech, &GCAI_Expresser::SetConsiderSceneInvolvementAsSpeech)
        .addProperty("SceneEntityDisabled", &GCAI_Expresser::GetSceneEntityDisabled, &GCAI_Expresser::SetSceneEntityDisabled)
        .addProperty("LastSpokenPriority", &GCAI_Expresser::GetLastSpokenPriority, &GCAI_Expresser::SetLastSpokenPriority)
        .addProperty("Outer", &GCAI_Expresser::GetOuter, &GCAI_Expresser::SetOuter)
        .endClass();
}