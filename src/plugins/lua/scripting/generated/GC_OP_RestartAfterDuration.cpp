#include "../../../core/scripting/generated/classes/GC_OP_RestartAfterDuration.h"
#include "../core.h"

void SetupLuaClassGC_OP_RestartAfterDuration(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RestartAfterDuration>("C_OP_RestartAfterDuration")
        .addProperty("DurationMin", &GC_OP_RestartAfterDuration::GetDurationMin, &GC_OP_RestartAfterDuration::SetDurationMin)
        .addProperty("DurationMax", &GC_OP_RestartAfterDuration::GetDurationMax, &GC_OP_RestartAfterDuration::SetDurationMax)
        .addProperty("CP", &GC_OP_RestartAfterDuration::GetCP, &GC_OP_RestartAfterDuration::SetCP)
        .addProperty("CPField", &GC_OP_RestartAfterDuration::GetCPField, &GC_OP_RestartAfterDuration::SetCPField)
        .addProperty("ChildGroupID", &GC_OP_RestartAfterDuration::GetChildGroupID, &GC_OP_RestartAfterDuration::SetChildGroupID)
        .addProperty("OnlyChildren", &GC_OP_RestartAfterDuration::GetOnlyChildren, &GC_OP_RestartAfterDuration::SetOnlyChildren)
        .endClass();
}