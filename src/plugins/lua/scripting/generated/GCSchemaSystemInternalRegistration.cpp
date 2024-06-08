#include "../../../core/scripting/generated/classes/GCSchemaSystemInternalRegistration.h"
#include "../core.h"

void SetupLuaClassGCSchemaSystemInternalRegistration(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSchemaSystemInternalRegistration>("CSchemaSystemInternalRegistration")
        .addProperty("Vector2D", &GCSchemaSystemInternalRegistration::GetVector2D, &GCSchemaSystemInternalRegistration::SetVector2D)
        .addProperty("Vector", &GCSchemaSystemInternalRegistration::GetVector, &GCSchemaSystemInternalRegistration::SetVector)
        .addProperty("VectorAligned", &GCSchemaSystemInternalRegistration::GetVectorAligned, &GCSchemaSystemInternalRegistration::SetVectorAligned)
        .addProperty("Quaternion", &GCSchemaSystemInternalRegistration::GetQuaternion, &GCSchemaSystemInternalRegistration::SetQuaternion)
        .addProperty("QAngle", &GCSchemaSystemInternalRegistration::GetQAngle, &GCSchemaSystemInternalRegistration::SetQAngle)
        .addProperty("RotationVector", &GCSchemaSystemInternalRegistration::GetRotationVector, &GCSchemaSystemInternalRegistration::SetRotationVector)
        .addProperty("RadianEuler", &GCSchemaSystemInternalRegistration::GetRadianEuler, &GCSchemaSystemInternalRegistration::SetRadianEuler)
        .addProperty("Matrix3x4_t", &GCSchemaSystemInternalRegistration::GetMatrix3x4_t, &GCSchemaSystemInternalRegistration::SetMatrix3x4_t)
        .addProperty("Matrix3x4a_t", &GCSchemaSystemInternalRegistration::GetMatrix3x4a_t, &GCSchemaSystemInternalRegistration::SetMatrix3x4a_t)
        .addProperty("Color", &GCSchemaSystemInternalRegistration::GetColor, &GCSchemaSystemInternalRegistration::SetColor)
        .addProperty("Vector4D", &GCSchemaSystemInternalRegistration::GetVector4D, &GCSchemaSystemInternalRegistration::SetVector4D)
        .addProperty("KeyValues", &GCSchemaSystemInternalRegistration::GetKeyValues, &GCSchemaSystemInternalRegistration::SetKeyValues)
        .addProperty("CUtlString", &GCSchemaSystemInternalRegistration::GetCUtlString, &GCSchemaSystemInternalRegistration::SetCUtlString)
        .addProperty("CUtlSymbol", &GCSchemaSystemInternalRegistration::GetCUtlSymbol, &GCSchemaSystemInternalRegistration::SetCUtlSymbol)
        .addProperty("StringToken", &GCSchemaSystemInternalRegistration::GetStringToken, &GCSchemaSystemInternalRegistration::SetStringToken)
        .endClass();
}