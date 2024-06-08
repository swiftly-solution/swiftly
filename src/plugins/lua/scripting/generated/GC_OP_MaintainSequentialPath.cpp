#include "../../../core/scripting/generated/classes/GC_OP_MaintainSequentialPath.h"
#include "../core.h"

void SetupLuaClassGC_OP_MaintainSequentialPath(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_MaintainSequentialPath>("C_OP_MaintainSequentialPath")
        .addProperty("MaxDistance", &GC_OP_MaintainSequentialPath::GetMaxDistance, &GC_OP_MaintainSequentialPath::SetMaxDistance)
        .addProperty("NumToAssign", &GC_OP_MaintainSequentialPath::GetNumToAssign, &GC_OP_MaintainSequentialPath::SetNumToAssign)
        .addProperty("CohesionStrength", &GC_OP_MaintainSequentialPath::GetCohesionStrength, &GC_OP_MaintainSequentialPath::SetCohesionStrength)
        .addProperty("Tolerance", &GC_OP_MaintainSequentialPath::GetTolerance, &GC_OP_MaintainSequentialPath::SetTolerance)
        .addProperty("Loop", &GC_OP_MaintainSequentialPath::GetLoop, &GC_OP_MaintainSequentialPath::SetLoop)
        .addProperty("UseParticleCount", &GC_OP_MaintainSequentialPath::GetUseParticleCount, &GC_OP_MaintainSequentialPath::SetUseParticleCount)
        .addProperty("PathParams", &GC_OP_MaintainSequentialPath::GetPathParams, &GC_OP_MaintainSequentialPath::SetPathParams)
        .endClass();
}