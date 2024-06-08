#include "../../../core/scripting/generated/classes/GCSeqIKLock.h"
#include "../core.h"

void SetupLuaClassGCSeqIKLock(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqIKLock>("CSeqIKLock")
        .addProperty("PosWeight", &GCSeqIKLock::GetPosWeight, &GCSeqIKLock::SetPosWeight)
        .addProperty("AngleWeight", &GCSeqIKLock::GetAngleWeight, &GCSeqIKLock::SetAngleWeight)
        .addProperty("LocalBone", &GCSeqIKLock::GetLocalBone, &GCSeqIKLock::SetLocalBone)
        .addProperty("BonesOrientedAlongPositiveX", &GCSeqIKLock::GetBonesOrientedAlongPositiveX, &GCSeqIKLock::SetBonesOrientedAlongPositiveX)
        .endClass();
}