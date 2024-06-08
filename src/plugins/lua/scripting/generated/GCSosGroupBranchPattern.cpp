#include "../../../core/scripting/generated/classes/GCSosGroupBranchPattern.h"
#include "../core.h"

void SetupLuaClassGCSosGroupBranchPattern(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupBranchPattern>("CSosGroupBranchPattern")
        .addProperty("MatchEventName", &GCSosGroupBranchPattern::GetMatchEventName, &GCSosGroupBranchPattern::SetMatchEventName)
        .addProperty("MatchEventSubString", &GCSosGroupBranchPattern::GetMatchEventSubString, &GCSosGroupBranchPattern::SetMatchEventSubString)
        .addProperty("MatchEntIndex", &GCSosGroupBranchPattern::GetMatchEntIndex, &GCSosGroupBranchPattern::SetMatchEntIndex)
        .addProperty("MatchOpvar", &GCSosGroupBranchPattern::GetMatchOpvar, &GCSosGroupBranchPattern::SetMatchOpvar)
        .addProperty("MatchString", &GCSosGroupBranchPattern::GetMatchString, &GCSosGroupBranchPattern::SetMatchString)
        .endClass();
}