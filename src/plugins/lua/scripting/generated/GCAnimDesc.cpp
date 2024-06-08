#include "../../../core/scripting/generated/classes/GCAnimDesc.h"
#include "../core.h"

void SetupLuaClassGCAnimDesc(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimDesc>("CAnimDesc")
        .addProperty("Name", &GCAnimDesc::GetName, &GCAnimDesc::SetName)
        .addProperty("Flags", &GCAnimDesc::GetFlags, &GCAnimDesc::SetFlags)
        .addProperty("Fps", &GCAnimDesc::GetFps, &GCAnimDesc::SetFps)
        .addProperty("Data", &GCAnimDesc::GetData, &GCAnimDesc::SetData)
        .addProperty("MovementArray", &GCAnimDesc::GetMovementArray, &GCAnimDesc::SetMovementArray)
        .addProperty("EventArray", &GCAnimDesc::GetEventArray, &GCAnimDesc::SetEventArray)
        .addProperty("ActivityArray", &GCAnimDesc::GetActivityArray, &GCAnimDesc::SetActivityArray)
        .addProperty("HierarchyArray", &GCAnimDesc::GetHierarchyArray, &GCAnimDesc::SetHierarchyArray)
        .addProperty("Framestalltime", &GCAnimDesc::GetFramestalltime, &GCAnimDesc::SetFramestalltime)
        .addProperty("RootMin", &GCAnimDesc::GetRootMin, &GCAnimDesc::SetRootMin)
        .addProperty("RootMax", &GCAnimDesc::GetRootMax, &GCAnimDesc::SetRootMax)
        .addProperty("BoneWorldMin", &GCAnimDesc::GetBoneWorldMin, &GCAnimDesc::SetBoneWorldMin)
        .addProperty("BoneWorldMax", &GCAnimDesc::GetBoneWorldMax, &GCAnimDesc::SetBoneWorldMax)
        .addProperty("SequenceParams", &GCAnimDesc::GetSequenceParams, &GCAnimDesc::SetSequenceParams)
        .endClass();
}