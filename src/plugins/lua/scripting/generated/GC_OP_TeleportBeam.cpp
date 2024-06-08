#include "../../../core/scripting/generated/classes/GC_OP_TeleportBeam.h"
#include "../core.h"

void SetupLuaClassGC_OP_TeleportBeam(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_TeleportBeam>("C_OP_TeleportBeam")
        .addProperty("CPPosition", &GC_OP_TeleportBeam::GetCPPosition, &GC_OP_TeleportBeam::SetCPPosition)
        .addProperty("CPVelocity", &GC_OP_TeleportBeam::GetCPVelocity, &GC_OP_TeleportBeam::SetCPVelocity)
        .addProperty("CPMisc", &GC_OP_TeleportBeam::GetCPMisc, &GC_OP_TeleportBeam::SetCPMisc)
        .addProperty("CPColor", &GC_OP_TeleportBeam::GetCPColor, &GC_OP_TeleportBeam::SetCPColor)
        .addProperty("CPInvalidColor", &GC_OP_TeleportBeam::GetCPInvalidColor, &GC_OP_TeleportBeam::SetCPInvalidColor)
        .addProperty("CPExtraArcData", &GC_OP_TeleportBeam::GetCPExtraArcData, &GC_OP_TeleportBeam::SetCPExtraArcData)
        .addProperty("Gravity", &GC_OP_TeleportBeam::GetGravity, &GC_OP_TeleportBeam::SetGravity)
        .addProperty("ArcMaxDuration", &GC_OP_TeleportBeam::GetArcMaxDuration, &GC_OP_TeleportBeam::SetArcMaxDuration)
        .addProperty("SegmentBreak", &GC_OP_TeleportBeam::GetSegmentBreak, &GC_OP_TeleportBeam::SetSegmentBreak)
        .addProperty("ArcSpeed", &GC_OP_TeleportBeam::GetArcSpeed, &GC_OP_TeleportBeam::SetArcSpeed)
        .addProperty("Alpha", &GC_OP_TeleportBeam::GetAlpha, &GC_OP_TeleportBeam::SetAlpha)
        .endClass();
}