class GCModelConfigElement_AttachedModel;

#ifndef _gccmodelconfigelement_attachedmodel_h
#define _gccmodelconfigelement_attachedmodel_h

#include "../../../scripting.h"

#include "../types/GModelConfigAttachmentType_t.h"


class GCModelConfigElement_AttachedModel
{
private:
    void *m_ptr;

public:
    GCModelConfigElement_AttachedModel() {}
    GCModelConfigElement_AttachedModel(void *ptr) : m_ptr(ptr) {}

    CUtlString GetInstanceName() const { return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_AttachedModel", "m_InstanceName"); }
    void SetInstanceName(CUtlString value) { SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_InstanceName", false, value); }
    CUtlString GetEntityClass() const { return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_AttachedModel", "m_EntityClass"); }
    void SetEntityClass(CUtlString value) { SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_EntityClass", false, value); }
    Vector GetOffset() const { return GetSchemaValue<Vector>(m_ptr, "CModelConfigElement_AttachedModel", "m_vOffset"); }
    void SetOffset(Vector value) { SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_vOffset", false, value); }
    QAngle GetAngOffset() const { return GetSchemaValue<QAngle>(m_ptr, "CModelConfigElement_AttachedModel", "m_aAngOffset"); }
    void SetAngOffset(QAngle value) { SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_aAngOffset", false, value); }
    CUtlString GetAttachmentName() const { return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_AttachedModel", "m_AttachmentName"); }
    void SetAttachmentName(CUtlString value) { SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_AttachmentName", false, value); }
    CUtlString GetLocalAttachmentOffsetName() const { return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_AttachedModel", "m_LocalAttachmentOffsetName"); }
    void SetLocalAttachmentOffsetName(CUtlString value) { SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_LocalAttachmentOffsetName", false, value); }
    ModelConfigAttachmentType_t GetAttachmentType() const { return GetSchemaValue<ModelConfigAttachmentType_t>(m_ptr, "CModelConfigElement_AttachedModel", "m_AttachmentType"); }
    void SetAttachmentType(ModelConfigAttachmentType_t value) { SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_AttachmentType", false, value); }
    bool GetBoneMergeFlex() const { return GetSchemaValue<bool>(m_ptr, "CModelConfigElement_AttachedModel", "m_bBoneMergeFlex"); }
    void SetBoneMergeFlex(bool value) { SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_bBoneMergeFlex", false, value); }
    bool GetUserSpecifiedColor() const { return GetSchemaValue<bool>(m_ptr, "CModelConfigElement_AttachedModel", "m_bUserSpecifiedColor"); }
    void SetUserSpecifiedColor(bool value) { SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_bUserSpecifiedColor", false, value); }
    bool GetUserSpecifiedMaterialGroup() const { return GetSchemaValue<bool>(m_ptr, "CModelConfigElement_AttachedModel", "m_bUserSpecifiedMaterialGroup"); }
    void SetUserSpecifiedMaterialGroup(bool value) { SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_bUserSpecifiedMaterialGroup", false, value); }
    bool GetAcceptParentMaterialDrivenDecals() const { return GetSchemaValue<bool>(m_ptr, "CModelConfigElement_AttachedModel", "m_bAcceptParentMaterialDrivenDecals"); }
    void SetAcceptParentMaterialDrivenDecals(bool value) { SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_bAcceptParentMaterialDrivenDecals", false, value); }
    CUtlString GetBodygroupOnOtherModels() const { return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_AttachedModel", "m_BodygroupOnOtherModels"); }
    void SetBodygroupOnOtherModels(CUtlString value) { SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_BodygroupOnOtherModels", false, value); }
    CUtlString GetMaterialGroupOnOtherModels() const { return GetSchemaValue<CUtlString>(m_ptr, "CModelConfigElement_AttachedModel", "m_MaterialGroupOnOtherModels"); }
    void SetMaterialGroupOnOtherModels(CUtlString value) { SetSchemaValue(m_ptr, "CModelConfigElement_AttachedModel", "m_MaterialGroupOnOtherModels", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif