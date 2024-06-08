#include "../../../core/scripting/generated/classes/GCTriggerDetectExplosion.h"
#include "../core.h"

void SetupLuaClassGCTriggerDetectExplosion(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTriggerDetectExplosion>("CTriggerDetectExplosion")
        .addProperty("OnDetectedExplosion", &GCTriggerDetectExplosion::GetOnDetectedExplosion, &GCTriggerDetectExplosion::SetOnDetectedExplosion)
        .endClass();
}