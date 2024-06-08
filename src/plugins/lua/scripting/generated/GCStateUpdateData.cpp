#include "../../../core/scripting/generated/classes/GCStateUpdateData.h"
#include "../core.h"

void SetupLuaClassGCStateUpdateData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCStateUpdateData>("CStateUpdateData")
        .addProperty("Name", &GCStateUpdateData::GetName, &GCStateUpdateData::SetName)
        .addProperty("Script", &GCStateUpdateData::GetScript, &GCStateUpdateData::SetScript)
        .addProperty("TransitionIndices", &GCStateUpdateData::GetTransitionIndices, &GCStateUpdateData::SetTransitionIndices)
        .addProperty("Actions", &GCStateUpdateData::GetActions, &GCStateUpdateData::SetActions)
        .addProperty("StateID", &GCStateUpdateData::GetStateID, &GCStateUpdateData::SetStateID)
        .endClass();
}