#include "../../../core/scripting/generated/classes/GCDampedPathAnimMotorUpdater.h"
#include "../core.h"

void SetupLuaClassGCDampedPathAnimMotorUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCDampedPathAnimMotorUpdater>("CDampedPathAnimMotorUpdater")
        .addProperty("AnticipationTime", &GCDampedPathAnimMotorUpdater::GetAnticipationTime, &GCDampedPathAnimMotorUpdater::SetAnticipationTime)
        .addProperty("MinSpeedScale", &GCDampedPathAnimMotorUpdater::GetMinSpeedScale, &GCDampedPathAnimMotorUpdater::SetMinSpeedScale)
        .addProperty("AnticipationPosParam", &GCDampedPathAnimMotorUpdater::GetAnticipationPosParam, &GCDampedPathAnimMotorUpdater::SetAnticipationPosParam)
        .addProperty("AnticipationHeadingParam", &GCDampedPathAnimMotorUpdater::GetAnticipationHeadingParam, &GCDampedPathAnimMotorUpdater::SetAnticipationHeadingParam)
        .addProperty("SpringConstant", &GCDampedPathAnimMotorUpdater::GetSpringConstant, &GCDampedPathAnimMotorUpdater::SetSpringConstant)
        .addProperty("MinSpringTension", &GCDampedPathAnimMotorUpdater::GetMinSpringTension, &GCDampedPathAnimMotorUpdater::SetMinSpringTension)
        .addProperty("MaxSpringTension", &GCDampedPathAnimMotorUpdater::GetMaxSpringTension, &GCDampedPathAnimMotorUpdater::SetMaxSpringTension)
        .endClass();
}