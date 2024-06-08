#include "../../../core/scripting/generated/classes/GCAudioAnimTag.h"
#include "../core.h"

void SetupLuaClassGCAudioAnimTag(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAudioAnimTag>("CAudioAnimTag")
        .addProperty("ClipName", &GCAudioAnimTag::GetClipName, &GCAudioAnimTag::SetClipName)
        .addProperty("AttachmentName", &GCAudioAnimTag::GetAttachmentName, &GCAudioAnimTag::SetAttachmentName)
        .addProperty("Volume", &GCAudioAnimTag::GetVolume, &GCAudioAnimTag::SetVolume)
        .addProperty("StopWhenTagEnds", &GCAudioAnimTag::GetStopWhenTagEnds, &GCAudioAnimTag::SetStopWhenTagEnds)
        .addProperty("StopWhenGraphEnds", &GCAudioAnimTag::GetStopWhenGraphEnds, &GCAudioAnimTag::SetStopWhenGraphEnds)
        .addProperty("PlayOnServer", &GCAudioAnimTag::GetPlayOnServer, &GCAudioAnimTag::SetPlayOnServer)
        .addProperty("PlayOnClient", &GCAudioAnimTag::GetPlayOnClient, &GCAudioAnimTag::SetPlayOnClient)
        .endClass();
}