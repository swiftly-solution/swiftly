#include "../../../core/scripting/generated/classes/GCCommentaryViewPosition.h"
#include "../core.h"

void SetupLuaClassGCCommentaryViewPosition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCommentaryViewPosition>("CCommentaryViewPosition")

        .endClass();
}