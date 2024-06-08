#include "../../../core/scripting/generated/classes/GCompositeMaterialAssemblyProcedure_t.h"
#include "../core.h"

void SetupLuaClassGCompositeMaterialAssemblyProcedure_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCompositeMaterialAssemblyProcedure_t>("CompositeMaterialAssemblyProcedure_t")
        .addProperty("MatchFilters", &GCompositeMaterialAssemblyProcedure_t::GetMatchFilters, &GCompositeMaterialAssemblyProcedure_t::SetMatchFilters)
        .addProperty("CompositeInputContainers", &GCompositeMaterialAssemblyProcedure_t::GetCompositeInputContainers, &GCompositeMaterialAssemblyProcedure_t::SetCompositeInputContainers)
        .addProperty("PropertyMutators", &GCompositeMaterialAssemblyProcedure_t::GetPropertyMutators, &GCompositeMaterialAssemblyProcedure_t::SetPropertyMutators)
        .endClass();
}