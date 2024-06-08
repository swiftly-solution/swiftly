#include "../../../core/scripting/generated/classes/GCMarkupVolumeTagged.h"
#include "../core.h"

void SetupLuaClassGCMarkupVolumeTagged(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMarkupVolumeTagged>("CMarkupVolumeTagged")
        .addProperty("IsGroup", &GCMarkupVolumeTagged::GetIsGroup, &GCMarkupVolumeTagged::SetIsGroup)
        .addProperty("GroupByPrefab", &GCMarkupVolumeTagged::GetGroupByPrefab, &GCMarkupVolumeTagged::SetGroupByPrefab)
        .addProperty("GroupByVolume", &GCMarkupVolumeTagged::GetGroupByVolume, &GCMarkupVolumeTagged::SetGroupByVolume)
        .addProperty("GroupOtherGroups", &GCMarkupVolumeTagged::GetGroupOtherGroups, &GCMarkupVolumeTagged::SetGroupOtherGroups)
        .addProperty("IsInGroup", &GCMarkupVolumeTagged::GetIsInGroup, &GCMarkupVolumeTagged::SetIsInGroup)
        .endClass();
}