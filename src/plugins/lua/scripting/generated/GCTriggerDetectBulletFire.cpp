#include "../../../core/scripting/generated/classes/GCTriggerDetectBulletFire.h"
#include "../core.h"

void SetupLuaClassGCTriggerDetectBulletFire(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerDetectBulletFire>("CTriggerDetectBulletFire")
        .addProperty("PlayerFireOnly", &GCTriggerDetectBulletFire::GetPlayerFireOnly, &GCTriggerDetectBulletFire::SetPlayerFireOnly)
        .addProperty("OnDetectedBulletFire", &GCTriggerDetectBulletFire::GetOnDetectedBulletFire, &GCTriggerDetectBulletFire::SetOnDetectedBulletFire)
        .endClass();
}