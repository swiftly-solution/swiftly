#include "../../../core/scripting/generated/classes/GCSosGroupMatchPattern.h"
#include "../core.h"

void SetupLuaClassGCSosGroupMatchPattern(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupMatchPattern>("CSosGroupMatchPattern")
        .addProperty("MatchSoundEventName", &GCSosGroupMatchPattern::GetMatchSoundEventName, &GCSosGroupMatchPattern::SetMatchSoundEventName)
        .addProperty("MatchSoundEventSubString", &GCSosGroupMatchPattern::GetMatchSoundEventSubString, &GCSosGroupMatchPattern::SetMatchSoundEventSubString)
        .addProperty("EntIndex", &GCSosGroupMatchPattern::GetEntIndex, &GCSosGroupMatchPattern::SetEntIndex)
        .addProperty("Opvar", &GCSosGroupMatchPattern::GetOpvar, &GCSosGroupMatchPattern::SetOpvar)
        .addProperty("OpvarString", &GCSosGroupMatchPattern::GetOpvarString, &GCSosGroupMatchPattern::SetOpvarString)
        .endClass();
}