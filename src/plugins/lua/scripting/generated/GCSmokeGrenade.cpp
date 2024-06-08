#include "../../../core/scripting/generated/classes/GCSmokeGrenade.h"
#include "../core.h"

void SetupLuaClassGCSmokeGrenade(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSmokeGrenade>("CSmokeGrenade")

        .endClass();
}