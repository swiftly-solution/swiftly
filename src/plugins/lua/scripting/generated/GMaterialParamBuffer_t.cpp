#include "../../../core/scripting/generated/classes/GMaterialParamBuffer_t.h"
#include "../core.h"

void SetupLuaClassGMaterialParamBuffer_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMaterialParamBuffer_t>("MaterialParamBuffer_t")

        .endClass();
}