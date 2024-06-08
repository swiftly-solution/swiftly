#include "../../../core/scripting/generated/classes/GRnSphereDesc_t.h"
#include "../core.h"

void SetupLuaClassGRnSphereDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRnSphereDesc_t>("RnSphereDesc_t")

        .endClass();
}