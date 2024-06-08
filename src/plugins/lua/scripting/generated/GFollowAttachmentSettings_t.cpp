#include "../../../core/scripting/generated/classes/GFollowAttachmentSettings_t.h"
#include "../core.h"

void SetupLuaClassGFollowAttachmentSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFollowAttachmentSettings_t>("FollowAttachmentSettings_t")
        .addProperty("Attachment", &GFollowAttachmentSettings_t::GetAttachment, &GFollowAttachmentSettings_t::SetAttachment)
        .addProperty("BoneIndex", &GFollowAttachmentSettings_t::GetBoneIndex, &GFollowAttachmentSettings_t::SetBoneIndex)
        .addProperty("MatchTranslation", &GFollowAttachmentSettings_t::GetMatchTranslation, &GFollowAttachmentSettings_t::SetMatchTranslation)
        .addProperty("MatchRotation", &GFollowAttachmentSettings_t::GetMatchRotation, &GFollowAttachmentSettings_t::SetMatchRotation)
        .endClass();
}