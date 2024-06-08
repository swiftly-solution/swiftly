#include "../../../core/scripting/generated/classes/GCTriggerLerpObject.h"
#include "../core.h"

void SetupLuaClassGCTriggerLerpObject(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerLerpObject>("CTriggerLerpObject")
        .addProperty("LerpTarget", &GCTriggerLerpObject::GetLerpTarget, &GCTriggerLerpObject::SetLerpTarget)
        .addProperty("LerpTarget1", &GCTriggerLerpObject::GetLerpTarget1, &GCTriggerLerpObject::SetLerpTarget1)
        .addProperty("LerpTargetAttachment", &GCTriggerLerpObject::GetLerpTargetAttachment, &GCTriggerLerpObject::SetLerpTargetAttachment)
        .addProperty("LerpDuration", &GCTriggerLerpObject::GetLerpDuration, &GCTriggerLerpObject::SetLerpDuration)
        .addProperty("LerpRestoreMoveType", &GCTriggerLerpObject::GetLerpRestoreMoveType, &GCTriggerLerpObject::SetLerpRestoreMoveType)
        .addProperty("SingleLerpObject", &GCTriggerLerpObject::GetSingleLerpObject, &GCTriggerLerpObject::SetSingleLerpObject)
        .addProperty("LerpingObjects", &GCTriggerLerpObject::GetLerpingObjects, &GCTriggerLerpObject::SetLerpingObjects)
        .addProperty("LerpEffect", &GCTriggerLerpObject::GetLerpEffect, &GCTriggerLerpObject::SetLerpEffect)
        .addProperty("LerpSound", &GCTriggerLerpObject::GetLerpSound, &GCTriggerLerpObject::SetLerpSound)
        .addProperty("AttachTouchingObject", &GCTriggerLerpObject::GetAttachTouchingObject, &GCTriggerLerpObject::SetAttachTouchingObject)
        .addProperty("EntityToWaitForDisconnect", &GCTriggerLerpObject::GetEntityToWaitForDisconnect, &GCTriggerLerpObject::SetEntityToWaitForDisconnect)
        .addProperty("OnLerpStarted", &GCTriggerLerpObject::GetOnLerpStarted, &GCTriggerLerpObject::SetOnLerpStarted)
        .addProperty("OnLerpFinished", &GCTriggerLerpObject::GetOnLerpFinished, &GCTriggerLerpObject::SetOnLerpFinished)
        .endClass();
}