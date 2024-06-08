#include "../../../core/scripting/generated/classes/GCNetworkVelocityVector.h"
#include "../core.h"

void SetupLuaClassGCNetworkVelocityVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNetworkVelocityVector>("CNetworkVelocityVector")
        .addProperty("X", &GCNetworkVelocityVector::GetX, &GCNetworkVelocityVector::SetX)
        .addProperty("Y", &GCNetworkVelocityVector::GetY, &GCNetworkVelocityVector::SetY)
        .addProperty("Z", &GCNetworkVelocityVector::GetZ, &GCNetworkVelocityVector::SetZ)
        .endClass();
}