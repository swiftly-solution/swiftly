#include "../../../core/scripting/generated/classes/GCFollowAttachmentUpdateNode.h"
#include "../core.h"

void SetupLuaClassGCFollowAttachmentUpdateNode(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFollowAttachmentUpdateNode>("CFollowAttachmentUpdateNode")
        .addProperty("OpFixedData", &GCFollowAttachmentUpdateNode::GetOpFixedData, &GCFollowAttachmentUpdateNode::SetOpFixedData)
        .endClass();
}