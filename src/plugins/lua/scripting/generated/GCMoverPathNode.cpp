#include "../../../core/scripting/generated/classes/GCMoverPathNode.h"
#include "../core.h"

void SetupLuaClassGCMoverPathNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCMoverPathNode>("CMoverPathNode")
        .addProperty("InTangentLocal", &GCMoverPathNode::GetInTangentLocal, &GCMoverPathNode::SetInTangentLocal)
        .addProperty("OutTangentLocal", &GCMoverPathNode::GetOutTangentLocal, &GCMoverPathNode::SetOutTangentLocal)
        .addProperty("ParentPathUniqueID", &GCMoverPathNode::GetParentPathUniqueID, &GCMoverPathNode::SetParentPathUniqueID)
        .addProperty("OnPassThrough", &GCMoverPathNode::GetOnPassThrough, &GCMoverPathNode::SetOnPassThrough)
        .addProperty("Mover", &GCMoverPathNode::GetMover, &GCMoverPathNode::SetMover)
        .endClass();
}