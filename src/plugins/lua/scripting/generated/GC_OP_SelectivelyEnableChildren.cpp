#include "../../../core/scripting/generated/classes/GC_OP_SelectivelyEnableChildren.h"
#include "../core.h"

void SetupLuaClassGC_OP_SelectivelyEnableChildren(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SelectivelyEnableChildren>("C_OP_SelectivelyEnableChildren")
        .addProperty("ChildGroupID", &GC_OP_SelectivelyEnableChildren::GetChildGroupID, &GC_OP_SelectivelyEnableChildren::SetChildGroupID)
        .addProperty("FirstChild", &GC_OP_SelectivelyEnableChildren::GetFirstChild, &GC_OP_SelectivelyEnableChildren::SetFirstChild)
        .addProperty("NumChildrenToEnable", &GC_OP_SelectivelyEnableChildren::GetNumChildrenToEnable, &GC_OP_SelectivelyEnableChildren::SetNumChildrenToEnable)
        .addProperty("PlayEndcapOnStop", &GC_OP_SelectivelyEnableChildren::GetPlayEndcapOnStop, &GC_OP_SelectivelyEnableChildren::SetPlayEndcapOnStop)
        .addProperty("DestroyImmediately", &GC_OP_SelectivelyEnableChildren::GetDestroyImmediately, &GC_OP_SelectivelyEnableChildren::SetDestroyImmediately)
        .endClass();
}