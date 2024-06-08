#include "../../../core/scripting/generated/classes/GCVoiceContainerNull.h"
#include "../core.h"

void SetupLuaClassGCVoiceContainerNull(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerNull>("CVoiceContainerNull")

        .endClass();
}