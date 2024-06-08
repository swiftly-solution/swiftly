#include "../../../core/scripting/generated/classes/GCModelConfigElement_RandomPick.h"
#include "../core.h"

void SetupLuaClassGCModelConfigElement_RandomPick(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_RandomPick>("CModelConfigElement_RandomPick")
        .addProperty("Choices", &GCModelConfigElement_RandomPick::GetChoices, &GCModelConfigElement_RandomPick::SetChoices)
        .addProperty("ChoiceWeights", &GCModelConfigElement_RandomPick::GetChoiceWeights, &GCModelConfigElement_RandomPick::SetChoiceWeights)
        .endClass();
}