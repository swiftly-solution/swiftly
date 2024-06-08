#include "../../../core/scripting/generated/classes/GCPhysicsShake.h"
#include "../core.h"

void SetupLuaClassGCPhysicsShake(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysicsShake>("CPhysicsShake")
        .addProperty("Force", &GCPhysicsShake::GetForce, &GCPhysicsShake::SetForce)
        .endClass();
}