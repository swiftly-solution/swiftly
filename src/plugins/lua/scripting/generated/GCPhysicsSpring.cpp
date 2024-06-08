#include "../../../core/scripting/generated/classes/GCPhysicsSpring.h"
#include "../core.h"

void SetupLuaClassGCPhysicsSpring(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysicsSpring>("CPhysicsSpring")
        .addProperty("Frequency", &GCPhysicsSpring::GetFrequency, &GCPhysicsSpring::SetFrequency)
        .addProperty("DampingRatio", &GCPhysicsSpring::GetDampingRatio, &GCPhysicsSpring::SetDampingRatio)
        .addProperty("RestLength", &GCPhysicsSpring::GetRestLength, &GCPhysicsSpring::SetRestLength)
        .addProperty("NameAttachStart", &GCPhysicsSpring::GetNameAttachStart, &GCPhysicsSpring::SetNameAttachStart)
        .addProperty("NameAttachEnd", &GCPhysicsSpring::GetNameAttachEnd, &GCPhysicsSpring::SetNameAttachEnd)
        .addProperty("Start", &GCPhysicsSpring::GetStart, &GCPhysicsSpring::SetStart)
        .addProperty("End", &GCPhysicsSpring::GetEnd, &GCPhysicsSpring::SetEnd)
        .addProperty("TeleportTick", &GCPhysicsSpring::GetTeleportTick, &GCPhysicsSpring::SetTeleportTick)
        .endClass();
}