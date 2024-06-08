#include "../../../core/scripting/generated/classes/GCPathKeyFrame.h"
#include "../core.h"

void SetupLuaClassGCPathKeyFrame(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPathKeyFrame>("CPathKeyFrame")
        .addProperty("Origin", &GCPathKeyFrame::GetOrigin, &GCPathKeyFrame::SetOrigin)
        .addProperty("Angles", &GCPathKeyFrame::GetAngles, &GCPathKeyFrame::SetAngles)
        .addProperty("Angle", &GCPathKeyFrame::GetAngle, &GCPathKeyFrame::SetAngle)
        .addProperty("NextKey", &GCPathKeyFrame::GetNextKey, &GCPathKeyFrame::SetNextKey)
        .addProperty("NextTime", &GCPathKeyFrame::GetNextTime, &GCPathKeyFrame::SetNextTime)
        .addProperty("NextKey1", &GCPathKeyFrame::GetNextKey1, &GCPathKeyFrame::SetNextKey1)
        .addProperty("PrevKey", &GCPathKeyFrame::GetPrevKey, &GCPathKeyFrame::SetPrevKey)
        .addProperty("MoveSpeed", &GCPathKeyFrame::GetMoveSpeed, &GCPathKeyFrame::SetMoveSpeed)
        .endClass();
}