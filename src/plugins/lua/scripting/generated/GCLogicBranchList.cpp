#include "../../../core/scripting/generated/classes/GCLogicBranchList.h"
#include "../core.h"

void SetupLuaClassGCLogicBranchList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicBranchList>("CLogicBranchList")
        .addProperty("LogicBranchNames", &GCLogicBranchList::GetLogicBranchNames, &GCLogicBranchList::SetLogicBranchNames)
        .addProperty("LastState", &GCLogicBranchList::GetLastState, &GCLogicBranchList::SetLastState)
        .addProperty("OnAllTrue", &GCLogicBranchList::GetOnAllTrue, &GCLogicBranchList::SetOnAllTrue)
        .addProperty("OnAllFalse", &GCLogicBranchList::GetOnAllFalse, &GCLogicBranchList::SetOnAllFalse)
        .addProperty("OnMixed", &GCLogicBranchList::GetOnMixed, &GCLogicBranchList::SetOnMixed)
        .endClass();
}