#include "../../../core/scripting/generated/classes/GCRuleBrushEntity.h"
#include "../core.h"

void SetupLuaClassGCRuleBrushEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRuleBrushEntity>("CRuleBrushEntity")

        .endClass();
}