#include "../../../core/scripting/generated/classes/GCEnableMotionFixup.h"
#include "../core.h"

void SetupLuaClassGCEnableMotionFixup(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnableMotionFixup>("CEnableMotionFixup")

        .endClass();
}