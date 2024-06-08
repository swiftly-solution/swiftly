#include "../../../core/scripting/generated/classes/GQuestProgress.h"
#include "../core.h"

void SetupLuaClassGQuestProgress(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GQuestProgress>("QuestProgress")

        .endClass();
}