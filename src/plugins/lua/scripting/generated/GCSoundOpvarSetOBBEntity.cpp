#include "../../../core/scripting/generated/classes/GCSoundOpvarSetOBBEntity.h"
#include "../core.h"

void SetupLuaClassGCSoundOpvarSetOBBEntity(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSoundOpvarSetOBBEntity>("CSoundOpvarSetOBBEntity")

        .endClass();
}