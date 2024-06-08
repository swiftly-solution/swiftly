#include "../../../core/scripting/generated/classes/GFootStepTrigger.h"
#include "../core.h"

void SetupLuaClassGFootStepTrigger(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFootStepTrigger>("FootStepTrigger")
        .addProperty("Tags", &GFootStepTrigger::GetTags, &GFootStepTrigger::SetTags)
        .addProperty("FootIndex", &GFootStepTrigger::GetFootIndex, &GFootStepTrigger::SetFootIndex)
        .addProperty("TriggerPhase", &GFootStepTrigger::GetTriggerPhase, &GFootStepTrigger::SetTriggerPhase)
        .endClass();
}