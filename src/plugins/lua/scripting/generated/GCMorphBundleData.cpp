#include "../../../core/scripting/generated/classes/GCMorphBundleData.h"
#include "../core.h"

void SetupLuaClassGCMorphBundleData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMorphBundleData>("CMorphBundleData")
        .addProperty("ULeftSrc", &GCMorphBundleData::GetULeftSrc, &GCMorphBundleData::SetULeftSrc)
        .addProperty("VTopSrc", &GCMorphBundleData::GetVTopSrc, &GCMorphBundleData::SetVTopSrc)
        .addProperty("Offsets", &GCMorphBundleData::GetOffsets, &GCMorphBundleData::SetOffsets)
        .addProperty("Ranges", &GCMorphBundleData::GetRanges, &GCMorphBundleData::SetRanges)
        .endClass();
}