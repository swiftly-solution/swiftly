#include "../../../core/scripting/generated/classes/GCPlayerSprayDecalRenderHelper.h"
#include "../core.h"

void SetupLuaClassGCPlayerSprayDecalRenderHelper(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayerSprayDecalRenderHelper>("CPlayerSprayDecalRenderHelper")

        .endClass();
}