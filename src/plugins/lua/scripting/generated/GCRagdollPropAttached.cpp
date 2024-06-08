#include "../../../core/scripting/generated/classes/GCRagdollPropAttached.h"
#include "../core.h"

void SetupLuaClassGCRagdollPropAttached(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollPropAttached>("CRagdollPropAttached")
        .addProperty("BoneIndexAttached", &GCRagdollPropAttached::GetBoneIndexAttached, &GCRagdollPropAttached::SetBoneIndexAttached)
        .addProperty("RagdollAttachedObjectIndex", &GCRagdollPropAttached::GetRagdollAttachedObjectIndex, &GCRagdollPropAttached::SetRagdollAttachedObjectIndex)
        .addProperty("AttachmentPointBoneSpace", &GCRagdollPropAttached::GetAttachmentPointBoneSpace, &GCRagdollPropAttached::SetAttachmentPointBoneSpace)
        .addProperty("AttachmentPointRagdollSpace", &GCRagdollPropAttached::GetAttachmentPointRagdollSpace, &GCRagdollPropAttached::SetAttachmentPointRagdollSpace)
        .addProperty("ShouldDetach", &GCRagdollPropAttached::GetShouldDetach, &GCRagdollPropAttached::SetShouldDetach)
        .addProperty("ShouldDeleteAttachedActivationRecord", &GCRagdollPropAttached::GetShouldDeleteAttachedActivationRecord, &GCRagdollPropAttached::SetShouldDeleteAttachedActivationRecord)
        .endClass();
}