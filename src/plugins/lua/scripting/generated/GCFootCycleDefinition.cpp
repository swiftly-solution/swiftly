#include "../../../core/scripting/generated/classes/GCFootCycleDefinition.h"
#include "../core.h"

void SetupLuaClassGCFootCycleDefinition(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFootCycleDefinition>("CFootCycleDefinition")
        .addProperty("StancePositionMS", &GCFootCycleDefinition::GetStancePositionMS, &GCFootCycleDefinition::SetStancePositionMS)
        .addProperty("MidpointPositionMS", &GCFootCycleDefinition::GetMidpointPositionMS, &GCFootCycleDefinition::SetMidpointPositionMS)
        .addProperty("StanceDirectionMS", &GCFootCycleDefinition::GetStanceDirectionMS, &GCFootCycleDefinition::SetStanceDirectionMS)
        .addProperty("ToStrideStartPos", &GCFootCycleDefinition::GetToStrideStartPos, &GCFootCycleDefinition::SetToStrideStartPos)
        .addProperty("StanceCycle", &GCFootCycleDefinition::GetStanceCycle, &GCFootCycleDefinition::SetStanceCycle)
        .addProperty("FootLiftCycle", &GCFootCycleDefinition::GetFootLiftCycle, &GCFootCycleDefinition::SetFootLiftCycle)
        .addProperty("FootOffCycle", &GCFootCycleDefinition::GetFootOffCycle, &GCFootCycleDefinition::SetFootOffCycle)
        .addProperty("FootStrikeCycle", &GCFootCycleDefinition::GetFootStrikeCycle, &GCFootCycleDefinition::SetFootStrikeCycle)
        .addProperty("FootLandCycle", &GCFootCycleDefinition::GetFootLandCycle, &GCFootCycleDefinition::SetFootLandCycle)
        .endClass();
}