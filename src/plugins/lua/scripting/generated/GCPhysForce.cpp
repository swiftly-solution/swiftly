#include "../../../core/scripting/generated/classes/GCPhysForce.h"
#include "../core.h"

void SetupLuaClassGCPhysForce(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysForce>("CPhysForce")
        .addProperty("NameAttach", &GCPhysForce::GetNameAttach, &GCPhysForce::SetNameAttach)
        .addProperty("Force", &GCPhysForce::GetForce, &GCPhysForce::SetForce)
        .addProperty("ForceTime", &GCPhysForce::GetForceTime, &GCPhysForce::SetForceTime)
        .addProperty("AttachedObject", &GCPhysForce::GetAttachedObject, &GCPhysForce::SetAttachedObject)
        .addProperty("WasRestored", &GCPhysForce::GetWasRestored, &GCPhysForce::SetWasRestored)
        .addProperty("Integrator", &GCPhysForce::GetIntegrator, &GCPhysForce::SetIntegrator)
        .endClass();
}