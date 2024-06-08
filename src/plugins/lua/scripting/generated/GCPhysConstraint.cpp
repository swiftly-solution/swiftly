#include "../../../core/scripting/generated/classes/GCPhysConstraint.h"
#include "../core.h"

void SetupLuaClassGCPhysConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPhysConstraint>("CPhysConstraint")
        .addProperty("NameAttach1", &GCPhysConstraint::GetNameAttach1, &GCPhysConstraint::SetNameAttach1)
        .addProperty("NameAttach2", &GCPhysConstraint::GetNameAttach2, &GCPhysConstraint::SetNameAttach2)
        .addProperty("Attach1", &GCPhysConstraint::GetAttach1, &GCPhysConstraint::SetAttach1)
        .addProperty("Attach2", &GCPhysConstraint::GetAttach2, &GCPhysConstraint::SetAttach2)
        .addProperty("NameAttachment1", &GCPhysConstraint::GetNameAttachment1, &GCPhysConstraint::SetNameAttachment1)
        .addProperty("NameAttachment2", &GCPhysConstraint::GetNameAttachment2, &GCPhysConstraint::SetNameAttachment2)
        .addProperty("BreakSound", &GCPhysConstraint::GetBreakSound, &GCPhysConstraint::SetBreakSound)
        .addProperty("ForceLimit", &GCPhysConstraint::GetForceLimit, &GCPhysConstraint::SetForceLimit)
        .addProperty("TorqueLimit", &GCPhysConstraint::GetTorqueLimit, &GCPhysConstraint::SetTorqueLimit)
        .addProperty("TeleportTick", &GCPhysConstraint::GetTeleportTick, &GCPhysConstraint::SetTeleportTick)
        .addProperty("MinTeleportDistance", &GCPhysConstraint::GetMinTeleportDistance, &GCPhysConstraint::SetMinTeleportDistance)
        .addProperty("SnapObjectPositions", &GCPhysConstraint::GetSnapObjectPositions, &GCPhysConstraint::SetSnapObjectPositions)
        .addProperty("OnBreak", &GCPhysConstraint::GetOnBreak, &GCPhysConstraint::SetOnBreak)
        .endClass();
}