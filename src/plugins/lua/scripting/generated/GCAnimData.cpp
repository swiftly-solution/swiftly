#include "../../../core/scripting/generated/classes/GCAnimData.h"
#include "../core.h"

void SetupLuaClassGCAnimData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimData>("CAnimData")
        .addProperty("Name", &GCAnimData::GetName, &GCAnimData::SetName)
        .addProperty("AnimArray", &GCAnimData::GetAnimArray, &GCAnimData::SetAnimArray)
        .addProperty("DecoderArray", &GCAnimData::GetDecoderArray, &GCAnimData::SetDecoderArray)
        .addProperty("MaxUniqueFrameIndex", &GCAnimData::GetMaxUniqueFrameIndex, &GCAnimData::SetMaxUniqueFrameIndex)
        .addProperty("SegmentArray", &GCAnimData::GetSegmentArray, &GCAnimData::SetSegmentArray)
        .endClass();
}