#include "../../../core/scripting/generated/classes/GC_OP_SetControlPointsToModelParticles.h"
#include "../core.h"

void SetupLuaClassGC_OP_SetControlPointsToModelParticles(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_SetControlPointsToModelParticles>("C_OP_SetControlPointsToModelParticles")
        .addProperty("HitboxSetName", &GC_OP_SetControlPointsToModelParticles::GetHitboxSetName, &GC_OP_SetControlPointsToModelParticles::SetHitboxSetName)
        .addProperty("AttachmentName", &GC_OP_SetControlPointsToModelParticles::GetAttachmentName, &GC_OP_SetControlPointsToModelParticles::SetAttachmentName)
        .addProperty("FirstControlPoint", &GC_OP_SetControlPointsToModelParticles::GetFirstControlPoint, &GC_OP_SetControlPointsToModelParticles::SetFirstControlPoint)
        .addProperty("NumControlPoints", &GC_OP_SetControlPointsToModelParticles::GetNumControlPoints, &GC_OP_SetControlPointsToModelParticles::SetNumControlPoints)
        .addProperty("FirstSourcePoint", &GC_OP_SetControlPointsToModelParticles::GetFirstSourcePoint, &GC_OP_SetControlPointsToModelParticles::SetFirstSourcePoint)
        .addProperty("Skin", &GC_OP_SetControlPointsToModelParticles::GetSkin, &GC_OP_SetControlPointsToModelParticles::SetSkin)
        .addProperty("Attachment", &GC_OP_SetControlPointsToModelParticles::GetAttachment, &GC_OP_SetControlPointsToModelParticles::SetAttachment)
        .endClass();
}