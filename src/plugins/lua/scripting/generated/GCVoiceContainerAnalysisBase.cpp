#include "../../../core/scripting/generated/classes/GCVoiceContainerAnalysisBase.h"
#include "../core.h"

void SetupLuaClassGCVoiceContainerAnalysisBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerAnalysisBase>("CVoiceContainerAnalysisBase")
        .addProperty("RegenerateCurveOnCompile", &GCVoiceContainerAnalysisBase::GetRegenerateCurveOnCompile, &GCVoiceContainerAnalysisBase::SetRegenerateCurveOnCompile)
        .endClass();
}