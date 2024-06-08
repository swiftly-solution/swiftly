#include "../../../core/scripting/generated/classes/GCPlayerInputAnimMotorUpdater.h"
#include "../core.h"

void SetupLuaClassGCPlayerInputAnimMotorUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayerInputAnimMotorUpdater>("CPlayerInputAnimMotorUpdater")
        .addProperty("SampleTimes", &GCPlayerInputAnimMotorUpdater::GetSampleTimes, &GCPlayerInputAnimMotorUpdater::SetSampleTimes)
        .addProperty("SpringConstant", &GCPlayerInputAnimMotorUpdater::GetSpringConstant, &GCPlayerInputAnimMotorUpdater::SetSpringConstant)
        .addProperty("AnticipationDistance", &GCPlayerInputAnimMotorUpdater::GetAnticipationDistance, &GCPlayerInputAnimMotorUpdater::SetAnticipationDistance)
        .addProperty("AnticipationPosParam", &GCPlayerInputAnimMotorUpdater::GetAnticipationPosParam, &GCPlayerInputAnimMotorUpdater::SetAnticipationPosParam)
        .addProperty("AnticipationHeadingParam", &GCPlayerInputAnimMotorUpdater::GetAnticipationHeadingParam, &GCPlayerInputAnimMotorUpdater::SetAnticipationHeadingParam)
        .addProperty("UseAcceleration", &GCPlayerInputAnimMotorUpdater::GetUseAcceleration, &GCPlayerInputAnimMotorUpdater::SetUseAcceleration)
        .endClass();
}