#include "../../../core/scripting/generated/classes/GCGameRules.h"
#include "../core.h"

void SetupLuaClassGCGameRules(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameRules>("CGameRules")
        .addProperty("__pChainEntity", &GCGameRules::Get__pChainEntity, &GCGameRules::Set__pChainEntity)
        .addProperty("QuestName", &GCGameRules::GetQuestName, &GCGameRules::SetQuestName)
        .addProperty("QuestPhase", &GCGameRules::GetQuestPhase, &GCGameRules::SetQuestPhase)
        .addProperty("TotalPausedTicks", &GCGameRules::GetTotalPausedTicks, &GCGameRules::SetTotalPausedTicks)
        .addProperty("PauseStartTick", &GCGameRules::GetPauseStartTick, &GCGameRules::SetPauseStartTick)
        .addProperty("GamePaused", &GCGameRules::GetGamePaused, &GCGameRules::SetGamePaused)
        .endClass();
}