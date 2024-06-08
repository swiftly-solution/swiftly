#include "../../../core/scripting/generated/classes/GCScriptItem.h"
#include "../core.h"

void SetupLuaClassGCScriptItem(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptItem>("CScriptItem")
        .addProperty("MoveTypeOverride", &GCScriptItem::GetMoveTypeOverride, &GCScriptItem::SetMoveTypeOverride)
        .endClass();
}