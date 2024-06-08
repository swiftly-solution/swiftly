#include "../../../core/scripting/generated/classes/GCAnimEncodedFrames.h"
#include "../core.h"

void SetupLuaClassGCAnimEncodedFrames(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimEncodedFrames>("CAnimEncodedFrames")
        .addProperty("FileName", &GCAnimEncodedFrames::GetFileName, &GCAnimEncodedFrames::SetFileName)
        .addProperty("Frames", &GCAnimEncodedFrames::GetFrames, &GCAnimEncodedFrames::SetFrames)
        .addProperty("FramesPerBlock", &GCAnimEncodedFrames::GetFramesPerBlock, &GCAnimEncodedFrames::SetFramesPerBlock)
        .addProperty("FrameblockArray", &GCAnimEncodedFrames::GetFrameblockArray, &GCAnimEncodedFrames::SetFrameblockArray)
        .addProperty("UsageDifferences", &GCAnimEncodedFrames::GetUsageDifferences, &GCAnimEncodedFrames::SetUsageDifferences)
        .endClass();
}