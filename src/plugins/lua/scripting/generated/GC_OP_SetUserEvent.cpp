#include "../../../core/scripting/generated/classes/GC_OP_SetUserEvent.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetUserEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetUserEvent>("C_OP_SetUserEvent")
        .addProperty("Input", &GC_OP_SetUserEvent::GetInput, &GC_OP_SetUserEvent::SetInput)
        .addProperty("RisingEdge", &GC_OP_SetUserEvent::GetRisingEdge, &GC_OP_SetUserEvent::SetRisingEdge)
        .addProperty("RisingEventType", &GC_OP_SetUserEvent::GetRisingEventType, &GC_OP_SetUserEvent::SetRisingEventType)
        .addProperty("FallingEdge", &GC_OP_SetUserEvent::GetFallingEdge, &GC_OP_SetUserEvent::SetFallingEdge)
        .addProperty("FallingEventType", &GC_OP_SetUserEvent::GetFallingEventType, &GC_OP_SetUserEvent::SetFallingEventType)
        .endClass();
}