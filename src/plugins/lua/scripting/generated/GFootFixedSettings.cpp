#include "../../../core/scripting/generated/classes/GFootFixedSettings.h"
#include "../core.h"

void SetupLuaClassGFootFixedSettings(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFootFixedSettings>("FootFixedSettings")
        .addProperty("TraceSettings", &GFootFixedSettings::GetTraceSettings, &GFootFixedSettings::SetTraceSettings)
        .addProperty("FootBaseBindPosePositionMS", &GFootFixedSettings::GetFootBaseBindPosePositionMS, &GFootFixedSettings::SetFootBaseBindPosePositionMS)
        .addProperty("FootBaseLength", &GFootFixedSettings::GetFootBaseLength, &GFootFixedSettings::SetFootBaseLength)
        .addProperty("MaxRotationLeft", &GFootFixedSettings::GetMaxRotationLeft, &GFootFixedSettings::SetMaxRotationLeft)
        .addProperty("MaxRotationRight", &GFootFixedSettings::GetMaxRotationRight, &GFootFixedSettings::SetMaxRotationRight)
        .addProperty("FootstepLandedTagIndex", &GFootFixedSettings::GetFootstepLandedTagIndex, &GFootFixedSettings::SetFootstepLandedTagIndex)
        .addProperty("EnableTracing", &GFootFixedSettings::GetEnableTracing, &GFootFixedSettings::SetEnableTracing)
        .addProperty("TraceAngleBlend", &GFootFixedSettings::GetTraceAngleBlend, &GFootFixedSettings::SetTraceAngleBlend)
        .addProperty("DisableTagIndex", &GFootFixedSettings::GetDisableTagIndex, &GFootFixedSettings::SetDisableTagIndex)
        .addProperty("FootIndex", &GFootFixedSettings::GetFootIndex, &GFootFixedSettings::SetFootIndex)
        .endClass();
}