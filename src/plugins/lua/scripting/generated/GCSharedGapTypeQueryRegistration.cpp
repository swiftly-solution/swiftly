#include "../../../core/scripting/generated/classes/GCSharedGapTypeQueryRegistration.h"
#include "../core.h"

void SetupLuaClassGCSharedGapTypeQueryRegistration(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSharedGapTypeQueryRegistration>("CSharedGapTypeQueryRegistration")

        .endClass();
}