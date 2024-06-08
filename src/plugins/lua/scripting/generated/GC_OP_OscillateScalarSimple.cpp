#include "../../../core/scripting/generated/classes/GC_OP_OscillateScalarSimple.h"
#include "../core.h"

void SetupLuaClassGC_OP_OscillateScalarSimple(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_OscillateScalarSimple>("C_OP_OscillateScalarSimple")
        .addProperty("Rate", &GC_OP_OscillateScalarSimple::GetRate, &GC_OP_OscillateScalarSimple::SetRate)
        .addProperty("Frequency", &GC_OP_OscillateScalarSimple::GetFrequency, &GC_OP_OscillateScalarSimple::SetFrequency)
        .addProperty("Field", &GC_OP_OscillateScalarSimple::GetField, &GC_OP_OscillateScalarSimple::SetField)
        .addProperty("OscMult", &GC_OP_OscillateScalarSimple::GetOscMult, &GC_OP_OscillateScalarSimple::SetOscMult)
        .addProperty("OscAdd", &GC_OP_OscillateScalarSimple::GetOscAdd, &GC_OP_OscillateScalarSimple::SetOscAdd)
        .endClass();
}