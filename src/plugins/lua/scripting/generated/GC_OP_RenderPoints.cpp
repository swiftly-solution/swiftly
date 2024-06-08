#include "../../../core/scripting/generated/classes/GC_OP_RenderPoints.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderPoints(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderPoints>("C_OP_RenderPoints")

        .endClass();
}