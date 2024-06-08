#include "../../../core/scripting/generated/classes/GCBaseTrigger.h"
#include "../core.h"

void SetupLuaClassGCBaseTrigger(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCBaseTrigger>("CBaseTrigger")
        .addProperty("Disabled", &GCBaseTrigger::GetDisabled, &GCBaseTrigger::SetDisabled)
        .addProperty("FilterName", &GCBaseTrigger::GetFilterName, &GCBaseTrigger::SetFilterName)
        .addProperty("Filter", &GCBaseTrigger::GetFilter, &GCBaseTrigger::SetFilter)
        .addProperty("OnStartTouch", &GCBaseTrigger::GetOnStartTouch, &GCBaseTrigger::SetOnStartTouch)
        .addProperty("OnStartTouchAll", &GCBaseTrigger::GetOnStartTouchAll, &GCBaseTrigger::SetOnStartTouchAll)
        .addProperty("OnEndTouch", &GCBaseTrigger::GetOnEndTouch, &GCBaseTrigger::SetOnEndTouch)
        .addProperty("OnEndTouchAll", &GCBaseTrigger::GetOnEndTouchAll, &GCBaseTrigger::SetOnEndTouchAll)
        .addProperty("OnTouching", &GCBaseTrigger::GetOnTouching, &GCBaseTrigger::SetOnTouching)
        .addProperty("OnTouchingEachEntity", &GCBaseTrigger::GetOnTouchingEachEntity, &GCBaseTrigger::SetOnTouchingEachEntity)
        .addProperty("OnNotTouching", &GCBaseTrigger::GetOnNotTouching, &GCBaseTrigger::SetOnNotTouching)
        .addProperty("ClientSidePredicted", &GCBaseTrigger::GetClientSidePredicted, &GCBaseTrigger::SetClientSidePredicted)
        .endClass();
}