#include "../../../core/scripting/generated/classes/GC_OP_DirectionBetweenVecsToVec.h"
#include "../core.h"

void SetupLuaClassGC_OP_DirectionBetweenVecsToVec(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_DirectionBetweenVecsToVec>("C_OP_DirectionBetweenVecsToVec")
        .addProperty("FieldOutput", &GC_OP_DirectionBetweenVecsToVec::GetFieldOutput, &GC_OP_DirectionBetweenVecsToVec::SetFieldOutput)
        .addProperty("Point1", &GC_OP_DirectionBetweenVecsToVec::GetPoint1, &GC_OP_DirectionBetweenVecsToVec::SetPoint1)
        .addProperty("Point2", &GC_OP_DirectionBetweenVecsToVec::GetPoint2, &GC_OP_DirectionBetweenVecsToVec::SetPoint2)
        .endClass();
}