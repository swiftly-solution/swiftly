#include "../../../core/scripting/generated/classes/GRenderProjectedMaterial_t.h"
#include "../core.h"

void SetupLuaClassGRenderProjectedMaterial_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRenderProjectedMaterial_t>("RenderProjectedMaterial_t")

        .endClass();
}