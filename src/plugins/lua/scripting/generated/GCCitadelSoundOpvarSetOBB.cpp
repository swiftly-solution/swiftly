#include "../../../core/scripting/generated/classes/GCCitadelSoundOpvarSetOBB.h"
#include "../core.h"

void SetupLuaClassGCCitadelSoundOpvarSetOBB(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCitadelSoundOpvarSetOBB>("CCitadelSoundOpvarSetOBB")
        .addProperty("StackName", &GCCitadelSoundOpvarSetOBB::GetStackName, &GCCitadelSoundOpvarSetOBB::SetStackName)
        .addProperty("OperatorName", &GCCitadelSoundOpvarSetOBB::GetOperatorName, &GCCitadelSoundOpvarSetOBB::SetOperatorName)
        .addProperty("OpvarName", &GCCitadelSoundOpvarSetOBB::GetOpvarName, &GCCitadelSoundOpvarSetOBB::SetOpvarName)
        .addProperty("DistanceInnerMins", &GCCitadelSoundOpvarSetOBB::GetDistanceInnerMins, &GCCitadelSoundOpvarSetOBB::SetDistanceInnerMins)
        .addProperty("DistanceInnerMaxs", &GCCitadelSoundOpvarSetOBB::GetDistanceInnerMaxs, &GCCitadelSoundOpvarSetOBB::SetDistanceInnerMaxs)
        .addProperty("DistanceOuterMins", &GCCitadelSoundOpvarSetOBB::GetDistanceOuterMins, &GCCitadelSoundOpvarSetOBB::SetDistanceOuterMins)
        .addProperty("DistanceOuterMaxs", &GCCitadelSoundOpvarSetOBB::GetDistanceOuterMaxs, &GCCitadelSoundOpvarSetOBB::SetDistanceOuterMaxs)
        .addProperty("AABBDirection", &GCCitadelSoundOpvarSetOBB::GetAABBDirection, &GCCitadelSoundOpvarSetOBB::SetAABBDirection)
        .endClass();
}