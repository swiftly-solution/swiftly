#include "../../../core/scripting/generated/classes/GCGeneralRandomRotation.h"
#include "../core.h"

void SetupLuaClassGCGeneralRandomRotation(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCGeneralRandomRotation>("CGeneralRandomRotation")
        .addProperty("FieldOutput", &GCGeneralRandomRotation::GetFieldOutput, &GCGeneralRandomRotation::SetFieldOutput)
        .addProperty("Degrees", &GCGeneralRandomRotation::GetDegrees, &GCGeneralRandomRotation::SetDegrees)
        .addProperty("DegreesMin", &GCGeneralRandomRotation::GetDegreesMin, &GCGeneralRandomRotation::SetDegreesMin)
        .addProperty("DegreesMax", &GCGeneralRandomRotation::GetDegreesMax, &GCGeneralRandomRotation::SetDegreesMax)
        .addProperty("RotationRandExponent", &GCGeneralRandomRotation::GetRotationRandExponent, &GCGeneralRandomRotation::SetRotationRandExponent)
        .addProperty("RandomlyFlipDirection", &GCGeneralRandomRotation::GetRandomlyFlipDirection, &GCGeneralRandomRotation::SetRandomlyFlipDirection)
        .endClass();
}