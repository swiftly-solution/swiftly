#include "../../../core/scripting/generated/classes/GCVoiceContainerBase.h"
#include "../core.h"

void SetupLuaClassGCVoiceContainerBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerBase>("CVoiceContainerBase")
        .addProperty("HideAnalyzers", &GCVoiceContainerBase::GetHideAnalyzers, &GCVoiceContainerBase::SetHideAnalyzers)
        .addProperty("AnalysisContainers", &GCVoiceContainerBase::GetAnalysisContainers, &GCVoiceContainerBase::SetAnalysisContainers)
        .endClass();
}