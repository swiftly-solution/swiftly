#include "../../../core/scripting/generated/classes/GCNavVolumeBreadthFirstSearch.h"
#include "../core.h"

void SetupLuaClassGCNavVolumeBreadthFirstSearch(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavVolumeBreadthFirstSearch>("CNavVolumeBreadthFirstSearch")
        .addProperty("StartPos", &GCNavVolumeBreadthFirstSearch::GetStartPos, &GCNavVolumeBreadthFirstSearch::SetStartPos)
        .addProperty("SearchDist", &GCNavVolumeBreadthFirstSearch::GetSearchDist, &GCNavVolumeBreadthFirstSearch::SetSearchDist)
        .endClass();
}