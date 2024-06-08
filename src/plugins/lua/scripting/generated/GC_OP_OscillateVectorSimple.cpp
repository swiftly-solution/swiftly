#include "../../../core/scripting/generated/classes/GC_OP_OscillateVectorSimple.h"
#include "../core.h"

void SetupLuaClassGC_OP_OscillateVectorSimple(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_OscillateVectorSimple>("C_OP_OscillateVectorSimple")
        .addProperty("Rate", &GC_OP_OscillateVectorSimple::GetRate, &GC_OP_OscillateVectorSimple::SetRate)
        .addProperty("Frequency", &GC_OP_OscillateVectorSimple::GetFrequency, &GC_OP_OscillateVectorSimple::SetFrequency)
        .addProperty("Field", &GC_OP_OscillateVectorSimple::GetField, &GC_OP_OscillateVectorSimple::SetField)
        .addProperty("OscMult", &GC_OP_OscillateVectorSimple::GetOscMult, &GC_OP_OscillateVectorSimple::SetOscMult)
        .addProperty("OscAdd", &GC_OP_OscillateVectorSimple::GetOscAdd, &GC_OP_OscillateVectorSimple::SetOscAdd)
        .addProperty("Offset", &GC_OP_OscillateVectorSimple::GetOffset, &GC_OP_OscillateVectorSimple::SetOffset)
        .endClass();
}