#include "../../../core/scripting/generated/classes/GCSSDSMsg_PostLayer.h"
#include "../core.h"

void SetupLuaClassGCSSDSMsg_PostLayer(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSSDSMsg_PostLayer>("CSSDSMsg_PostLayer")

        .endClass();
}