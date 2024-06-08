#include "../../../core/scripting/generated/classes/GCPointEntityFinder.h"
#include "../core.h"

void SetupLuaClassGCPointEntityFinder(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointEntityFinder>("CPointEntityFinder")
        .addProperty("Entity", &GCPointEntityFinder::GetEntity, &GCPointEntityFinder::SetEntity)
        .addProperty("FilterName", &GCPointEntityFinder::GetFilterName, &GCPointEntityFinder::SetFilterName)
        .addProperty("Filter", &GCPointEntityFinder::GetFilter, &GCPointEntityFinder::SetFilter)
        .addProperty("RefName", &GCPointEntityFinder::GetRefName, &GCPointEntityFinder::SetRefName)
        .addProperty("Reference", &GCPointEntityFinder::GetReference, &GCPointEntityFinder::SetReference)
        .addProperty("FindMethod", &GCPointEntityFinder::GetFindMethod, &GCPointEntityFinder::SetFindMethod)
        .addProperty("OnFoundEntity", &GCPointEntityFinder::GetOnFoundEntity, &GCPointEntityFinder::SetOnFoundEntity)
        .endClass();
}