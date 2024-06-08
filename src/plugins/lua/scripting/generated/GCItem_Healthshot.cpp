#include "../../../core/scripting/generated/classes/GCItem_Healthshot.h"
#include "../core.h"

void SetupLuaClassGCItem_Healthshot(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCItem_Healthshot>("CItem_Healthshot")

        .endClass();
}