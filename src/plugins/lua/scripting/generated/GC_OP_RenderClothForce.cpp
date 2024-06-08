#include "../../../core/scripting/generated/classes/GC_OP_RenderClothForce.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderClothForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderClothForce>("C_OP_RenderClothForce")

        .endClass();
}