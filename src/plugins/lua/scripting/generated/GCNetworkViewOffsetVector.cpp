#include "../../../core/scripting/generated/classes/GCNetworkViewOffsetVector.h"
#include "../core.h"

void SetupLuaClassGCNetworkViewOffsetVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNetworkViewOffsetVector>("CNetworkViewOffsetVector")
        .addProperty("X", &GCNetworkViewOffsetVector::GetX, &GCNetworkViewOffsetVector::SetX)
        .addProperty("Y", &GCNetworkViewOffsetVector::GetY, &GCNetworkViewOffsetVector::SetY)
        .addProperty("Z", &GCNetworkViewOffsetVector::GetZ, &GCNetworkViewOffsetVector::SetZ)
        .endClass();
}