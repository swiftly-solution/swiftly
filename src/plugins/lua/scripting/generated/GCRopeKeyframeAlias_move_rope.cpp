#include "../../../core/scripting/generated/classes/GCRopeKeyframeAlias_move_rope.h"
#include "../core.h"

void SetupLuaClassGCRopeKeyframeAlias_move_rope(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRopeKeyframeAlias_move_rope>("CRopeKeyframeAlias_move_rope")

        .endClass();
}