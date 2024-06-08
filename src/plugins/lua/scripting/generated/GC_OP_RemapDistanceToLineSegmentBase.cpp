#include "../../../core/scripting/generated/classes/GC_OP_RemapDistanceToLineSegmentBase.h"
#include "../core.h"

void SetupLuaClassGC_OP_RemapDistanceToLineSegmentBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_RemapDistanceToLineSegmentBase>("C_OP_RemapDistanceToLineSegmentBase")
        .addProperty("CP0", &GC_OP_RemapDistanceToLineSegmentBase::GetCP0, &GC_OP_RemapDistanceToLineSegmentBase::SetCP0)
        .addProperty("CP1", &GC_OP_RemapDistanceToLineSegmentBase::GetCP1, &GC_OP_RemapDistanceToLineSegmentBase::SetCP1)
        .addProperty("MinInputValue", &GC_OP_RemapDistanceToLineSegmentBase::GetMinInputValue, &GC_OP_RemapDistanceToLineSegmentBase::SetMinInputValue)
        .addProperty("MaxInputValue", &GC_OP_RemapDistanceToLineSegmentBase::GetMaxInputValue, &GC_OP_RemapDistanceToLineSegmentBase::SetMaxInputValue)
        .addProperty("InfiniteLine", &GC_OP_RemapDistanceToLineSegmentBase::GetInfiniteLine, &GC_OP_RemapDistanceToLineSegmentBase::SetInfiniteLine)
        .endClass();
}