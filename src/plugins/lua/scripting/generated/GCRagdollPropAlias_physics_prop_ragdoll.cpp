#include "../../../core/scripting/generated/classes/GCRagdollPropAlias_physics_prop_ragdoll.h"
#include "../core.h"

void SetupLuaClassGCRagdollPropAlias_physics_prop_ragdoll(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollPropAlias_physics_prop_ragdoll>("CRagdollPropAlias_physics_prop_ragdoll")

        .endClass();
}