#include "../../../core/scripting/generated/classes/GCPhysicsEntitySolver.h"
#include "../core.h"

void SetupLuaClassGCPhysicsEntitySolver(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysicsEntitySolver>("CPhysicsEntitySolver")
        .addProperty("MovingEntity", &GCPhysicsEntitySolver::GetMovingEntity, &GCPhysicsEntitySolver::SetMovingEntity)
        .addProperty("PhysicsBlocker", &GCPhysicsEntitySolver::GetPhysicsBlocker, &GCPhysicsEntitySolver::SetPhysicsBlocker)
        .addProperty("SeparationDuration", &GCPhysicsEntitySolver::GetSeparationDuration, &GCPhysicsEntitySolver::SetSeparationDuration)
        .endClass();
}