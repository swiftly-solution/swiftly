#include "../../../core/scripting/generated/classes/GCTriggerPush.h"
#include "../core.h"

void SetupLuaClassGCTriggerPush(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerPush>("CTriggerPush")
        .addProperty("PushEntitySpace", &GCTriggerPush::GetPushEntitySpace, &GCTriggerPush::SetPushEntitySpace)
        .addProperty("PushDirEntitySpace", &GCTriggerPush::GetPushDirEntitySpace, &GCTriggerPush::SetPushDirEntitySpace)
        .addProperty("TriggerOnStartTouch", &GCTriggerPush::GetTriggerOnStartTouch, &GCTriggerPush::SetTriggerOnStartTouch)
        .addProperty("UsePathSimple", &GCTriggerPush::GetUsePathSimple, &GCTriggerPush::SetUsePathSimple)
        .addProperty("PathSimpleName", &GCTriggerPush::GetPathSimpleName, &GCTriggerPush::SetPathSimpleName)
        .addProperty("PathSimple", &GCTriggerPush::GetPathSimple, &GCTriggerPush::SetPathSimple)
        .addProperty("SplinePushType", &GCTriggerPush::GetSplinePushType, &GCTriggerPush::SetSplinePushType)
        .endClass();
}