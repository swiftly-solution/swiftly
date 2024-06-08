#include "../../../core/scripting/generated/classes/GCSSDSMsg_PreLayer.h"
#include "../core.h"

void SetupLuaClassGCSSDSMsg_PreLayer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSSDSMsg_PreLayer>("CSSDSMsg_PreLayer")

        .endClass();
}