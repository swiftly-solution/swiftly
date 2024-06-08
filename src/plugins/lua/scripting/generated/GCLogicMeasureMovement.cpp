#include "../../../core/scripting/generated/classes/GCLogicMeasureMovement.h"
#include "../core.h"

void SetupLuaClassGCLogicMeasureMovement(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCLogicMeasureMovement>("CLogicMeasureMovement")
        .addProperty("StrMeasureTarget", &GCLogicMeasureMovement::GetStrMeasureTarget, &GCLogicMeasureMovement::SetStrMeasureTarget)
        .addProperty("StrMeasureReference", &GCLogicMeasureMovement::GetStrMeasureReference, &GCLogicMeasureMovement::SetStrMeasureReference)
        .addProperty("StrTargetReference", &GCLogicMeasureMovement::GetStrTargetReference, &GCLogicMeasureMovement::SetStrTargetReference)
        .addProperty("MeasureTarget", &GCLogicMeasureMovement::GetMeasureTarget, &GCLogicMeasureMovement::SetMeasureTarget)
        .addProperty("MeasureReference", &GCLogicMeasureMovement::GetMeasureReference, &GCLogicMeasureMovement::SetMeasureReference)
        .addProperty("Target", &GCLogicMeasureMovement::GetTarget, &GCLogicMeasureMovement::SetTarget)
        .addProperty("TargetReference", &GCLogicMeasureMovement::GetTargetReference, &GCLogicMeasureMovement::SetTargetReference)
        .addProperty("Scale", &GCLogicMeasureMovement::GetScale, &GCLogicMeasureMovement::SetScale)
        .addProperty("MeasureType", &GCLogicMeasureMovement::GetMeasureType, &GCLogicMeasureMovement::SetMeasureType)
        .endClass();
}