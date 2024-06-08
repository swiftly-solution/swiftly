#include "../../../core/scripting/generated/classes/GCNetworkOriginQuantizedVector.h"
#include "../core.h"

void SetupLuaClassGCNetworkOriginQuantizedVector(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNetworkOriginQuantizedVector>("CNetworkOriginQuantizedVector")
        .addProperty("X", &GCNetworkOriginQuantizedVector::GetX, &GCNetworkOriginQuantizedVector::SetX)
        .addProperty("Y", &GCNetworkOriginQuantizedVector::GetY, &GCNetworkOriginQuantizedVector::SetY)
        .addProperty("Z", &GCNetworkOriginQuantizedVector::GetZ, &GCNetworkOriginQuantizedVector::SetZ)
        .endClass();
}