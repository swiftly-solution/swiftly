#include "../../../core/scripting/generated/classes/GCNavLinkAnimgraphVar.h"
#include "../core.h"

void SetupLuaClassGCNavLinkAnimgraphVar(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCNavLinkAnimgraphVar>("CNavLinkAnimgraphVar")
        .addProperty("AlignmentDegrees", &GCNavLinkAnimgraphVar::GetAlignmentDegrees, &GCNavLinkAnimgraphVar::SetAlignmentDegrees)
        .endClass();
}