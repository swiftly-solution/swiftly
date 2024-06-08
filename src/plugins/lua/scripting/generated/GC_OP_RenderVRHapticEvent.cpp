#include "../../../core/scripting/generated/classes/GC_OP_RenderVRHapticEvent.h"
#include "../core.h"

void SetupLuaClassGC_OP_RenderVRHapticEvent(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RenderVRHapticEvent>("C_OP_RenderVRHapticEvent")
        .addProperty("Hand", &GC_OP_RenderVRHapticEvent::GetHand, &GC_OP_RenderVRHapticEvent::SetHand)
        .addProperty("OutputHandCP", &GC_OP_RenderVRHapticEvent::GetOutputHandCP, &GC_OP_RenderVRHapticEvent::SetOutputHandCP)
        .addProperty("OutputField", &GC_OP_RenderVRHapticEvent::GetOutputField, &GC_OP_RenderVRHapticEvent::SetOutputField)
        .addProperty("Amplitude", &GC_OP_RenderVRHapticEvent::GetAmplitude, &GC_OP_RenderVRHapticEvent::SetAmplitude)
        .endClass();
}