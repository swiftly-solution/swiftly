#include "../../../core/scripting/generated/classes/GCConcreteAnimParameter.h"
#include "../core.h"

void SetupLuaClassGCConcreteAnimParameter(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCConcreteAnimParameter>("CConcreteAnimParameter")
        .addProperty("PreviewButton", &GCConcreteAnimParameter::GetPreviewButton, &GCConcreteAnimParameter::SetPreviewButton)
        .addProperty("NetworkSetting", &GCConcreteAnimParameter::GetNetworkSetting, &GCConcreteAnimParameter::SetNetworkSetting)
        .addProperty("UseMostRecentValue", &GCConcreteAnimParameter::GetUseMostRecentValue, &GCConcreteAnimParameter::SetUseMostRecentValue)
        .addProperty("AutoReset", &GCConcreteAnimParameter::GetAutoReset, &GCConcreteAnimParameter::SetAutoReset)
        .addProperty("GameWritable", &GCConcreteAnimParameter::GetGameWritable, &GCConcreteAnimParameter::SetGameWritable)
        .addProperty("GraphWritable", &GCConcreteAnimParameter::GetGraphWritable, &GCConcreteAnimParameter::SetGraphWritable)
        .endClass();
}