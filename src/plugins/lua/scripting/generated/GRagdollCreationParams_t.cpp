#include "../../../core/scripting/generated/classes/GRagdollCreationParams_t.h"
#include "../core.h"

void SetupLuaClassGRagdollCreationParams_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GRagdollCreationParams_t>("RagdollCreationParams_t")
        .addProperty("Force", &GRagdollCreationParams_t::GetForce, &GRagdollCreationParams_t::SetForce)
        .addProperty("ForceBone", &GRagdollCreationParams_t::GetForceBone, &GRagdollCreationParams_t::SetForceBone)
        .addProperty("ForceCurrentWorldTransform", &GRagdollCreationParams_t::GetForceCurrentWorldTransform, &GRagdollCreationParams_t::SetForceCurrentWorldTransform)
        .endClass();
}