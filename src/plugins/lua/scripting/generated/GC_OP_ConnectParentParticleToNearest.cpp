#include "../../../core/scripting/generated/classes/GC_OP_ConnectParentParticleToNearest.h"
#include "../core.h"

void SetupLuaClassGC_OP_ConnectParentParticleToNearest(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ConnectParentParticleToNearest>("C_OP_ConnectParentParticleToNearest")
        .addProperty("FirstControlPoint", &GC_OP_ConnectParentParticleToNearest::GetFirstControlPoint, &GC_OP_ConnectParentParticleToNearest::SetFirstControlPoint)
        .addProperty("SecondControlPoint", &GC_OP_ConnectParentParticleToNearest::GetSecondControlPoint, &GC_OP_ConnectParentParticleToNearest::SetSecondControlPoint)
        .addProperty("UseRadius", &GC_OP_ConnectParentParticleToNearest::GetUseRadius, &GC_OP_ConnectParentParticleToNearest::SetUseRadius)
        .addProperty("RadiusScale", &GC_OP_ConnectParentParticleToNearest::GetRadiusScale, &GC_OP_ConnectParentParticleToNearest::SetRadiusScale)
        .addProperty("ParentRadiusScale", &GC_OP_ConnectParentParticleToNearest::GetParentRadiusScale, &GC_OP_ConnectParentParticleToNearest::SetParentRadiusScale)
        .endClass();
}