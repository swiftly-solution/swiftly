#include "../../../core/scripting/generated/classes/GCHitBox.h"
#include "../core.h"

void SetupLuaClassGCHitBox(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHitBox>("CHitBox")
        .addProperty("Name", &GCHitBox::GetName, &GCHitBox::SetName)
        .addProperty("SurfaceProperty", &GCHitBox::GetSurfaceProperty, &GCHitBox::SetSurfaceProperty)
        .addProperty("BoneName", &GCHitBox::GetBoneName, &GCHitBox::SetBoneName)
        .addProperty("MinBounds", &GCHitBox::GetMinBounds, &GCHitBox::SetMinBounds)
        .addProperty("MaxBounds", &GCHitBox::GetMaxBounds, &GCHitBox::SetMaxBounds)
        .addProperty("ShapeRadius", &GCHitBox::GetShapeRadius, &GCHitBox::SetShapeRadius)
        .addProperty("BoneNameHash", &GCHitBox::GetBoneNameHash, &GCHitBox::SetBoneNameHash)
        .addProperty("GroupId", &GCHitBox::GetGroupId, &GCHitBox::SetGroupId)
        .addProperty("ShapeType", &GCHitBox::GetShapeType, &GCHitBox::SetShapeType)
        .addProperty("TranslationOnly", &GCHitBox::GetTranslationOnly, &GCHitBox::SetTranslationOnly)
        .addProperty("CRC", &GCHitBox::GetCRC, &GCHitBox::SetCRC)
        .addProperty("CRenderColor", &GCHitBox::GetCRenderColor, &GCHitBox::SetCRenderColor)
        .addProperty("HitBoxIndex", &GCHitBox::GetHitBoxIndex, &GCHitBox::SetHitBoxIndex)
        .endClass();
}