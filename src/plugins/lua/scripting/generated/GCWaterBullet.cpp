#include "../../../core/scripting/generated/classes/GCWaterBullet.h"
#include "../core.h"

void SetupLuaClassGCWaterBullet(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCWaterBullet>("CWaterBullet")

        .endClass();
}