#include "../../../core/scripting/generated/classes/GCAnimParameterManagerUpdater.h"
#include "../core.h"

void SetupLuaClassGCAnimParameterManagerUpdater(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimParameterManagerUpdater>("CAnimParameterManagerUpdater")
        .addProperty("IndexToHandle", &GCAnimParameterManagerUpdater::GetIndexToHandle, &GCAnimParameterManagerUpdater::SetIndexToHandle)
        .endClass();
}