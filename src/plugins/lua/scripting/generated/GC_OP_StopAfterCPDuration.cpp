#include "../../../core/scripting/generated/classes/GC_OP_StopAfterCPDuration.h"
#include "../core.h"

void SetupLuaClassGC_OP_StopAfterCPDuration(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_StopAfterCPDuration>("C_OP_StopAfterCPDuration")
        .addProperty("Duration", &GC_OP_StopAfterCPDuration::GetDuration, &GC_OP_StopAfterCPDuration::SetDuration)
        .addProperty("DestroyImmediately", &GC_OP_StopAfterCPDuration::GetDestroyImmediately, &GC_OP_StopAfterCPDuration::SetDestroyImmediately)
        .addProperty("PlayEndCap", &GC_OP_StopAfterCPDuration::GetPlayEndCap, &GC_OP_StopAfterCPDuration::SetPlayEndCap)
        .endClass();
}