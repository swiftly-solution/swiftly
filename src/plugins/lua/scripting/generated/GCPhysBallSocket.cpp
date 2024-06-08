#include "../../../core/scripting/generated/classes/GCPhysBallSocket.h"
#include "../core.h"

void SetupLuaClassGCPhysBallSocket(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysBallSocket>("CPhysBallSocket")
        .addProperty("JointFriction", &GCPhysBallSocket::GetJointFriction, &GCPhysBallSocket::SetJointFriction)
        .addProperty("EnableSwingLimit", &GCPhysBallSocket::GetEnableSwingLimit, &GCPhysBallSocket::SetEnableSwingLimit)
        .addProperty("SwingLimit", &GCPhysBallSocket::GetSwingLimit, &GCPhysBallSocket::SetSwingLimit)
        .addProperty("EnableTwistLimit", &GCPhysBallSocket::GetEnableTwistLimit, &GCPhysBallSocket::SetEnableTwistLimit)
        .addProperty("MinTwistAngle", &GCPhysBallSocket::GetMinTwistAngle, &GCPhysBallSocket::SetMinTwistAngle)
        .addProperty("MaxTwistAngle", &GCPhysBallSocket::GetMaxTwistAngle, &GCPhysBallSocket::SetMaxTwistAngle)
        .endClass();
}