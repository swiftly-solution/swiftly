#include "../../../core/scripting/generated/classes/GCFuseProgram.h"
#include "../core.h"

void SetupLuaClassGCFuseProgram(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuseProgram>("CFuseProgram")
        .addProperty("ProgramBuffer", &GCFuseProgram::GetProgramBuffer, &GCFuseProgram::SetProgramBuffer)
        .addProperty("VariablesRead", &GCFuseProgram::GetVariablesRead, &GCFuseProgram::SetVariablesRead)
        .addProperty("VariablesWritten", &GCFuseProgram::GetVariablesWritten, &GCFuseProgram::SetVariablesWritten)
        .addProperty("MaxTempVarsUsed", &GCFuseProgram::GetMaxTempVarsUsed, &GCFuseProgram::SetMaxTempVarsUsed)
        .endClass();
}