#include "../../../core/scripting/generated/classes/GCLogicCase.h"
#include "../core.h"

void SetupLuaClassGCLogicCase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicCase>("CLogicCase")
        .addProperty("Case", &GCLogicCase::GetCase, &GCLogicCase::SetCase)
        .addProperty("ShuffleCases", &GCLogicCase::GetShuffleCases, &GCLogicCase::SetShuffleCases)
        .addProperty("LastShuffleCase", &GCLogicCase::GetLastShuffleCase, &GCLogicCase::SetLastShuffleCase)
        .addProperty("UchShuffleCaseMap", &GCLogicCase::GetUchShuffleCaseMap, &GCLogicCase::SetUchShuffleCaseMap)
        .addProperty("OnCase", &GCLogicCase::GetOnCase, &GCLogicCase::SetOnCase)
        .endClass();
}