#include "../../../core/scripting/generated/classes/GCSmoothFunc.h"
#include "../core.h"

void SetupLuaClassGCSmoothFunc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSmoothFunc>("CSmoothFunc")
        .addProperty("SmoothAmplitude", &GCSmoothFunc::GetSmoothAmplitude, &GCSmoothFunc::SetSmoothAmplitude)
        .addProperty("SmoothBias", &GCSmoothFunc::GetSmoothBias, &GCSmoothFunc::SetSmoothBias)
        .addProperty("SmoothDuration", &GCSmoothFunc::GetSmoothDuration, &GCSmoothFunc::SetSmoothDuration)
        .addProperty("SmoothRemainingTime", &GCSmoothFunc::GetSmoothRemainingTime, &GCSmoothFunc::SetSmoothRemainingTime)
        .addProperty("SmoothDir", &GCSmoothFunc::GetSmoothDir, &GCSmoothFunc::SetSmoothDir)
        .endClass();
}