#include "../../../core/scripting/generated/classes/GCAnimLocalHierarchy.h"
#include "../core.h"

void SetupLuaClassGCAnimLocalHierarchy(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimLocalHierarchy>("CAnimLocalHierarchy")
        .addProperty("Bone", &GCAnimLocalHierarchy::GetBone, &GCAnimLocalHierarchy::SetBone)
        .addProperty("NewParent", &GCAnimLocalHierarchy::GetNewParent, &GCAnimLocalHierarchy::SetNewParent)
        .addProperty("StartFrame", &GCAnimLocalHierarchy::GetStartFrame, &GCAnimLocalHierarchy::SetStartFrame)
        .addProperty("PeakFrame", &GCAnimLocalHierarchy::GetPeakFrame, &GCAnimLocalHierarchy::SetPeakFrame)
        .addProperty("TailFrame", &GCAnimLocalHierarchy::GetTailFrame, &GCAnimLocalHierarchy::SetTailFrame)
        .addProperty("EndFrame", &GCAnimLocalHierarchy::GetEndFrame, &GCAnimLocalHierarchy::SetEndFrame)
        .endClass();
}