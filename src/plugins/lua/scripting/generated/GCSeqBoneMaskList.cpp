#include "../../../core/scripting/generated/classes/GCSeqBoneMaskList.h"
#include "../core.h"

void SetupLuaClassGCSeqBoneMaskList(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSeqBoneMaskList>("CSeqBoneMaskList")
        .addProperty("Name", &GCSeqBoneMaskList::GetName, &GCSeqBoneMaskList::SetName)
        .addProperty("LocalBoneArray", &GCSeqBoneMaskList::GetLocalBoneArray, &GCSeqBoneMaskList::SetLocalBoneArray)
        .addProperty("BoneWeightArray", &GCSeqBoneMaskList::GetBoneWeightArray, &GCSeqBoneMaskList::SetBoneWeightArray)
        .addProperty("DefaultMorphCtrlWeight", &GCSeqBoneMaskList::GetDefaultMorphCtrlWeight, &GCSeqBoneMaskList::SetDefaultMorphCtrlWeight)
        .endClass();
}