#include "../../../core/scripting/generated/classes/GCPlayer_MovementServices.h"
#include "../core.h"

void SetupLuaClassGCPlayer_MovementServices(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayer_MovementServices>("CPlayer_MovementServices")
        .addProperty("Impulse", &GCPlayer_MovementServices::GetImpulse, &GCPlayer_MovementServices::SetImpulse)
        .addProperty("Buttons", &GCPlayer_MovementServices::GetButtons, &GCPlayer_MovementServices::SetButtons)
        .addProperty("QueuedButtonDownMask", &GCPlayer_MovementServices::GetQueuedButtonDownMask, &GCPlayer_MovementServices::SetQueuedButtonDownMask)
        .addProperty("QueuedButtonChangeMask", &GCPlayer_MovementServices::GetQueuedButtonChangeMask, &GCPlayer_MovementServices::SetQueuedButtonChangeMask)
        .addProperty("ButtonDoublePressed", &GCPlayer_MovementServices::GetButtonDoublePressed, &GCPlayer_MovementServices::SetButtonDoublePressed)
        .addProperty("ButtonPressedCmdNumber", &GCPlayer_MovementServices::GetButtonPressedCmdNumber, &GCPlayer_MovementServices::SetButtonPressedCmdNumber)
        .addProperty("LastCommandNumberProcessed", &GCPlayer_MovementServices::GetLastCommandNumberProcessed, &GCPlayer_MovementServices::SetLastCommandNumberProcessed)
        .addProperty("ToggleButtonDownMask", &GCPlayer_MovementServices::GetToggleButtonDownMask, &GCPlayer_MovementServices::SetToggleButtonDownMask)
        .addProperty("Maxspeed", &GCPlayer_MovementServices::GetMaxspeed, &GCPlayer_MovementServices::SetMaxspeed)
        .addProperty("ForceSubtickMoveWhen", &GCPlayer_MovementServices::GetForceSubtickMoveWhen, &GCPlayer_MovementServices::SetForceSubtickMoveWhen)
        .addProperty("ForwardMove", &GCPlayer_MovementServices::GetForwardMove, &GCPlayer_MovementServices::SetForwardMove)
        .addProperty("LeftMove", &GCPlayer_MovementServices::GetLeftMove, &GCPlayer_MovementServices::SetLeftMove)
        .addProperty("UpMove", &GCPlayer_MovementServices::GetUpMove, &GCPlayer_MovementServices::SetUpMove)
        .addProperty("LastMovementImpulses", &GCPlayer_MovementServices::GetLastMovementImpulses, &GCPlayer_MovementServices::SetLastMovementImpulses)
        .addProperty("OldViewAngles", &GCPlayer_MovementServices::GetOldViewAngles, &GCPlayer_MovementServices::SetOldViewAngles)
        .endClass();
}