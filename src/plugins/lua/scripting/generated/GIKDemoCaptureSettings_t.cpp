#include "../../../core/scripting/generated/classes/GIKDemoCaptureSettings_t.h"
#include "../core.h"

void SetupLuaClassGIKDemoCaptureSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIKDemoCaptureSettings_t>("IKDemoCaptureSettings_t")
        .addProperty("ParentBoneName", &GIKDemoCaptureSettings_t::GetParentBoneName, &GIKDemoCaptureSettings_t::SetParentBoneName)
        .addProperty("Mode", &GIKDemoCaptureSettings_t::GetMode, &GIKDemoCaptureSettings_t::SetMode)
        .addProperty("IkChainName", &GIKDemoCaptureSettings_t::GetIkChainName, &GIKDemoCaptureSettings_t::SetIkChainName)
        .addProperty("OneBoneStart", &GIKDemoCaptureSettings_t::GetOneBoneStart, &GIKDemoCaptureSettings_t::SetOneBoneStart)
        .addProperty("OneBoneEnd", &GIKDemoCaptureSettings_t::GetOneBoneEnd, &GIKDemoCaptureSettings_t::SetOneBoneEnd)
        .endClass();
}