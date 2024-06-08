#include "../../../core/scripting/generated/classes/GCAnimFrameSegment.h"
#include "../core.h"

void SetupLuaClassGCAnimFrameSegment(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimFrameSegment>("CAnimFrameSegment")
        .addProperty("UniqueFrameIndex", &GCAnimFrameSegment::GetUniqueFrameIndex, &GCAnimFrameSegment::SetUniqueFrameIndex)
        .addProperty("LocalElementMasks", &GCAnimFrameSegment::GetLocalElementMasks, &GCAnimFrameSegment::SetLocalElementMasks)
        .addProperty("LocalChannel", &GCAnimFrameSegment::GetLocalChannel, &GCAnimFrameSegment::SetLocalChannel)
        .endClass();
}