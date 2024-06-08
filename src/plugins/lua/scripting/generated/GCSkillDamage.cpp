#include "../../../core/scripting/generated/classes/GCSkillDamage.h"
#include "../core.h"

void SetupLuaClassGCSkillDamage(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSkillDamage>("CSkillDamage")
        .addProperty("Damage", &GCSkillDamage::GetDamage, &GCSkillDamage::SetDamage)
        .addProperty("NPCDamageScalarVsNPC", &GCSkillDamage::GetNPCDamageScalarVsNPC, &GCSkillDamage::SetNPCDamageScalarVsNPC)
        .addProperty("PhysicsForceDamage", &GCSkillDamage::GetPhysicsForceDamage, &GCSkillDamage::SetPhysicsForceDamage)
        .endClass();
}