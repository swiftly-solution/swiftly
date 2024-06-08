#include "../../../core/scripting/generated/classes/GCEffectData.h"
#include "../core.h"

void SetupLuaClassGCEffectData(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEffectData>("CEffectData")
        .addProperty("Origin", &GCEffectData::GetOrigin, &GCEffectData::SetOrigin)
        .addProperty("Start", &GCEffectData::GetStart, &GCEffectData::SetStart)
        .addProperty("Normal", &GCEffectData::GetNormal, &GCEffectData::SetNormal)
        .addProperty("Angles", &GCEffectData::GetAngles, &GCEffectData::SetAngles)
        .addProperty("Entity", &GCEffectData::GetEntity, &GCEffectData::SetEntity)
        .addProperty("OtherEntity", &GCEffectData::GetOtherEntity, &GCEffectData::SetOtherEntity)
        .addProperty("Scale", &GCEffectData::GetScale, &GCEffectData::SetScale)
        .addProperty("Magnitude", &GCEffectData::GetMagnitude, &GCEffectData::SetMagnitude)
        .addProperty("Radius", &GCEffectData::GetRadius, &GCEffectData::SetRadius)
        .addProperty("SurfaceProp", &GCEffectData::GetSurfaceProp, &GCEffectData::SetSurfaceProp)
        .addProperty("DamageType", &GCEffectData::GetDamageType, &GCEffectData::SetDamageType)
        .addProperty("Penetrate", &GCEffectData::GetPenetrate, &GCEffectData::SetPenetrate)
        .addProperty("Material", &GCEffectData::GetMaterial, &GCEffectData::SetMaterial)
        .addProperty("HitBox", &GCEffectData::GetHitBox, &GCEffectData::SetHitBox)
        .addProperty("Color", &GCEffectData::GetColor, &GCEffectData::SetColor)
        .addProperty("Flags", &GCEffectData::GetFlags, &GCEffectData::SetFlags)
        .addProperty("AttachmentName", &GCEffectData::GetAttachmentName, &GCEffectData::SetAttachmentName)
        .addProperty("EffectName", &GCEffectData::GetEffectName, &GCEffectData::SetEffectName)
        .addProperty("ExplosionType", &GCEffectData::GetExplosionType, &GCEffectData::SetExplosionType)
        .endClass();
}