#include "../../../core/scripting/generated/classes/GCEnvTilt.h"
#include "../core.h"

void SetupLuaClassGCEnvTilt(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvTilt>("CEnvTilt")
        .addProperty("Duration", &GCEnvTilt::GetDuration, &GCEnvTilt::SetDuration)
        .addProperty("Radius", &GCEnvTilt::GetRadius, &GCEnvTilt::SetRadius)
        .addProperty("TiltTime", &GCEnvTilt::GetTiltTime, &GCEnvTilt::SetTiltTime)
        .endClass();
}