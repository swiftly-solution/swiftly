#include "../../../core/scripting/generated/classes/GCAnimGraphDebugReplay.h"
#include "../core.h"

void SetupLuaClassGCAnimGraphDebugReplay(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimGraphDebugReplay>("CAnimGraphDebugReplay")
        .addProperty("AnimGraphFileName", &GCAnimGraphDebugReplay::GetAnimGraphFileName, &GCAnimGraphDebugReplay::SetAnimGraphFileName)
        .addProperty("StartIndex", &GCAnimGraphDebugReplay::GetStartIndex, &GCAnimGraphDebugReplay::SetStartIndex)
        .addProperty("WriteIndex", &GCAnimGraphDebugReplay::GetWriteIndex, &GCAnimGraphDebugReplay::SetWriteIndex)
        .addProperty("FrameCount", &GCAnimGraphDebugReplay::GetFrameCount, &GCAnimGraphDebugReplay::SetFrameCount)
        .endClass();
}