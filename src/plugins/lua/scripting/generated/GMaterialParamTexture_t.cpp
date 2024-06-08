#include "../../../core/scripting/generated/classes/GMaterialParamTexture_t.h"
#include "../core.h"

void SetupLuaClassGMaterialParamTexture_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialParamTexture_t>("MaterialParamTexture_t")

        .endClass();
}