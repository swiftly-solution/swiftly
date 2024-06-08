#include "../../../core/scripting/generated/classes/GC_INIT_InitialVelocityFromHitbox.h"
#include "../core.h"

void SetupLuaClassGC_INIT_InitialVelocityFromHitbox(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_InitialVelocityFromHitbox>("C_INIT_InitialVelocityFromHitbox")
        .addProperty("VelocityMin", &GC_INIT_InitialVelocityFromHitbox::GetVelocityMin, &GC_INIT_InitialVelocityFromHitbox::SetVelocityMin)
        .addProperty("VelocityMax", &GC_INIT_InitialVelocityFromHitbox::GetVelocityMax, &GC_INIT_InitialVelocityFromHitbox::SetVelocityMax)
        .addProperty("ControlPointNumber", &GC_INIT_InitialVelocityFromHitbox::GetControlPointNumber, &GC_INIT_InitialVelocityFromHitbox::SetControlPointNumber)
        .addProperty("HitboxSetName", &GC_INIT_InitialVelocityFromHitbox::GetHitboxSetName, &GC_INIT_InitialVelocityFromHitbox::SetHitboxSetName)
        .addProperty("UseBones", &GC_INIT_InitialVelocityFromHitbox::GetUseBones, &GC_INIT_InitialVelocityFromHitbox::SetUseBones)
        .endClass();
}