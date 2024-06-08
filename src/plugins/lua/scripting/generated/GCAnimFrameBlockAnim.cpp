#include "../../../core/scripting/generated/classes/GCAnimFrameBlockAnim.h"
#include "../core.h"

void SetupLuaClassGCAnimFrameBlockAnim(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimFrameBlockAnim>("CAnimFrameBlockAnim")
        .addProperty("StartFrame", &GCAnimFrameBlockAnim::GetStartFrame, &GCAnimFrameBlockAnim::SetStartFrame)
        .addProperty("EndFrame", &GCAnimFrameBlockAnim::GetEndFrame, &GCAnimFrameBlockAnim::SetEndFrame)
        .addProperty("SegmentIndexArray", &GCAnimFrameBlockAnim::GetSegmentIndexArray, &GCAnimFrameBlockAnim::SetSegmentIndexArray)
        .endClass();
}