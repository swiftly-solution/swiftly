#include "../../../core/scripting/generated/classes/GCSingleFrameUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCSingleFrameUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSingleFrameUpdateNode>("CSingleFrameUpdateNode")
        .addProperty("PoseCacheHandle", &GCSingleFrameUpdateNode::GetPoseCacheHandle, &GCSingleFrameUpdateNode::SetPoseCacheHandle)
        .addProperty("Cycle", &GCSingleFrameUpdateNode::GetCycle, &GCSingleFrameUpdateNode::SetCycle)
        .endClass();
}