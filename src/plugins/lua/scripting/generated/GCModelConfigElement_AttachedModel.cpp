#include "../../../core/scripting/generated/classes/GCModelConfigElement_AttachedModel.h"
#include "../core.h"

void SetupLuaClassGCModelConfigElement_AttachedModel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCModelConfigElement_AttachedModel>("CModelConfigElement_AttachedModel")
        .addProperty("InstanceName", &GCModelConfigElement_AttachedModel::GetInstanceName, &GCModelConfigElement_AttachedModel::SetInstanceName)
        .addProperty("EntityClass", &GCModelConfigElement_AttachedModel::GetEntityClass, &GCModelConfigElement_AttachedModel::SetEntityClass)
        .addProperty("Offset", &GCModelConfigElement_AttachedModel::GetOffset, &GCModelConfigElement_AttachedModel::SetOffset)
        .addProperty("AngOffset", &GCModelConfigElement_AttachedModel::GetAngOffset, &GCModelConfigElement_AttachedModel::SetAngOffset)
        .addProperty("AttachmentName", &GCModelConfigElement_AttachedModel::GetAttachmentName, &GCModelConfigElement_AttachedModel::SetAttachmentName)
        .addProperty("LocalAttachmentOffsetName", &GCModelConfigElement_AttachedModel::GetLocalAttachmentOffsetName, &GCModelConfigElement_AttachedModel::SetLocalAttachmentOffsetName)
        .addProperty("AttachmentType", &GCModelConfigElement_AttachedModel::GetAttachmentType, &GCModelConfigElement_AttachedModel::SetAttachmentType)
        .addProperty("BoneMergeFlex", &GCModelConfigElement_AttachedModel::GetBoneMergeFlex, &GCModelConfigElement_AttachedModel::SetBoneMergeFlex)
        .addProperty("UserSpecifiedColor", &GCModelConfigElement_AttachedModel::GetUserSpecifiedColor, &GCModelConfigElement_AttachedModel::SetUserSpecifiedColor)
        .addProperty("UserSpecifiedMaterialGroup", &GCModelConfigElement_AttachedModel::GetUserSpecifiedMaterialGroup, &GCModelConfigElement_AttachedModel::SetUserSpecifiedMaterialGroup)
        .addProperty("AcceptParentMaterialDrivenDecals", &GCModelConfigElement_AttachedModel::GetAcceptParentMaterialDrivenDecals, &GCModelConfigElement_AttachedModel::SetAcceptParentMaterialDrivenDecals)
        .addProperty("BodygroupOnOtherModels", &GCModelConfigElement_AttachedModel::GetBodygroupOnOtherModels, &GCModelConfigElement_AttachedModel::SetBodygroupOnOtherModels)
        .addProperty("MaterialGroupOnOtherModels", &GCModelConfigElement_AttachedModel::GetMaterialGroupOnOtherModels, &GCModelConfigElement_AttachedModel::SetMaterialGroupOnOtherModels)
        .endClass();
}