#include "../../../core/scripting/generated/classes/GCPhysicsWire.h"
#include "../core.h"

void SetupLuaClassGCPhysicsWire(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysicsWire>("CPhysicsWire")
        .addProperty("Density", &GCPhysicsWire::GetDensity, &GCPhysicsWire::SetDensity)
        .endClass();
}