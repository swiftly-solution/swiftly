#include "../../../core/scripting/generated/classes/GCAnimEventDefinition.h"
#include "../core.h"

void SetupLuaClassGCAnimEventDefinition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimEventDefinition>("CAnimEventDefinition")
        .addProperty("Frame", &GCAnimEventDefinition::GetFrame, &GCAnimEventDefinition::SetFrame)
        .addProperty("EndFrame", &GCAnimEventDefinition::GetEndFrame, &GCAnimEventDefinition::SetEndFrame)
        .addProperty("Cycle", &GCAnimEventDefinition::GetCycle, &GCAnimEventDefinition::SetCycle)
        .addProperty("Duration", &GCAnimEventDefinition::GetDuration, &GCAnimEventDefinition::SetDuration)
        .addProperty("LegacyOptions", &GCAnimEventDefinition::GetLegacyOptions, &GCAnimEventDefinition::SetLegacyOptions)
        .endClass();
}