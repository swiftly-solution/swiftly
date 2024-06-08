#include "../../../core/scripting/generated/classes/GCEnvHudHint.h"
#include "../core.h"

void SetupLuaClassGCEnvHudHint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvHudHint>("CEnvHudHint")
        .addProperty("Message", &GCEnvHudHint::GetMessage, &GCEnvHudHint::SetMessage)
        .endClass();
}