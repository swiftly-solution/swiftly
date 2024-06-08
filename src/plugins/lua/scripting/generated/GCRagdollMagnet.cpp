#include "../../../core/scripting/generated/classes/GCRagdollMagnet.h"
#include "../core.h"

void SetupLuaClassGCRagdollMagnet(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCRagdollMagnet>("CRagdollMagnet")
        .addProperty("Disabled", &GCRagdollMagnet::GetDisabled, &GCRagdollMagnet::SetDisabled)
        .addProperty("Radius", &GCRagdollMagnet::GetRadius, &GCRagdollMagnet::SetRadius)
        .addProperty("Force", &GCRagdollMagnet::GetForce, &GCRagdollMagnet::SetForce)
        .addProperty("Axis", &GCRagdollMagnet::GetAxis, &GCRagdollMagnet::SetAxis)
        .endClass();
}