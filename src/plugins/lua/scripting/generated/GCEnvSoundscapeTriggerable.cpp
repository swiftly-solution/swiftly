#include "../../../core/scripting/generated/classes/GCEnvSoundscapeTriggerable.h"
#include "../core.h"

void SetupLuaClassGCEnvSoundscapeTriggerable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvSoundscapeTriggerable>("CEnvSoundscapeTriggerable")

        .endClass();
}