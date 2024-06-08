#include "../../../core/scripting/generated/classes/GCItemDefuserAlias_item_defuser.h"
#include "../core.h"

void SetupLuaClassGCItemDefuserAlias_item_defuser(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItemDefuserAlias_item_defuser>("CItemDefuserAlias_item_defuser")

        .endClass();
}