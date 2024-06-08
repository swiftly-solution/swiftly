#include "../../../core/scripting/generated/classes/GCTriggerBrush.h"
#include "../core.h"

void SetupLuaClassGCTriggerBrush(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerBrush>("CTriggerBrush")
        .addProperty("OnStartTouch", &GCTriggerBrush::GetOnStartTouch, &GCTriggerBrush::SetOnStartTouch)
        .addProperty("OnEndTouch", &GCTriggerBrush::GetOnEndTouch, &GCTriggerBrush::SetOnEndTouch)
        .addProperty("OnUse", &GCTriggerBrush::GetOnUse, &GCTriggerBrush::SetOnUse)
        .addProperty("InputFilter", &GCTriggerBrush::GetInputFilter, &GCTriggerBrush::SetInputFilter)
        .addProperty("DontMessageParent", &GCTriggerBrush::GetDontMessageParent, &GCTriggerBrush::SetDontMessageParent)
        .endClass();
}