#include "../../../core/scripting/generated/classes/GCPhysHingeAlias_phys_hinge_local.h"
#include "../core.h"

void SetupLuaClassGCPhysHingeAlias_phys_hinge_local(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysHingeAlias_phys_hinge_local>("CPhysHingeAlias_phys_hinge_local")

        .endClass();
}