#include "../../../core/scripting/generated/classes/GC_OP_ConstrainDistanceToPath.h"
#include "../core.h"

void SetupLuaClassGC_OP_ConstrainDistanceToPath(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ConstrainDistanceToPath>("C_OP_ConstrainDistanceToPath")
        .addProperty("MinDistance", &GC_OP_ConstrainDistanceToPath::GetMinDistance, &GC_OP_ConstrainDistanceToPath::SetMinDistance)
        .addProperty("MaxDistance0", &GC_OP_ConstrainDistanceToPath::GetMaxDistance0, &GC_OP_ConstrainDistanceToPath::SetMaxDistance0)
        .addProperty("MaxDistanceMid", &GC_OP_ConstrainDistanceToPath::GetMaxDistanceMid, &GC_OP_ConstrainDistanceToPath::SetMaxDistanceMid)
        .addProperty("MaxDistance1", &GC_OP_ConstrainDistanceToPath::GetMaxDistance1, &GC_OP_ConstrainDistanceToPath::SetMaxDistance1)
        .addProperty("PathParameters", &GC_OP_ConstrainDistanceToPath::GetPathParameters, &GC_OP_ConstrainDistanceToPath::SetPathParameters)
        .addProperty("TravelTime", &GC_OP_ConstrainDistanceToPath::GetTravelTime, &GC_OP_ConstrainDistanceToPath::SetTravelTime)
        .addProperty("FieldScale", &GC_OP_ConstrainDistanceToPath::GetFieldScale, &GC_OP_ConstrainDistanceToPath::SetFieldScale)
        .addProperty("ManualTField", &GC_OP_ConstrainDistanceToPath::GetManualTField, &GC_OP_ConstrainDistanceToPath::SetManualTField)
        .endClass();
}