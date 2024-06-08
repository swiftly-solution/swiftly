#include "../../../core/scripting/generated/classes/Gdynpitchvol_t.h"
#include "../core.h"

void SetupLuaClassGdynpitchvol_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Gdynpitchvol_t>("dynpitchvol_t")

        .endClass();
}