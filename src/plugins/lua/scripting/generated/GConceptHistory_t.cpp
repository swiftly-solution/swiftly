#include "../../../core/scripting/generated/classes/GConceptHistory_t.h"
#include "../core.h"

void SetupLuaClassGConceptHistory_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GConceptHistory_t>("ConceptHistory_t")
        .addProperty("TimeSpoken", &GConceptHistory_t::GetTimeSpoken, &GConceptHistory_t::SetTimeSpoken)
        .endClass();
}