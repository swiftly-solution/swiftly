#include "../../../core/scripting/generated/classes/GCChangeLevel.h"
#include "../core.h"

void SetupLuaClassGCChangeLevel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCChangeLevel>("CChangeLevel")
        .addProperty("MapName", &GCChangeLevel::GetMapName, &GCChangeLevel::SetMapName)
        .addProperty("LandmarkName", &GCChangeLevel::GetLandmarkName, &GCChangeLevel::SetLandmarkName)
        .addProperty("OnChangeLevel", &GCChangeLevel::GetOnChangeLevel, &GCChangeLevel::SetOnChangeLevel)
        .addProperty("Touched", &GCChangeLevel::GetTouched, &GCChangeLevel::SetTouched)
        .addProperty("NoTouch", &GCChangeLevel::GetNoTouch, &GCChangeLevel::SetNoTouch)
        .addProperty("NewChapter", &GCChangeLevel::GetNewChapter, &GCChangeLevel::SetNewChapter)
        .addProperty("OnChangeLevelFired", &GCChangeLevel::GetOnChangeLevelFired, &GCChangeLevel::SetOnChangeLevelFired)
        .endClass();
}