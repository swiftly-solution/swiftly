#include "../../../core/scripting/generated/classes/GSkeletonAnimCapture_t__Camera_t.h"
#include "../core.h"

void SetupLuaClassGSkeletonAnimCapture_t__Camera_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GSkeletonAnimCapture_t__Camera_t>("SkeletonAnimCapture_t__Camera_t")
        .addProperty("Time", &GSkeletonAnimCapture_t__Camera_t::GetTime, &GSkeletonAnimCapture_t__Camera_t::SetTime)
        .endClass();
}