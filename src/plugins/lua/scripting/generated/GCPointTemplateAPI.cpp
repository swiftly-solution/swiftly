#include "../../../core/scripting/generated/classes/GCPointTemplateAPI.h"
#include "../core.h"

void SetupLuaClassGCPointTemplateAPI(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointTemplateAPI>("CPointTemplateAPI")

        .endClass();
}