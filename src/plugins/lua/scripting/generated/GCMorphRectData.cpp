#include "../../../core/scripting/generated/classes/GCMorphRectData.h"
#include "../core.h"

void SetupLuaClassGCMorphRectData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMorphRectData>("CMorphRectData")
        .addProperty("XLeftDst", &GCMorphRectData::GetXLeftDst, &GCMorphRectData::SetXLeftDst)
        .addProperty("YTopDst", &GCMorphRectData::GetYTopDst, &GCMorphRectData::SetYTopDst)
        .addProperty("UWidthSrc", &GCMorphRectData::GetUWidthSrc, &GCMorphRectData::SetUWidthSrc)
        .addProperty("VHeightSrc", &GCMorphRectData::GetVHeightSrc, &GCMorphRectData::SetVHeightSrc)
        .addProperty("BundleDatas", &GCMorphRectData::GetBundleDatas, &GCMorphRectData::SetBundleDatas)
        .endClass();
}