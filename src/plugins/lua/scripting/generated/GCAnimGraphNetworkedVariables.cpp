#include "../../../core/scripting/generated/classes/GCAnimGraphNetworkedVariables.h"
#include "../core.h"

void SetupLuaClassGCAnimGraphNetworkedVariables(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimGraphNetworkedVariables>("CAnimGraphNetworkedVariables")
        .addProperty("PredNetBoolVariables", &GCAnimGraphNetworkedVariables::GetPredNetBoolVariables, &GCAnimGraphNetworkedVariables::SetPredNetBoolVariables)
        .addProperty("PredNetByteVariables", &GCAnimGraphNetworkedVariables::GetPredNetByteVariables, &GCAnimGraphNetworkedVariables::SetPredNetByteVariables)
        .addProperty("PredNetUInt16Variables", &GCAnimGraphNetworkedVariables::GetPredNetUInt16Variables, &GCAnimGraphNetworkedVariables::SetPredNetUInt16Variables)
        .addProperty("PredNetIntVariables", &GCAnimGraphNetworkedVariables::GetPredNetIntVariables, &GCAnimGraphNetworkedVariables::SetPredNetIntVariables)
        .addProperty("PredNetUInt32Variables", &GCAnimGraphNetworkedVariables::GetPredNetUInt32Variables, &GCAnimGraphNetworkedVariables::SetPredNetUInt32Variables)
        .addProperty("PredNetUInt64Variables", &GCAnimGraphNetworkedVariables::GetPredNetUInt64Variables, &GCAnimGraphNetworkedVariables::SetPredNetUInt64Variables)
        .addProperty("PredNetFloatVariables", &GCAnimGraphNetworkedVariables::GetPredNetFloatVariables, &GCAnimGraphNetworkedVariables::SetPredNetFloatVariables)
        .addProperty("PredNetVectorVariables", &GCAnimGraphNetworkedVariables::GetPredNetVectorVariables, &GCAnimGraphNetworkedVariables::SetPredNetVectorVariables)
        .addProperty("PredNetQuaternionVariables", &GCAnimGraphNetworkedVariables::GetPredNetQuaternionVariables, &GCAnimGraphNetworkedVariables::SetPredNetQuaternionVariables)
        .addProperty("OwnerOnlyPredNetBoolVariables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetBoolVariables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetBoolVariables)
        .addProperty("OwnerOnlyPredNetByteVariables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetByteVariables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetByteVariables)
        .addProperty("OwnerOnlyPredNetUInt16Variables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetUInt16Variables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetUInt16Variables)
        .addProperty("OwnerOnlyPredNetIntVariables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetIntVariables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetIntVariables)
        .addProperty("OwnerOnlyPredNetUInt32Variables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetUInt32Variables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetUInt32Variables)
        .addProperty("OwnerOnlyPredNetUInt64Variables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetUInt64Variables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetUInt64Variables)
        .addProperty("OwnerOnlyPredNetFloatVariables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetFloatVariables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetFloatVariables)
        .addProperty("OwnerOnlyPredNetVectorVariables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetVectorVariables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetVectorVariables)
        .addProperty("OwnerOnlyPredNetQuaternionVariables", &GCAnimGraphNetworkedVariables::GetOwnerOnlyPredNetQuaternionVariables, &GCAnimGraphNetworkedVariables::SetOwnerOnlyPredNetQuaternionVariables)
        .addProperty("BoolVariablesCount", &GCAnimGraphNetworkedVariables::GetBoolVariablesCount, &GCAnimGraphNetworkedVariables::SetBoolVariablesCount)
        .addProperty("OwnerOnlyBoolVariablesCount", &GCAnimGraphNetworkedVariables::GetOwnerOnlyBoolVariablesCount, &GCAnimGraphNetworkedVariables::SetOwnerOnlyBoolVariablesCount)
        .addProperty("RandomSeedOffset", &GCAnimGraphNetworkedVariables::GetRandomSeedOffset, &GCAnimGraphNetworkedVariables::SetRandomSeedOffset)
        .addProperty("LastTeleportTime", &GCAnimGraphNetworkedVariables::GetLastTeleportTime, &GCAnimGraphNetworkedVariables::SetLastTeleportTime)
        .endClass();
}