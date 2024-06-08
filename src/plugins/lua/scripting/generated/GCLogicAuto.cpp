#include "../../../core/scripting/generated/classes/GCLogicAuto.h"
#include "../core.h"

void SetupLuaClassGCLogicAuto(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicAuto>("CLogicAuto")
        .addProperty("OnMapSpawn", &GCLogicAuto::GetOnMapSpawn, &GCLogicAuto::SetOnMapSpawn)
        .addProperty("OnDemoMapSpawn", &GCLogicAuto::GetOnDemoMapSpawn, &GCLogicAuto::SetOnDemoMapSpawn)
        .addProperty("OnNewGame", &GCLogicAuto::GetOnNewGame, &GCLogicAuto::SetOnNewGame)
        .addProperty("OnLoadGame", &GCLogicAuto::GetOnLoadGame, &GCLogicAuto::SetOnLoadGame)
        .addProperty("OnMapTransition", &GCLogicAuto::GetOnMapTransition, &GCLogicAuto::SetOnMapTransition)
        .addProperty("OnBackgroundMap", &GCLogicAuto::GetOnBackgroundMap, &GCLogicAuto::SetOnBackgroundMap)
        .addProperty("OnMultiNewMap", &GCLogicAuto::GetOnMultiNewMap, &GCLogicAuto::SetOnMultiNewMap)
        .addProperty("OnMultiNewRound", &GCLogicAuto::GetOnMultiNewRound, &GCLogicAuto::SetOnMultiNewRound)
        .addProperty("OnVREnabled", &GCLogicAuto::GetOnVREnabled, &GCLogicAuto::SetOnVREnabled)
        .addProperty("OnVRNotEnabled", &GCLogicAuto::GetOnVRNotEnabled, &GCLogicAuto::SetOnVRNotEnabled)
        .addProperty("Globalstate", &GCLogicAuto::GetGlobalstate, &GCLogicAuto::SetGlobalstate)
        .endClass();
}