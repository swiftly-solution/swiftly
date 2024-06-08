#include "../../../core/scripting/generated/classes/GCPointProximitySensor.h"
#include "../core.h"

void SetupLuaClassGCPointProximitySensor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointProximitySensor>("CPointProximitySensor")
        .addProperty("Disabled", &GCPointProximitySensor::GetDisabled, &GCPointProximitySensor::SetDisabled)
        .addProperty("TargetEntity", &GCPointProximitySensor::GetTargetEntity, &GCPointProximitySensor::SetTargetEntity)
        .endClass();
}