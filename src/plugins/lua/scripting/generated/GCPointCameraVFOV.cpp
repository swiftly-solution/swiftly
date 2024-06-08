#include "../../../core/scripting/generated/classes/GCPointCameraVFOV.h"
#include "../core.h"

void SetupLuaClassGCPointCameraVFOV(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointCameraVFOV>("CPointCameraVFOV")
        .addProperty("VerticalFOV", &GCPointCameraVFOV::GetVerticalFOV, &GCPointCameraVFOV::SetVerticalFOV)
        .endClass();
}