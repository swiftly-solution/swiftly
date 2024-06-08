#include "../../../core/scripting/generated/classes/GCGameChoreoServices.h"
#include "../core.h"

void SetupLuaClassGCGameChoreoServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGameChoreoServices>("CGameChoreoServices")
        .addProperty("Owner", &GCGameChoreoServices::GetOwner, &GCGameChoreoServices::SetOwner)
        .addProperty("ScriptedSequence", &GCGameChoreoServices::GetScriptedSequence, &GCGameChoreoServices::SetScriptedSequence)
        .addProperty("ScriptState", &GCGameChoreoServices::GetScriptState, &GCGameChoreoServices::SetScriptState)
        .addProperty("ChoreoState", &GCGameChoreoServices::GetChoreoState, &GCGameChoreoServices::SetChoreoState)
        .endClass();
}