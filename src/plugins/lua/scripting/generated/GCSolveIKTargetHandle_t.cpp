#include "../../../core/scripting/generated/classes/GCSolveIKTargetHandle_t.h"
#include "../core.h"

void SetupLuaClassGCSolveIKTargetHandle_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSolveIKTargetHandle_t>("CSolveIKTargetHandle_t")
        .addProperty("PositionHandle", &GCSolveIKTargetHandle_t::GetPositionHandle, &GCSolveIKTargetHandle_t::SetPositionHandle)
        .addProperty("OrientationHandle", &GCSolveIKTargetHandle_t::GetOrientationHandle, &GCSolveIKTargetHandle_t::SetOrientationHandle)
        .endClass();
}