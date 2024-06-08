#include "../../../core/scripting/generated/classes/GCSensorGrenade.h"
#include "../core.h"

void SetupLuaClassGCSensorGrenade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSensorGrenade>("CSensorGrenade")

        .endClass();
}