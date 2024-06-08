#include "../../../core/scripting/generated/classes/GVPhysXConstraint2_t.h"
#include "../core.h"

void SetupLuaClassGVPhysXConstraint2_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVPhysXConstraint2_t>("VPhysXConstraint2_t")
        .addProperty("Flags", &GVPhysXConstraint2_t::GetFlags, &GVPhysXConstraint2_t::SetFlags)
        .addProperty("Parent", &GVPhysXConstraint2_t::GetParent, &GVPhysXConstraint2_t::SetParent)
        .addProperty("Child", &GVPhysXConstraint2_t::GetChild, &GVPhysXConstraint2_t::SetChild)
        .addProperty("Params", &GVPhysXConstraint2_t::GetParams, &GVPhysXConstraint2_t::SetParams)
        .endClass();
}