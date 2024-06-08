#include "../../../core/scripting/generated/classes/GCEntityFlame.h"
#include "../core.h"

void SetupLuaClassGCEntityFlame(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEntityFlame>("CEntityFlame")
        .addProperty("EntAttached", &GCEntityFlame::GetEntAttached, &GCEntityFlame::SetEntAttached)
        .addProperty("CheapEffect", &GCEntityFlame::GetCheapEffect, &GCEntityFlame::SetCheapEffect)
        .addProperty("Size", &GCEntityFlame::GetSize, &GCEntityFlame::SetSize)
        .addProperty("UseHitboxes", &GCEntityFlame::GetUseHitboxes, &GCEntityFlame::SetUseHitboxes)
        .addProperty("NumHitboxFires", &GCEntityFlame::GetNumHitboxFires, &GCEntityFlame::SetNumHitboxFires)
        .addProperty("HitboxFireScale", &GCEntityFlame::GetHitboxFireScale, &GCEntityFlame::SetHitboxFireScale)
        .addProperty("Attacker", &GCEntityFlame::GetAttacker, &GCEntityFlame::SetAttacker)
        .addProperty("DangerSound", &GCEntityFlame::GetDangerSound, &GCEntityFlame::SetDangerSound)
        .addProperty("DirectDamagePerSecond", &GCEntityFlame::GetDirectDamagePerSecond, &GCEntityFlame::SetDirectDamagePerSecond)
        .addProperty("CustomDamageType", &GCEntityFlame::GetCustomDamageType, &GCEntityFlame::SetCustomDamageType)
        .endClass();
}