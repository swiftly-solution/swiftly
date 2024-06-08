#include "../../../core/scripting/generated/classes/GCInfoData.h"
#include "../core.h"

void SetupLuaClassGCInfoData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCInfoData>("CInfoData")

        .endClass();
}