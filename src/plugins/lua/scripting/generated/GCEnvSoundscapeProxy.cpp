#include "../../../core/scripting/generated/classes/GCEnvSoundscapeProxy.h"
#include "../core.h"

void SetupLuaClassGCEnvSoundscapeProxy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSoundscapeProxy>("CEnvSoundscapeProxy")
        .addProperty("MainSoundscapeName", &GCEnvSoundscapeProxy::GetMainSoundscapeName, &GCEnvSoundscapeProxy::SetMainSoundscapeName)
        .endClass();
}