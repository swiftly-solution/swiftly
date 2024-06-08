#include "../../../core/scripting/generated/classes/GCSeqScaleSet.h"
#include "../core.h"

void SetupLuaClassGCSeqScaleSet(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqScaleSet>("CSeqScaleSet")
        .addProperty("Name", &GCSeqScaleSet::GetName, &GCSeqScaleSet::SetName)
        .addProperty("RootOffset", &GCSeqScaleSet::GetRootOffset, &GCSeqScaleSet::SetRootOffset)
        .addProperty("RootOffset1", &GCSeqScaleSet::GetRootOffset1, &GCSeqScaleSet::SetRootOffset1)
        .addProperty("LocalBoneArray", &GCSeqScaleSet::GetLocalBoneArray, &GCSeqScaleSet::SetLocalBoneArray)
        .addProperty("BoneScaleArray", &GCSeqScaleSet::GetBoneScaleArray, &GCSeqScaleSet::SetBoneScaleArray)
        .endClass();
}