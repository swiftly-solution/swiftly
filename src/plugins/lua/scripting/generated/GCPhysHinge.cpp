#include "../../../core/scripting/generated/classes/GCPhysHinge.h"
#include "../core.h"

void SetupLuaClassGCPhysHinge(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysHinge>("CPhysHinge")
        .addProperty("SoundInfo", &GCPhysHinge::GetSoundInfo, &GCPhysHinge::SetSoundInfo)
        .addProperty("NotifyMinLimitReached", &GCPhysHinge::GetNotifyMinLimitReached, &GCPhysHinge::SetNotifyMinLimitReached)
        .addProperty("NotifyMaxLimitReached", &GCPhysHinge::GetNotifyMaxLimitReached, &GCPhysHinge::SetNotifyMaxLimitReached)
        .addProperty("AtMinLimit", &GCPhysHinge::GetAtMinLimit, &GCPhysHinge::SetAtMinLimit)
        .addProperty("AtMaxLimit", &GCPhysHinge::GetAtMaxLimit, &GCPhysHinge::SetAtMaxLimit)
        .addProperty("Hinge", &GCPhysHinge::GetHinge, &GCPhysHinge::SetHinge)
        .addProperty("HingeFriction", &GCPhysHinge::GetHingeFriction, &GCPhysHinge::SetHingeFriction)
        .addProperty("SystemLoadScale", &GCPhysHinge::GetSystemLoadScale, &GCPhysHinge::SetSystemLoadScale)
        .addProperty("IsAxisLocal", &GCPhysHinge::GetIsAxisLocal, &GCPhysHinge::SetIsAxisLocal)
        .addProperty("MinRotation", &GCPhysHinge::GetMinRotation, &GCPhysHinge::SetMinRotation)
        .addProperty("MaxRotation", &GCPhysHinge::GetMaxRotation, &GCPhysHinge::SetMaxRotation)
        .addProperty("InitialRotation", &GCPhysHinge::GetInitialRotation, &GCPhysHinge::SetInitialRotation)
        .addProperty("MotorFrequency", &GCPhysHinge::GetMotorFrequency, &GCPhysHinge::SetMotorFrequency)
        .addProperty("MotorDampingRatio", &GCPhysHinge::GetMotorDampingRatio, &GCPhysHinge::SetMotorDampingRatio)
        .addProperty("AngleSpeed", &GCPhysHinge::GetAngleSpeed, &GCPhysHinge::SetAngleSpeed)
        .addProperty("AngleSpeedThreshold", &GCPhysHinge::GetAngleSpeedThreshold, &GCPhysHinge::SetAngleSpeedThreshold)
        .addProperty("OnStartMoving", &GCPhysHinge::GetOnStartMoving, &GCPhysHinge::SetOnStartMoving)
        .addProperty("OnStopMoving", &GCPhysHinge::GetOnStopMoving, &GCPhysHinge::SetOnStopMoving)
        .endClass();
}