#include "../../../core/scripting/generated/classes/GCCSTeam.h"
#include "../core.h"

void SetupLuaClassGCCSTeam(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSTeam>("CCSTeam")
        .addProperty("LastRecievedShorthandedRoundBonus", &GCCSTeam::GetLastRecievedShorthandedRoundBonus, &GCCSTeam::SetLastRecievedShorthandedRoundBonus)
        .addProperty("ShorthandedRoundBonusStartRound", &GCCSTeam::GetShorthandedRoundBonusStartRound, &GCCSTeam::SetShorthandedRoundBonusStartRound)
        .addProperty("Surrendered", &GCCSTeam::GetSurrendered, &GCCSTeam::SetSurrendered)
        .addProperty("TeamMatchStat", &GCCSTeam::GetTeamMatchStat, &GCCSTeam::SetTeamMatchStat)
        .addProperty("NumMapVictories", &GCCSTeam::GetNumMapVictories, &GCCSTeam::SetNumMapVictories)
        .addProperty("ScoreFirstHalf", &GCCSTeam::GetScoreFirstHalf, &GCCSTeam::SetScoreFirstHalf)
        .addProperty("ScoreSecondHalf", &GCCSTeam::GetScoreSecondHalf, &GCCSTeam::SetScoreSecondHalf)
        .addProperty("ScoreOvertime", &GCCSTeam::GetScoreOvertime, &GCCSTeam::SetScoreOvertime)
        .addProperty("ClanTeamname", &GCCSTeam::GetClanTeamname, &GCCSTeam::SetClanTeamname)
        .addProperty("ClanID", &GCCSTeam::GetClanID, &GCCSTeam::SetClanID)
        .addProperty("TeamFlagImage", &GCCSTeam::GetTeamFlagImage, &GCCSTeam::SetTeamFlagImage)
        .addProperty("TeamLogoImage", &GCCSTeam::GetTeamLogoImage, &GCCSTeam::SetTeamLogoImage)
        .addProperty("NextResourceTime", &GCCSTeam::GetNextResourceTime, &GCCSTeam::SetNextResourceTime)
        .addProperty("LastUpdateSentAt", &GCCSTeam::GetLastUpdateSentAt, &GCCSTeam::SetLastUpdateSentAt)
        .endClass();
}