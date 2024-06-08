#include "../../../core/scripting/generated/classes/GIKSolverSettings_t.h"
#include "../core.h"

void SetupLuaClassGIKSolverSettings_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GIKSolverSettings_t>("IKSolverSettings_t")
        .addProperty("SolverType", &GIKSolverSettings_t::GetSolverType, &GIKSolverSettings_t::SetSolverType)
        .addProperty("NumIterations", &GIKSolverSettings_t::GetNumIterations, &GIKSolverSettings_t::SetNumIterations)
        .endClass();
}