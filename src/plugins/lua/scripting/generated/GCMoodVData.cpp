#include "../../../core/scripting/generated/classes/GCMoodVData.h"
#include "../core.h"

void SetupLuaClassGCMoodVData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMoodVData>("CMoodVData")
        .addProperty("MoodType", &GCMoodVData::GetMoodType, &GCMoodVData::SetMoodType)
        .endClass();
}