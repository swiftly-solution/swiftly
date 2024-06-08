#include "../../../core/scripting/generated/classes/GCEnvViewPunch.h"
#include "../core.h"

void SetupLuaClassGCEnvViewPunch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvViewPunch>("CEnvViewPunch")
        .addProperty("Radius", &GCEnvViewPunch::GetRadius, &GCEnvViewPunch::SetRadius)
        .addProperty("ViewPunch", &GCEnvViewPunch::GetViewPunch, &GCEnvViewPunch::SetViewPunch)
        .endClass();
}