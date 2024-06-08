#include "../../../core/scripting/generated/classes/GCLogicAchievement.h"
#include "../core.h"

void SetupLuaClassGCLogicAchievement(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicAchievement>("CLogicAchievement")
        .addProperty("Disabled", &GCLogicAchievement::GetDisabled, &GCLogicAchievement::SetDisabled)
        .addProperty("AchievementEventID", &GCLogicAchievement::GetAchievementEventID, &GCLogicAchievement::SetAchievementEventID)
        .addProperty("OnFired", &GCLogicAchievement::GetOnFired, &GCLogicAchievement::SetOnFired)
        .endClass();
}