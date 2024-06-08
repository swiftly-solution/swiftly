#include "../../../core/scripting/generated/classes/GCVoiceContainerDefault.h"
#include "../core.h"

void SetupLuaClassGCVoiceContainerDefault(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCVoiceContainerDefault>("CVoiceContainerDefault")

        .endClass();
}