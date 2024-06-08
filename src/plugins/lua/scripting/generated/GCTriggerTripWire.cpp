#include "../../../core/scripting/generated/classes/GCTriggerTripWire.h"
#include "../core.h"

void SetupLuaClassGCTriggerTripWire(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerTripWire>("CTriggerTripWire")

        .endClass();
}