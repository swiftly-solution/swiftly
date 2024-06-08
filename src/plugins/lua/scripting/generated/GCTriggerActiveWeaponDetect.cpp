#include "../../../core/scripting/generated/classes/GCTriggerActiveWeaponDetect.h"
#include "../core.h"

void SetupLuaClassGCTriggerActiveWeaponDetect(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerActiveWeaponDetect>("CTriggerActiveWeaponDetect")
        .addProperty("OnTouchedActiveWeapon", &GCTriggerActiveWeaponDetect::GetOnTouchedActiveWeapon, &GCTriggerActiveWeaponDetect::SetOnTouchedActiveWeapon)
        .addProperty("WeaponClassName", &GCTriggerActiveWeaponDetect::GetWeaponClassName, &GCTriggerActiveWeaponDetect::SetWeaponClassName)
        .endClass();
}