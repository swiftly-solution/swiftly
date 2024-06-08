#include "../../../core/scripting/generated/classes/GCPlayerSprayDecal.h"
#include "../core.h"

void SetupLuaClassGCPlayerSprayDecal(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPlayerSprayDecal>("CPlayerSprayDecal")
        .addProperty("UniqueID", &GCPlayerSprayDecal::GetUniqueID, &GCPlayerSprayDecal::SetUniqueID)
        .addProperty("AccountID", &GCPlayerSprayDecal::GetAccountID, &GCPlayerSprayDecal::SetAccountID)
        .addProperty("TraceID", &GCPlayerSprayDecal::GetTraceID, &GCPlayerSprayDecal::SetTraceID)
        .addProperty("RtGcTime", &GCPlayerSprayDecal::GetRtGcTime, &GCPlayerSprayDecal::SetRtGcTime)
        .addProperty("EndPos", &GCPlayerSprayDecal::GetEndPos, &GCPlayerSprayDecal::SetEndPos)
        .addProperty("Start", &GCPlayerSprayDecal::GetStart, &GCPlayerSprayDecal::SetStart)
        .addProperty("Left", &GCPlayerSprayDecal::GetLeft, &GCPlayerSprayDecal::SetLeft)
        .addProperty("Normal", &GCPlayerSprayDecal::GetNormal, &GCPlayerSprayDecal::SetNormal)
        .addProperty("Player", &GCPlayerSprayDecal::GetPlayer, &GCPlayerSprayDecal::SetPlayer)
        .addProperty("Entity", &GCPlayerSprayDecal::GetEntity, &GCPlayerSprayDecal::SetEntity)
        .addProperty("Hitbox", &GCPlayerSprayDecal::GetHitbox, &GCPlayerSprayDecal::SetHitbox)
        .addProperty("CreationTime", &GCPlayerSprayDecal::GetCreationTime, &GCPlayerSprayDecal::SetCreationTime)
        .addProperty("TintID", &GCPlayerSprayDecal::GetTintID, &GCPlayerSprayDecal::SetTintID)
        .addProperty("Version", &GCPlayerSprayDecal::GetVersion, &GCPlayerSprayDecal::SetVersion)
        .addProperty("Signature", &GCPlayerSprayDecal::GetSignature, &GCPlayerSprayDecal::SetSignature)
        .endClass();
}